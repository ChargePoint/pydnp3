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

#ifndef PYDNP3_OPENDNP3_GEN_LINKFUNCTION_H
#define PYDNP3_OPENDNP3_GEN_LINKFUNCTION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/LinkFunction.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_LinkFunction(py::module &m) {
    // ----- enum class: opendnp3::LinkFunction -----
    py::enum_<opendnp3::LinkFunction>(m, "LinkFunction",
        "Link layer function code enumeration.")

        .value("PRI_RESET_LINK_STATES", opendnp3::LinkFunction::PRI_RESET_LINK_STATES)
		.value("PRI_TEST_LINK_STATES", opendnp3::LinkFunction::PRI_TEST_LINK_STATES)
		.value("PRI_CONFIRMED_USER_DATA", opendnp3::LinkFunction::PRI_CONFIRMED_USER_DATA)
		.value("PRI_UNCONFIRMED_USER_DATA", opendnp3::LinkFunction::PRI_UNCONFIRMED_USER_DATA)
		.value("PRI_REQUEST_LINK_STATUS", opendnp3::LinkFunction::PRI_REQUEST_LINK_STATUS)
		.value("SEC_ACK", opendnp3::LinkFunction::SEC_ACK)
		.value("SEC_NACK", opendnp3::LinkFunction::SEC_NACK)
		.value("SEC_LINK_STATUS", opendnp3::LinkFunction::SEC_LINK_STATUS)
		.value("SEC_NOT_SUPPORTED", opendnp3::LinkFunction::SEC_NOT_SUPPORTED)
		.value("INVALID", opendnp3::LinkFunction::INVALID);

    // ----- function: opendnp3::LinkFunctionToType -----
    m.def(
        "LinkFunctionToType",
        &opendnp3::LinkFunctionToType,
        py::arg("linkFunction")
    );

    // ----- function: opendnp3::LinkFunctionFromType -----
    m.def(
        "LinkFunctionFromType",
        &opendnp3::LinkFunctionFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );

    // ----- function: opendnp3::LinkFunctionToString -----
    m.def(
        "LinkFunctionToString",
        &opendnp3::LinkFunctionToString,
        py::arg("linkFunction")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
