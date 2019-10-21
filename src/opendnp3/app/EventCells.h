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

#ifndef PYDNP3_OPENDNP3_APP_EVENTCELLS_H
#define PYDNP3_OPENDNP3_APP_EVENTCELLS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/EventCells.h>
#include <opendnp3/app/MeasurementTypeSpecs.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

template <class Spec>
void declareEventCellBase(py::module &m, string const &type)
{
    // ----- class: opendnp3::EventCellBase<Spec> -----
    py::class_<opendnp3::EventCellBase<Spec>>(m, ("EventCellBase" + type).c_str(),
        "Base class for different types of event metadata.")

        .def_readwrite(
            "clazz",
            &opendnp3::EventCellBase<Spec>::clazz
        )

        .def(
            "SetEventValue",
            &opendnp3::EventCellBase<Spec>::SetEventValue,
            py::arg("value")
        );
}

template <class Spec>
void declareSimpleEventCell(py::module &m, string const &type)
{
    declareEventCellBase<Spec>(m, type);

    // ----- class: opendnp3::SimpleEventCell<Spec> -----
    py::class_<opendnp3::SimpleEventCell<Spec>, opendnp3::EventCellBase<Spec>>(m, ("SimpleEventCell" + type).c_str(),
        "Metatype without a deadband.")

        .def(
            "IsEvent",
            &opendnp3::SimpleEventCell<Spec>::IsEvent,
            py::arg("config"), py::arg("newValue")
        );
}

template <class Spec>
void declareDeadbandEventCell(py::module &m, string const &type)
{
    declareSimpleEventCell<Spec>(m, type);

    // ----- class: opendnp3::SimpleEventCell<Spec> -----
    py::class_<opendnp3::DeadbandEventCell<Spec>,
               opendnp3::SimpleEventCell<Spec>>(m, ("DeadbandEventCell" + type).c_str(),
        "Structure for holding metadata information on points that have support deadbanding.")

        .def(
            "IsEvent",
            &opendnp3::DeadbandEventCell<Spec>::IsEvent,
            py::arg("config"), py::arg("newValue")
        );
}

void bind_EventCells(py::module &m)
{
    // ----- class: opendnp3::EmptyEventCell -----
    py::class_<opendnp3::EmptyEventCell>(m, "EmptyEventCell"
        "A null object for types that have no metadata.");

    declareSimpleEventCell<opendnp3::BinarySpec>(m, "BinarySpec");
    declareSimpleEventCell<opendnp3::DoubleBitBinarySpec>(m, "DoubleBitBinarySpec");
    declareSimpleEventCell<opendnp3::BinaryOutputStatusSpec>(m, "BinaryOutputStatusSpec");
//    declareDeadbandEventCell<opendnp3::AnalogSpec>(m, "AnalogSpec");
//    declareDeadbandEventCell<opendnp3::CounterSpec>(m, "CounterSpec");
//    declareDeadbandEventCell<opendnp3::FrozenCounterSpec>(m, "FrozenCounterSpec");
//    declareDeadbandEventCell<opendnp3::AnalogOutputStatusSpec>(m, "AnalogOutputStatusSpec");
}

#endif // PYDNP3_OPENDNP3
#endif
