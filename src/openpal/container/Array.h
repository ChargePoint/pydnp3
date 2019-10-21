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

#ifndef PYDNP3_OPENPAL_CONTAINER_ARRAY_H
#define PYDNP3_OPENPAL_CONTAINER_ARRAY_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/container/Array.h>
#include <pybind11/operators.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

namespace opendnp3 {
    class BinaryConfig;
    class DoubleBitBinaryConfig;
    class AnalogConfig;
    class CounterConfig;
    class FrozenCounterConfig;
    class BOStatusConfig;
    class AOStatusConfig;
    class TimeAndIntervalConfig;
}

template <class ValueType, class IndexType>
void declareArray(py::module &m, std::string const &valueType, std::string const &indexType)
{
    // ----- class: openpal::Array<ValueType, IndexType> -----
    py::class_<openpal::Array<ValueType, IndexType>, openpal::HasSize<IndexType>>(m, ("Array" + valueType).c_str(),
        "Template type for a dynamically allocated array.")

        .def(py::init<>())

        .def(
            py::init<IndexType>(),
            (":type size: " + indexType).c_str(),
            py::arg("size")
        )

        .def(
            py::init<const openpal::Array<ValueType, IndexType>&>(),
            py::arg("copy")
        )

        .def(
            "ToView",
            &openpal::Array<ValueType, IndexType>::ToView
        )

        .def(
            "Contains",
            &openpal::Array<ValueType, IndexType>::Contains,
            (":type index: " + indexType).c_str(),
            py::arg("index")
        )

        .def(
            "__getitem__",
            (ValueType& (openpal::Array<ValueType, IndexType>::*)(IndexType))
            &openpal::Array<ValueType, IndexType>::operator[],
            (":type index: " + indexType).c_str(),
            py::arg("index")
        )

        .def(
            "__getitem__",
            (const ValueType& (openpal::Array<ValueType, IndexType>::*)(IndexType) const)
            &openpal::Array<ValueType, IndexType>::operator[],
            (":type index: " + indexType).c_str(),
            py::arg("index")
        );
}

void bind_Array(py::module &m)
{
    declareArray<opendnp3::BinaryConfig, uint16_t>(m, "BinaryConfig", "unsigned short");
    declareArray<opendnp3::DoubleBitBinaryConfig, uint16_t>(m, "DoubleBitBinaryConfig", "unsigned short");
    declareArray<opendnp3::AnalogConfig, uint16_t>(m, "AnalogConfig", "unsigned short");
    declareArray<opendnp3::CounterConfig, uint16_t>(m, "CounterConfig", "unsigned short");
    declareArray<opendnp3::FrozenCounterConfig, uint16_t>(m, "FrozenCounterConfig", "unsigned short");
    declareArray<opendnp3::BOStatusConfig, uint16_t>(m, "BOStatusConfig", "unsigned short");
    declareArray<opendnp3::AOStatusConfig, uint16_t>(m, "AOStatusConfig", "unsigned short");
    declareArray<opendnp3::TimeAndIntervalConfig, uint16_t>(m, "TimeAndIntervalConfig", "unsigned short");
    declareArray<uint8_t, uint32_t>(m, "Buffer", "unsigned int");
}

#endif // PYDNP3_OPENPAL
#endif
