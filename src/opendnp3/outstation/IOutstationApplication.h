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

#ifndef PYDNP3_OPENDNP3_OUTSTATION_IOUTSTATIONAPPLICATION_H
#define PYDNP3_OPENDNP3_OUTSTATION_IOUTSTATIONAPPLICATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/outstation/IOutstationApplication.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

namespace opendnp3
{
/**
* Overriding virtual functions from interface class IOutstationApplication.
*/
    class PyIOutstationApplication : public IOutstationApplication
    {
    public:
        /* Inherit the constructors */
        using IOutstationApplication::IOutstationApplication;

        /* Trampoline for IOutstationApplication virtual functions */
        bool SupportsWriteAbsoluteTime() override {
            PYBIND11_OVERLOAD(
                bool,
                IOutstationApplication,
                SupportsWriteAbsoluteTime,
            );
        }
        bool WriteAbsoluteTime(const openpal::UTCTimestamp& timestamp) override {
            PYBIND11_OVERLOAD(
            bool,
            IOutstationApplication,
            WriteAbsoluteTime,
            timestamp
            );
        }
        bool SupportsWriteTimeAndInterval() override {
            PYBIND11_OVERLOAD(
                bool,
                IOutstationApplication,
                SupportsWriteTimeAndInterval,
            );
        }
        bool WriteTimeAndInterval(const ICollection<Indexed<TimeAndInterval>>& values) override {
            PYBIND11_OVERLOAD(
                bool,
                IOutstationApplication,
                WriteTimeAndInterval,
                values
            );
        }
        bool SupportsAssignClass() override {
            PYBIND11_OVERLOAD(
                bool,
                IOutstationApplication,
                SupportsAssignClass,
            );
        }
        void RecordClassAssignment(AssignClassType type, PointClass clazz, uint16_t start, uint16_t stop) override {
            PYBIND11_OVERLOAD(
                void,
                IOutstationApplication,
                RecordClassAssignment,
                type, clazz, start, stop
            );
        }
        ApplicationIIN GetApplicationIIN() const override {
            PYBIND11_OVERLOAD(
                ApplicationIIN,
                IOutstationApplication,
                GetApplicationIIN,
            );
        }
        RestartMode ColdRestartSupport() const override {
            PYBIND11_OVERLOAD(
                RestartMode,
                IOutstationApplication,
                ColdRestartSupport,
            );
        }
        RestartMode WarmRestartSupport() const override {
            PYBIND11_OVERLOAD(
                RestartMode,
                IOutstationApplication,
                WarmRestartSupport,
            );
        }
        uint16_t ColdRestart() override {
            PYBIND11_OVERLOAD(
                uint16_t,
                IOutstationApplication,
                ColdRestart,
            );
        }
        uint16_t WarmRestart() override {
            PYBIND11_OVERLOAD(
                uint16_t,
                IOutstationApplication,
                WarmRestart,
            );
        }

        /* Trampoline for ILinkListener virtual functions */
        void OnStateChange(LinkStatus value) override {
            PYBIND11_OVERLOAD(
                void,
                IOutstationApplication,
                OnStateChange,
                value
            );
        }
        void OnKeepAliveInitiated() override {
            PYBIND11_OVERLOAD(
                void,
                IOutstationApplication,
                OnKeepAliveInitiated,
            );
        }
        void OnKeepAliveFailure() override {
            PYBIND11_OVERLOAD(
                void,
                IOutstationApplication,
                OnKeepAliveFailure,
            );
        }
        void OnKeepAliveSuccess() override {
            PYBIND11_OVERLOAD(
                void,
                IOutstationApplication,
                OnKeepAliveSuccess,
            );
        }
    };
}

