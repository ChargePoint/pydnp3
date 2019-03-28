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

#ifndef PYDNP3_OPENDNP3_GEN_STOPBITS_H
#define PYDNP3_OPENDNP3_GEN_STOPBITS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/StopBits.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_StopBits(py::module &m)
{
    // ----- enum class: opendnp3::StopBits
    py::enum_<opendnp3::StopBits>(m, "StopBits",
        "Enumeration for setting serial port stop bits.")

        .value("One", opendnp3::StopBits::One)
        .value("OnePointFive", opendnp3::StopBits::OnePointFive)
        .value("Two", opendnp3::StopBits::Two)
        .value("None", opendnp3::StopBits::None);

    // ----- func: opendnp3::StopBitsToType -----
    m.def(
        "StopBitsToType",
        &opendnp3::StopBitsToType,
        py::arg("stopBits")
    );

    // ----- func: opendnp3::StopBitsFromType -----
    m.def(
        "StopBitsFromType",
        &opendnp3::StopBitsFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );

    // ----- func: opendnp3::StopBitsToString -----
    m.def(
        "StopBitsToString",
        &opendnp3::StopBitsToString,
        py::arg("stopBits")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
