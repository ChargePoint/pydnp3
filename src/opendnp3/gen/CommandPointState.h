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

#ifndef PYDNP3_OPENDNP3_GEN_COMMANDPOINTSTATE_H
#define PYDNP3_OPENDNP3_GEN_COMMANDPOINTSTATE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/CommandPointState.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandPointState(py::module &m)
{
    // ----- enum class: opendnp3::CommandPointState -----
    py::enum_<opendnp3::CommandPointState>(m, "CommandPointState",
        "List the various states that an individual command object can be in after an SBO or direct operate request.")

        .value(
            "INIT",
            opendnp3::CommandPointState::INIT,
            "No corresponding response was ever received for this command point."
        )

		.value(
		    "SELECT_SUCCESS",
		    opendnp3::CommandPointState::SELECT_SUCCESS,
		    "A response to a select request was received and matched, but the operate did not complete."
		)

		.value(
		    "SELECT_MISMATCH",
		    opendnp3::CommandPointState::SELECT_MISMATCH,
		    "A response to a select operation did not contain the same value that was sent."
		)

		.value(
		    "SELECT_FAIL",
		    opendnp3::CommandPointState::SELECT_FAIL,
		    "A response to a select operation contained a command status other than success."
		)

		.value(
		    "OPERATE_FAIL",
		    opendnp3::CommandPointState::OPERATE_FAIL,
		    "A response to an operate or direct operate did not match the request."
		)

		.value(
		    "SUCCESS",
		    opendnp3::CommandPointState::SUCCESS,
		    "A matching response was received to the operate."
		);

	// ----- func: opendnp3::CommandPointStateToString -----
	m.def(
	    "CommandPointStateToString",
	    &opendnp3::CommandPointStateToString,
	    py::arg("state")
	);
}

#endif // PYDNP3_OPENDNP3
#endif
