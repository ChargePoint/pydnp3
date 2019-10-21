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

#ifndef PYDNP3_ASIODNP3_DEFAULTMASTERAPPLICATION_H
#define PYDNP3_ASIODNP3_DEFAULTMASTERAPPLICATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/DefaultMasterApplication.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_DefaultMasterApplication(py::module &m)
{
	// ----- class: asiodnp3::DefaultMasterApplication -----
    py::class_<asiodnp3::DefaultMasterApplication,
               opendnp3::IMasterApplication,
               std::shared_ptr<asiodnp3::DefaultMasterApplication>>(m, "DefaultMasterApplication")

        .def(py::init<>())

        .def_static(
            "Create",
            &asiodnp3::DefaultMasterApplication::Create,
            ":return: shared_ptr to opendnp3.IMasterApplication"
        )

        .def(
            "OnReceiveIIN",
            &asiodnp3::DefaultMasterApplication::OnReceiveIIN,
            "Called when a response or unsolicited response is receive from the outstation.",
            py::arg("iin")
        )

        .def(
            "OnTaskStart",
            &asiodnp3::DefaultMasterApplication::OnTaskStart,
            "Task start notification.",
            py::arg("type"), py::arg("id")
        )

        .def(
            "OnTaskComplete",
            &asiodnp3::DefaultMasterApplication::OnTaskComplete,
            "Task completion notification.",
            py::arg("info")
        )

        .def(
            "AssignClassDuringStartup",
            &asiodnp3::DefaultMasterApplication::AssignClassDuringStartup
        )

        .def(
            "ConfigureAssignClassRequest",
            &asiodnp3::DefaultMasterApplication::ConfigureAssignClassRequest,
            "Configure the request headers for assign class. \n"
            "Only called if AssignClassDuringStartup returns true. \n"
            "The user only needs to call the function for each header type to be written.",
            py::arg("fun")
        )

        .def(
            "Now",
            &asiodnp3::DefaultMasterApplication::Now,
            ":return: a UTCTimestamp of the current time"
        )

        .def(
            "OnStateChange",
            &asiodnp3::DefaultMasterApplication::OnStateChange,
            "Called when a the reset/unreset status of the link layer changes.",
            py::arg("value")
        );
}

#endif // PYDNP3_ASIODNP3
#endif
