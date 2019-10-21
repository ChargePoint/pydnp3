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

#ifndef PYDNP3_OPENDNP3_LINK_LINKHEADERFIELDS_H
#define PYDNP3_OPENDNP3_LINK_LINKHEADERFIELDS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/link/LinkHeaderFields.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_LinkHeaderFields(py::module &m)
{
    // ----- struct: opendnp3::LinkHeaderFields -----
    py::class_<opendnp3::LinkHeaderFields>(m, "LinkHeaderFields")

        .def(py::init<>())

        .def(
            py::init<opendnp3::LinkFunction, bool, bool, bool, uint16_t, uint16_t>(),
            ":type dest: unsigned short \n"
            ":type src: unsigned short",
            py::arg("func"), py::arg("isFromMaster"), py::arg("fcb"), py::arg("fcvdfc"), py::arg("dest"), py::arg("src")
        )

        .def_readwrite(
            "func",
            &opendnp3::LinkHeaderFields::func
        )

        .def_readwrite(
            "isFromMaster",
            &opendnp3::LinkHeaderFields::isFromMaster
        )

        .def_readwrite(
            "fcb",
            &opendnp3::LinkHeaderFields::fcb
        )

        .def_readwrite(
            "fcvdfc",
            &opendnp3::LinkHeaderFields::fcvdfc
        )

        .def_readwrite(
            "dest",
            &opendnp3::LinkHeaderFields::dest,
            ":type dest: unsigned short"
        )

        .def_readwrite(
            "src",
            &opendnp3::LinkHeaderFields::src,
            ":type src: unsigned short"
        );
}

#endif // PYDNP3_OPENDNP3
#endif
