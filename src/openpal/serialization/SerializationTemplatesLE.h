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

#ifndef PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATIONTEMPLATESLE_H
#define PYDNP3_OPENPAL_SERIALIZATION_SERIALIZATIONTEMPLATESLE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/serialization/SerializationTemplatesLE.h>

#ifdef PYDNP3_OPENPAL

template <class T>
void declareBit16LE(py::module &m, string const &type)
{
    // ----- class: openpal::Bit16LE<T> -----
    py::class_<openpal::Bit16LE<T>>(m, ("Bit16LE" + type).c_str())

        .def_static(
            "Read",
            &openpal::Bit16LE<T>::Read,
            ":type data: unsigned char",
            py::arg("data")
        )

        .def_static(
            "Write",
            &openpal::Bit16LE<T>::Write,
            ":type data: unsigned char",
            py::arg("data"), py::arg("value")
        )

        .def_static(
            "WriteBuffer",
            &openpal::Bit16LE<T>::WriteBuffer,
            py::arg("buffer"), py::arg("aValue")
        )

        .def_static(
            "ReadBuffer",
            &openpal::Bit16LE<T>::ReadBuffer,
            py::arg("arBuffer")
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::Bit16LE<T>::SIZE; }
        )

        .def_property_readonly_static(
            "Max",
            [](py::object) { return openpal::Bit16LE<T>::Max; }
        )

        .def_property_readonly_static(
            "Min",
            [](py::object) { return openpal::Bit16LE<T>::Min; }
        );
}

template <class T>
void declareBit32LE(py::module &m, string const &type)
{
    // ----- class: openpal::Bit32LE<T> -----
    py::class_<openpal::Bit32LE<T>>(m, ("Bit32LE" + type).c_str())

        .def_static(
            "Read",
            &openpal::Bit32LE<T>::Read,
            ":type data: unsigned char",
            py::arg("data")
        )

        .def_static(
            "Write",
            &openpal::Bit32LE<T>::Write,
            ":type data: unsigned char",
            py::arg("data"), py::arg("value")
        )

        .def_static(
            "WriteBuffer",
            &openpal::Bit32LE<T>::WriteBuffer,
            py::arg("buffer"), py::arg("aValue")
        )

        .def_static(
            "ReadBuffer",
            &openpal::Bit32LE<T>::ReadBuffer,
            py::arg("buffer")
        )

        .def_property_readonly_static(
            "SIZE",
            [](py::object) { return openpal::Bit32LE<T>::SIZE; }
        )

        .def_property_readonly_static(
            "Max",
            [](py::object) { return openpal::Bit32LE<T>::Max; }
        )

        .def_property_readonly_static(
            "Min",
            [](py::object) { return openpal::Bit32LE<T>::Min; }
        );
}

void bind_SerializationTemplatesLE(py::module &m)
{
}

#endif // PYDNP3_OPENPAL
#endif
