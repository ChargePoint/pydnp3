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

#ifndef PYDNP3_OPENDNP3_APP_BASEMEASUREMENTTYPES_H
#define PYDNP3_OPENDNP3_APP_BASEMEASUREMENTTYPES_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/BaseMeasurementTypes.h>
#include <opendnp3/gen/DoubleBit.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

template <typename T>
void declareTypedMeasurement(py::module &m, string const & type)
{
    // ----- class: opendnp3::TypedMeasurement<T> -----
    py::class_<opendnp3::TypedMeasurement<T>, opendnp3::Measurement>(m, ("TypedMeasurement" + type).c_str(),
        "Common subclass to analogs and counters.")

        .def_readwrite(
            "value",
            &opendnp3::TypedMeasurement<T>::value
        );
}

void bind_BaseMeasurementTypes(py::module &m)
{
    // ----- class: opendnp3::Measurement -----
    py::class_<opendnp3::Measurement>(m, "Measurement",
        "Base class shared by all of the DataPoint types.")

        .def_readwrite(
            "flags",
            &opendnp3::Measurement::flags,
            "Bitfield that stores type specific quality information."
        )

        .def_readwrite(
            "time",
            &opendnp3::Measurement::time,
            "Timestamp associated with the measurement."
        );

    declareTypedMeasurement<bool>(m, "Bool");
    declareTypedMeasurement<opendnp3::DoubleBit>(m, "DoubleBit");
    declareTypedMeasurement<double>(m, "Double");
    declareTypedMeasurement<uint32_t>(m, "Uint32");
}

#endif // PYDNP3_OPENDNP3
#endif
