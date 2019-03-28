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

#ifndef PYDNP3_OPENDNP3_APP_GROUPVARIATIONID_H
#define PYDNP3_OPENDNP3_APP_GROUPVARIATIONID_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/GroupVariationID.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_GroupVariationID(py::module &m)
{
    // ----- class: opendnp3::GroupVariationID -----
    py::class_<opendnp3::GroupVariationID>(m, "GroupVariationID",
        "Simple uint8_t/uint8_t tuple for group and variation.")

        .def(
            py::init<uint8_t, uint8_t>(),
            ":param group: defaults to 0xFF \n"
            ":param variation: defaults to 0xFF \n"
            ":type group: unsigned char \n"
            ":type varitaion: unsigned char",
            py::arg("group") = 0xFF, py::arg("variation") = 0xFF
        )

        .def_readwrite(
            "group",
            &opendnp3::GroupVariationID::group,
            ":type group: unsigned char"
        )

        .def_readwrite(
            "variation",
            &opendnp3::GroupVariationID::variation,
            ":type varitaion: unsigned char"
        );
}

#endif // PYDNP3_OPENDNP3
#endif
