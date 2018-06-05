# PYDNP3 Master Hang on Shutdown Issue

## Description

run_master() function is the python version of `dnp3/cpp/examples/master/main.cpp`:
* Create dnp3 manager
* Connect via a TCPClient socket to a outstation
* Create a master
* Enable the master to start communications

The hang on shutdown issue happens if:
* Define run_master() and call manager.Shutdown() in the same function
Example at: `tests/master.py::run_master_1_hang()`
Example at: `tests/master.py::run_master_4_hang()`

The issue does NOT happen if:
* Define run_master() function to return manager, call manager=run_master() and manager.Shutdown() outside of the stack
Example at: `tests/master.py::run_master_2_no_hang()`
* Define manager as global variable, call run_master()
Example at: `tests/master.py::run_master_3_no_hang()`
* Define manager as global variable, call run_master() and manager.Shutdown() outside of the stack
Example at: `tests/master.py::run_master_5_no_hang()`


## Install Library

From pydnp3 root directory

Check out branch anh/dnp3 to test the hang on shutdown issue with the most updated dnp3 commit from branch 2.0.x
>$ git checkout anh/dnp3

Run shell script for re-install dnp3 submodule due to the version conflict with master branch
>$ source reset_dnp3_submodule.sh

Install pydnp3
>$ python setup.py -q install

## Test

Run outstation from examples/outstation_cmd.py
>$ python examples/outstation_cmd.py

Run master from tests/master.py (in a different terminal)
>$ cd tests
>$ python -c 'from master import *; run_master_1_hang()'
>$ python -c 'from master import *; run_master_2_no_hang()'
>$ python -c 'from master import *; run_master_3_no_hang()'
>$ python -c 'from master import *; run_master_4_hang()'
>$ python -c 'from master import *; run_master_5_no_hang()'

If the hang on shutdown occurs, make sure to kill process to shutdown master:
> $ pkill -9 -f master