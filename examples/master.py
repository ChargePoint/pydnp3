import logging
import sys

from pydnp3 import opendnp3, openpal, asiopal, asiodnp3

from visitors import VisitorIndexedBinary, VisitorIndexedDoubleBitBinary
from visitors import VisitorIndexedCounter, VisitorIndexedFrozenCounter
from visitors import VisitorIndexedAnalog, VisitorIndexedBinaryOutputStatus
from visitors import VisitorIndexedAnalogOutputStatus, VisitorIndexedTimeAndInterval

LOG_LEVELS = opendnp3.levels.NORMAL | opendnp3.levels.ALL_APP_COMMS
SERVER_IP = "127.0.0.1"
CLIENT_IP = "0.0.0.0"
PORT_NUMBER = 20000

stdout_stream = logging.StreamHandler(sys.stdout)
stdout_stream.setFormatter(logging.Formatter('%(asctime)s\t%(name)s\t%(levelname)s\t%(message)s'))

_log = logging.getLogger(__name__)
_log.addHandler(stdout_stream)
_log.setLevel(logging.DEBUG)


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


class MasterApplication(opendnp3.IMasterApplication):
    """
        Interface for all master application callback info except for measurement values.

        DNP3 spec section 5.1.6.1:
            The Application Layer provides the following services for the DNP3 User Layer in a master:
                - Formats requests directed to one or more outstations.
                - Notifies the DNP3 User Layer when new data or information arrives from an outstation.

        DNP spec section 5.1.6.3:
            The Application Layer requires specific services from the layers beneath it.
                - Partitioning of fragments into smaller portions for transport reliability.
                - Knowledge of which device(s) were the source of received messages.
                - Transmission of messages to specific devices or to all devices.
                - Message integrity (i.e., error-free reception and transmission of messages).
                - Knowledge of the time when messages arrive.
                - Either precise times of transmission or the ability to set time values
                  into outgoing messages.
    """

    master = None

    def __init__(self):
        super(MasterApplication, self).__init__()

        _log.debug('Configuring the DNP3 stack.')
        self.stack_config = self.configure_stack()

        _log.debug('Creating a DNP3Manager.')
        threads_to_allocate = 1
        self.log_handler = MyLogger()
        # self.log_handler = asiodnp3.ConsoleLogger().Create()          # (or use this during regression testing)
        self.manager = asiodnp3.DNP3Manager(threads_to_allocate, self.log_handler)

        _log.debug('Creating the DNP3 channel, a TCP client.')
        self.retry = asiopal.ChannelRetry().Default()
        self.listener = AppChannelListener()
        # self.listener = asiodnp3.PrintingChannelListener().Create()   # (or use this during regression testing)
        self.channel = self.manager.AddTCPClient("tcpclient",
                                                 LOG_LEVELS,
                                                 self.retry,
                                                 SERVER_IP,
                                                 CLIENT_IP,
                                                 PORT_NUMBER,
                                                 self.listener)

        _log.debug('Adding the master to the channel.')
        self.soe_handler = SOEHandler()
        # self.soe_handler = asiodnp3.PrintingSOEHandler().Create()     # (or use this during regression testing)
        self.master = self.channel.AddMaster("master", self.soe_handler, self, self.stack_config)

        # Hold the Master singleton in MasterApplication.
        self.set_master(self.master)

        _log.debug('Configuring some scans (periodic reads).')
        # Set up a "slow scan", an infrequent integrity poll that requests events and static data for all classes.
        self.slow_scan = self.master.AddClassScan(opendnp3.ClassField().AllClasses(),
                                                  openpal.TimeDuration().Minutes(30),
                                                  opendnp3.TaskConfig().Default())
        # Set up a "fast scan", a relatively-frequent exception poll that requests events and class 1 static data.
        self.fast_scan = self.master.AddClassScan(opendnp3.ClassField(opendnp3.ClassField.CLASS_1),
                                                  openpal.TimeDuration().Minutes(1),
                                                  opendnp3.TaskConfig().Default())

        self.channel.SetLogFilters(openpal.LogFilters(opendnp3.levels.ALL_COMMS))
        self.master.SetLogFilters(openpal.LogFilters(opendnp3.levels.ALL_COMMS))

        _log.debug('Enabling the master. At this point, traffic will start to flow between the Master and Outstations.')
        self.master.Enable()

    @classmethod
    def get_master(cls):
        return cls.master

    @classmethod
    def set_master(cls, mstr):
        cls.master = mstr

    # Overridden method
    def AssignClassDuringStartup(self):
        _log.debug('In MasterApplication.AssignClassDuringStartup')
        return False

    # Overridden method
    def OnClose(self):
        _log.debug('In MasterApplication.OnClose')

    # Overridden method
    def OnOpen(self):
        _log.debug('In MasterApplication.OnOpen')

    # Overridden method
    def OnReceiveIIN(self, iin):
        _log.debug('In MasterApplication.OnReceiveIIN')

    # Overridden method
    def OnTaskComplete(self, info):
        _log.debug('In MasterApplication.OnTaskComplete')

    # Overridden method
    def OnTaskStart(self, type, id):
        _log.debug('In MasterApplication.OnTaskStart')

    @staticmethod
    def configure_stack():
        """Set up the OpenDNP3 configuration."""
        stack_config = asiodnp3.MasterStackConfig()
        stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
        stack_config.master.disableUnsolOnStartup = True
        stack_config.link.LocalAddr = 1
        stack_config.link.RemoteAddr = 10
        return stack_config

    def write_integer_value(self, index, value):
        """Write a single integer value to the outstation."""
        _log.debug('Writing integer value {} at index {}'.format(value, index))
        self.write_value(index, opendnp3.AnalogOutputInt32(value))

    def write_floating_point_value(self, index, value):
        """Write a single floating-point value to the outstation."""
        _log.debug('Writing floating-point value {} at index {}'.format(value, index))
        self.write_value(index, opendnp3.AnalogOutputFloat32(value))

    def write_value(self, index, wrapped_value):
        """Write a single analog value (which is already wrapped) to the outstation."""
        self.master.DirectOperate(wrapped_value,
                                  index,
                                  command_callback,
                                  opendnp3.TaskConfig().Default())

    def send_direct_operate_command(self, index, control_code=opendnp3.ControlCode.LATCH_ON):
        """Send a single DirectOperate command to the outstation."""
        self.master.DirectOperate(opendnp3.ControlRelayOutputBlock(control_code),
                                  index,
                                  command_callback,
                                  opendnp3.TaskConfig().Default())

    def send_direct_operate_command_set(self, command_set):
        """Send a DirectOperate CommandSet to the outstation."""
        self.master.DirectOperate(command_set,
                                  command_callback,
                                  opendnp3.TaskConfig().Default())

    def send_select_and_operate_command(self, index, control_code=opendnp3.ControlCode.LATCH_ON):
        """Send a single SelectAndOperate command to the outstation."""
        self.master.SelectAndOperate(opendnp3.ControlRelayOutputBlock(control_code),
                                     index,
                                     command_callback,
                                     opendnp3.TaskConfig().Default())

    def send_select_and_operate_command_set(self, command_set):
        """Send a SelectAndOperate CommandSet to the outstation."""
        self.master.SelectAndOperate(command_set,
                                     command_callback,
                                     opendnp3.TaskConfig().Default())

    def shutdown(self):
        """
            Execute an orderly shutdown of the Master.

            The debug messages may be helpful if errors occur during shutdown.
        """
        # _log.debug('Exiting application...')
        # _log.debug('Shutting down scans...')
        # self.fast_scan = None
        # self.slow_scan = None
        # _log.debug('Shutting down Master...')
        # self.get_master().Disable()
        # _log.debug('Shutting down stack config...')
        # self.stack_config = None
        # _log.debug('Shutting down channel...')
        # self.channel = None
        # _log.debug('Shutting down Master...')
        # self.master = None
        # _log.debug('Shutting down DNP3Manager...')
        # self.manager = None

        self.manager.Shutdown()


