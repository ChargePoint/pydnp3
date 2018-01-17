# -*- coding: utf-8 -*- {{{
# vim: set fenc=utf-8 ft=python sw=4 ts=4 sts=4 et:
#
# Copyright 2018, Kisensum.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Neither Kisensum, nor any of its employees, nor any jurisdiction or 
# organization that has cooperated in the development of these materials, 
# makes any warranty, express or implied, or assumes any legal liability 
# or responsibility for the accuracy, completeness, or usefulness or any 
# information, apparatus, product, software, or process disclosed, or 
# represents that its use would not infringe privately owned rights. 
# Reference herein to any specific commercial product, process, or service 
# by trade name, trademark, manufacturer, or otherwise does not necessarily 
# constitute or imply its endorsement, recommendation, or favoring by Kisensum.
# }}}

from pydnp3 import asiodnp3 as asiodnp3
from pydnp3 import asiopal as asiopal
from pydnp3 import opendnp3 as opendnp3
from pydnp3 import openpal as openpal
from multiprocessing import Manager, Process

import time


FILTERS = opendnp3.levels.NORMAL | opendnp3.levels.ALL_COMMS
HOST = "127.0.0.1"
LOCAL = "0.0.0.0"
PORT = 20000


class OutstationApplication(opendnp3.IOutstationApplication):
    """
        Interface for all outstation application callback info except for control requests.
    """

    def __init__(self):
        super(OutstationApplication, self).__init__()
        self.link_status = None

    def OnStateChange(self, value):
        """
            Called when a the reset/unreset status of the link layer changes.
        """
        self.link_status = value


class ChannelListener(asiodnp3.IChannelListener):
    """
        Callback interface for receiving information about a running channel.
    """

    def __init__(self):
        super(ChannelListener, self).__init__()
        self.state = None

    def OnStateChange(self, state):
        """
            State change notification.
        """
        self.state = state


class LogHandler(openpal.ILogHandler):
    """
        Callback interface for log messages.
    """

    def __init__(self):
        super(LogHandler, self).__init__()
        self.server = False

    def Log(self, entry):
        """
            Log information.
        """
        if entry.loggerid == "server":
            self.server = True


class TestMaster():

    @staticmethod
    def run_master():
        # Root DNP3 object used to create channels and sessions
        manager = asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create())

        # Connect via a TCPClient socket to an outstation
        channel = manager.AddTCPClient("tcpclient",
                                       FILTERS,
                                       asiopal.ChannelRetry(),
                                       HOST,
                                       LOCAL,
                                       PORT,
                                       asiodnp3.PrintingChannelListener().Create())

        # Master config object for a master
        stack_config = asiodnp3.MasterStackConfig()
        stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
        stack_config.link.RemoteAddr = 10

        # Add a master to a communication channel
        master = channel.AddMaster("master",
                                   asiodnp3.PrintingSOEHandler().Create(),
                                   asiodnp3.DefaultMasterApplication().Create(),
                                   stack_config)

        # Enable the master. This will start communications.
        master.Enable()

        time.sleep(1000)

    @staticmethod
    def run_outstation(exit_dict, value=None, index=0):
        try:
            # Callback interface for log messages
            handler = LogHandler()

            # Root DNP3 object used to create channels and sessions
            manager = asiodnp3.DNP3Manager(1, handler)

            # Connect via a TCPServer socket to a server
            channel_listener = ChannelListener()
            channel = manager.AddTCPServer("server",
                                           FILTERS,
                                           asiopal.ChannelRetry().Default(),
                                           LOCAL,
                                           PORT,
                                           channel_listener)

            # A composite configuration struct that contains all the config information for a dnp3 outstation stack
            config = asiodnp3.OutstationStackConfig(opendnp3.DatabaseSizes.AllTypes(10))
            config.outstation.eventBufferConfig = opendnp3.EventBufferConfig().AllTypes(10)
            config.outstation.params.allowUnsolicited = True
            config.link.LocalAddr = 10
            config.link.KeepAliveTimeout = openpal.TimeDuration().Max()

            # Add an outstation to a communication channel
            outstation_application = OutstationApplication()
            outstation = channel.AddOutstation("outstation",
                                               opendnp3.SuccessCommandHandler().Create(),
                                               outstation_application,
                                               config)
            outstation.Enable()

            # If the master is running, the channel listener state is OPEN
            time.sleep(2)
            assert channel_listener.state == opendnp3.ChannelState.OPEN

            if value is not None:
                # reset the logger id server to False before sending the cmd, if the cmd is sent successful,
                # the log handler should catch the logger id "server"
                handler.server = False

                builder = asiodnp3.UpdateBuilder()
                builder.Update(value, index)
                outstation.Apply(builder.Build())

                # If the message sent successful, the log handler should catch loggerid "server"
                time.sleep(0.2)
                assert handler.server == True

                # Test outstation application tracking info
                assert outstation_application.link_status == opendnp3.LinkStatus.UNRESET

        except AssertionError:
            exit_dict["AssertionError"] = "Failed to send value {0} to master".format(value)

    def test_outstation(self, value=None, index=0):
        exit_dict = Manager().dict()

        master_process = Process(target=self.run_master)
        outstation_process = Process(target=self.run_outstation, args=(exit_dict, value, index))

        master_process.start()
        outstation_process.start()

        master_process.join(timeout=2)
        outstation_process.join(timeout=2)

        # Get process states, if the state = False, the process is terminated due to some error
        master_state = master_process.is_alive()
        outstation_state = outstation_process.is_alive()

        master_process.terminate()
        outstation_process.terminate()

        assert exit_dict.get("AssertionError", None) is None
        assert master_state == True
        assert outstation_state == True

    def test_send_analog(self):
        self.test_outstation(value=opendnp3.Analog(2))

    def test_send_binary(self):
        self.test_outstation(value=opendnp3.Binary(False))

    def test_send_counter(self):
        self.test_outstation(value=opendnp3.Counter(0))

    def test_send_double_bit_binary(self):
        self.test_outstation(value=opendnp3.DoubleBitBinary(opendnp3.DoubleBit.DETERMINED_ON))

