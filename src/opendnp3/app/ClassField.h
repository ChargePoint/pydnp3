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

#ifndef PYDNP3_OPENDNP3_APP_CLASSFIELD_H
#define PYDNP3_OPENDNP3_APP_CLASSFIELD_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/ClassField.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

uint8_t CLASS_0 = opendnp3::ClassField::CLASS_0;
uint8_t CLASS_1 = opendnp3::ClassField::CLASS_1;
uint8_t CLASS_2 = opendnp3::ClassField::CLASS_2;
uint8_t CLASS_3 = opendnp3::ClassField::CLASS_3;
uint8_t EVENT_CLASSES = opendnp3::ClassField::EVENT_CLASSES;
uint8_t ALL_CLASSES = opendnp3::ClassField::ALL_CLASSES;
 
void bind_ClassField(py::module &m)
{
    // ----- class: opendnp3::ClassField -----
    py::class_<opendnp3::ClassField>cls(m, "ClassField",
    "Specifies a set of event classes e.g. some subset of {0, 1, 2, 3}.");

    cls.def(py::init<>());

    cls.def(
        py::init<opendnp3::PointClass>(),
        py::arg("pc")
    );

    cls.def(
        py::init<uint8_t>(),
        py::arg("mask")
    );

    cls.def(
        py::init<bool, bool, bool, bool>(),
        py::arg("class0"), py::arg("class1"), py::arg("class2"), py::arg("class3")
    );

    cls.def(
        "IsEmpty",
        &opendnp3::ClassField::IsEmpty
    );

    cls.def(
        "Intersects",
        &opendnp3::ClassField::Intersects,
        py::arg("other")
    );

    cls.def(
        "GetBitfield",
        &opendnp3::ClassField::GetBitfield
    );

    cls.def(
        "OnlyEventClasses",
        &opendnp3::ClassField::OnlyEventClasses
    );

    cls.def(
        "Clear",
        &opendnp3::ClassField::Clear,
        py::arg("field")
    );

    cls.def(
        "Set",
        (void (opendnp3::ClassField::*)(const opendnp3::ClassField &))
        &opendnp3::ClassField::Set,
        py::arg("field")
    );

    cls.def(
        "Set",
        (void (opendnp3::ClassField::*)(opendnp3::PointClass))
        &opendnp3::ClassField::Set,
        py::arg("pc")
    );

    cls.attr("CLASS_0") = CLASS_0;

    cls.attr("CLASS_1") = CLASS_1;

    cls.attr("CLASS_2") = CLASS_2;

    cls.attr("CLASS_3") = CLASS_3;

    cls.attr("EVENT_CLASSES") = EVENT_CLASSES;

    cls.attr("ALL_CLASSES") = ALL_CLASSES;

    cls.def(
        "HasEventType",
        &opendnp3::ClassField::HasEventType
    );

    cls.def(
        "HasClass0",
        &opendnp3::ClassField::HasClass0
    );

    cls.def(
        "HasClass1",
        &opendnp3::ClassField::HasClass1
    );

    cls.def(
        "HasClass2",
        &opendnp3::ClassField::HasClass2
    );

    cls.def(
        "HasClass3",
        &opendnp3::ClassField::HasClass3
    );

    cls.def(
        "HasEventClass",
        &opendnp3::ClassField::HasEventClass
    );

    cls.def(
        "HasAnyClass",
        &opendnp3::ClassField::HasAnyClass
    );

    cls.def_static(
        "None",
        &opendnp3::ClassField::None
    );

    cls.def_static(
        "AllClasses",
        &opendnp3::ClassField::AllClasses
    );

    cls.def_static(
        "AllEventClasses",
        &opendnp3::ClassField::AllEventClasses
    );
}

#endif // PYDNP3_OPENDNP3
#endif
