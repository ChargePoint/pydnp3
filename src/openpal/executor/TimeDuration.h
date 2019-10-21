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

#ifndef PYDNP3_OPENPAL_EXECUTOR_TIMEDURATION_H
#define PYDNP3_OPENPAL_EXECUTOR_TIMEDURATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/executor/TimeDuration.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_TimeDuration(py::module &m)
{
	// ----- class: openpal::TimeDurationBase<int64_t> -----
    py::class_<openpal::TimeDurationBase<int64_t>>(m, "TimeDurationBase")

        .def(py::init<>())

        .def(
            "GetMilliseconds",
            &openpal::TimeDurationBase<int64_t>::GetMilliseconds
        )

        .def(
            "IsNegative",
            &openpal::TimeDurationBase<int64_t>::IsNegative
        )

        .def_readwrite(
            "milliseconds",
            &openpal::TimeDurationBase<int64_t>::milliseconds,
            ":type milliseconds: long"
        );

	// ----- class: openpal::TimeDuration -----
    py::class_<openpal::TimeDuration, openpal::TimeDurationBase<int64_t>>(m, "TimeDuration",
        "Strong typing for millisecond based time durations.")

        .def(py::init<>())

        .def(
            "MultiplyBy",
            &openpal::TimeDuration::MultiplyBy,
            py::arg("factor")
        )

        .def_static(
            "Min",
            &openpal::TimeDuration::Min
        )

        .def_static(
            "Max",
            &openpal::TimeDuration::Max
        )

        .def_static(
            "Zero",
            &openpal::TimeDuration::Zero
        )

        .def_static(
            "Milliseconds",
            &openpal::TimeDuration::Milliseconds,
            ":type milliseconds: long",
            py::arg("milliseconds")
        )

        .def_static(
            "Seconds",
            &openpal::TimeDuration::Seconds,
            ":type seconds: long",
            py::arg("seconds")
        )

        .def_static(
            "Minutes",
            &openpal::TimeDuration::Minutes,
            ":type minutes: long",
            py::arg("minutes")
        )

        .def_static(
            "Hours",
            &openpal::TimeDuration::Hours,
            ":type hours: long",
            py::arg("hours")
        )

        .def_static(
            "Days",
            &openpal::TimeDuration::Days,
            ":type days: long",
            py::arg("days")
        );

    // ----- openpal::operator -----
    m.def(
        "__eq__",
        (bool (*)(const openpal::TimeDuration&, const openpal::TimeDuration&))
        &openpal::operator==,
        "TimeDuration equality comparision."
    );
}

#endif // PYDNP3_OPENPAL
#endif
