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

#ifndef PYDNP3_OPENDNP3_APP_MEASUREMENTINFO_H
#define PYDNP3_OPENDNP3_APP_MEASUREMENTINFO_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/MeasurementInfo.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_MeasurementInfo(py::module &m)
{
    // ----- class: opendnp3::BinaryInfo -----
    py::class_<opendnp3::BinaryInfo>(m, "BinaryInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::BinaryInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::BinaryInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::BinaryInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::BinaryInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::DoubleBitBinaryInfo -----
    py::class_<opendnp3::DoubleBitBinaryInfo>(m, "DoubleBitBinaryInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::DoubleBitBinaryInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::DoubleBitBinaryInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::DoubleBitBinaryInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::DoubleBitBinaryInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::BinaryOutputStatusInfo -----
    py::class_<opendnp3::BinaryOutputStatusInfo>(m, "BinaryOutputStatusInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::BinaryOutputStatusInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::BinaryOutputStatusInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::BinaryOutputStatusInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::BinaryOutputStatusInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::AnalogInfo -----
    py::class_<opendnp3::AnalogInfo>(m, "AnalogInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::AnalogInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::AnalogInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::AnalogInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::AnalogInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::CounterInfo -----
    py::class_<opendnp3::CounterInfo>(m, "CounterInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::CounterInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::CounterInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::CounterInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::CounterInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::FrozenCounterInfo -----
    py::class_<opendnp3::FrozenCounterInfo>(m, "FrozenCounterInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::FrozenCounterInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::FrozenCounterInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::FrozenCounterInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::FrozenCounterInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::AnalogOutputStatusInfo -----
    py::class_<opendnp3::AnalogOutputStatusInfo>(m, "AnalogOutputStatusInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::AnalogOutputStatusInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::AnalogOutputStatusInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::AnalogOutputStatusInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::AnalogOutputStatusInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::TimeAndIntervalInfo -----
    py::class_<opendnp3::TimeAndIntervalInfo>(m, "TimeAndIntervalInfo")

        .def_property_readonly_static(
            "StaticTypeEnum",
            [](py::object) { return opendnp3::TimeAndIntervalInfo::StaticTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::TimeAndIntervalInfo::DefaultStaticVariation; }
        );

    // ----- class: opendnp3::SecurityStatInfo -----
    py::class_<opendnp3::SecurityStatInfo>(m, "SecurityStatInfo")

        .def_property_readonly_static(
            "EventTypeEnum",
            [](py::object) { return opendnp3::SecurityStatInfo::EventTypeEnum; }
        )

        .def_property_readonly_static(
            "DefaultEventVariation",
            [](py::object) { return opendnp3::SecurityStatInfo::DefaultEventVariation; }
        )

        .def_property_readonly_static(
            "DefaultStaticVariation",
            [](py::object) { return opendnp3::SecurityStatInfo::DefaultStaticVariation; }
        );
}

#endif // PYDNP3_OPENDNP3
#endif
