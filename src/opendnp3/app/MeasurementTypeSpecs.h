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

#ifndef PYDNP3_OPENDNP3_APP_MEASUREMENTTYPESPECS_H
#define PYDNP3_OPENDNP3_APP_MEASUREMENTTYPESPECS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/MeasurementTypeSpecs.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_MeasurementTypeSpecs(py::module &m)
{
    // ----- class: opendnp3::BinarySpec -----
    py::class_<opendnp3::BinarySpec, opendnp3::BinaryInfo>(m, "BinarySpec")

        .def_static(
            "IsQualityOnlineOnly",
            &opendnp3::BinarySpec::IsQualityOnlineOnly,
            py::arg("binary")
        )

        .def_static(
            "IsEvent",
            &opendnp3::BinarySpec::IsEvent,
            py::arg("oldValue"), py::arg("newValue")
        );

    // ----- class: opendnp3::DoubleBitBinarySpec -----
    py::class_<opendnp3::DoubleBitBinarySpec, opendnp3::DoubleBitBinaryInfo>(m, "DoubleBitBinarySpec")

        .def_static(
            "IsEvent",
            &opendnp3::DoubleBitBinarySpec::IsEvent,
            py::arg("oldValue"), py::arg("newValue")
        );

    // ----- class: opendnp3::BinaryOutputStatusSpec -----
    py::class_<opendnp3::BinaryOutputStatusSpec, opendnp3::BinaryOutputStatusInfo>(m, "BinaryOutputStatusSpec")

        .def_static(
            "IsEvent",
            &opendnp3::BinaryOutputStatusSpec::IsEvent,
            py::arg("oldValue"), py::arg("newValue")
        );

    // ----- class: opendnp3::AnalogSpec -----
    py::class_<opendnp3::AnalogSpec, opendnp3::AnalogInfo>(m, "AnalogSpec")

        .def_static(
            "IsEvent",
            &opendnp3::AnalogSpec::IsEvent,
            ":type deadband: double",
            py::arg("oldValue"), py::arg("newValue"), py::arg("deadband")
        );

    // ----- class: opendnp3::CounterSpec -----
    py::class_<opendnp3::CounterSpec, opendnp3::CounterInfo>(m, "CounterSpec")
        .def_static(
            "IsEvent",
            &opendnp3::CounterSpec::IsEvent,
            ":type deadband: unsigned int",
            py::arg("oldValue"), py::arg("newValue"), py::arg("deadband")
        );

    // ----- class: opendnp3::FrozenCounterSpec -----
    py::class_<opendnp3::FrozenCounterSpec, opendnp3::FrozenCounterInfo>(m, "FrozenCounterSpec")

        .def_static(
            "IsEvent",
            &opendnp3::FrozenCounterSpec::IsEvent,
            ":type deadband: unsigned int",
            py::arg("oldValue"), py::arg("newValue"), py::arg("deadband")
        );

    // ----- class: opendnp3::AnalogOutputStatusSpec -----
    py::class_<opendnp3::AnalogOutputStatusSpec, opendnp3::AnalogOutputStatusInfo>(m, "AnalogOutputStatusSpec")

        .def_static(
            "IsEvent",
            &opendnp3::AnalogOutputStatusSpec::IsEvent,
            ":type deadband: double",
            py::arg("oldValue"), py::arg("newValue"), py::arg("deadband")
        );

    // ----- class: opendnp3::TimeAndIntervalSpec -----
    py::class_<opendnp3::TimeAndIntervalSpec, opendnp3::TimeAndIntervalInfo>(m, "TimeAndIntervalSpec");

    // ----- class: opendnp3::SecurityStatSpec -----
    py::class_<opendnp3::SecurityStatSpec, opendnp3::SecurityStatInfo>(m, "SecurityStatSpec")

        .def_static(
            "IsEvent",
            &opendnp3::SecurityStatSpec::IsEvent,
            ":type deadband: unsigned int",
            py::arg("oldValue"), py::arg("newValue"), py::arg("deadband")
        );
}

#endif // PYDNP3_OPENDNP3
#endif
