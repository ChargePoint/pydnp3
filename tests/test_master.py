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

from pydnp3 import asiodnp3, asiopal, opendnp3, openpal

import time
import pytest


FILTERS = opendnp3.levels.NORMAL | opendnp3.levels.ALL_COMMS
HOST = "127.0.0.1"
LOCAL = "0.0.0.0"
PORT = 20000


class MasterApplication(opendnp3.IMasterApplication):
    """
        Interface for all master application callback info except for measurement values.
    """

    def __init__(self):
        super(MasterApplication, self).__init__()
        self.iin_field = None
        self.task_id = None
        self.task_info = None
        self.link_status = None

    def OnReceiveIIN(self, iin):
        """
            Called when a response or unsolicited response is receive from the outstation.
        """
        self.iin_field = dict(
            LSB=iin.LSB,
            MSB=iin.MSB
        )

    def OnTaskStart(self, type, id):
        """
            Task start notification.
        """
        self.task_id = dict(
            id=id.GetId(),
            defined=id.IsDefined()
        )

    def OnTaskComplete(self, info):
        """
            Task completion notification.
        """
        self.task_info = dict(
            type=info.type,
            result=info.result
        )

    def OnStateChange(self, value):
        """
            Called when a the reset/unreset status of the link layer changes.
        """
        self.link_status = value

    def Now(self):
        """
            Returns a UTCTimestamp of the current time.
        """
        pass


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
        self.tcp_client = False

    def Log(self, entry):
        """
            Log information.
        """
        if entry.loggerid == "tcpclient":
            self.tcp_client = True


def restart_callback(result=None):
    """
    :type result: opendnp3.RestartOperationResult
    """
    if result.summary == opendnp3.TaskCompletion.SUCCESS:
        print("Restart success | Restart Time: {}".format(result.restartTime.GetMilliseconds()))
    else:
        print("Restart fail | Failure: {}".format(opendnp3.TaskCompletionToString(result.summary)))


def collection_callback(result=None):
    """
    :type result: opendnp3.CommandPointResult
    """
    print("Header: {0} | Index:  {1} | State:  {2} | Status: {3}".format(
        result.headerIndex,
        result.index,
        opendnp3.CommandPointStateToString(result.state),
        opendnp3.CommandStatusToString(result.status)
    ))

def command_callback(result=None):
    """
    :type result: opendnp3.ICommandTaskResult
    """
    print("Received command result with summary: {}".format(opendnp3.TaskCompletionToString(result.summary)))
    result.ForeachItem(collection_callback)


@pytest.fixture(scope="module")
def run_outstation():
    # Root DNP3 object used to create channels and sessions
    manager = asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create())

    # Connect via a TCPServer socket to a server
    channel = manager.AddTCPServer("server",
                                   FILTERS,
                                   asiopal.ChannelRetry().Default(),
                                   LOCAL,
                                   PORT,
                                   asiodnp3.PrintingChannelListener().Create())

    # A composite configuration struct that contains all the config information for a dnp3 outstation stack
    config = asiodnp3.OutstationStackConfig(opendnp3.DatabaseSizes.AllTypes(10))
    config.outstation.eventBufferConfig = opendnp3.EventBufferConfig().AllTypes(10)
    config.outstation.params.allowUnsolicited = True
    config.link.LocalAddr = 10
    config.link.KeepAliveTimeout = openpal.TimeDuration().Max()

    # Add an outstation to a communication channel
    outstation = channel.AddOutstation("outstation",
                                       opendnp3.SuccessCommandHandler().Create(),
                                       opendnp3.DefaultOutstationApplication().Create(),
                                       config)
    outstation.Enable()

    return manager


