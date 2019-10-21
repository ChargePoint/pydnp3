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

#ifndef PYDNP3_OPENDNP3_MASTER_ICOMMANDPROCESSOR_H
#define PYDNP3_OPENDNP3_MASTER_ICOMMANDPROCESSOR_H

#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
#include <Python.h>

#include <opendnp3/master/ICommandProcessor.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3 {
/**
* Overriding virtual functions from interface class ICommandProcessor.
*/
    class PyICommandProcessor : public ICommandProcessor {
    public:
        /* Inherit the constructors */
        using ICommandProcessor::ICommandProcessor;

        /* Trampoline for ICommandProcessor virtual functions */
        void SelectAndOperate(CommandSet&& commands,
                              const CommandCallbackT& callback,
                              const TaskConfig& config = TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ICommandProcessor,
                SelectAndOperate,
                commands, callback, config
            );
        }
        void DirectOperate(CommandSet&& commands,
                           const CommandCallbackT& callback,
                           const TaskConfig& config = TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ICommandProcessor,
                DirectOperate,
                commands, callback, config
            );
        }
        template <class T>
        void SelectAndOperate(const T& command,
                              uint16_t index,
                              const CommandCallbackT& callback,
                              const TaskConfig& config = TaskConfig::Default()) {
            PYBIND11_OVERLOAD(
                void,
                ICommandProcessor,
                SelectAndOperate,
                command, index, callback, config
            );
        }
        template <class T>
        void DirectOperate(const T& command,
                           uint16_t index,
                           const CommandCallbackT& callback,
                           const TaskConfig& config = TaskConfig::Default()) {
            PYBIND11_OVERLOAD(
                void,
                ICommandProcessor,
                DirectOperate,
                command, index, callback, config
            );
        }
    };
}

void bind_ICommandProcessor(py::module &m)
{
    // ----- class: opendnp3::ICommandProcessor -----
    py::class_<opendnp3::ICommandProcessor,
               opendnp3::PyICommandProcessor,
               std::shared_ptr<opendnp3::ICommandProcessor>>cls(m, "ICommandProcessor",
        "Interface used to dispatch SELECT / OPERATE / DIRECT OPERATE from application code to a master.");

    cls.def(py::init<>());

    const char* selectAndOperate_singleCommand =
    "   Select and operate a single command. \n"
    ":param command: Command to operate \n"
    ":param index: in dex of the command \n"
    ":param callback: callback that will be invoked upon completion or failure \n"
    ":param config: optional configuration that controls normal callbacks and allows the user to be specified for SA";

    cls.def(
        "SelectAndOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::ControlRelayOutputBlock &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::SelectAndOperate<opendnp3::ControlRelayOutputBlock>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "SelectAndOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputInt16 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::SelectAndOperate<opendnp3::AnalogOutputInt16>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "SelectAndOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputInt32 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::SelectAndOperate<opendnp3::AnalogOutputInt32>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "SelectAndOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputFloat32 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::SelectAndOperate<opendnp3::AnalogOutputFloat32>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "SelectAndOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputDouble64 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::SelectAndOperate<opendnp3::AnalogOutputDouble64>,
        selectAndOperate_singleCommand,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    const char* directOperate_singleCommand =
    "   Direct operate a single command. \n"
    ":param command: Command to operate \n"
    ":param index: in dex of the command \n"
    ":param callback: callback that will be invoked upon completion or failure \n"
    ":param config: optional configuration that controls normal callbacks and allows the user to be specified for SA";

    cls.def(
        "DirectOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::ControlRelayOutputBlock &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::DirectOperate<opendnp3::ControlRelayOutputBlock>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "DirectOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputInt16 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::DirectOperate<opendnp3::AnalogOutputInt16>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "DirectOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputInt32 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::DirectOperate<opendnp3::AnalogOutputInt32>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "DirectOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputFloat32 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::DirectOperate<opendnp3::AnalogOutputFloat32>,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    cls.def(
        "DirectOperate",
        (void (opendnp3::ICommandProcessor::*)(const opendnp3::AnalogOutputDouble64 &,
                                               uint16_t,
                                               const opendnp3::CommandCallbackT &,
                                               const opendnp3::TaskConfig &))
        &opendnp3::ICommandProcessor::DirectOperate<opendnp3::AnalogOutputDouble64>,
        directOperate_singleCommand,
        py::arg("command"), py::arg("index"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    const char* selectAndOperate_commandSet =
	"   Select and operate a set of commands. \n"
	":param commands: Set of command headers \n"
	":param callback: callback that will be invoked upon completion or failure \n"
	":param config: optional configuration that controls normal callbacks and allows the user to be specified for SA";

    cls.def(
        "SelectAndOperate",
        [](opendnp3::ICommandProcessor &self,
           opendnp3::CommandSet& commands,
           const opendnp3::CommandCallbackT& callback,
           const opendnp3::TaskConfig& config) -> void {
            return self.SelectAndOperate(std::move(commands), callback, config);
        },
        selectAndOperate_commandSet,
        py::arg("commands"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );

    const char* directOperate_commandSet =
    "   Direct operate a set of commands. \n"
    ":param commands: Set of command headers \n"
    ":param callback: callback that will be invoked upon completion or failure \n"
    ":param config: optional configuration that controls normal callbacks and allows the user to be specified for SA";

    cls.def(
        "DirectOperate",
        [](opendnp3::ICommandProcessor &self,
           opendnp3::CommandSet& commands,
           const opendnp3::CommandCallbackT& callback,
           const opendnp3::TaskConfig& config) -> void {
            return self.DirectOperate(std::move(commands), callback, config);
        },
        directOperate_commandSet,
        py::arg("commands"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
    );
}

// @todo This code is a work-around for pybind11 issue related to 'const ref' arguments. However,
// it is seg faulting on the callback.  For now, the workaround is to reply on the pybind11 patch
// that ignores the copy constructor/non-copyable error and seems to work without issue.
//
//    cls.def(
//            "DirectOperate",
//            [](opendnp3::ICommandProcessor &self,
//               opendnp3::CommandSet& commands,
//               py::function callback,
//               const opendnp3::TaskConfig& config) {
//                return self.DirectOperate(
//                    std::move(commands),
//                    [callback](const opendnp3::ICommandTaskResult& result) -> void {
//                        std::cout << "In lambda callback" << std::endl ;
//                        auto py_result = py::cast(result, py::return_value_policy::reference);
//                        callback(py_result);
//                    },
//                    config
//                );
//            },
//            directOperate_commandSet,
//            py::call_guard<py::gil_scoped_release>(),
//            py::arg("commands"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default(),
//            py::return_value_policy::reference
//        );
//}

#endif // PYDNP3_OPENDNP3
#endif
