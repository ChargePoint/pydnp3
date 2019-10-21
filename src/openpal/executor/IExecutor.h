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

#ifndef PYDNP3_OPENPAL_EXECUTOR_IEXECUTOR_H
#define PYDNP3_OPENPAL_EXECUTOR_IEXECUTOR_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/executor/IExecutor.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;
using namespace std;

namespace openpal
{
/**
* Overriding virtual functions from interface class IExecutor.
*/
    class PyIExecutor : public IExecutor
    {
    public:
        /* Inherit the constructors */
        using IExecutor::IExecutor;

        /* Trampoline for IExecutor virtual functions */
        ITimer* Start(const TimeDuration& duration, const action_t& action) override {
            PYBIND11_OVERLOAD_PURE(
                ITimer*,
                IExecutor,
                Start,
                duration, action
            );
        }
        ITimer* Start(const MonotonicTimestamp& expiration, const action_t& action) override {
            PYBIND11_OVERLOAD_PURE(
                ITimer*,
                IExecutor,
                Start,
                expiration, action
            );
        }
        void Post(const action_t& action) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IExecutor,
                Post,
                action
            );
        }

        /* Trampoline for IMonotonicTimeSource virtual functions */
        MonotonicTimestamp GetTime() override {
            PYBIND11_OVERLOAD_PURE(
                MonotonicTimestamp,
                IExecutor,
                GetTime,
            );
        }
    };
}

void bind_IExecutor(py::module &m) {
    // ----- class: openpal::IExecutor -----
    py::class_<openpal::IExecutor,
               openpal::PyIExecutor,
               openpal::IMonotonicTimeSource,
               std::shared_ptr<openpal::IExecutor>>(m, "IExecutor",
        "Interface for posting events to a queue. \n"
        "Events can be posted for immediate consumption or some time in the future. \n"
        "Events are processed in the order they are received.")

        .def(py::init<>())

        .def(
            "Start",
            (openpal::ITimer* (openpal::IExecutor::*)(const openpal::TimeDuration&, const openpal::action_t&))
            &openpal::IExecutor::Start,
            ":return: a new timer based on a relative time duration",
            py::arg("duration"), py::arg("action"),
            py::return_value_policy::reference
        )

        .def(
            "Start",
            (openpal::ITimer* (openpal::IExecutor::*)(const openpal::MonotonicTimestamp&, const openpal::action_t&))
            &openpal::IExecutor::Start,
            ":return: a new timer based on an absolute timestamp of the monotonic clock",
            py::arg("expiration"), py::arg("action"),
            py::return_value_policy::reference
        )

        .def(
            "Post",
            &openpal::IExecutor::Post,
            ":return: thread-safe way to post an event to be handled asynchronously",
            py::arg("action")
        );
}

#endif // PYDNP3_OPENPAL
#endif
