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

#ifndef PYDNP3_OPENPAL_EXECUTOR_IUTCTIMESOURCE_H
#define PYDNP3_OPENPAL_EXECUTOR_IUTCTIMESOURCE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/executor/IUTCTimeSource.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

namespace openpal
{
/**
* Overriding virtual functions from interface class IUTCTimeSource.
*/
    class PyIUTCTimeSource : public IUTCTimeSource
    {
    public:
        /* Inherit the constructors */
        using IUTCTimeSource::IUTCTimeSource;

        /* Trampoline for IUTCTimeSource virtual functions */
        UTCTimestamp Now() override {
            PYBIND11_OVERLOAD_PURE(
                UTCTimestamp,
                IUTCTimeSource,
                Now,
            );
        }
    };
}

void bind_IUTCTimeSource(py::module &m)
{
	// ----- class: openpal::IUTCTimeSource -----
    py::class_<openpal::IUTCTimeSource,
               openpal::PyIUTCTimeSource,
               std::shared_ptr<openpal::IUTCTimeSource>>(m, "IUTCTimeSource",
        "Interface that defines a method to get UTC timestamps.")

        .def(py::init<>())

        .def(
            "Now",
            &openpal::IUTCTimeSource::Now
        );

	// ----- class: openpal::FixedUTCTimeSource -----
    py::class_<openpal::FixedUTCTimeSource,
               openpal::IUTCTimeSource,
               std::shared_ptr<openpal::FixedUTCTimeSource>>(m, "FixedUTCTimeSource",
        "Mock usable for testing.")

        .def(
            py::init<int64_t>(),
            ":type time: long",
            py::arg("time")
        )

        .def(
            "Now",
            &openpal::FixedUTCTimeSource::Now
        )

        .def_readwrite(
            "time",
            &openpal::FixedUTCTimeSource::time,
            ":type time: long"
        );
}

#endif // PYDNP3_OPENPAL
#endif
