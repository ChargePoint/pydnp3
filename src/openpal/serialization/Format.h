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

#ifndef PYDNP3_OPENPAL_SERIALIZATION_FORMAT_H
#define PYDNP3_OPENPAL_SERIALIZATION_FORMAT_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/serialization/Format.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Format(py::module &m)
{
	// ----- class: openpal::Format -----
    py::class_<openpal::Format>(m, "Format")

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const uint8_t&))
            &openpal::Format::Write,
            ":type value: unsigned char",
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const uint16_t&))
            &openpal::Format::Write,
            ":type value: unsigned short",
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const uint32_t&))
            &openpal::Format::Write,
            ":type value: unsigned int",
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const openpal::UInt48Type&))
            &openpal::Format::Write,
            ":type value: opendnp3.DNPTime",
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const int16_t&))
            &openpal::Format::Write,
            ":type value: short",
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const int32_t&))
            &openpal::Format::Write,
            ":type value: int",
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const double&))
            &openpal::Format::Write,
            ":type value: double",
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Write",
            (bool (*)(openpal::WSlice&, const float&))
            &openpal::Format::Write,
            py::arg("dest"), py::arg("value")
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, int>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, float>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, double>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, int, int>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, int, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, float, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, double, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Format::Many<int, int, int, opendnp3::DNPTime>
        );
}

#endif // PYDNP3_OPENPAL
#endif
