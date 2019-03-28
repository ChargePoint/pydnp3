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

#ifndef PYDNP3_OPENDNP3_OUTSTATION_ICOMMANDHANDLER_H
#define PYDNP3_OPENDNP3_OUTSTATION_ICOMMANDHANDLER_H

#include <pybind11/pybind11.h>
#include <Python.h>
#include <opendnp3/outstation/ICommandHandler.h>

#include "opendnp3/app/ITransactable.h"

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ICommandHandler.
*/
    class PyICommandHandler : public ICommandHandler
    {
    public:
        /* Inherit the constructors */
        using ICommandHandler::ICommandHandler;

        /* Trampoline for ITransactable virtual functions */
        void Start() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ICommandHandler,
                Start,
            );
        }
        void End() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ICommandHandler,
                End,
            );
        }

        /* Trampoline for ICommandHandler virtual functions */
        CommandStatus Select(const ControlRelayOutputBlock& command, uint16_t index) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Select,
                command, index
            );
        }
        CommandStatus Operate(const ControlRelayOutputBlock& command, uint16_t index, OperateType opType) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Operate,
                command, index, opType
            );
        }
        CommandStatus Select(const AnalogOutputInt16& command, uint16_t index) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Select,
                command, index
            );
        }
        CommandStatus Operate(const AnalogOutputInt16& command, uint16_t index, OperateType opType) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Operate,
                command, index, opType
            );
        }
        CommandStatus Select(const AnalogOutputInt32& command, uint16_t index) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Select,
                command, index
            );
        }
        CommandStatus Operate(const AnalogOutputInt32& command, uint16_t index, OperateType opType) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Operate,
                command, index, opType
            );
        }
        CommandStatus Select(const AnalogOutputFloat32& command, uint16_t index) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Select,
                command, index
            );
        }
        CommandStatus Operate(const AnalogOutputFloat32& command, uint16_t index, OperateType opType) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Operate,
                command, index, opType
            );
        }
        CommandStatus Select(const AnalogOutputDouble64& command, uint16_t index) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Select,
                command, index
            );
        }
        CommandStatus Operate(const AnalogOutputDouble64& command, uint16_t index, OperateType opType) override {
            PYBIND11_OVERLOAD_PURE(
                CommandStatus,
                ICommandHandler,
                Operate,
                command, index, opType
            );
        }
    };
}

void bind_ICommandHandler(py::module &m)
{
    // ----- class: opendnp3::ICommandHandler -----
    py::class_<opendnp3::ICommandHandler,
               opendnp3::ITransactable,
               opendnp3::PyICommandHandler,
               std::shared_ptr<opendnp3::ICommandHandler>>(m, "ICommandHandler",
        "Interface used to dispatch SELECT / OPERATE / DIRECT OPERATE (Binary/Analog output) from the outstation "
        "to application code. \n"
        "The ITransactable sub-interface is used to determine the start and end of an ASDU containing commands.")

        .def(py::init<>())

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::ControlRelayOutputBlock&, uint16_t))
            &opendnp3::ICommandHandler::Select,
            "   Ask if the application supports a ControlRelayOutputBlock - group 12 variation 1. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::ControlRelayOutputBlock&,
                                                                    uint16_t,
                                                                    opendnp3::OperateType))
            &opendnp3::ICommandHandler::Operate,
            "   Operate a ControlRelayOutputBlock - group 12 variation 1. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":param opType: the operation type the outstation received \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt16&, uint16_t))
            &opendnp3::ICommandHandler::Select,
            "   Ask if the application supports a 16 bit analog output - group 41 variation 2. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt16&,
                                                                    uint16_t,
                                                                    opendnp3::OperateType))
            &opendnp3::ICommandHandler::Operate,
            "   Ask if the application supports a 16 bit analog output - group 41 variation 2. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":param opType: the operation type the outstation received \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt32&, uint16_t))
            &opendnp3::ICommandHandler::Select,
            "   Ask if the application supports a 32 bit analog output - group 41 variation 1. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputInt32&,
                                                                    uint16_t,
                                                                    opendnp3::OperateType))
            &opendnp3::ICommandHandler::Operate,
            "   Operate a 32 bit analog output - group 41 variation 1. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":param opType: the operation type the outstation received \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputFloat32&, uint16_t))
            &opendnp3::ICommandHandler::Select,
            "   Ask if the application supports a single precision, floating point analog output - "
            "group 41 variation 3. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputFloat32&,
                                                                    uint16_t,
                                                                    opendnp3::OperateType))
            &opendnp3::ICommandHandler::Operate,
            "   Operate a single precision, floating point analog output - group 41 variation 3. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":param opType: the operation type the outstation received \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index"), py::arg("opType")
        )

        .def(
            "Select",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputDouble64&, uint16_t))
            &opendnp3::ICommandHandler::Select,
            "   Ask if the application supports a double precision, floating point analog output - "
            "group 41 variation 4. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index")
        )

        .def(
            "Operate",
            (opendnp3::CommandStatus (opendnp3::ICommandHandler::*)(const opendnp3::AnalogOutputDouble64&,
                                                                    uint16_t,
                                                                    opendnp3::OperateType))
            &opendnp3::ICommandHandler::Operate,
            "   Operate a double precision, floating point analog output - group 41 variation 4. \n"
            ":param command: command to operate \n"
            ":param index: index of the command \n"
            ":param opType: the operation type the outstation received \n"
            ":type index: unsigned short \n"
            ":return: result of request",
            py::arg("command"), py::arg("index"), py::arg("opType")
        );
}

#endif // PYDNP3_OPENDNP3
#endif
