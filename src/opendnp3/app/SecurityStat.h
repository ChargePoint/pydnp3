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

#ifndef PYDNP3_OPENDNP3_APP_SECURITYSTAT_H
#define PYDNP3_OPENDNP3_APP_SECURITYSTAT_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/SecurityStat.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_SecurityStat(py::module &m)
{
    // ----- struct: opendnp3::SecurityStatValue -----
    py::class_<opendnp3::SecurityStat::Value>(m, "SecurityStatValue")

        .def(
            py::init<uint16_t, uint32_t>(),
            ":param assocId: defaults to 0 \n"
            ":param count: defaults to 0 \n"
            ":type assocId: unsigned short \n"
            ":type count: unsigned int",
            py::arg("assocId") = 0, py::arg("count") = 0
        )

        .def_readwrite(
            "assocId",
            &opendnp3::SecurityStat::Value::assocId,
            ":type assocId: unsigned short"
        )

        .def_readwrite(
            "count",
            &opendnp3::SecurityStat::Value::count,
            ":type count: unsigned int"
        );

    // ----- class: opendnp3::SecurityStat -----
    py::class_<opendnp3::SecurityStat, std::shared_ptr<opendnp3::SecurityStat>>(m, "SecurityStat",
        "SA security statistic object as used by the API.")

        .def(py::init<>())

        .def(
            py::init<opendnp3::SecurityStat::Value, uint8_t, opendnp3::DNPTime>(),
            ":type quality: unsigned char",
            py::arg("value"), py::arg("quality"), py::arg("time")
        )

        .def(
            py::init<uint8_t, uint16_t, uint32_t>(),
            ":type quality: unsigned char \n"
            ":type assocId: unsigned short \n"
            ":type count: unsigned int",
            py::arg("quality"), py::arg("assocId"), py::arg("count")
        )

        .def(
            py::init<uint8_t, uint16_t, uint32_t, opendnp3::DNPTime>(),
            ":type quality: unsigned char \n"
            ":type assocId: unsigned short \n"
            ":type count: unsigned int \n",
            py::arg("quality"), py::arg("assocId"), py::arg("count"), py::arg("time")
        )

        .def_readwrite(
            "quality",
            &opendnp3::SecurityStat::quality,
            ":type quality: unsigned char"
        )

        .def_readwrite(
            "value",
            &opendnp3::SecurityStat::value
        )

        .def_readwrite(
            "time",
            &opendnp3::SecurityStat::time
        );
}

#endif // PYDNP3_OPENDNP3
#endif
