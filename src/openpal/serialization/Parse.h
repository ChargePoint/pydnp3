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

#ifndef PYDNP3_OPENPAL_SERIALIZATION_PARSE_H
#define PYDNP3_OPENPAL_SERIALIZATION_PARSE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/serialization/Parse.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Parse(py::module &m)
{
	// ----- class: openpal::Parse -----
    py::class_<openpal::Parse>(m, "Parse")

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, uint8_t&))
            &openpal::Parse::Read,
            ":type output: unsigned char",
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, uint16_t&))
            &openpal::Parse::Read,
            ":type output: unsigned short",
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, uint32_t&))
            &openpal::Parse::Read,
            ":type output: unsigned int",
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, openpal::UInt48Type&))
            &openpal::Parse::Read,
            ":type output: opendnp3.DNPTime",
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, int16_t&))
            &openpal::Parse::Read,
            ":type output: short",
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, int32_t&))
            &openpal::Parse::Read,
            ":type output: int",
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, double&))
            &openpal::Parse::Read,
            ":type output: double",
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Read",
            (bool (*)(openpal::RSlice &, float&))
            &openpal::Parse::Read,
            py::arg("input"), py::arg("output")
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, int>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, float>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, double>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, int, int>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, int, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, float, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<int, double, opendnp3::DNPTime>
        )

        .def_static(
            "Many",
            &openpal::Parse::Many<opendnp3::DNPTime, int, int>
        );
}

#endif // PYDNP3_OPENPAL
#endif
