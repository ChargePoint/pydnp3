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

#ifndef PYDNP3_ASIODNP3_ERRORCODES_H
#define PYDNP3_ASIODNP3_ERRORCODES_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/ErrorCodes.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;
using namespace std;

void bind_ErrorCodes(py::module &m)
{
    // ----- enum class: asiodnp3::Error -----
    py::enum_<asiodnp3::Error>(m, "Error")
        .value("SHUTTING_DOWN", asiodnp3::Error::SHUTTING_DOWN)
        .value("NO_TLS_SUPPORT", asiodnp3::Error::NO_TLS_SUPPORT)
        .value("NO_SERIAL_SUPPORT", asiodnp3::Error::NO_SERIAL_SUPPORT);

    // ----- class: asiodnp3::ErrorCategory -----
    py::class_<asiodnp3::ErrorCategory>(m, "ErrorCategory")

        .def_static(
            "Instance",
            &asiodnp3::ErrorCategory::Instance
        )

        .def(
            "name",
            &asiodnp3::ErrorCategory::name
        )

        .def(
            "message",
            &asiodnp3::ErrorCategory::message,
            py::arg("ev")
        );

    // ----- func: asiodnp3::make_error_code -----
    m.def(
        "make_error_code",
        &asiodnp3::make_error_code,
        py::arg("err")
    );

    // ----- class: asiodnp3::is_error_code_enum -----
    py::class_<std::is_error_code_enum<asiodnp3::Error>>(m, "is_error_code_enum");
}

#endif // PYDNP3_ASIODNP3
#endif
