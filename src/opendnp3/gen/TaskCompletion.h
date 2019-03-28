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

#ifndef PYDNP3_OPENDNP3_GEN_TASKCOMPLETION_H
#define PYDNP3_OPENDNP3_GEN_TASKCOMPLETION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/TaskCompletion.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_TaskCompletion(py::module &m)
{
    // ----- enum class: opendnp3::TaskCompletion -----
    py::enum_<opendnp3::TaskCompletion>(m, "TaskCompletion",
        "Enum that describes if a master task succeeded or failed.")

        .value(
            "SUCCESS",
            opendnp3::TaskCompletion::SUCCESS,
            "A valid response was received from the outstation."
        )

        .value(
            "FAILURE_BAD_RESPONSE",
            opendnp3::TaskCompletion::FAILURE_BAD_RESPONSE,
            "A response was received from the outstation, but it was not valid."
        )

        .value(
            "FAILURE_RESPONSE_TIMEOUT",
            opendnp3::TaskCompletion::FAILURE_RESPONSE_TIMEOUT,
            "The task request did not receive a response within the timeout."
        )

        .value(
            "FAILURE_START_TIMEOUT",
            opendnp3::TaskCompletion::FAILURE_START_TIMEOUT,
            "The start timeout expired before the task could begin running."
        )

        .value(
            "FAILURE_MESSAGE_FORMAT_ERROR",
            opendnp3::TaskCompletion::FAILURE_MESSAGE_FORMAT_ERROR,
            "The task failed because the master was unable to format the request."
        )

        .value(
            "FAILURE_NO_COMMS",
            opendnp3::TaskCompletion::FAILURE_NO_COMMS,
            "There is no communication with the outstation, so the task was not attempted."
        );

    // ----- function: opendnp3::TaskCompletionToString -----
    m.def(
        "TaskCompletionToString",
        &opendnp3::TaskCompletionToString
    );
}

#endif // PYDNP3_OPENDNP3
#endif
