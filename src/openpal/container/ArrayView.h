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

#ifndef PYDNP3_OPENPAL_CONTAINER_ARRAYVIEW_H
#define PYDNP3_OPENPAL_CONTAINER_ARRAYVIEW_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/outstation/MeasurementConfig.h>
#include <openpal/container/ArrayView.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class ValueType, class IndexType>
void declareArrayView(py::module &m, std::string const &valueType, std::string const &indexType)
{
    // ----- class: openpal::ArrayView<ValueType, IndexType> -----
    py::class_<openpal::ArrayView<ValueType, IndexType>,
               openpal::HasSize<IndexType>>(m, ("ArrayView" + valueType).c_str(),
        "Acts as a safe facade around an underlying array.")

        .def(
            py::init(&openpal::ArrayView<ValueType, IndexType>::Empty),
            "Constructor: ArrayView(nullptr, 0)"
        )

        .def(
            py::init<ValueType*, IndexType>(),
            (":type aSize: " + indexType).c_str(),
            py::arg("start"), py::arg("aSize")
        )

        .def_static(
            "Empty",
            &openpal::ArrayView<ValueType, IndexType>::Empty
        )

        .def(
            "Contains",
            (bool (openpal::ArrayView<ValueType, IndexType>::*)(IndexType) const)
            &openpal::ArrayView<ValueType, IndexType>::Contains,
            (":type index: " + indexType).c_str(),
            py::arg("index")
        )

        .def(
            "Contains",
            (bool (openpal::ArrayView<ValueType, IndexType>::*)(IndexType, IndexType) const)
            &openpal::ArrayView<ValueType, IndexType>::Contains,
            (":type start: " + indexType + "\n:type stop: " + indexType).c_str(),
            py::arg("start"), py::arg("stop")
        )

        .def(
            "__getitem__",
            (ValueType& (openpal::ArrayView<ValueType, IndexType>::*)(IndexType))
            &openpal::ArrayView<ValueType, IndexType>::operator[],
            (":type index: " + indexType).c_str(),
            py::arg("index")
        )

        .def(
            "__getitem__",
            (const ValueType& (openpal::ArrayView<ValueType, IndexType>::*)(IndexType) const)
            &openpal::ArrayView<ValueType, IndexType>::operator[],
            (":type index: " + indexType).c_str(),
            py::arg("index")
        );

    // ----- func: openpal::ArrayView -----
    m.def(
        "ArrayView",
        [](ValueType* start, IndexType aSize){return openpal::ArrayView<ValueType, IndexType>(start, aSize);},
        "Return instance of class ArrayView<ValueType, IndexType>"
    );
}

void bind_ArrayView(py::module &m)
{
    declareArrayView<opendnp3::BinaryConfig, uint16_t>(m, "BinaryConfig", "unsigned short");
    declareArrayView<opendnp3::DoubleBitBinaryConfig, uint16_t>(m, "DoubleBitBinaryConfig", "unsigned short");
    declareArrayView<opendnp3::AnalogConfig, uint16_t>(m, "AnalogConfig", "unsigned short");
    declareArrayView<opendnp3::CounterConfig, uint16_t>(m, "CounterConfig", "unsigned short");
    declareArrayView<opendnp3::FrozenCounterConfig, uint16_t>(m, "FrozenCounterConfig", "unsigned short");
    declareArrayView<opendnp3::BOStatusConfig, uint16_t>(m, "BOStatusConfig", "unsigned short");
    declareArrayView<opendnp3::AOStatusConfig, uint16_t>(m, "AOStatusConfig", "unsigned short");
    declareArrayView<opendnp3::TimeAndIntervalConfig, uint16_t>(m, "TimeAndIntervalConfig", "unsigned short");
    declareArrayView<uint8_t, uint32_t>(m, "Buffer", "unsigned int");
}

#endif // PYDNP3_OPENPAL
#endif
