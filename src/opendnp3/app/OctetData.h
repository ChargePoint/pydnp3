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

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/OctetData.h>

namespace py = pybind11;
using namespace std;

void bind_OctetData(py::module &m)
{
    // ----- class: opendnp3::OctetData -----
    py::class_<opendnp3::OctetData, std::shared_ptr<opendnp3::OctetData>>(m, "OctetData",
        "A base-class for bitstrings containing up to 255 bytes")

        .def(
            py::init<>(),
            "Construct with a default value of [0x00] (length == 1)."
        )

        .def(
            py::init<const char *>(),
            "Construct from a c-style string, strlen() is used internally to determine the length. \n"
            "If the length is 0, the default value of [0x00] is assigned \n"
            "If the length is > 255, only the first 255 bytes are copied. \n"
            "The null terminator is NOT copied as part of buffer.",
            py::arg("input")
        )

        .def(
            py::init<const openpal::RSlice&>(),
            "Construct from read-only buffer slice. \n"
            "If the length is 0, the default value of [0x00] is assigned \n"
            "If the length is > 255, only the first 255 bytes are copied. \n"
            "The null terminator is NOT copied as part of buffer.",
            py::arg("input")
        )

        .def(
            "Size",
            &opendnp3::OctetData::Size
        )

        .def(
            "Set",
            (bool (opendnp3::OctetData::*)(const openpal::RSlice&))
            &opendnp3::OctetData::Set,
            "Set the octet data to the input buffer. \n"
            "If the length is 0, the default value of [0x00] is assigned \n"
            "If the length is > 255, only the first 255 bytes are copied. \n"
            "Return true if the input meets the length requirements, false otherwise. \n"
            ":param input: input the input data to copy into this object",
            py::arg("input")
        )

        .def(
            "Set",
            (bool (opendnp3::OctetData::*)(const char *))
            &opendnp3::OctetData::Set,
            "Set the buffer equal to the supplied c-string. \n"
            "If the length is 0, the default value of [0x00] is assigned \n"
            "If the length is > 255, only the first 255 bytes are copied. \n"
            "Return true if the input meets the length requirements, false otherwise. \n"
            ":param input: c-style string to copy into this object",
            py::arg("input")
        )

        .def(
            "ToRSlice",
            &opendnp3::OctetData::ToRSlice,
            "Return a view of the current data as a read-only slice."
        )

        .def_property_readonly_static(
            "MAX_SIZE",
            [](py::object) { return opendnp3::OctetData::MAX_SIZE; }
        );
}
