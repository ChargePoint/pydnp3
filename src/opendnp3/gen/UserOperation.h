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

#ifndef PYDNP3_OPENDNP3_GEN_USEROPERATION_H
#define PYDNP3_OPENDNP3_GEN_USEROPERATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/UserOperation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_UserOperation(py::module &m)
{
    // ----- enum class: opendnp3::UserOperation -----
    py::enum_<opendnp3::UserOperation>(m, "UserOperation",
        "Enumerates possible remote operations on users.")

        .value("OP_ADD", opendnp3::UserOperation::OP_ADD)
        .value("OP_DELETE", opendnp3::UserOperation::OP_DELETE)
        .value("OP_CHANGE", opendnp3::UserOperation::OP_CHANGE)
        .value("OP_UNDEFINED", opendnp3::UserOperation::OP_UNDEFINED);

    // ----- func: opendnp3::UserOperationToType -----
    m.def(
        "UserOperationToType",
        &opendnp3::UserOperationToType,
        py::arg("userOperation")
    );

    // ----- func: opendnp3::UserOperationFromType -----
    m.def(
        "UserOperationFromType",
        &opendnp3::UserOperationFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );

    // ----- func: opendnp3::UserOperationToString -----
    m.def(
        "UserOperationToString",
        &opendnp3::UserOperationToString,
        py::arg("userOperation")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
