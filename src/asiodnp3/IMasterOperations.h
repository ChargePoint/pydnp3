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

#ifndef PYDNP3_ASIODNP3_IMASTEROPERATIONS_H
#define PYDNP3_ASIODNP3_IMASTEROPERATIONS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/IMasterOperations.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class IMasterOperations.
*/
    class PyIMasterOperations : public IMasterOperations
    {
    public:
        /* Inherit the constructors */
        using IMasterOperations::IMasterOperations;

        /* Trampoline for IMasterOperations virtual functions */
        void SetLogFilters(const openpal::LogFilters& filters) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                SetLogFilters,
                filters
            );
        }
        std::shared_ptr<IMasterScan> AddScan(openpal::TimeDuration period,
                                             const std::vector<opendnp3::Header>& headers,
                                             const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                std::shared_ptr<IMasterScan>,
                IMasterOperations,
                AddScan,
                period, headers, config
            );
        }
        std::shared_ptr<IMasterScan> AddAllObjectsScan(opendnp3::GroupVariationID gvId,
                                                       openpal::TimeDuration period,
                                                       const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                std::shared_ptr<IMasterScan>,
                IMasterOperations,
                AddAllObjectsScan,
                gvId, period, config
            );
        }
        std::shared_ptr<IMasterScan> AddClassScan(const opendnp3::ClassField& field,
                                                  openpal::TimeDuration period,
                                                  const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                std::shared_ptr<IMasterScan>,
                IMasterOperations,
                AddClassScan,
                field, period, config
            );
        }
        std::shared_ptr<IMasterScan> AddRangeScan(opendnp3::GroupVariationID gvId,
                                                  uint16_t start,
                                                  uint16_t stop,
                                                  openpal::TimeDuration period,
                                                  const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                std::shared_ptr<IMasterScan>,
                IMasterOperations,
                AddRangeScan,
                gvId, start, stop, period, config
            );
        }
        void Scan(const std::vector<opendnp3::Header>& headers,
                  const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                Scan,
                headers, config
            );
        }
        void ScanAllObjects(opendnp3::GroupVariationID gvId,
                            const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                ScanAllObjects,
                gvId, config
            );
        }
        void ScanClasses(const opendnp3::ClassField& field,
                         const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                ScanClasses,
                field, config
            );
        }
        void ScanRange(opendnp3::GroupVariationID gvId,
                       uint16_t start,
                       uint16_t stop,
                       const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                ScanRange,
                gvId, start, stop, config
            );
        }
        void Write(const opendnp3::TimeAndInterval& value,
                   uint16_t index,
                   const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                Write,
                value, index, config
            );
        }
        void Restart(opendnp3::RestartType op,
                     const opendnp3::RestartOperationCallbackT& callback,
                     opendnp3::TaskConfig config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                Restart,
                op, callback, config
            );
        }
        void PerformFunction(const std::string& name,
                             opendnp3::FunctionCode func,
                             const std::vector<opendnp3::Header>& headers,
                             const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                PerformFunction,
                name, func, headers, config
            );
        }

        /* Trampoline for ICommandProcessor virtual functions */
        void SelectAndOperate(opendnp3::CommandSet&& commands,
                              const opendnp3::CommandCallbackT& callback,
                              const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                SelectAndOperate,
                commands, callback, config
            );
        }
        void DirectOperate(opendnp3::CommandSet&& commands,
                           const opendnp3::CommandCallbackT& callback,
                           const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                DirectOperate,
                commands, callback, config
            );
        }
        template <class T>
        void SelectAndOperate(const T& command,
                              uint16_t index,
                              const opendnp3::CommandCallbackT& callback,
                              const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                SelectAndOperate,
                command, index, callback, config
            );
        }
        template <class T>
        void DirectOperate(const T& command,
                           uint16_t index,
                           const opendnp3::CommandCallbackT& callback,
                           const opendnp3::TaskConfig& config = opendnp3::TaskConfig::Default()) {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterOperations,
                DirectOperate,
                command, index, callback, config
            );
        }
    };
}

