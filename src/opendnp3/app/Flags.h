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

#ifndef PYDNP3_OPENDNP3_APP_FLAGS_H
#define PYDNP3_OPENDNP3_APP_FLAGS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/Flags.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_Flags(py::module &m)
{
    // ----- class: opendnp3::Flags -----
    py::class_<opendnp3::Flags>(m, "Flags",
        "Measurement Flags.")

        .def(
            py::init<uint8_t>(),
            ":param value: defaults to 0 \n"
            ":type value: unsigned char",
            py::arg("value") = 0
        )

        .def_readwrite(
            "value",
            &opendnp3::Flags::value,
            ":type value: unsigned char"
        )

        .def(
            "IsSet",
            (bool (opendnp3::Flags::*)(opendnp3::BinaryQuality) const)
            &opendnp3::Flags::IsSet,
            py::arg("flag")
        )

        .def(
            "IsSet",
            (bool (opendnp3::Flags::*)(opendnp3::AnalogQuality) const)
            &opendnp3::Flags::IsSet,
            py::arg("flag")
        )

        .def(
            "IsSet",
            (bool (opendnp3::Flags::*)(opendnp3::CounterQuality) const)
            &opendnp3::Flags::IsSet,
            py::arg("flag")
        )

        .def(
            "IsSet",
            (bool (opendnp3::Flags::*)(opendnp3::FrozenCounterQuality) const)
            &opendnp3::Flags::IsSet,
            py::arg("flag")
        )

        .def(
            "IsSet",
            (bool (opendnp3::Flags::*)(opendnp3::BinaryOutputStatusQuality) const)
            &opendnp3::Flags::IsSet,
            py::arg("flag")
        )

        .def(
            "IsSet",
            (bool (opendnp3::Flags::*)(opendnp3::AnalogOutputStatusQuality) const)
            &opendnp3::Flags::IsSet,
            py::arg("flag")
        )

        .def(
            "Set",
            (void (opendnp3::Flags::*)(opendnp3::BinaryQuality))
            &opendnp3::Flags::Set,
            py::arg("flag")
        )

        .def(
            "Set",
            (void (opendnp3::Flags::*)(opendnp3::AnalogQuality))
            &opendnp3::Flags::Set,
            py::arg("flag")
        )

        .def(
            "Set",
            (void (opendnp3::Flags::*)(opendnp3::CounterQuality))
            &opendnp3::Flags::Set,
            py::arg("flag")
        )

        .def(
            "Set",
            (void (opendnp3::Flags::*)(opendnp3::FrozenCounterQuality))
            &opendnp3::Flags::Set,
            py::arg("flag")
        )

        .def(
            "Set",
            (void (opendnp3::Flags::*)(opendnp3::BinaryOutputStatusQuality))
            &opendnp3::Flags::Set,
            py::arg("flag")
        )

        .def(
            "Set",
            (void (opendnp3::Flags::*)(opendnp3::AnalogOutputStatusQuality))
            &opendnp3::Flags::Set,
            py::arg("flag")
        );
}

#endif // PYDNP3_OPENDNP3
#endif
