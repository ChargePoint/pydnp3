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

#ifndef PYDNP3_ASIOPAL_IOPENDELAYSTRATEGY_H
#define PYDNP3_ASIOPAL_IOPENDELAYSTRATEGY_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiopal/IOpenDelayStrategy.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal
{
/**
* Overriding virtual functions from interface class IOpenDelayStrategy.
*/
    class PyIOpenDelayStrategy : public IOpenDelayStrategy
    {
        /* Inherit the constructors */
        using IOpenDelayStrategy::IOpenDelayStrategy;

        /* Trampoline for IOpenDelayStrategy virtual functions */
        openpal::TimeDuration GetNextDelay(const openpal::TimeDuration& current, const openpal::TimeDuration& max) const override {
            PYBIND11_OVERLOAD_PURE(
                openpal::TimeDuration,
                IOpenDelayStrategy,
                GetNextDelay,
                current, max
            );
        }
    };
}

void bind_IOpenDelayStrategy(py::module &m)
{
    // ----- class: asiopal::IOpenDelayStrategy -----
    py::class_<asiopal::IOpenDelayStrategy, asiopal::PyIOpenDelayStrategy>(m, "IOpenDelayStrategy",
        "A strategy interface for controlling how connection are retried")

        .def(py::init<>())

        .def(
            "GetNextDelay",
            &asiopal::IOpenDelayStrategy::GetNextDelay,
            py::arg("current"), py::arg("max")
        );

    // ----- class: asiopal::ExponentialBackoffStrategy -----
    py::class_<asiopal::ExponentialBackoffStrategy, asiopal::IOpenDelayStrategy>(m, "ExponentialBackoffStrategy",
        "Implements IOpenDelayStrategy using exponential-backoff.")

        .def_static(
            "Instance",
            &asiopal::ExponentialBackoffStrategy::Instance
        )

        .def(
            "GetNextDelay",
            &asiopal::ExponentialBackoffStrategy::GetNextDelay,
            py::arg("current"), py::arg("max")
        );
}

#endif // PYDNP3_ASIOPAL
#endif
