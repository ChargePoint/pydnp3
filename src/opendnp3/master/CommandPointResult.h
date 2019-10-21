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

#ifndef PYDNP3_OPENDNP3_MASTER_COMMANDPOINTRESULT_H
#define PYDNP3_OPENDNP3_MASTER_COMMANDPOINTRESULT_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/CommandPointResult.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandPointResult(py::module &m)
{
    py::class_<opendnp3::CommandPointResult>(m, "CommandPointResult",
        "Represents the result of a command operation on a particular point.")

        .def(
            py::init<uint32_t, uint16_t, opendnp3::CommandPointState, opendnp3::CommandStatus>(),
            "   Fully construct based on all members. \n"
            ":type headerIndex: unsigned int \n"
            ":type index: unsigned short",
            py::arg("headerIndex"), py::arg("index"), py::arg("state"), py::arg("status")
        )

        .def(
            "Equals",
            &opendnp3::CommandPointResult::Equals,
            "Check the result for equality against another value.",
            py::arg("other")
        )

        .def_readwrite(
            "headerIndex",
            &opendnp3::CommandPointResult::headerIndex,
            "   The index of the header when request was made (0-based). \n"
            ":type headerIndex: unsigned int"
        )

        .def_readwrite(
            "index",
            &opendnp3::CommandPointResult::index,
            "   The index of the command that was requested. \n"
            ":type index: unsigned short"
        )

        .def_readwrite(
            "state",
            &opendnp3::CommandPointResult::state,
            "The final state of the command operation on this point."
        )

        .def_readwrite(
            "status",
            &opendnp3::CommandPointResult::status,
            "The response value. This is only valid if state == SUCCESS or state == SELECT_FAIL."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
