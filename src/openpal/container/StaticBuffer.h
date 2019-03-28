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

#ifndef PYDNP3_OPENPAL_CONTAINER_STATICBUFFER_H
#define PYDNP3_OPENPAL_CONTAINER_STATICBUFFER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/container/StaticBuffer.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <uint32_t SIZE>
void declareStaticBuffer(py::module &m, std::string const &type)
{
    // ----- class: openpal::StaticBuffer<SIZE> -----
    py::class_<openpal::StaticBuffer<SIZE>>(m, ("StaticBuffer" + type).c_str())

        .def(py::init<>())

        .def(
            "ToRSlice",
            (openpal::RSlice (openpal::StaticBuffer<SIZE>::*)() const)
            &openpal::StaticBuffer<SIZE>::ToRSlice
        )

        .def(
            "ToRSlice",
            (openpal::RSlice (openpal::StaticBuffer<SIZE>::*)(uint32_t) const)
            &openpal::StaticBuffer<SIZE>::ToRSlice,
            ":type maxSize: unsigned int",
            py::arg("maxSize")
        )

        .def(
            "GetWSlice",
            (openpal::WSlice (openpal::StaticBuffer<SIZE>::*)())
            &openpal::StaticBuffer<SIZE>::GetWSlice
        )

        .def(
            "GetWSlice",
            (openpal::WSlice (openpal::StaticBuffer<SIZE>::*)(uint32_t))
            &openpal::StaticBuffer<SIZE>::GetWSlice,
            ":type maxSize: unsigned int",
            py::arg("maxSize")
        )

        .def(
            "Size",
            &openpal::StaticBuffer<SIZE>::Size
        );
}

void bind_StaticBuffer(py::module &m)
{
    declareStaticBuffer<100>(m, "100");
    declareStaticBuffer<14>(m, "14");
    declareStaticBuffer<292>(m, "292");
    declareStaticBuffer<4>(m, "4");
}

#endif // PYDNP3_OPENPAL
#endif
