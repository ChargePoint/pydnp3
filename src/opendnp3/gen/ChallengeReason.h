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

#ifndef PYDNP3_OPENDNP3_GEN_CHALLENGEREASON_H
#define PYDNP3_OPENDNP3_GEN_CHALLENGEREASON_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/ChallengeReason.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_ChallengeReason(py::module &m)
{
    // ----- enum class: opendnp3::ChallengeReason -----
    py::enum_<opendnp3::ChallengeReason>(m, "ChallengeReason",
        "Enumerates reasons for a sec-auth challenge")

        .value(
            "CRITICAL",
            opendnp3::ChallengeReason::CRITICAL,
            "Challenging a critical function."
        )

		.value(
		    "UNKNOWN",
		    opendnp3::ChallengeReason::UNKNOWN,
		    "Unknown reason"
		);

	// ----- func: opendnp3::ChallengeReasonToType -----
	m.def(
	    "ChallengeReasonToType",
	    &opendnp3::ChallengeReasonToType,
	    py::arg("reason")
	);

	// ----- func: opendnp3::ChallengeReasonFromType -----
	m.def(
	    "ChallengeReasonFromType",
	    &opendnp3::ChallengeReasonFromType,
	    ":type rawType: unsigned char",
	    py::arg("rawType")
	);

	// ----- func: opendnp3::ChallengeReasonToString -----
	m.def(
	    "ChallengeReasonToString",
	    &opendnp3::ChallengeReasonToString,
	    py::arg("reason")
	);
}

#endif // PYDNP3_OPENDNP3
#endif
