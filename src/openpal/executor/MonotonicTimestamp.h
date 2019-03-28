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

#ifndef PYDNP3_OPENPAL_EXECUTOR_MONOTONICTIMESTAMP_H
#define PYDNP3_OPENPAL_EXECUTOR_MONOTONICTIMESTAMP_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/executor/MonotonicTimestamp.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_MonotonicTimestamp(py::module &m)
{
    // ----- class: openpal::MonotonicTimestamp -----
    py::class_<openpal::MonotonicTimestamp>(m, "MonotonicTimestamp",
        "Strong typing for millisecond-based monotonic timestamps")

        .def(py::init<>())

        .def(
            py::init<int64_t>(),
            ":type milliseconds: long",
            py::arg("milliseconds")
        )

        .def_static(
            "Max",
            &openpal::MonotonicTimestamp::Max
        )

        .def_static(
            "Min",
            &openpal::MonotonicTimestamp::Min
        )

        .def(
            "IsMax",
            &openpal::MonotonicTimestamp::IsMax
        )

        .def(
            "IsMin",
            &openpal::MonotonicTimestamp::IsMin
        )

        .def(
            "Add",
            &openpal::MonotonicTimestamp::Add,
            py::arg("duration")
        )

        .def_readwrite(
            "milliseconds",
            &openpal::MonotonicTimestamp::milliseconds,
            ":type milliseconds: long"
        );

    // ----- openpal::operator -----
    m.def(
        "__eq__",
        (bool (*)(const openpal::MonotonicTimestamp&, const openpal::MonotonicTimestamp&))
        &openpal::operator==,
        "MonotonicTimestamp equality comparision."
    );

    m.def(
        "__gt__",
        (bool (*)(const openpal::MonotonicTimestamp&, const openpal::MonotonicTimestamp&))
        &openpal::operator>,
        "MonotonicTimestamp greater than comparision."
    );

    m.def(
        "__lt__",
        (bool (*)(const openpal::MonotonicTimestamp&, const openpal::MonotonicTimestamp&))
        &openpal::operator<,
        "MonotonicTimestamp less than comparision."
    );
}

#endif // PYDNP3_OPENPAL
#endif
