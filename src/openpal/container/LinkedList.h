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

#ifndef PYDNP3_OPENPAL_CONTAINER_LINKEDLIST_H
#define PYDNP3_OPENPAL_CONTAINER_LINKEDLIST_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/container/LinkedList.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class ValueType, class IndexType>
void declareLinkedList(py::module &m, std::string const &type, std::string const &indexType)
{
    // ----- class: openpal::ListNode<ValueType> -----
    py::class_<openpal::ListNode<ValueType>>(m, ("ListNode" + type).c_str())

        .def(py::init<>())

        .def_readwrite(
            "value",
            &openpal::ListNode<ValueType>::value
        );

    // ----- class: openpal::LinkedListIterator<ValueType> -----
    py::class_<openpal::LinkedListIterator<ValueType>>(m, ("LinkedListIterator" + type).c_str())

        .def_static(
            "Undefined",
            &openpal::LinkedListIterator<ValueType>::Undefined
        )

        .def_static(
            "From",
            &openpal::LinkedListIterator<ValueType>::From
        )

        .def(
            "HasNext",
            &openpal::LinkedListIterator<ValueType>::HasNext
        )

        .def(
            "Next",
            &openpal::LinkedListIterator<ValueType>::Next
        )

        .def(
            "Current",
            &openpal::LinkedListIterator<ValueType>::Current
        )

        .def(
            "CurrentValue",
            &openpal::LinkedListIterator<ValueType>::CurrentValue
        );

    // ----- class: openpal::LinkedList<ValueType, IndexType> -----
    py::class_<openpal::LinkedList<ValueType, IndexType>, openpal::HasSize<IndexType>>(m, ("LinkedList" + type).c_str(),
        "A container adapter for a -linked list.")

        .def(
            py::init<IndexType>(),
            (":type maxSize: " + indexType).c_str(),
            py::arg("maxSize")
        )

        .def(
            "Capacity",
            &openpal::LinkedList<ValueType, IndexType>::Capacity
        )

        .def(
            "Clear",
            &openpal::LinkedList<ValueType, IndexType>::Clear
        )

        .def(
            "Head",
            &openpal::LinkedList<ValueType, IndexType>::Head
        )

        .def(
            "Iterate",
            &openpal::LinkedList<ValueType, IndexType>::Iterate
        )

        .def(
            "Add",
            &openpal::LinkedList<ValueType, IndexType>::Add,
            py::arg("value")
        )

        .def(
            "Remove",
            (bool (openpal::LinkedList<ValueType, IndexType>::*)(const ValueType&))
            &openpal::LinkedList<ValueType, IndexType>::Remove,
            py::arg("value")
        )

        .def(
            "Remove",
            (void (openpal::LinkedList<ValueType, IndexType>::*)(openpal::ListNode<ValueType>*))
            &openpal::LinkedList<ValueType, IndexType>::Remove,
            py::arg("apNode")
        )

        .def(
            "IsFull",
            &openpal::LinkedList<ValueType, IndexType>::IsFull
        );
}

void bind_LinkedList(py::module &m)
{
    declareLinkedList<int, uint16_t>(m, "Int", "unsigned short");
}

#endif // PYDNP3_OPENPAL
#endif
