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

#ifndef PYDNP3_OPENPAL_CONTAINER_WSLICE_H
#define PYDNP3_OPENPAL_CONTAINER_WSLICE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/container/WSlice.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_WSlice(py::module &m)
{
    // ----- class: openpal::WSlice -----
    py::class_<openpal::WSlice, openpal::HasSize<uint32_t>>(m, "WSlice",
        "Represents a write-able slice of a buffer located elsewhere. \n"
        "Mediates writing to the buffer to prevent overruns and other errors.")

        .def(py::init<>())

        .def(
            py::init<uint8_t*, uint32_t>(),
            ":type pBuffer: unsigned char \n"
            ":type size: unsigned int",
            py::arg("pBuffer"), py::arg("size")
        )

        .def_static(
            "Empty",
            &openpal::WSlice::Empty
        )

        .def(
            "SetAllTo",
            &openpal::WSlice::SetAllTo,
            ":type value: unsgined char",
            py::arg("value")
        )

        .def(
            "Clear",
            &openpal::WSlice::Clear
        )

        .def(
            "Advance",
            &openpal::WSlice::Advance,
            ":type count: unsigned int",
            py::arg("count")
        )

        .def(
            "Skip",
            &openpal::WSlice::Skip,
            ":type count: unsigned int",
            py::arg("count")
        )

        .def(
            "ToRSlice",
            &openpal::WSlice::ToRSlice
        );
}

#endif // PYDNP3_OPENPALs
#endif
