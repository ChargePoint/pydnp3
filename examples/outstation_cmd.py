import cmd
import logging
import sys

from pydnp3 import opendnp3

from outstation import OutstationApplication

stdout_stream = logging.StreamHandler(sys.stdout)
stdout_stream.setFormatter(logging.Formatter('%(asctime)s\t%(name)s\t%(levelname)s\t%(message)s'))

_log = logging.getLogger(__name__)
_log.addHandler(stdout_stream)
_log.setLevel(logging.DEBUG)


class OutstationCmd(cmd.Cmd):
    """
        Create a pydnp3 DNP3Manager that acts as the Outstation in a DNP3 Master/Outstation interaction.

        Accept command-line input that sends simulated measurement changes to the Master,
        using the line-oriented command interpreter framework from the 'cmd' Python Standard Library.
    """

    def __init__(self):
        cmd.Cmd.__init__(self)
        self.prompt = 'outstation> '   # Used by the Cmd framework, displayed when issuing a command-line prompt.
        self.application = OutstationApplication()

    def startup(self):
        """Display the command-line interface's menu and issue a prompt."""
        print('Welcome to the outstation request command line. Supported commands include:')
        self.do_menu('')
        self.cmdloop('Please enter a command.')
        exit()

    def do_a(self, line):
        """Send the Master an AnalogInput (group 32) value. Command syntax is: a index value"""
        index, value_string = self.index_and_value_from_line(line)
        if index and value_string:
            try:
                self.application.apply_update(opendnp3.Analog(float(value_string)), index)
            except ValueError:
                print('Please enter a floating-point value as the second argument.')

    def do_a2(self, line):
        """Send the Master an AnalogInput (group 32) value of 2 at index 4. Command syntax is: a2"""
        self.application.apply_update(opendnp3.Analog(2), index=4)

    def do_b(self, line):
        """Send the Master a BinaryInput (group 2) value. Command syntax is: 'b index true' or 'b index false'"""
        index, value_string = self.index_and_value_from_line(line)
        if index and value_string:
            if value_string.lower() == 'true' or value_string.lower() == 'false':
                self.application.apply_update(opendnp3.Binary(value_string == 'true'), index)
            else:
                print('Please enter true or false as the second argument.')

    def do_b0(self, line):
        """Send the Master a BinaryInput (group 2) value of False at index 6. Command syntax is: b0"""
        self.application.apply_update(opendnp3.Binary(False), index=6)

    def do_c(self, line):
        """Send the Master a Counter (group 22) value. Command syntax is: c index value"""
        index, value_string = self.index_and_value_from_line(line)
        if index and value_string:
            try:
                self.application.apply_update(opendnp3.Counter(int(value_string)), index)
            except ValueError:
                print('Please enter an integer value as the second argument.')

    def do_d(self, line):
        """Send the Master a DoubleBitBinaryInput (group 4) value of DETERMINED_ON. Command syntax is: d index"""
        index = self.index_from_line(line)
        if index:
            self.application.apply_update(opendnp3.DoubleBitBinary(opendnp3.DoubleBit.DETERMINED_ON), index)

    def do_menu(self, line):
        """Display a menu of command-line options. Command syntax is: menu"""
        print('\ta\t\tAnalog measurement.\tEnter index and value as arguments.')
        print('\ta2\t\tAnalog 2 for MMDC.Vol (index 4).')
        print('\tb\t\tBinary measurement.\tEnter index and value as arguments.')
        print('\tb0\t\tBinary False for MMDC1.Amp.range (index 6).')
        print('\tc\t\tCounter measurement.\tEnter index and value as arguments.')
        print('\td\t\tDoubleBit DETERMINED_ON.\tEnter index as an argument.')
        print('\thelp\t\tDisplay command-line help.')
        print('\tmenu\t\tDisplay this menu.')
        print('\tquit')

    def do_quit(self, line):
        """Quit the command line interface. Command syntax is: quit"""
        self.application.shutdown()
        exit()

    @staticmethod
    def index_and_value_from_line(line):
        """Parse an index (integer) and value (string) from command line args and return them."""
        try:
            index = int(line.split(' ')[0])
        except (ValueError, IndexError):
            print('Please enter an integer index as the first argument.')
            index = None
        try:
            value_string = line.split(' ')[1]
        except (ValueError, IndexError):
            print('Please enter a second argument.')
            value_string = None
        return index, value_string

    @staticmethod
    def index_from_line(line):
        """Parse an index (integer) from command line args and return it."""
        try:
            index = int(line.split(' ')[0])
        except (ValueError, IndexError):
            print('Please enter an integer index as the first argument.')
            index = None
        return index


def main():
    cmd_interface = OutstationCmd()
    _log.debug('Initialization complete. In command loop.')
    cmd_interface.startup()
    _log.debug('Exiting.')


if __name__ == '__main__':
    main()
