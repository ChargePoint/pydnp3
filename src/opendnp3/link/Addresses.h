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

#include <opendnp3/link/Addresses.h>

namespace py = pybind11;
using namespace std;

void bind_Addresses(py::module &m)
{
    // ----- class: opendnp3::Addresses -----
    py::class_<opendnp3::Addresses>(m, "Addresses")

        .def(py::init<>())

        .def(
            py::init<uint16_t, uint16_t>(),
            py::arg("source"), py::arg("destination"),
            ":type source: unsigned short \n"
            ":type destination: unsigned short"
        )

        .def(
            "Reverse",
            &opendnp3::Addresses::Reverse
        )

        .def(
            "__eq__",
            &opendnp3::Addresses::operator==
        )

        .def(
            "__ne__",
            &opendnp3::Addresses::operator!=
        )

        .def_readwrite(
            "source",
            &opendnp3::Addresses::source
        )

        .def_readwrite(
            "destination",
            &opendnp3::Addresses::destination
        );
}
