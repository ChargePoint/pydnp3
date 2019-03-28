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

#ifndef PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONCONFIG_H
#define PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONCONFIG_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/outstation/OutstationConfig.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OutstationConfig(py::module &m)
{
    // ----- struct: opendnp3::OutstationConfig -----
    py::class_<opendnp3::OutstationConfig>(m, "OutstationConfig",
        "Configuration information for a dnp3 outstation (outstation). \n"
        "Used as both input describing the startup configuration of the outstation, and as configuration state of "
        "mutable properties (i.e. unsolicited responses). \n"
        "Major feature areas are unsolicited responses, time synchronization requests, event buffer limits, "
        "and the DNP3 object/variations to use by default when the master requests class data or variation 0.")

        .def(py::init<>())

        .def(
            py::init<opendnp3::OutstationParams, opendnp3::EventBufferConfig>(),
            py::arg("params"), py::arg("eventBufferConfig")
        )

        .def_readwrite(
            "params",
            &opendnp3::OutstationConfig::params,
            "Various parameters that govern outstation behavior."
        )

        .def_readwrite(
            "eventBufferConfig",
            &opendnp3::OutstationConfig::eventBufferConfig,
            "Describes the sizes in the event buffer."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
