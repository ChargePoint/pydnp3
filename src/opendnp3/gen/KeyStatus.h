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

#ifndef PYDNP3_OPENDNP3_GEN_KEYSTATUS_H
#define PYDNP3_OPENDNP3_GEN_KEYSTATUS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/KeyStatus.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_KeyStatus(py::module &m)
{
    // ----- enum class: opendnp3::KeyStatus -----
    py::enum_<opendnp3::KeyStatus>(m, "KeyStatus",
        "Describes the status of the two session keys as known by the outstation.")

        .value(
            "OK",
            opendnp3::KeyStatus::OK,
            "Session keys are valid."
        )

		.value(
		    "NOT_INIT",
		    opendnp3::KeyStatus::NOT_INIT,
		    "Sessions keys are not valid due to no init or interval expiration."
		)

		.value(
		    "COMM_FAIL",
		    opendnp3::KeyStatus::COMM_FAIL,
		    "Session keys are not valid due to communications failure."
		)

		.value(
		    "AUTH_FAIL",
		    opendnp3::KeyStatus::AUTH_FAIL,
		    "Session keys are not valid due to an authentication failure"
		)

		.value(
		    "UNDEFINED",
		    opendnp3::KeyStatus::UNDEFINED
		);

    // ----- function: opendnp3::KeyStatusToType -----
    m.def(
        "KeyStatusToType",
        &opendnp3::KeyStatusToType,
        py::arg("status")
    );

    // ----- function: opendnp3::KeyStatusFromType -----
    m.def(
        "KeyStatusFromType",
        &opendnp3::KeyStatusFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );

    // ----- function: opendnp3::KeyStatusToString -----
    m.def(
        "KeyStatusToString",
        &opendnp3::KeyStatusToString,
        py::arg("status")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
