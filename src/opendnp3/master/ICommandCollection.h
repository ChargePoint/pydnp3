/*
 * -*- coding: utf-8 -*- {{{
 * vim: set fenc=utf-8 ft=python sw=4 ts=4 sts=4 et:
 *
 * Copyright 2018, Kisensum.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Neither Kisensum, nor any of its employees, nor any jurisdiction or
 * organization that has cooperated in the development of these materials,
 * makes any warranty, express or implied, or assumes any legal liability
 * or responsibility for the accuracy, completeness, or usefulness or any
 * information, apparatus, product, software, or process disclosed, or
 * represents that its use would not infringe privately owned rights.
 * Reference herein to any specific commercial product, process, or service
 * by trade name, trademark, manufacturer, or otherwise does not necessarily
 * constitute or imply its endorsement, recommendation, or favoring by Kisensum.
 * }}}
 */

#ifndef PYDNP3_OPENDNP3_MASTER_ICOMMANDCOLLECTION_H
#define PYDNP3_OPENDNP3_MASTER_ICOMMANDCOLLECTION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/ICommandCollection.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3
{
/**
* Overriding virtual functions from interface class ICommandCollection<T>.
*/
    template <class T>
    class PyICommandCollection : public ICommandCollection<T>
    {
    public:
        /* Trampoline for ICommandCollection virtual functions */
        ICommandCollection<T>& Add(const T& command, uint16_t index) override {
            PYBIND11_OVERLOAD_PURE(
                ICommandCollection<T>&,
                ICommandCollection<T>,
                Add,
                command, index
            );
        }
    };
}

template <class T>
void declareICommandCollection(py::module &m, string const &type)
{
    // ----- class: opendnp3::ICommandCollection<T> -----
    py::class_<opendnp3::ICommandCollection<T>,
               opendnp3::PyICommandCollection<T>>(m, ("ICommandCollection" + type).c_str(),
        "A collection type for command to which the user can add by type and index.")

        .def(py::init<>())

        .def(
            "Add",
            &opendnp3::ICommandCollection<T>::Add,
            py::arg("command"), py::arg("index")
        );
}

void bind_ICommandCollection(py::module &m)
{
    declareICommandCollection<opendnp3::ControlRelayOutputBlock>(m, "ControlRelayOutputBlock");
    declareICommandCollection<opendnp3::AnalogOutputInt32>(m, "AnalogOutputInt32");
    declareICommandCollection<opendnp3::AnalogOutputInt16>(m, "AnalogOutputInt16");
    declareICommandCollection<opendnp3::AnalogOutputFloat32>(m, "AnalogOutputFloat32");
    declareICommandCollection<opendnp3::AnalogOutputDouble64>(m, "AnalogOutputDouble64");
}

#endif // PYDNP3_OPENDNP3
#endif
