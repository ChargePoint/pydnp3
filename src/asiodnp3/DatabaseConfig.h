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

#ifndef PYDNP3_ASIODNP3_DATABASECONFIG_H
#define PYDNP3_ASIODNP3_DATABASECONFIG_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/DatabaseConfig.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_DatabaseConfig(py::module &m)
{
	// ----- class: asiodnp3::DatabaseConfig -----
    py::class_<asiodnp3::DatabaseConfig, std::shared_ptr<asiodnp3::DatabaseConfig>>(m, "DatabaseConfig")

        .def(
            py::init<const opendnp3::DatabaseSizes &>(),
            py::arg("sizes")
        )

        .def_readonly(
            "sizes",
            &asiodnp3::DatabaseConfig::sizes
        )

        .def_property_readonly(
            "binary",
            [](const asiodnp3::DatabaseConfig &self) { return &self.binary;},
            py::return_value_policy::reference
        )

        .def_property_readonly(
            "doubleBinary",
            [](const asiodnp3::DatabaseConfig &self) { return &self.doubleBinary;},
            py::return_value_policy::reference
        )

        .def_property_readonly(
            "analog",
            [](const asiodnp3::DatabaseConfig &self) { return &self.analog;},
            py::return_value_policy::reference
        )

        .def_property_readonly(
            "counter",
            [](const asiodnp3::DatabaseConfig &self) { return &self.counter;},
            py::return_value_policy::reference
        )

        .def_property_readonly(
            "frozenCounter",
            [](const asiodnp3::DatabaseConfig &self) { return &self.frozenCounter;},
            py::return_value_policy::reference
        )

        .def_property_readonly(
            "boStatus",
            [](const asiodnp3::DatabaseConfig &self) { return &self.boStatus;},
            py::return_value_policy::reference
        )

        .def_property_readonly(
            "aoStatus",
            [](const asiodnp3::DatabaseConfig &self) { return &self.aoStatus;},
            py::return_value_policy::reference
        )

        .def_property_readonly(
            "timeAndInterval",
            [](const asiodnp3::DatabaseConfig &self) { return &self.timeAndInterval;},
            py::return_value_policy::reference
        );
}

#endif // PYDNP3_ASIODNP3
#endif
