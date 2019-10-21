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

#ifndef PYDNP3_OPENDNP3_GEN_EVENTANALOGVARIATION_H
#define PYDNP3_OPENDNP3_GEN_EVENTANALOGVARIATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/EventAnalogVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_EventAnalogVariation(py::module &m)
{
    // ----- enum class: opendnp3::EventAnalogVariation -----
    py::enum_<opendnp3::EventAnalogVariation>(m, "EventAnalogVariation")
        .value("Group32Var1", opendnp3::EventAnalogVariation::Group32Var1)
        .value("Group32Var2", opendnp3::EventAnalogVariation::Group32Var2)
        .value("Group32Var3", opendnp3::EventAnalogVariation::Group32Var3)
        .value("Group32Var4", opendnp3::EventAnalogVariation::Group32Var4)
        .value("Group32Var5", opendnp3::EventAnalogVariation::Group32Var5)
        .value("Group32Var6", opendnp3::EventAnalogVariation::Group32Var6)
        .value("Group32Var7", opendnp3::EventAnalogVariation::Group32Var7)
        .value("Group32Var8", opendnp3::EventAnalogVariation::Group32Var8);
}

#endif // PYDNP3_OPENDNP3
#endif
