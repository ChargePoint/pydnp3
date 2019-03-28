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

#ifndef PYDNP3_OPENDNP3_APP_INDEXED_H
#define PYDNP3_OPENDNP3_APP_INDEXED_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/Indexed.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
    class AnalogOutputFloat32;
    class AnalogOutputDouble64;
    class AnalogOutputInt16;
    class AnalogOutputInt32;
    class ControlRelayOutputBlock;
}

template <class T>
void declareIndexed(py::module &m, string const & type)
{
    // ----- class: opendnp3::Indexed<T> -----
    py::class_<opendnp3::Indexed<T>>(m, ("Indexed" + type).c_str(),
        "A simple tuple for pairing Values with an index.")

        .def(py::init<>())

        .def(
            py::init<const T&, uint16_t>(),
            ":type index: unsigned short",
            py::arg("value"), py::arg("index") = 0
        )

        .def_readwrite(
            "value",
            &opendnp3::Indexed<T>::value
        )

        .def_readwrite(
            "index",
            &opendnp3::Indexed<T>::index,
            ":type index: unsigned short"
        );

    // ----- function: opendnp3::WithIndex<T> -----
    m.def("WithIndex", &opendnp3::WithIndex<T>);
}

void bind_Indexed(py::module &m)
{
    declareIndexed<opendnp3::Binary>(m, "Binary");
    declareIndexed<opendnp3::DoubleBitBinary>(m, "DoubleBitBinary");
    declareIndexed<opendnp3::Analog>(m, "Analog");
    declareIndexed<opendnp3::Counter>(m, "Counter");
    declareIndexed<opendnp3::FrozenCounter>(m, "FrozenCounter");
    declareIndexed<opendnp3::BinaryOutputStatus>(m, "BinaryOutputStatus");
    declareIndexed<opendnp3::AnalogOutputStatus>(m, "AnalogOutputStatus");
    declareIndexed<opendnp3::OctetString>(m, "OctetString");
    declareIndexed<opendnp3::TimeAndInterval>(m, "TimeAndInterval");
    declareIndexed<opendnp3::BinaryCommandEvent>(m, "BinaryCommandEvent");
    declareIndexed<opendnp3::AnalogCommandEvent>(m, "AnalogCommandEvent");
    declareIndexed<opendnp3::SecurityStat>(m, "SecurityStat");
    declareIndexed<opendnp3::ControlRelayOutputBlock>(m, "ControlRelayOutputBlock");
    declareIndexed<opendnp3::AnalogOutputInt16>(m, "AnalogOutputInt16");
    declareIndexed<opendnp3::AnalogOutputInt32>(m, "AnalogOutputInt32");
    declareIndexed<opendnp3::AnalogOutputFloat32>(m, "AnalogOutputFloat32");
    declareIndexed<opendnp3::AnalogOutputDouble64>(m, "AnalogOutputDouble64");
}

#endif // PYDNP3_OPENDNP3
#endif
