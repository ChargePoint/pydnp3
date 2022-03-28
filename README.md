# pydnp3
Python bindings for the [opendnp3](https://github.com/automatak/dnp3) library,  an open source
implementation of the [DNP3](http://ww.dnp.org) protocol stack written in C++14.

Note:  This is a work in progress.  See [Issues](http://github.com/Kisensum/pydnp3/issues) for things we know about and feel free to add your own.

**Supported Platforms:** Linux, MacOS

## Building `manylinux2010` wheels

```
make manylinux2010-build-wheel
make manylinux2010-copy-wheel-to-host
```

Python's manylinux2010 wheels should work on most common Linux distributions.

To change the Python version, change the `MANYLINUX2010_DOCKERFILE`
variable in the Makefile. You may need to create a new Dockerfile.
See the existing manylinux2010 Dockerfiles for a comment indicating
what directory to change to use another CPython manylinux2010 version.

## Building wheels for other OSs and architectures

### Dependencies

To build the library from source, you must have:

* The required version of Python and pip
* A toolchain with a C++14 compiler
* CMake >= 2.8.12 (https://cmake.org/download/)

This repository includes two repositories as submodules (under `deps/`):

* dnp3 (https://github.com/automatak/dnp3)
* pybind11 (https://github.com/Kisensum/pybind11) - This is a fork containing a minor patch
required to compile some of the pydnp3 wrapper code. It will be replaced with pybind11 proper
when the issue is resolved.

#### MacOS

Use brew to install cmake.

Use either pyenv, asdf, or brew to install the right version of Python.
Verify the Python version with:

```
$ pip --version
pip 22.0.2 from /usr/local/lib/python3.10/site-packages/pip (python 3.10)
```

You may need to use `pip3` instead of `pip`.
If so, change the commands in the Makefile.

### Build

```
make local-setup local-build-wheel
```

The wheel will be found in the `wheels/` directory.

If necessary, upload this wheel to the git repo.

## Documentation

pydnp3 is a thin wrapper around most all of the opendnp3 classes.  Documentation for the opendnp3
classes is available at [automatak](https://www.automatak.com/opendnp3/#documentation).

Use python's help to discover the available wrapper classes and functions.  For example,

```
> import pydnp3
> help (pydnp3.opendnp3)
Help on module pydnp3.opendnp3 in pydnp3:

NAME
    pydnp3.opendnp3 - Bindings for opendnp3 namespace

FILE
    (built-in)

CLASSES
    pybind11_builtins.pybind11_object(__builtin__.object)
        AnalogCommandEvent
        AnalogInfo
            AnalogSpec
...
```

