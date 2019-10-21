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

#ifndef PYDNP3_OPENDNP3_MASTER_TASKINFO_H
#define PYDNP3_OPENDNP3_MASTER_TASKINFO_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/TaskInfo.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

void bind_TaskInfo(py::module &m)
{
	// ----- class: opendnp3::TaskInfo -----
    py::class_<opendnp3::TaskInfo, std::shared_ptr<opendnp3::TaskInfo>>(m, "TaskInfo",
        "Struct that provides information about a completed or failed task.")

        .def(
            py::init<opendnp3::MasterTaskType, opendnp3::TaskCompletion, opendnp3::TaskId>(),
            py::arg("type"), py::arg("result"), py::arg("id")
        )

        .def_readwrite(
            "type",
            &opendnp3::TaskInfo::type
        )

		.def_readwrite(
		    "result",
		    &opendnp3::TaskInfo::result
		)

		.def_readwrite(
		    "id",
		    &opendnp3::TaskInfo::id
		);
}

#endif // PYDNP3_OPENDNP3
#endif
