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

#ifndef PYDNP3_ASIOPAL_EXECUTOR_H
#define PYDNP3_ASIOPAL_EXECUTOR_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/StackStatistics.h>
#include <opendnp3/link/LinkStatistics.h>
#include <asiopal/Executor.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace openpal {
    class LogFilters;
}

void bind_Executor(py::module &m)
{
    // ----- class: asiopal::Executor -----
    py::class_<asiopal::Executor, openpal::IExecutor, std::shared_ptr<asiopal::Executor>>(m, "Executor",
        "Implementation of openpal::IExecutor backed by asio::strand. \n"
        "Shutdown life-cycle guarantees are provided by using std::shared_ptr.")

        .def(
            py::init<const std::shared_ptr<asiopal::IO>&>(),
            py::arg("io")
        )

        .def_static(
            "Create",
            &asiopal::Executor::Create,
            ":return: shared_ptr to openpal.Executor",
            py::arg("io")
        )

        .def(
            "GetTime",
            &asiopal::Executor::GetTime
        )

        .def(
            "Start",
            (openpal::ITimer* (asiopal::Executor::*)(const openpal::TimeDuration&, const openpal::action_t&))
            &asiopal::Executor::Start,
            py::arg("duration"), py::arg("runnable")
        )

        .def(
            "Start",
            (openpal::ITimer* (asiopal::Executor::*)(const openpal::MonotonicTimestamp&, const openpal::action_t&))
            &asiopal::Executor::Start,
            py::arg("duration"), py::arg("runnable")
        )

        .def(
            "Post",
            &asiopal::Executor::Post,
            py::arg("runnable")
        )

        .def(
            "ReturnFrom",
            &asiopal::Executor::ReturnFrom<bool>,
            py::arg("action")
        )

        .def(
            "ReturnFrom",
            &asiopal::Executor::ReturnFrom<opendnp3::StackStatistics>,
            py::arg("action")
        )

        .def(
            "ReturnFrom",
            &asiopal::Executor::ReturnFrom<opendnp3::LinkStatistics>,
            py::arg("action")
        )

        .def(
            "ReturnFrom",
            &asiopal::Executor::ReturnFrom<openpal::LogFilters>,
            py::arg("action")
        )

        .def(
            "BlockUntil",
            &asiopal::Executor::BlockUntil,
            py::arg("action")
        )

        .def(
            "BlockUntilAndFlush",
            &asiopal::Executor::BlockUntilAndFlush,
            py::arg("action")
        )

        .def(
            "Fork",
            &asiopal::Executor::Fork,
            "Create a new Executor that shares the underling std::shared_ptr<IO>."
        )

        .def_readonly(
            "strand",
            &asiopal::Executor::strand
        );
}

#endif // PYDNP3_ASIOPAL
#endif
