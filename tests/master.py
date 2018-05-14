#   MAKE SURE TO RUN OUTSTATION FOR TESTING

from pydnp3 import asiodnp3, asiopal, opendnp3, openpal

import time

FILTERS = opendnp3.levels.NORMAL | opendnp3.levels.ALL_COMMS
HOST = "127.0.0.1"
LOCAL = "0.0.0.0"
PORT = 20000


# Declare the manager1 & calling manager1.Shutdown() inside the stack, the master is hanging
def run_master_1_hang():
    manager1 = asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create())
    channel = manager1.AddTCPClient("tcpclient",
                                   FILTERS,
                                   asiopal.ChannelRetry(),
                                   HOST,
                                   LOCAL,
                                   PORT,
                                   asiodnp3.PrintingChannelListener().Create())
    stack_config = asiodnp3.MasterStackConfig()
    stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
    stack_config.link.RemoteAddr = 10
    master = channel.AddMaster("master",
                               asiodnp3.PrintingSOEHandler().Create(),
                               asiodnp3.DefaultMasterApplication().Create(),
                               stack_config)
    master.Enable()
    time.sleep(5)
    manager1.Shutdown()


# Get the manager2 & calling manager2 outside of the stack, the hang issue does not happen
def get_manager_2():
    manager2 = asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create())
    channel = manager2.AddTCPClient("tcpclient",
                                    FILTERS,
                                    asiopal.ChannelRetry(),
                                    HOST,
                                    LOCAL,
                                    PORT,
                                    asiodnp3.PrintingChannelListener().Create())

    stack_config = asiodnp3.MasterStackConfig()
    stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
    stack_config.link.RemoteAddr = 10
    master = channel.AddMaster("master",
                               asiodnp3.PrintingSOEHandler().Create(),
                               asiodnp3.DefaultMasterApplication().Create(),
                               stack_config)
    master.Enable()
    time.sleep(5)
    return manager2 # <--- Return the manager2 so that we can get the manager2 outside the stack

def run_master_2_no_hang():
    manager2 = get_manager_2() # <--- Get the manager2 by calling get_manager_2() function
    manager2.Shutdown()        # <--- The hang issue does not happen either with or without calling Shutdown()


# Declare global variable manager3, without calling manager3.Shutdown(), the hang issue does not happen
manager3 = None
def run_master_3_no_hang():
    global manager3
    manager3 = asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create())
    channel = manager3.AddTCPClient("tcpclient",
                                    FILTERS,
                                    asiopal.ChannelRetry(),
                                    HOST,
                                    LOCAL,
                                    PORT,
                                    asiodnp3.PrintingChannelListener().Create())
    stack_config = asiodnp3.MasterStackConfig()
    stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
    stack_config.link.RemoteAddr = 10
    master = channel.AddMaster("master",
                               asiodnp3.PrintingSOEHandler().Create(),
                               asiodnp3.DefaultMasterApplication().Create(),
                               stack_config)
    master.Enable()
    time.sleep(5)


# Same as run_master_3 but calling manager4.Shutdown() inside the stack, the master is hanging
manager4 = None
def run_master_4_hang():
    global manager4
    manager4 = asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create())
    channel = manager4.AddTCPClient("tcpclient",
                                    FILTERS,
                                    asiopal.ChannelRetry(),
                                    HOST,
                                    LOCAL,
                                    PORT,
                                    asiodnp3.PrintingChannelListener().Create())
    stack_config = asiodnp3.MasterStackConfig()
    stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
    stack_config.link.RemoteAddr = 10
    master = channel.AddMaster("master",
                               asiodnp3.PrintingSOEHandler().Create(),
                               asiodnp3.DefaultMasterApplication().Create(),
                               stack_config)
    master.Enable()
    time.sleep(5)
    manager4.Shutdown() # <--- the hang issue happens when calling Shutdown() inside the function


# Same as run_master_3 but calling Shutdown outside of the stack, the hang issue does not happen
def run_master_5_no_hang():
    run_master_3_no_hang()
    manager3.Shutdown() # <--- The hang issue does not happen either with or without calling Shutdown()


# run_master_1_hang()
# run_master_2_no_hang()
# run_master_3_no_hang()
# run_master_4_hang()
# run_master_5_no_hang()