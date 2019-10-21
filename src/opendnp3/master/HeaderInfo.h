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

#ifndef PYDNP3_OPENDNP3_MASTER_HEADERINFO_H
#define PYDNP3_OPENDNP3_MASTER_HEADERINFO_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/HeaderInfo.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_HeaderInfo(py::module &m)
{
    py::class_<opendnp3::HeaderInfo>(m, "HeaderInfo",
        "Simple structure used in the ISOEHandler callbacks to return information about the associated header.")

        .def(py::init<>())

        .def(
            py::init<opendnp3::GroupVariation, opendnp3::QualifierCode, opendnp3::TimestampMode, uint32_t>(),
            ":type headerIndex: unsigned int",
            py::arg("gv"), py::arg("qualifier"), py::arg("tsmode"), py::arg("headerIndex")
        )

        .def_readwrite(
            "gv",
            &opendnp3::HeaderInfo::gv,
            "The group/variation enumeration for the header."
        )

        .def_readwrite(
            "qualifier",
            &opendnp3::HeaderInfo::qualifier,
            "The qualifier code enumeration for the header."
        )

        .def_readwrite(
            "tsmode",
            &opendnp3::HeaderInfo::tsmode,
            "Enumeration that provides information about the validity of timestamps on the associated objects."
        )

        .def_readwrite(
            "isEventVariation",
            &opendnp3::HeaderInfo::isEventVariation,
            "True if the specfied variation is an event variation."
        )

        .def_readwrite(
            "flagsValid",
            &opendnp3::HeaderInfo::flagsValid,
            "True if the flags on the value were present on underlying type, false if online is just assumed."
        )

        .def_readwrite(
            "headerIndex",
            &opendnp3::HeaderInfo::headerIndex,
            "   The 0-based index of the header within the ASDU. \n"
            ":type headerIndex: unsigned int"
        );
}

#endif // PYDNP3_OPENDNP3
#endif