class TestMaster:

    def config_master(self):
        # Callback interface for log messages
        self.handler = LogHandler()

        # Root DNP3 object used to create channels and sessions
        self.manager = asiodnp3.DNP3Manager(1, self.handler)

        # Connect via a TCPClient socket to an outstation
        self.channel_listener = ChannelListener()
        self.channel = self.manager.AddTCPClient("tcpclient",
                                                 FILTERS,
                                                 asiopal.ChannelRetry(),
                                                 HOST,
                                                 LOCAL,
                                                 PORT,
                                                 self.channel_listener)

        # Master config object for a master
        stack_config = asiodnp3.MasterStackConfig()
        stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
        stack_config.link.RemoteAddr = 10

        # Add a master to a communication channel
        self.master_application = MasterApplication()
        self.master = self.channel.AddMaster("master",
                                             asiodnp3.PrintingSOEHandler().Create(),
                                             self.master_application,
                                             stack_config)

        # Do an integrity poll (Class 3/2/1/0) once per minute
        self.integrity_scan = self.master.AddClassScan(opendnp3.ClassField().AllClasses(),
                                                       openpal.TimeDuration().Minutes(1))

        # Do a Class 1 exception poll every 5 seconds
        self.exception_scan = self.master.AddClassScan(opendnp3.ClassField(opendnp3.ClassField.CLASS_1),
                                                       openpal.TimeDuration().Seconds(2))

        # Enable the master. This will start communications.
        self.master.Enable()

    def shutdown(self):
        del self.exception_scan
        del self.integrity_scan
        del self.master
        del self.channel
        self.manager.__del__()

    def run_master(self, cmd=None):
        self.config_master()

        # reset the logger id tcpclient to False before sending the cmd, if the cmd is sent successful,
        # the log handler should catch the logger id "tcpclient"
        self.handler.tcp_client = False

        if cmd == "a":
            self.master.ScanRange(opendnp3.GroupVariationID(1, 2), 0, 3)
        if cmd == "i":
            self.integrity_scan.Demand()
        if cmd == "e":
            self.exception_scan.Demand()
        if cmd == "c1":
            crob = opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON)
            self.master.SelectAndOperate(crob, 0, command_callback)
        if cmd == "c2":
            crob = opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON)
            commands = opendnp3.CommandSet([opendnp3.WithIndex(crob, 0),
                                            opendnp3.WithIndex(crob, 1)])
            self.master.SelectAndOperate(commands, command_callback)
        if cmd == "d1":
            self.master.DirectOperate(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON),
                                 4,
                                 command_callback)
        if cmd == "d2":
            crob = opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON)
            commands = opendnp3.CommandSet([opendnp3.WithIndex(crob, 0),
                                            opendnp3.WithIndex(crob, 1)])
            self.master.DirectOperate(commands, command_callback)
        if cmd == "r":
            self.master.Restart(opendnp3.RestartType.COLD, restart_callback)

        # If the message sent successful, the log handler should catch loggerid "tcpclient"
        time.sleep(1)
        assert self.handler.tcp_client is True

        # Test master application tracking info
        assert self.master_application.link_status == opendnp3.LinkStatus.UNRESET
        assert self.master_application.task_info == dict(
            type=opendnp3.MasterTaskType.USER_TASK,
            result=opendnp3.TaskCompletion.SUCCESS
        )
        assert self.master_application.iin_field == dict(
            LSB=0,
            MSB=0
        )
        assert self.master_application.task_id == dict(
            defined=False,
            id=-1
        )

        time.sleep(1)
        self.shutdown()

    def test_start(self, run_outstation):
        """Test start the master without sending command."""
        self.run_master()

    def test_send_range_scan(self, run_outstation):
        """Test performs and ad-hoc range scan."""
        self.run_master("a")

    def test_send_integrity_demand_scan(self, run_outstation):
        """Test integrity demand scan."""
        self.run_master("i")

    def test_send_exception_demand_scan(self, run_outstation):
        """Test exception demand scan."""
        self.run_master("e")

    def test_send_SelectAndOperate_single_command(self, run_outstation):
        """Test send CROB select and operate single command."""
        self.run_master("c1")

    def test_send_SelectAndOperate_command_set(self, run_outstation):
        """Test send CROB select and operate command set."""
        self.run_master("c2")

    def test_send_DirectOperate_single_command(self, run_outstation):
        """Test send CROB direct operate single command."""
        self.run_master("d1")

    def test_send_DirectOperate_command_set(self, run_outstation):
        """Test send CROB direct operate command set."""
        self.run_master("d2")

    def test_cold_restart(self, run_outstation):
        """Test cold restart."""
        self.run_master("r")