void bind_IOutstationApplication(py::module &m)
{
    // ----- class: opendnp3::IOutstationApplication -----
    py::class_<opendnp3::IOutstationApplication,
               opendnp3::PyIOutstationApplication,
               opendnp3::ILinkListener,
               std::shared_ptr<opendnp3::IOutstationApplication>>(m, "IOutstationApplication",
        "Interface for all outstation application callback info except for control requests.")

        .def(py::init<>())

        .def(
            "SupportsWriteAbsoluteTime",
            &opendnp3::IOutstationApplication::SupportsWriteAbsoluteTime,
            "Queries whether the the outstation supports absolute time writes. \n"
            "If this function returns false, WriteAbsoluteTime will never be called and the outstation will return "
            "IIN 2.1 (FUNC_NOT_SUPPORTED)."
        )

        .def(
            "WriteAbsoluteTime",
            &opendnp3::IOutstationApplication::WriteAbsoluteTime,
            "Write the time to outstation, only called if SupportsWriteAbsoluteTime return true. \n"
            "Return boolean value indicating if the time value supplied was accepted. Returning false will cause "
            "the outstation to set IIN 2.3 (PARAM_ERROR) in its response. \n"
            "The outstation should clear its NEED_TIME field when handling this response.",
            py::arg("timestamp")
        )

        .def(
            "SupportsWriteTimeAndInterval",
            &opendnp3::IOutstationApplication::SupportsWriteTimeAndInterval,
            "Queries whether the outstation supports the writing of TimeAndInterval. \n"
            "If this function returns false, WriteTimeAndInterval will never be called and the outstation will "
            "return IIN 2.1 (FUNC_NOT_SUPPORTED) when it receives this request."
        )

        .def(
            "WriteTimeAndInterval",
            &opendnp3::IOutstationApplication::WriteTimeAndInterval,
            "Write one or more TimeAndInterval values. Only called if SupportsWriteTimeAndInterval returns true. \n"
            "The outstation application code is reponsible for updating TimeAndInterval values in the database if "
            "this behavior is desired. \n"
            "Return boolean value indicating if the values supplied were accepted. Returning false will cause "
            "the outstation to set IIN 2.3 (PARAM_ERROR) in its response.",
            py::arg("values")
        )

        .def(
            "SupportsAssignClass",
            &opendnp3::IOutstationApplication::SupportsAssignClass,
            "True if the outstation supports the assign class function code. \n"
            "If this function returns false, the assign class callbacks will never be called and the outstation "
            "will return IIN 2.1 (FUNC_NOT_SUPPORTED) when it receives this function code."
        )

        .def(
            "RecordClassAssignment",
            &opendnp3::IOutstationApplication::RecordClassAssignment,
            "   Called if SupportsAssignClass returns true. \n"
            "   The type and range are pre-validated against the outstation's database and class assignments are "
            "automatically applied internally. \n"
            "   This callback allows user code to persist the changes to non-volatile memory."
            ":type start: unsigned short \n"
            ":type stop: unsigned short",
            py::arg("type"), py::arg("clazz"), py::arg("start"), py::arg("stop")
        )

        .def(
            "GetApplicationIIN",
            &opendnp3::IOutstationApplication::GetApplicationIIN,
            "Returns the application-controlled IIN field."
        )

        .def(
            "ColdRestartSupport",
            &opendnp3::IOutstationApplication::ColdRestartSupport,
            "Query the outstation for the cold restart mode it supports."
        )

        .def(
            "WarmRestartSupport",
            &opendnp3::IOutstationApplication::WarmRestartSupport,
            "Query the outstation for the warm restart mode it supports."
        )

        .def(
            "ColdRestart",
            &opendnp3::IOutstationApplication::ColdRestart,
            "The outstation should perform a complete restart. \n"
            "(See the DNP3 specification for a complete descripton of normal behavior.) \n"
            "Return number of seconds or milliseconds until restart is complete. The value is interpreted based on "
            "the Restart Mode returned from ColdRestartSupport()."
        )

        .def(
            "WarmRestart",
            &opendnp3::IOutstationApplication::WarmRestart,
            "The outstation should perform a partial restart of only the DNP3 application. \n"
            "(See the DNP3 specification for a complete descripton of normal behavior.) \n"
            "Return number of seconds or milliseconds until restart is complete. The value is interpreted based on "
            "the Restart Mode returned from WarmRestartSupport()."
        );

    // ----- class: DefaultOutstationApplication -----
    py::class_<opendnp3::DefaultOutstationApplication,
               opendnp3::IOutstationApplication,
               std::shared_ptr<opendnp3::DefaultOutstationApplication>>(m, "DefaultOutstationApplication",
        "A singleton with default setting useful for examples.")

        .def(py::init<>())

        .def_static(
            "Create",
            &opendnp3::DefaultOutstationApplication::Create,
            ":return: shared_ptr to opendnp3.IOutstationApplication"
        );
}

#endif // PYDNP3_OPENDNP3
#endif
