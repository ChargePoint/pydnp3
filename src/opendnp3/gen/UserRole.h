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

#ifndef PYDNP3_OPENDNP3_GEN_USERROLE_H
#define PYDNP3_OPENDNP3_GEN_USERROLE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/UserRole.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_UserRole(py::module &m)
{
    // ----- enum class: opendnp3::UserRole -----
    py::enum_<opendnp3::UserRole>(m, "UserRole",
        "Enumerates pre-defined rules in secure authentication.")

        .value("VIEWER", opendnp3::UserRole::VIEWER)
		.value("OPERATOR", opendnp3::UserRole::OPERATOR)
		.value("ENGINEER", opendnp3::UserRole::ENGINEER)
		.value("INSTALLER", opendnp3::UserRole::INSTALLER)
		.value("SECADM", opendnp3::UserRole::SECADM)
		.value("SECAUD", opendnp3::UserRole::SECAUD)
		.value("RBACMNT", opendnp3::UserRole::RBACMNT)
		.value("SINGLE_USER", opendnp3::UserRole::SINGLE_USER)
		.value("UNDEFINED", opendnp3::UserRole::UNDEFINED);

    // ----- func: opendnp3::UserRoleToType -----
    m.def(
        "UserRoleToType",
        &opendnp3::UserRoleToType,
        py::arg("userRole")
    );

    // ----- func: opendnp3::UserRoleFromType -----
    m.def(
        "UserRoleFromType",
        &opendnp3::UserRoleFromType,
        ":type rawType: unsigned short",
        py::arg("rawType")
    );

    // ----- func: opendnp3::UserRoleToString -----
    m.def(
        "UserRoleToString",
        &opendnp3::UserRoleToString,
        py::arg("userRole")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
