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

#ifndef PYDNP3_OPENDNP3_APP_QUALITYMASKS_H
#define PYDNP3_OPENDNP3_APP_QUALITYMASKS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/QualityMasks.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

template <class T>
void declareToUnderlying(py::module &m)
{
    // ----- func: opendnp3::ToUnderlying -----
    m.def(
        "ToUnderlying",
        &opendnp3::ToUnderlying<T>,
        py::arg("flag")
    );
}

void bind_QualityMasks(py::module &m)
{
    declareToUnderlying<opendnp3::BinaryQuality>(m);
    declareToUnderlying<opendnp3::DoubleBitBinaryQuality>(m);
    declareToUnderlying<opendnp3::CounterQuality>(m);
    declareToUnderlying<opendnp3::FrozenCounterQuality>(m);
    declareToUnderlying<opendnp3::AnalogQuality>(m);
    declareToUnderlying<opendnp3::AnalogOutputStatusQuality>(m);
    declareToUnderlying<opendnp3::BinaryOutputStatusQuality>(m);
}

#endif // PYDNP3_OPENDNP3
#endif
