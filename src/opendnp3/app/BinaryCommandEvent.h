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

#ifndef PYDNP3_OPENDNP3_APP_BINARYCOMMANDEVENT_H
#define PYDNP3_OPENDNP3_APP_BINARYCOMMANDEVENT_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/BinaryCommandEvent.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_BinaryCommandEvent(py::module &m)
{
    // ----- class: opendnp3::BinaryCommandEvent -----
    py::class_<opendnp3::BinaryCommandEvent, std::shared_ptr<opendnp3::BinaryCommandEvent>>(m, "BinaryCommandEvent",
        "Maps to Group13Var1/2.")

        .def(py::init<>())

        .def(
            py::init<opendnp3::Flags>(),
            py::arg("flags")
        )

        .def(
            py::init<opendnp3::Flags, opendnp3::DNPTime>(),
            py::arg("flags"), py::arg("time")
        )

        .def(
            py::init<bool, opendnp3::CommandStatus>(),
            py::arg("value"), py::arg("status")
        )

        .def(
            py::init<bool, opendnp3::CommandStatus, opendnp3::DNPTime>(),
            py::arg("value"), py::arg("status"), py::arg("time")
        )

        .def_readwrite(
            "value",
            &opendnp3::BinaryCommandEvent::value
        )

        .def_readwrite(
            "status",
            &opendnp3::BinaryCommandEvent::status
        )

        .def_readwrite(
            "time",
            &opendnp3::BinaryCommandEvent::time
        )

        .def(
            "GetFlags",
            &opendnp3::BinaryCommandEvent::GetFlags
        )

        .def(
            "__eq__",
            &opendnp3::BinaryCommandEvent::operator==,
            "Equality comparision."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
