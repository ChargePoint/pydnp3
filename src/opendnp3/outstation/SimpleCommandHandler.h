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

#ifndef PYDNP3_OPENDNP3_OUTSTATION_SIMPLECOMMANDHANDLER_H
#define PYDNP3_OPENDNP3_OUTSTATION_SIMPLECOMMANDHANDLER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/outstation/SimpleCommandHandler.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_SimpleCommandHandler(py::module &m)
{
	// ----- class: opendnp3::SimpleCommandHandler -----
    py::class_<opendnp3::SimpleCommandHandler,
               opendnp3::ICommandHandler,
               std::shared_ptr<opendnp3::SimpleCommandHandler>>(m, "SimpleCommandHandler",
        "Mock ICommandHandler used for examples and demos.")

        .def(
            py::init<opendnp3::CommandStatus>(),
            ":param status: The status value to return in response to all commands"
        )

        .def_readwrite(
            "numOperate",
            &opendnp3::SimpleCommandHandler::numOperate,
            ":type numOperate: unsigned int"
        )

        .def_readwrite(
            "numSelect",
            &opendnp3::SimpleCommandHandler::numSelect,
            ":type numSelect: unsigned int"
        )

        .def_readwrite(
            "numStart",
            &opendnp3::SimpleCommandHandler::numStart,
            ":type numStart: unsigned int"
        )

        .def_readwrite(
            "numEnd",
            &opendnp3::SimpleCommandHandler::numEnd,
            ":type numEnd: unsigned int"
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::ControlRelayOutputBlock&,
                                                                         unsigned short))
            &opendnp3::SimpleCommandHandler::Select,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::ControlRelayOutputBlock&,
                                                                         unsigned short,
                                                                         opendnp3::OperateType))
            &opendnp3::SimpleCommandHandler::Operate,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt16&,
                                                                         unsigned short))
            &opendnp3::SimpleCommandHandler::Select,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt16&,
                                                                         unsigned short,
                                                                         opendnp3::OperateType))
            &opendnp3::SimpleCommandHandler::Operate,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt32&,
                                                                         unsigned short))
            &opendnp3::SimpleCommandHandler::Select,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputInt32&,
                                                                         unsigned short,
                                                                         opendnp3::OperateType))
            &opendnp3::SimpleCommandHandler::Operate,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputFloat32&,
                                                                         unsigned short))
            &opendnp3::SimpleCommandHandler::Select,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputFloat32&,
                                                                         unsigned short,
                                                                         opendnp3::OperateType))
            &opendnp3::SimpleCommandHandler::Operate,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputDouble64&,
                                                                         unsigned short))
            &opendnp3::SimpleCommandHandler::Select,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::SimpleCommandHandler::*)(const opendnp3::AnalogOutputDouble64&,
                                                                         unsigned short,
                                                                         opendnp3::OperateType))
            &opendnp3::SimpleCommandHandler::Operate,
            ":type index: unsigned short",
            py::arg("command"), py::arg("index"), py::arg("opType")
        );

	// ----- class: opendnp3::SuccessCommandHandler -----
    py::class_<opendnp3::SuccessCommandHandler,
               opendnp3::SimpleCommandHandler,
               std::shared_ptr<opendnp3::SuccessCommandHandler>>(m, "SuccessCommandHandler",
        "A singleton command handler that always returns success.")

        .def(py::init<>())

        .def_static(
            "Create",
            &opendnp3::SuccessCommandHandler::Create,
            ":return: shared_ptr to opendnp3.ICommandHandler"
        );
}

#endif // PYDNP3_OPENDNP3
#endif
