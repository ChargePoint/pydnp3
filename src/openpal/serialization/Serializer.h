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

#ifndef PYDNP3_OPENPAL_SERIALIZATION_SERIALIZER_H
#define PYDNP3_OPENPAL_SERIALIZATION_SERIALIZER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/AnalogOutput.h>
#include <opendnp3/app/MeasurementTypes.h>
#include <openpal/serialization/Serializer.h>

#ifdef PYDNP3_OPENPAL

template <class T>
void declareSerializer(py::module &m, std::string const &type)
{
    typedef bool (*ReadFunc)(openpal::RSlice& buffer, T& output);
    typedef bool (*WriteFunc)(const T& value, openpal::WSlice& buffer);

    // ----- class: openpal::Serializer<T> -----
    py::class_<openpal::Serializer<T>>(m, ("Serializer" + type).c_str())

        .def(py::init<>())

        .def(
            py::init<uint32_t, ReadFunc, WriteFunc>(),
            py::arg("size"), py::arg("pReadFunc"), py::arg("pWriteFunc")
        )

        .def(
            "Size",
            &openpal::Serializer<T>::Size,
            ":return: the size (in bytes) required for every call to read/write"
        )

        .def(
            "Read",
            &openpal::Serializer<T>::Read,
            "Read the value and advances the read buffer.",
            py::arg("buffer"), py::arg("output")
        )

        .def(
            "Write",
            &openpal::Serializer<T>::Write,
            "Write the value and advances the write buffer.",
            py::arg("value"), py::arg("buffer")
        );
}

void bind_Serializer(py::module &m)
{
    declareSerializer<opendnp3::Binary>(m, "Binary");
    declareSerializer<opendnp3::DoubleBitBinary>(m, "DoubleBitBinary");
    declareSerializer<opendnp3::BinaryOutputStatus>(m, "BinaryOutputStatus");
    declareSerializer<opendnp3::Analog>(m, "Analog");
    declareSerializer<opendnp3::Counter>(m, "Counter");
    declareSerializer<opendnp3::FrozenCounter>(m, "FrozenCounter");
    declareSerializer<opendnp3::AnalogOutputStatus>(m, "AnalogOutputStatus");
    declareSerializer<opendnp3::TimeAndInterval>(m, "TimeAndInterval");
    declareSerializer<opendnp3::AnalogOutputInt16>(m, "AnalogOutputInt16");
    declareSerializer<opendnp3::AnalogOutputInt32>(m, "AnalogOutputInt32");
    declareSerializer<opendnp3::AnalogOutputFloat32>(m, "AnalogOutputFloat32");
    declareSerializer<opendnp3::AnalogOutputDouble64>(m, "AnalogOutputDouble64");
}

#endif // PYDNP3_OPENPAL
#endif
