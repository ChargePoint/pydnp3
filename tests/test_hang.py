#   MAKE SURE TO RUN OUTSTATION FOR TESTING

from pydnp3 import asiodnp3, asiopal, opendnp3, openpal

import time

FILTERS = opendnp3.levels.NORMAL | opendnp3.levels.ALL_COMMS
HOST = "127.0.0.1"
LOCAL = "0.0.0.0"
PORT = 20000



def run_master(hang=False):
    """Demonstrate hanging when channel and master are not deleted prior to manager.Shutdown()
    """
    logger = asiodnp3.ConsoleLogger().Create()
    manager = asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create())
    #printing_channel_listener = asiodnp3.PrintingChannelListener().Create()
    channel = manager.AddTCPClient("tcpclient",
                                   FILTERS,
                                   asiopal.ChannelRetry(),
                                   HOST,
                                   LOCAL,
                                   PORT,
                                   asiodnp3.PrintingChannelListener().Create())
    stack_config = asiodnp3.MasterStackConfig()
    stack_config.master.responseTimeout = openpal.TimeDuration().Seconds(2)
    stack_config.link.RemoteAddr = 10
    soe_handler = asiodnp3.PrintingSOEHandler().Create()
    default_master_app = asiodnp3.DefaultMasterApplication().Create()
    master = channel.AddMaster("master",
                               soe_handler,
                               default_master_app,
                               stack_config)
    master.Enable()
    time.sleep(2)
    if not hang:
        #del logger
        #del printing_channel_listener
        del channel
        #del stack_config
        #del soe_handler
        #del default_master_app
        del master
    print("Shutdown, Hang = {}".format(hang))
    manager.Shutdown()

# run_master(hang=False)
# run_master(hang=False)
# #run_master(hang=True)

