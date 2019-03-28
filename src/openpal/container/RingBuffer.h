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

#ifndef PYDNP3_OPENPAL_CONTAINER_RINGBUFFER_H
#define PYDNP3_OPENPAL_CONTAINER_RINGBUFFER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/container/RingBuffer.h>

#ifdef PYDNP3_OPENPAL

template <uint8_t N>
void declareRingBuffer(py::module &m, std::string const &type)
{
    // ----- class: openpal::RingBuffer<N> -----
    py::class_<openpal::RingBuffer<N>>(m, ("RingBuffer" + type).c_str(),
        "A byte-oriented ring buffer. \n"
        "Interrupt-safe (w/o disabling interrupts) for a single producer and single consumer, "
        "one reading and one writing. \n"
        "N must be a power of 2, and is enforced via static assert.")

        .def(py::init<>())

        .def(
            "Put",
            &openpal::RingBuffer<N>::Put,
            ":type byteIn: unsigned short",
            py::arg("byteIn")
        )

        .def(
            "Get",
            &openpal::RingBuffer<N>::Get,
            ":type byteOut: unsigned short",
            py::arg("byteOut")
        )

        .def(
            "GetMany",
            &openpal::RingBuffer<N>::GetMany,
            py::arg("output")
        )

        .def(
            "PutMany",
            &openpal::RingBuffer<N>::PutMany,
            py::arg("input")
        )

        .def(
            "Full",
            &openpal::RingBuffer<N>::Full
        )

        .def(
            "Empty",
            &openpal::RingBuffer<N>::Empty
        );
}

void bind_RingBuffer(py::module &m)
{
    // Example
    declareRingBuffer<16>(m, "16");
}

#endif // PYDNP3_OPENPAL
#endif
