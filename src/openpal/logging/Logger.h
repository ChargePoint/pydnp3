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

#ifndef PYDNP3_OPENPAL_LOGGING_LOGGER_H
#define PYDNP3_OPENPAL_LOGGING_LOGGER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/logging/Logger.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Logger(py::module &m)
{
	// ----- struct: openpal::Logger::Settings -----
	py::class_<openpal::Logger::Settings, std::shared_ptr<openpal::Logger::Settings>>(m, "LoggerSettings")

	    .def(
	        py::init<const std::string&, openpal::LogFilters>(),
	        py::arg("id"), py::arg("levels")
	    )

	    .def_readwrite(
	        "id",
	        &openpal::Logger::Settings::id
	    )

	    .def_readwrite(
	        "levels",
	        &openpal::Logger::Settings::levels
	    );

	// ----- class: openpal::Logger -----
    py::class_<openpal::Logger, std::shared_ptr<openpal::Logger>>(m, "Logger",
        "A copyable facade over a LogRoot class")

        .def(
            py::init(&openpal::Logger::Empty),
            "Empty constructor: Logger(nullptr, "", 0)"
        )

        .def(
            py::init<const std::shared_ptr<openpal::ILogHandler>&, const std::string&, openpal::LogFilters>(),
            py::arg("backend"), py::arg("id"), py::arg("levels")
        )

        .def_static(
            "Empty",
            &openpal::Logger::Empty
        )

        .def(
            "Log",
            &openpal::Logger::Log,
            py::arg("filters"), py::arg("location"), py::arg("message"),
            py::return_value_policy::reference
        )

        .def(
            "Detach",
            (openpal::Logger (openpal::Logger::*)(const std::string&) const)
            &openpal::Logger::Detach,
            py::arg("id")
        )

        .def(
            "Detach",
            (openpal::Logger (openpal::Logger::*)(const std::string&, openpal::LogFilters) const)
            &openpal::Logger::Detach,
            py::arg("id"), py::arg("levels")
        )

        .def(
            "Detach",
            (openpal::Logger (openpal::Logger::*)(openpal::LogFilters) const)
            &openpal::Logger::Detach,
            py::arg("levels")
        )

        .def(
            "IsEnabled",
            &openpal::Logger::IsEnabled,
            py::arg("filters")
        )

        .def(
            "GetFilters",
            &openpal::Logger::GetFilters
        )

        .def(
            "SetFilters",
            &openpal::Logger::SetFilters,
            py::arg("filters")
        )

        .def(
            "Rename",
            &openpal::Logger::Rename,
            py::arg("id")
        );
}

#endif // PYDNP3_OPENPAL
#endif