void bind_IMasterOperations(py::module &m)
{
    // ----- class: asiodnp3::IMasterOperations -----
        py::class_<asiodnp3::IMasterOperations,
                   asiodnp3::PyIMasterOperations,
                   opendnp3::ICommandProcessor,
                   std::shared_ptr<asiodnp3::IMasterOperations>>(m, "IMasterOperations",
            "All the operations that the user can perform on a running master.")

        .def(py::init<>())

        .def(
            "SetLogFilters",
            &asiodnp3::IMasterOperations::SetLogFilters,
            ":param filters: Adjust the filters to this value",
            py::arg("filters")
        )

        .def(
            "AddScan",
            &asiodnp3::IMasterOperations::AddScan,
            "   Add a recurring user-defined scan from a vector of headers. \n"
            ":param config: defaults to opendnp3.TaskConfig.Default() \n"
            ":return: shared_ptr to asiodnp3.IMasterScan - a proxy class used to manipulate the scan",
            py::arg("period"), py::arg("headers"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "AddAllObjectsScan",
            &asiodnp3::IMasterOperations::AddAllObjectsScan,
            "   Add a scan that requests all objects using qualifier code 0x06. \n"
            ":param config: defaults to opendnp3.TaskConfig.Default() \n"
            ":return: shared_ptr to asiodnp3.IMasterScan - a proxy class used to manipulate the scan",
            py::arg("gvId"), py::arg("period"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "AddClassScan",
            &asiodnp3::IMasterOperations::AddClassScan,
            "   Add a class-based scan to the master. \n"
            ":param config: defaults to opendnp3.TaskConfig.Default() \n"
            ":return: shared_ptr to asiodnp3.IMasterScan - a proxy class used to manipulate the scan",
            py::arg("field"), py::arg("period"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "AddRangeScan",
            &asiodnp3::IMasterOperations::AddRangeScan,
            "   Add a start/stop (range) scan to the master. \n"
            ":param config: defaults to opendnp3.TaskConfig.Default() \n"
            ":return: shared_ptr to asiodnp3.IMasterScan - a proxy class used to manipulate the scan.",
            py::arg("gvId"), py::arg("start"), py::arg("stop"), py::arg("period"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "Scan",
            &asiodnp3::IMasterOperations::Scan,
            "   Initiate a single user defined scan via a vector of headers. \n"
            ":param config: defaults to opendnp3.TaskConfig.Default()",
            py::arg("headers"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "ScanAllObjects",
            &asiodnp3::IMasterOperations::ScanAllObjects,
            "   Initiate a single scan that requests all objects (0x06 qualifier code) for a certain group and variation. \n"
            ":param config: defaults to opendnp3.TaskConfig.Default()",
            py::arg("gvId"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "ScanClasses",
            &asiodnp3::IMasterOperations::ScanClasses,
            "   Initiate a single class-based scan. \n"
            ":param config: defaults to opendnp3.TaskConfig.Default()",
            py::arg("field"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "ScanRange",
            &asiodnp3::IMasterOperations::ScanRange,
            "   Initiate a single start/stop (range) scan \n"
            ":param config: defaults to opendnp3.TaskConfig.Default()",
            py::arg("gvId"), py::arg("start"), py::arg("stop"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "Write",
            &asiodnp3::IMasterOperations::Write,
            "   Write a time and interval object to a specific index \n"
            ":param config: defaults to opendnp3.TaskConfig.Default()",
            py::arg("value"), py::arg("index"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "Restart",
            &asiodnp3::IMasterOperations::Restart,
            "   Perform a cold or warm restart and get back the time-to-complete value \n"
            ":param config: defaults to opendnp3.TaskConfig.Default()",
            py::arg("op"), py::arg("callback"), py::arg("config") = opendnp3::TaskConfig::Default()
        )

        .def(
            "PerformFunction",
            &asiodnp3::IMasterOperations::PerformFunction,
            "   Perform any operation that requires just a function code \n"
            ":param config: defaults to opendnp3.TaskConfig.Default()",
            py::arg("name"), py::arg("func"), py::arg("headers"), py::arg("config") = opendnp3::TaskConfig::Default()
        );
}

#endif // PYDNP3_ASIODNP3
#endif