class SOEHandler(opendnp3.ISOEHandler):
    """
        Override ISOEHandler in this manner to implement application-specific sequence-of-events behavior.

        This is an interface for SequenceOfEvents (SOE) callbacks from the Master stack to the application layer.
    """

    def __init__(self):
        super(SOEHandler, self).__init__()

    def Process(self, info, values):
        """
            Process measurement data.

        :param info: HeaderInfo
        :param values: A collection of values received from the Outstation (various data types are possible).
        """
        visitor_class_types = {
            opendnp3.ICollectionIndexedBinary: VisitorIndexedBinary,
            opendnp3.ICollectionIndexedDoubleBitBinary: VisitorIndexedDoubleBitBinary,
            opendnp3.ICollectionIndexedCounter: VisitorIndexedCounter,
            opendnp3.ICollectionIndexedFrozenCounter: VisitorIndexedFrozenCounter,
            opendnp3.ICollectionIndexedAnalog: VisitorIndexedAnalog,
            opendnp3.ICollectionIndexedBinaryOutputStatus: VisitorIndexedBinaryOutputStatus,
            opendnp3.ICollectionIndexedAnalogOutputStatus: VisitorIndexedAnalogOutputStatus,
            opendnp3.ICollectionIndexedTimeAndInterval: VisitorIndexedTimeAndInterval
        }
        visitor_class = visitor_class_types[type(values)]
        visitor = visitor_class()
        values.Foreach(visitor)
        for index, value in visitor.index_and_value:
            log_string = 'SOEHandler.Process {0}\theaderIndex={1}\tdata_type={2}\tindex={3}\tvalue={4}'
            _log.debug(log_string.format(info.gv, info.headerIndex, type(values).__name__, index, value))

    def Start(self):
        _log.debug('In SOEHandler.Start')

    def End(self):
        _log.debug('In SOEHandler.End')


class AppChannelListener(asiodnp3.IChannelListener):
    """
        Override IChannelListener in this manner to implement application-specific channel behavior.
    """

    def __init__(self):
        super(AppChannelListener, self).__init__()

    def OnStateChange(self, state):
        _log.debug('In AppChannelListener.OnStateChange: state={}'.format(state))


class MyLogger(openpal.ILogHandler):
    """
        Override ILogHandler in this manner to implement application-specific logging behavior.
    """

    def __init__(self):
        super(MyLogger, self).__init__()

    def Log(self, entry):
        filters = entry.filters.GetBitfield()
        location = entry.location.rsplit('/')[-1] if entry.location else ''
        message = entry.message
        _log.debug('Log\tfilters={}\tlocation={}\tentry={}'.format(filters, location, message))


def main():
    """The Master has been started from the command line. Execute ad-hoc tests if desired."""
    app = MasterApplication()
    _log.debug('Initialization complete. In command loop.')
    # Ad-hoc tests can be performed at this point. See master_cmd.py for examples.
    app.shutdown()
    _log.debug('Exiting.')
    exit()


if __name__ == '__main__':
    main()
