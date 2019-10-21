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

#ifndef PYDNP3_ASIODNP3_IOUTSTATION_H
#define PYDNP3_ASIODNP3_IOUTSTATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/IOutstation.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class IOutstation.
*/
    class PyIOutstation : public IOutstation
    {
    public:
        /* Inherit the constructors */
        using IOutstation::IOutstation;

        /* Trampoline for IOutstation virtual functions */
        void SetLogFilters(const openpal::LogFilters& filters) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IOutstation,
                SetLogFilters,
                filters
            );
        }
        void SetRestartIIN() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IOutstation,
                SetRestartIIN,
            );
        }
        void Apply(const Updates& updates) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IOutstation,
                Apply,
                updates
            );
        }

        /* Trampoline for IStack virtual functions */
        bool Enable() override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IOutstation,
                Enable,
            );
        }
        bool Disable() override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IOutstation,
                Disable,
            );
        }
        opendnp3::StackStatistics GetStackStatistics() override {
            PYBIND11_OVERLOAD_PURE(
                opendnp3::StackStatistics,
                IOutstation,
                GetStackStatistics,
            );
        }

        /* Trampoline for IResource virtual functions */
        void Shutdown() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IOutstation,
                Shutdown,
            );
        }
    };
}

void bind_IOutstation(py::module &m)
{
    // ----- class: asiodnp3::IOutstation -----
    py::class_<asiodnp3::IOutstation,
               asiodnp3::PyIOutstation,
               asiodnp3::IStack,
               std::shared_ptr<asiodnp3::IOutstation>>(m, "IOutstation",
        "Interface representing a running outstation.")

        .def(py::init<>())

        .def(
            "SetLogFilters",
            &asiodnp3::IOutstation::SetLogFilters,
            ":param filters: Adjust the filters to this value",
            py::arg("filters")
        )

        .def(
            "SetRestartIIN",
            &asiodnp3::IOutstation::SetRestartIIN,
            "Sets the restart IIN bit. \n"
            "Normally applications should not touch this bit, but it is provided for simulating restarts."
        )

        .def(
            "Apply",
            &asiodnp3::IOutstation::Apply,
            "Apply a set of measurement updates to the outstation.",
            py::arg("updates")
        );
}

#endif // PYDNP3_ASIODNP3
#endif
