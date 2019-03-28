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

#ifndef PYDNP3_OPENDNP3_MASTER_HEADERTYPES_H
#define PYDNP3_OPENDNP3_MASTER_HEADERTYPES_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/HeaderTypes.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3
{
    class HeaderWriter {};
}

void bind_HeaderTypes(py::module &m)
{
    // ----- class: opendnp3::HeaderWriter -----
    py::class_<opendnp3::HeaderWriter>(m, "HeaderWriter");

    // ----- enum class: opendnp3::HeaderType -----
    py::enum_<opendnp3::HeaderType>(m, "HeaderType",
        "An enumeration that defines the type of object header.")

        .value("AllObjects", opendnp3::HeaderType::AllObjects)
        .value("Ranged8", opendnp3::HeaderType::Ranged8)
        .value("Ranged16", opendnp3::HeaderType::Ranged16)
        .value("LimitedCount8", opendnp3::HeaderType::LimitedCount8)
        .value("LimitedCount16", opendnp3::HeaderType::LimitedCount16);

    // ----- struct: opendnp3::StartStopRangeUint8 -----
    py::class_<opendnp3::StartStopRange<uint8_t>>(m, "StartStopRangeUint8",
        "A template for a integer range.")

        .def(
            py::init<uint8_t, uint8_t>(),
            py::arg("start") = 0,
            py::arg("stop") = 0
        )

        .def_readwrite(
            "start",
            &opendnp3::StartStopRange<uint8_t>::start
        )

        .def_readwrite(
            "stop",
            &opendnp3::StartStopRange<uint8_t>::stop
        );

    // ----- struct: opendnp3::StartStopRangeUint16 -----
    py::class_<opendnp3::StartStopRange<uint16_t>>(m, "StartStopRangeUint16",
        "A template for a integer range.")

        .def(
            py::init<uint16_t, uint16_t>(),
            py::arg("start") = 0,
            py::arg("stop") = 0
        )

        .def_readwrite(
            "start",
            &opendnp3::StartStopRange<uint16_t>::start
        )

        .def_readwrite(
            "stop",
            &opendnp3::StartStopRange<uint16_t>::stop
        );

    // ----- struct: opendnp3::CountUint8 -----
    py::class_<opendnp3::Count<uint8_t>>(m, "CountUint8",
        "A template for an integer count.")

        .def(
            py::init<uint8_t>(),
            py::arg("value") = 0
        )
        .def_readwrite(
            "value",
            &opendnp3::Count<uint8_t>::value
        );

    // ----- struct: opendnp3::CountUint16 -----
    py::class_<opendnp3::Count<uint16_t>>(m, "CountUint16",
        "A template for an integer count.")

        .def(
            py::init<uint16_t>(),
            py::arg("value") = 0
        )

        .def_readwrite(
            "value",
            &opendnp3::Count<uint16_t>::value
        );

    // ----- union class: opendnp3::HeaderUnion -----
    py::class_<opendnp3::HeaderUnion>(m, "HeaderUnion",
        "Union type that holds information for a single header type.")

        .def(py::init<>())

        .def_property(
            "range8",
            [](const opendnp3::HeaderUnion &self) -> const opendnp3::StartStopRange<uint8_t>& { return self.range8; },
            [](opendnp3::HeaderUnion &self, const opendnp3::StartStopRange<uint8_t>& value) { self.range8 = value; },
            py::return_value_policy::reference_internal
        )

        .def_property(
            "range16",
            [](const opendnp3::HeaderUnion &self) -> const opendnp3::StartStopRange<uint16_t>& { return self.range16; },
            [](opendnp3::HeaderUnion &self, const opendnp3::StartStopRange<uint16_t>& value) { self.range16 = value; },
            py::return_value_policy::reference_internal
        )

        .def_property(
            "count8",
            [](const opendnp3::HeaderUnion &self) -> const opendnp3::Count<uint8_t>& { return self.count8; },
            [](opendnp3::HeaderUnion &self, const opendnp3::Count<uint8_t>& value) { self.count8 = value; },
            py::return_value_policy::reference_internal
        )

        .def_property(
            "count16",
            [](const opendnp3::HeaderUnion &self) -> const opendnp3::Count<uint16_t>& { return self.count16; },
            [](opendnp3::HeaderUnion &self, const opendnp3::Count<uint16_t>& value) { self.count16 = value; },
            py::return_value_policy::reference_internal
        );

    // ----- class: opendnp3::Header -----
    py::class_<opendnp3::Header>(m, "Header",
        "Class used to specify a header type.")

        .def(py::init<>())

        .def(
            "WriteTo",
            &opendnp3::Header::WriteTo,
            py::arg("writer")
        )

        .def_static(
            "AllObjects",
            &opendnp3::Header::AllObjects,
            "Create an all objects (0x06) header.",
            py::arg("group"), py::arg("variation")
        )

        .def_static(
            "From",
            &opendnp3::Header::From,
            "Create an all objects (0x06) header.",
            py::arg("pointClass")
        )

        .def_static(
            "Range8",
            &opendnp3::Header::Range8,
            "Create a 8-bit start stop header (0x00).",
            py::arg("group"), py::arg("variation"), py::arg("start"), py::arg("stop")
        )

        .def_static(
            "Range16",
            &opendnp3::Header::Range16,
            "Create a 16-bit start stop header (0x01).",
            py::arg("group"), py::arg("variation"), py::arg("start"), py::arg("stop")
        )

        .def_static(
            "Count8",
            &opendnp3::Header::Count8,
            "Create a 8-bit count header (0x07).",
            py::arg("group"), py::arg("variation"), py::arg("count")
        )

        .def_static(
            "Count16",
            &opendnp3::Header::Count16,
            "Create a 16-bit count header (0x08).",
            py::arg("group"), py::arg("variation"), py::arg("count")
        );
}

#endif // PYDNP3_OPENDNP3
#endif
