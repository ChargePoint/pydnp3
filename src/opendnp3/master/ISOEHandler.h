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

#ifndef PYDNP3_OPENDNP3_MASTER_ISOEHANDLER_H
#define PYDNP3_OPENDNP3_MASTER_ISOEHANDLER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/ISOEHandler.h>

#include "opendnp3/app/ITransactable.h"

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3
{
/**
* Overriding virtual functions from interface class ISOEHandler.
*/
    class PyISOEHandler : public ISOEHandler {
    public:
        /* Inherit the constructors */
        using ISOEHandler::ISOEHandler;

        /* Trampoline for ITransactable virtual functions */
        void Start() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Start,
            );
        }
        void End() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                End,
            );
        }

        /* Trampoline for ISOEHandler virtual functions */
        void Process(const HeaderInfo& info, const ICollection<Indexed<Binary>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<DoubleBitBinary>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<Analog>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<Counter>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<FrozenCounter>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<BinaryOutputStatus>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<AnalogOutputStatus>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<OctetString>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<TimeAndInterval>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<BinaryCommandEvent>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<AnalogCommandEvent>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<Indexed<SecurityStat>>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }
        void Process(const HeaderInfo& info, const ICollection<DNPTime>& values) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ISOEHandler,
                Process,
                info, &values
            );
        }

    };
}

void bind_ISOEHandler(py::module &m)
{
    // ----- class: opendnp3::ISOEHandler ------
    py::class_<opendnp3::ISOEHandler,
               opendnp3::ITransactable,
               opendnp3::PyISOEHandler,
               std::shared_ptr<opendnp3::ISOEHandler>>(m, "ISOEHandler",
        "An interface for Sequence-Of-Events (SOE) callbacks from a master stack to the application layer. \n"
        "A call is made to the appropriate member method for every measurement value in an ASDU. \n"
        "The HeaderInfo class provides information about the object header associated with the value.")

        .def(py::init<>())

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Analog>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Counter>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::FrozenCounter>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryOutputStatus>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputStatus>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::OctetString>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::TimeAndInterval>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryCommandEvent>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogCommandEvent>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::Indexed<opendnp3::SecurityStat>>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (opendnp3::ISOEHandler::*)(const opendnp3::HeaderInfo&,
                                             const opendnp3::ICollection<opendnp3::DNPTime>&))
            &opendnp3::ISOEHandler::Process,
            py::arg("info"), py::arg("values")
        );
}

#endif // PYDNP3_OPENDNP3
#endif
