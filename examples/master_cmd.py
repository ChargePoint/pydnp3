import cmd
import logging
import sys

from datetime import datetime
from pydnp3 import opendnp3, openpal
from master import MyMaster, MyLogger, AppChannelListener, SOEHandler, MasterApplication
from master import command_callback, restart_callback

stdout_stream = logging.StreamHandler(sys.stdout)
stdout_stream.setFormatter(logging.Formatter('%(asctime)s\t%(name)s\t%(levelname)s\t%(message)s'))

_log = logging.getLogger(__name__)
_log.addHandler(stdout_stream)
_log.setLevel(logging.DEBUG)


class MasterCmd(cmd.Cmd):
    """
        Create a DNP3Manager that acts as the Master in a DNP3 Master/Outstation interaction.

        Accept command-line input that sends commands and data to the Outstation,
        using the line-oriented command interpreter framework from the 'cmd' Python Standard Library.
    """

    def __init__(self):
        cmd.Cmd.__init__(self)
        self.prompt = 'master> '   # Used by the Cmd framework, displayed when issuing a command-line prompt.
        self.application = MyMaster(log_handler=MyLogger(),
                                    listener=AppChannelListener(),
                                    soe_handler=SOEHandler(),
                                    master_application=MasterApplication())

    def startup(self):
        """Display the command-line interface's menu and issue a prompt."""
        print('Welcome to the DNP3 master request command line. Supported commands include:')
        self.do_menu('')
        self.cmdloop('Please enter a command.')
        exit()

    def do_menu(self, line):
        """Display a menu of command-line options. Command syntax is: menu"""
        print('\tchan_log_all\tSet the channel log level to ALL_COMMS.')
        print('\tchan_log_normal\tSet the channel log level to NORMAL.')
        print('\tdisable_unsol\tPerform the function DISABLE_UNSOLICITED.')
        print('\thelp\t\tDisplay command-line help.')
        print('\tmast_log_all\tSet the master log level to ALL_COMMS.')
        print('\tmast_log_normal\tSet the master log level to NORMAL.')
        print('\tmenu\t\tDisplay this menu.')
        print('\to1\t\tSend a DirectOperate LATCH_ON command.')
        print('\to2\t\tSend a DirectOperate analog value.')
        print('\to3\t\tSend a DirectOperate CommandSet.')
        print('\tquit')
        print('\trestart\t\tRequest an outstation cold restart.')
        print('\ts1\t\tSend a SelectAndOperate LATCH_ON command.')
        print('\ts2\t\tSend a SelectAndOperate CommandSet.')
        print('\tscan_all\tRead data from the outstation (ScanAllObjects).')
        print('\tscan_fast\tDemand immediate execution of the fast (every 1 mins) Class 1 scan.')
        print('\tscan_range\tPerform an ad-hoc scan (ScanRange) of GroupVariation 1.2, range 0..3.')
        print('\tscan_slow\tDemand immediate execution of the slow (every 30 mins) All-Classes scan.')
        print('\twrite_time\tWrite a TimeAndInterval to the outstation.')

    def do_chan_log_all(self, line):
        """Set the channel log level to ALL_COMMS. Command syntax is: chan_log_all"""
        self.application.channel.SetLogFilters(openpal.LogFilters(opendnp3.levels.ALL_COMMS))
        print('Channel log filtering level is now: {0}'.format(opendnp3.levels.ALL_COMMS))

    def do_chan_log_normal(self, line):
        """Set the channel log level to NORMAL. Command syntax is: chan_log_normal"""
        self.application.channel.SetLogFilters(openpal.LogFilters(opendnp3.levels.NORMAL))
        print('Channel log filtering level is now: {0}'.format(opendnp3.levels.NORMAL))

    def do_disable_unsol(self, line):
        """Perform the function DISABLE_UNSOLICITED. Command syntax is: disable_unsol"""
        headers = [opendnp3.Header().AllObjects(60, 2),
                   opendnp3.Header().AllObjects(60, 3),
                   opendnp3.Header().AllObjects(60, 4)]
        self.application.master.PerformFunction("disable unsolicited",
                                                opendnp3.FunctionCode.DISABLE_UNSOLICITED,
                                                headers,
                                                opendnp3.TaskConfig().Default())

    def do_mast_log_all(self, line):
        """Set the master log level to ALL_COMMS. Command syntax is: mast_log_all"""
        self.application.master.SetLogFilters(openpal.LogFilters(opendnp3.levels.ALL_COMMS))
        _log.debug('Master log filtering level is now: {0}'.format(opendnp3.levels.ALL_COMMS))

    def do_mast_log_normal(self, line):
        """Set the master log level to NORMAL. Command syntax is: mast_log_normal"""
        self.application.master.SetLogFilters(openpal.LogFilters(opendnp3.levels.NORMAL))
        _log.debug('Master log filtering level is now: {0}'.format(opendnp3.levels.NORMAL))

    def do_o1(self, line):
        """Send a DirectOperate BinaryOutput (group 12) index 5 LATCH_ON to the Outstation. Command syntax is: o1"""
        self.application.send_direct_operate_command(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON),
                                                     5,
                                                     command_callback)

    def do_o2(self, line):
        """Send a DirectOperate AnalogOutput (group 41) index 10 value 7 to the Outstation. Command syntax is: o2"""
        self.application.send_direct_operate_command(opendnp3.AnalogOutputInt32(7),
                                                     10,
                                                     command_callback)

    def do_o3(self, line):
        """Send a DirectOperate BinaryOutput (group 12) CommandSet to the Outstation. Command syntax is: o3"""
        self.application.send_direct_operate_command_set(opendnp3.CommandSet(
            [
                opendnp3.WithIndex(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON), 0),
                opendnp3.WithIndex(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_OFF), 1)
            ]),
            command_callback
        )

        # This could also have been in multiple steps, as follows:
        # command_set = opendnp3.CommandSet()
        # command_set.Add([
        #     opendnp3.WithIndex(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON), 0),
        #     opendnp3.WithIndex(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_OFF), 1)
        # ])
        # self.application.send_direct_operate_command_set(command_set, command_callback)

    def do_restart(self, line):
        """Request that the Outstation perform a cold restart. Command syntax is: restart"""
        self.application.master.Restart(opendnp3.RestartType.COLD, restart_callback)

    def do_s1(self, line):
        """Send a SelectAndOperate BinaryOutput (group 12) index 8 LATCH_ON to the Outstation. Command syntax is: s1"""
        self.application.send_select_and_operate_command(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON),
                                                         8,
                                                         command_callback)

    def do_s2(self, line):
        """Send a SelectAndOperate BinaryOutput (group 12) CommandSet to the Outstation. Command syntax is: s2"""
        self.application.send_select_and_operate_command_set(opendnp3.CommandSet(
            [
                opendnp3.WithIndex(opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON), 0)
            ]),
            command_callback
        )

    def do_scan_all(self, line):
        """Call ScanAllObjects. Command syntax is: scan_all"""
        self.application.master.ScanAllObjects(opendnp3.GroupVariationID(2, 1), opendnp3.TaskConfig().Default())

    def do_scan_fast(self, line):
        """Demand an immediate fast scan. Command syntax is: scan_fast"""
        self.application.fast_scan.Demand()

    def do_scan_range(self, line):
        """Do an ad-hoc scan of a range of points (group 1, variation 2, indexes 0-3). Command syntax is: scan_range"""
        self.application.master.ScanRange(opendnp3.GroupVariationID(1, 2), 0, 3, opendnp3.TaskConfig().Default())

    def do_scan_slow(self, line):
        """Demand an immediate slow scan. Command syntax is: scan_slow"""
        self.application.slow_scan.Demand()

    def do_write_time(self, line):
        """Write a TimeAndInterval to the Outstation. Command syntax is: write_time"""
        millis_since_epoch = int((datetime.now() - datetime.utcfromtimestamp(0)).total_seconds() * 1000.0)
        self.application.master.Write(opendnp3.TimeAndInterval(opendnp3.DNPTime(millis_since_epoch),
                                                               100,
                                                               opendnp3.IntervalUnits.Seconds),
                                      0,                            # index
                                      opendnp3.TaskConfig().Default())

    def do_quit(self, line):
        """Quit the command-line interface. Command syntax is: quit"""
        self.application.shutdown()
        exit()


def main():
    cmd_interface = MasterCmd()
    _log.debug('Initialization complete. In command loop.')
    cmd_interface.startup()
    _log.debug('Exiting.')


if __name__ == '__main__':
    main()