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

#ifndef PYDNP3_OPENDNP3_MASTER_COMMANDSET_H
#define PYDNP3_OPENDNP3_MASTER_COMMANDSET_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <Python.h>

#include <opendnp3/master/CommandSet.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_CommandSet(py::module &m)
{
    // ----- class: opendnp3::CommandSet -----
    py::class_<opendnp3::CommandSet, std::shared_ptr<opendnp3::CommandSet>>(m, "CommandSet",
        "Provides a mechanism for building a set of one or more command headers.")

        .def(
            py::init<>(),
            "Contrsuct an empty command set."
        )

        .def(
            py::init([](opendnp3::CommandSet& other){return opendnp3::CommandSet(std::move(other));}),
            "Construct a new command set and take ownership of the headers in argument."
        )

        .def(
            py::init([](std::vector<opendnp3::Indexed<opendnp3::ControlRelayOutputBlock>> items)
            {
                opendnp3::CommandSet commands = opendnp3::CommandSet();
                commands.Add<opendnp3::ControlRelayOutputBlock>(items);
                return commands;
            }),
            "Construct a command set from a list of CROB.",
            py::arg("items")
        )

        .def(
            py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt16>> items)
            {
                opendnp3::CommandSet commands = opendnp3::CommandSet();
                commands.Add<opendnp3::AnalogOutputInt16>(items);
                return commands;
            }),
            "Construct a command set from a list of AOInt16.",
            py::arg("items")
        )

        .def(
            py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt32>> items)
            {
                opendnp3::CommandSet commands = opendnp3::CommandSet();
                commands.Add<opendnp3::AnalogOutputInt32>(items);
                return commands;
            }),
            "Construct a command set from a list of AOInt32.",
            py::arg("items")
        )

        .def(
            py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputFloat32>> items)
            {
                opendnp3::CommandSet commands = opendnp3::CommandSet();
                commands.Add<opendnp3::AnalogOutputFloat32>(items);
                return commands;
            }),
            "Construct a command set from a list of AOFloat32.",
            py::arg("items")
        )

        .def(
            py::init([](std::vector<opendnp3::Indexed<opendnp3::AnalogOutputDouble64>> items)
            {
                opendnp3::CommandSet commands = opendnp3::CommandSet();
                commands.Add<opendnp3::AnalogOutputDouble64>(items);
                return commands;
            }),
            "Construct a command set from a list of AODouble64.",
            py::arg("items")
        )

        .def(
            "Add",
            (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::ControlRelayOutputBlock>> items))
            &opendnp3::CommandSet::Add<opendnp3::ControlRelayOutputBlock>,
            py::arg("items")
        )

        .def(
            "Add",
            (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt16>> items))
            &opendnp3::CommandSet::Add<opendnp3::AnalogOutputInt16>,
            py::arg("items")
        )

        .def(
            "Add",
            (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputInt32>> items))
            &opendnp3::CommandSet::Add<opendnp3::AnalogOutputInt32>,
            py::arg("items")
        )

        .def(
            "Add",
            (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputFloat32>> items))
            &opendnp3::CommandSet::Add<opendnp3::AnalogOutputFloat32>,
            py::arg("items")
        )

        .def(
            "Add",
            (void (opendnp3::CommandSet::*)(std::vector<opendnp3::Indexed<opendnp3::AnalogOutputDouble64>> items))
            &opendnp3::CommandSet::Add<opendnp3::AnalogOutputDouble64>,
            py::arg("items")
        )

        .def(
            "StartHeader",
            &opendnp3::CommandSet::StartHeader<opendnp3::ControlRelayOutputBlock>,
            "Begin a header of the parameterized type."
        )

        .def(
            "StartHeader",
            &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputInt16>,
            "Begin a header of the parameterized type."
        )

        .def(
            "StartHeader",
            &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputInt32>,
            "Begin a header of the parameterized type."
        )

        .def(
            "StartHeader",
            &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputFloat32>,
            "Begin a header of the parameterized type."
        )

        .def(
            "StartHeader",
            &opendnp3::CommandSet::StartHeader<opendnp3::AnalogOutputDouble64>,
            "Begin a header of the parameterized type."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
