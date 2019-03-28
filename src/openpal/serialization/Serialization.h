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

#ifndef PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATION_H
#define PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/serialization/Serialization.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Serialization(py::module &m)
{
	// ----- class: openpal::Int16 -----
    py::class_<openpal::Int16>(m, "Int16")

        .def_static(
            "Read",
            &openpal::Int16::Read,
            ":type data: unsigned char",
            py::arg("data")
        )

        .def_static(
            "Write",
            &openpal::Int16::Write,
            ":type data: unsigned char \n"
            ":type value: short",
            py::arg("data"), py::arg("value")
        )

        .def_static(
            "WriteBuffer",
            &openpal::Int16::WriteBuffer,
            ":type aValue: short",
            py::arg("buffer"), py::arg("aValue")
        )

        .def_static(
            "ReadBuffer",
            &openpal::Int16::ReadBuffer,
            py::arg("arBuffer")
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::Int16::SIZE; }
        )

        .def_property_readonly_static(
            "Max",
            [](py::object) { return openpal::Int16::Max; }
        )

        .def_property_readonly_static(
            "Min",
            [](py::object) { return openpal::Int16::Min; }
        );

    // ----- class: openpal::UInt16 -----
    py::class_<openpal::UInt16>(m, "UInt16")

        .def_static(
            "Read",
            &openpal::UInt16::Read,
            ":type data: unsigned char",
            py::arg("data")
        )

        .def_static(
            "Write",
            &openpal::UInt16::Write,
            ":type data: unsigned char \n"
            ":type value: unsigned short",
            py::arg("data"), py::arg("value")
        )

        .def_static(
            "WriteBuffer",
            &openpal::UInt16::WriteBuffer,
            ":type aValue: unsigned short",
            py::arg("buffer"), py::arg("aValue")
        )

        .def_static(
            "ReadBuffer",
            &openpal::UInt16::ReadBuffer,
            py::arg("arBuffer")
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::UInt16::SIZE; }
        )

        .def_property_readonly_static(
            "Max",
            [](py::object) { return openpal::UInt16::Max; }
        )

        .def_property_readonly_static(
            "Min",
            [](py::object) { return openpal::UInt16::Min; }
        );

    // ----- class: openpal::Int32 -----
    py::class_<openpal::Int32>(m, "Int32")

        .def_static(
            "Read",
            &openpal::Int32::Read,
            ":type data: unsigned char",
            py::arg("data")
        )

        .def_static(
            "Write",
            &openpal::Int32::Write,
            ":type data: unsigned char \n"
            ":type value: short",
            py::arg("data"), py::arg("value")
        )

        .def_static(
            "WriteBuffer",
            &openpal::Int32::WriteBuffer,
            ":type aValue: short",
            py::arg("buffer"), py::arg("aValue")
        )

        .def_static(
            "ReadBuffer",
            &openpal::Int32::ReadBuffer,
            py::arg("buffer")
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::Int32::SIZE; }
        )

        .def_property_readonly_static(
            "Max",
            [](py::object) { return openpal::Int32::Max; }
        )

        .def_property_readonly_static(
            "Min",
            [](py::object) { return openpal::Int32::Min; }
        );

    // ----- class: openpal::UInt32 -----
    py::class_<openpal::UInt32>(m, "UInt32")

        .def_static(
            "Read",
            &openpal::UInt32::Read,
            ":type data: unsigned char",
            py::arg("data")
        )

        .def_static(
            "Write",
            &openpal::UInt32::Write,
            ":type data: unsigned char \n"
            ":type value: unsigned short",
            py::arg("data"), py::arg("value")
        )

        .def_static(
            "WriteBuffer",
            &openpal::UInt32::WriteBuffer,
            ":type aValue: unsigned short",
            py::arg("buffer"), py::arg("aValue")
        )

        .def_static(
            "ReadBuffer",
            &openpal::UInt32::ReadBuffer,
            py::arg("buffer")
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::UInt32::SIZE; }
        )

        .def_property_readonly_static(
            "Max",
            [](py::object) { return openpal::UInt32::Max; }
        )

        .def_property_readonly_static(
            "Min",
            [](py::object) { return openpal::UInt32::Min; }
        );

    // ----- class: openpal::UInt48 -----
    py::class_<openpal::UInt48>(m, "UInt48")

        .def_static(
            "Read",
            &openpal::UInt48::Read,
            ":type data: unsigned char",
            py::arg("data")
        )

        .def_static(
            "Write",
            &openpal::UInt48::Write,
            ":type data: unsigned char \n"
            ":type value: opendnp3.DNPTime",
            py::arg("data"), py::arg("value")
        )

        .def_static(
            "ReadBuffer",
            &openpal::UInt48::ReadBuffer,
            py::arg("buffer")
        )

        .def_static(
            "WriteBuffer",
            &openpal::UInt48::WriteBuffer,
            ":type value: opendnp3.DNPTime",
            py::arg("buffer"), py::arg("value")
        )

        .def_property_readonly_static(
            "MAX",
            [](py::object) { return openpal::UInt48::MAX; }
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::UInt48::SIZE; }
        );

    // ----- class: openpal::UInt8 -----
    py::class_<openpal::UInt8>(m, "UInt8")

        .def(py::init<>())

        .def_static(
            "Read",
            &openpal::UInt8::Read,
            ":type pStart: unsigned char",
            py::arg("pStart")
        )

        .def_static(
            "ReadBuffer",
            &openpal::UInt8::ReadBuffer,
            py::arg("buffer")
        )

        .def_static(
            "WriteBuffer",
            &openpal::UInt8::WriteBuffer,
            ":type value: unsigned short",
            py::arg("buffer"), py::arg("value")
        )

        .def_static(
            "Write",
            &openpal::UInt8::Write,
            ":type pStart: unsigned char \n"
            ":type value: unsigned char",
            py::arg("pStart"), py::arg("value")
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::UInt8::SIZE; }
        )

        .def_property_readonly_static(
            "Max",
            [](py::object) { return openpal::UInt8::Max; }
        )

        .def_property_readonly_static(
            "Min",
            [](py::object) { return openpal::UInt8::Min; }
        );
}

#endif // PYDNP3_OPENPAL
#endif
