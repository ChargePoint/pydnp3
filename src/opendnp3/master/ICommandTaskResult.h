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

#ifndef PYDNP3_OPENDNP3_MASTER_ICOMMANDTASKRESULT_H
#define PYDNP3_OPENDNP3_MASTER_ICOMMANDTASKRESULT_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/ICommandTaskResult.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3
{
/**
* Overriding virtual functions from interface class ICommandTaskResult.
*/
    class PyICommandTaskResult : public ICommandTaskResult {
    public:
        /* Inherit the constructors */
        using ICommandTaskResult::ICommandTaskResult;

        /* Trampoline for ICollection virtual functions */
        size_t Count() const override {
            PYBIND11_OVERLOAD_PURE(
                size_t,
                ICommandTaskResult,
                Count,
            );
        }
        void Foreach(IVisitor<opendnp3::CommandPointResult>& visitor) const override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ICommandTaskResult,
                Foreach,
                visitor
            );
        }
    };
}

void bind_ICommandTaskResult(py::module &m)
{
    // ----- class: opendnp3::ICommandTaskResult -----
    py::class_<opendnp3::ICommandTaskResult,
               opendnp3::PyICommandTaskResult,
               opendnp3::ICollection<opendnp3::CommandPointResult>>(m, "ICommandTaskResult",
        "Abstract result type returned via callback to a command operation. \n"
        "Provides the TaskCompleton summary value and access to a collection of flatten results. \n"
        "A result value is provided for every object in every header specified in the CommandSet used "
        "to start the operation.")

        .def(
            py::init<opendnp3::TaskCompletion>(),
            py::arg("summary")
        )

        .def_readwrite(
            "summary",
            &opendnp3::ICommandTaskResult::summary,
            "A summary result for the entire task."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
