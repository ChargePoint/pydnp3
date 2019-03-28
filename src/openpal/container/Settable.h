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

#ifndef PYDNP3_OPENPAL_CONTAINER_SETTABLE_H
#define PYDNP3_OPENPAL_CONTAINER_SETTABLE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/container/Settable.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

template <class T>
void declareSettable(py::module &m, std::string const &type)
{
    // ----- class: openpal::Settable<T> -----
    py::class_<openpal::Settable<T>>(m, ("Settable" + type).c_str(),
        "Utility class for representing a value that may or may not be set.")

        .def(py::init<>())

        .def(
            "IsSet",
            &openpal::Settable<T>::IsSet
        )

        .def(
            "IsEmpty",
            &openpal::Settable<T>::IsEmpty
        )

        .def(
            "Get",
            &openpal::Settable<T>::Get
        )

        .def(
            "Pop",
            &openpal::Settable<T>::Pop,
            py::arg("output")
        )

        .def(
            "Clear",
            &openpal::Settable<T>::Clear
        )

        .def(
            "Set",
            &openpal::Settable<T>::Set,
            py::arg("value")
        );
}

void bind_Settable(py::module &m)
{
    declareSettable<openpal::RSlice>(m, "RSlice");
    declareSettable<openpal::WSlice>(m, "WSlice");
}

#endif // PYDNP3_OPENPAL
#endif
