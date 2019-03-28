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

#ifndef PYDNP3_ASIODNP3_IMASTERSESSION_H
#define PYDNP3_ASIODNP3_IMASTERSESSION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/IMasterSession.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class IMasterSession.
*/
    class PyIMasterSession : public IMasterSession
    {
    public:
        /* Inherit the constructors */
        using IMasterSession::IMasterSession;

        /* Trampoline for IMasterSession virtual functions */
        opendnp3::StackStatistics GetStackStatistics() override {
            PYBIND11_OVERLOAD_PURE(
                opendnp3::StackStatistics,
                IMasterSession,
                GetStackStatistics,
            );
        }
        void BeginShutdown() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterSession,
                BeginShutdown,
            );
        }

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
            PYBIND11_OVERLOAD(
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
            PYBIND11_OVERLOAD(
                void,
                IMasterOperations,
                DirectOperate,
                command, index, callback, config
            );
        }
    };
}

void bind_IMasterSession(py::module &m)
{
    // ----- class: asiodnp3::IMasterSession -----
    py::class_<asiodnp3::IMasterSession,
               asiodnp3::PyIMasterSession,
               asiodnp3::IMasterOperations,
               std::shared_ptr<asiodnp3::IMasterSession>>(m, "IMasterSession",
        "Interface that represents an emphemeral master session.")

        .def(py::init<>())

        .def(
            "GetStackStatistics",
            &asiodnp3::IMasterSession::GetStackStatistics
        )

        .def(
            "BeginShutdown",
            &asiodnp3::IMasterSession::BeginShutdown
        );
}

#endif // PYDNP3_ASIODNP3
#endif
