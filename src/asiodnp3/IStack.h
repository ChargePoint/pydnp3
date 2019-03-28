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

#ifndef PYDNP3_ASIODNP3_ISTACK_H
#define PYDNP3_ASIODNP3_ISTACK_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/IStack.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class IStack.
*/
    class PyIStack : public IStack
    {
    public:
        /* Inherit the constructors */
        using IStack::IStack;

        /* Trampoline for IStack virtual functions */
        bool Enable() override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IStack,
                Enable,
            );
        }
        bool Disable() override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IStack,
                Disable,
            );
        }
        opendnp3::StackStatistics GetStackStatistics() override {
            PYBIND11_OVERLOAD_PURE(
                opendnp3::StackStatistics,
                IStack,
                GetStackStatistics,
            );
        }

        /* Trampoline for IResource virtual functions */
        void Shutdown() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IStack,
                Shutdown,
            );
        }
    };
}

void bind_IStack(py::module &m)
{
    // ----- class: asiodnp3::IStack -----
    py::class_<asiodnp3::IStack, asiodnp3::PyIStack, asiopal::IResource, std::shared_ptr<asiodnp3::IStack>>(m, "IStack",
        "Base class for masters or outstations.")

        .def(py::init<>())

        // the GIL is held when calling Log (py::gil_scoped_acquire by default)
        .def(
            "Enable",
            &asiodnp3::IStack::Enable,
            py::call_guard<py::gil_scoped_release>(),
            "Synchronously enable communications."
        )

        // the GIL is held when calling Log (py::gil_scoped_acquire by default)
        .def(
            "Disable",
            &asiodnp3::IStack::Disable,
            py::call_guard<py::gil_scoped_release>(),
            "Synchronously disable communications."
        )

        .def(
            "GetStackStatistics",
            &asiodnp3::IStack::GetStackStatistics,
            ":return: stack statistics counters."
        );
}

#endif // PYDNP3_ASIODNP3
#endif
