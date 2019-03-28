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

#ifndef PYDNP3_OPENDNP3_MASTER_ITASKCALLBACK_H
#define PYDNP3_OPENDNP3_MASTER_ITASKCALLBACK_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/ITaskCallback.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

namespace opendnp3
{
/**
* Overriding virtual functions from interface class ITaskCallback.
*/
    class PyITaskCallback : public ITaskCallback
    {
        /* Inherit the constructors */
        using ITaskCallback::ITaskCallback;

        /* Trampoline for ITaskCallback virtual functions */
        void OnStart() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ITaskCallback,
                OnStart,
            )
        }
        void OnComplete(TaskCompletion result) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ITaskCallback,
                OnComplete,
                result
            )
        }
        virtual void OnDestroyed() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ITaskCallback,
                OnDestroyed,
            )
        }
    };
}

void bind_ITaskCallback(py::module &m)
{
	// ----- class: opendnp3::ITaskCallback -----
    py::class_<opendnp3::ITaskCallback, opendnp3::PyITaskCallback>(m, "ITaskCallback",
        "Callbacks for when a task starts and completes.")

        .def(py::init<>())

        .def(
            "OnStart",
            &opendnp3::ITaskCallback::OnStart,
            "Called when the task starts running."
        )

        .def(
            "OnComplete",
            &opendnp3::ITaskCallback::OnComplete,
            "Called when the task succeeds or fails.",
            py::arg("result")
        )

        .def(
            "OnDestroyed",
            &opendnp3::ITaskCallback::OnDestroyed,
            "Called when the task no longer exists and no more calls will be made to OnStart/OnComplete."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
