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

#ifndef PYDNP3_ASIOPAL_CHANNELRETRY_H
#define PYDNP3_ASIOPAL_CHANNELRETRY_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiopal/ChannelRetry.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_ChannelRetry(py::module &m)
{
    // ----- class: asiopal::ChannelRetry -----
    py::class_<asiopal::ChannelRetry>(m, "ChannelRetry",
        "Class used to configure how channel failures are retried")
        .def(
            py::init<openpal::TimeDuration, openpal::TimeDuration>(),
            "   Construct a channel retry config class. \n"
            ":param minOpenRetry: minimum connection retry interval on failure \n"
            ":param maxOpenRetry: maximum connection retry interval on failure \n"
            ":param strategy: strategy to use",
            py::arg("minOpenRetry"), py::arg("maxOpenRetry")
        )
        .def(
            py::init<openpal::TimeDuration, openpal::TimeDuration, asiopal::IOpenDelayStrategy&>(),
            "   Construct a channel retry config class. \n"
            ":param minOpenRetry: minimum connection retry interval on failure \n"
            ":param maxOpenRetry: maximum connection retry interval on failure \n"
            ":param strategy: strategy to use",
            py::arg("minOpenRetry"), py::arg("maxOpenRetry"),
            py::arg("strategy")
        )

        .def(
            py::init(&asiopal::ChannelRetry::Default),
            "Default configuration of exponential backoff from 1 sec to 1 minute."
        )

        // @todo Return value policy experimental
        .def_static(
            "Default",
            &asiopal::ChannelRetry::Default,
            "Return the default configuration of exponential backoff from 1 sec to 1 minute.",
            py::return_value_policy::reference
        )

        .def_readwrite(
            "minOpenRetry",
            &asiopal::ChannelRetry::minOpenRetry,
            "Minimum connection retry interval on failure."
        )

        .def_readwrite(
            "maxOpenRetry",
            &asiopal::ChannelRetry::maxOpenRetry,
            "Maximum connection retry interval on failure."
        )

        .def(
            "NextDelay",
            &asiopal::ChannelRetry::NextDelay
        );
}

#endif // PYDNP3_ASIOPAL
#endif
