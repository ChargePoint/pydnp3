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

#ifndef PYDNP3_OPENDNP3_GEN_QUALIFIERCODE_H
#define PYDNP3_OPENDNP3_GEN_QUALIFIERCODE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/QualifierCode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_QualifierCode(py::module &m)
{
    // ----- enum class: opendnp3::QualifierCode -----
    py::enum_<opendnp3::QualifierCode>(m, "QualifierCode",
        "Object header range/prefix as a single enumeration.")

        .value("UINT8_START_STOP", opendnp3::QualifierCode::UINT8_START_STOP)
        .value("UINT16_START_STOP", opendnp3::QualifierCode::UINT16_START_STOP)
        .value("ALL_OBJECTS", opendnp3::QualifierCode::ALL_OBJECTS)
        .value("UINT8_CNT", opendnp3::QualifierCode::UINT8_CNT)
        .value("UINT16_CNT", opendnp3::QualifierCode::UINT16_CNT)
        .value("UINT8_CNT_UINT8_INDEX", opendnp3::QualifierCode::UINT8_CNT_UINT8_INDEX)
        .value("UINT16_CNT_UINT16_INDEX", opendnp3::QualifierCode::UINT16_CNT_UINT16_INDEX)
        .value("UINT16_FREE_FORMAT", opendnp3::QualifierCode::UINT16_FREE_FORMAT)
        .value("UNDEFINED", opendnp3::QualifierCode::UNDEFINED);
    
    // ----- function: opendnp3::QualifierCodeToType -----
    m.def(
        "QualifierCodeToType",
        &opendnp3::QualifierCodeToType,
        py::arg("code")
    );
    
    // ----- function: opendnp3::QualifierCodeFromType -----
    m.def(
        "QualifierCodeFromType",
        &opendnp3::QualifierCodeFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );
    
    // ----- function: opendnp3::QualifierCodeToString -----
    m.def(
        "QualifierCodeToString",
        &opendnp3::QualifierCodeToString,
        py::arg("code")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
