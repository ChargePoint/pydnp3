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

#ifndef PYDNP3_ASIODNP3_PRINTINGSOEHANDLER_H
#define PYDNP3_ASIODNP3_PRINTINGSOEHANDLER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/PrintingSOEHandler.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_PrintingSOEHandler(py::module &m)
{
    // ----- class: asiodnp3::PrintingSOEHandler -----
    py::class_<asiodnp3::PrintingSOEHandler,
               opendnp3::ISOEHandler,
               std::shared_ptr<asiodnp3::PrintingSOEHandler>>(m, "PrintingSOEHandler",
        "ISOEHandler singleton that prints to the console.")

        .def(py::init<>())

        .def_static(
            "Create",
            &asiodnp3::PrintingSOEHandler::Create,
            ":return: shared_ptr to opendnp3.ISOEHandler"
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                                    const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Binary>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                            const opendnp3::ICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                                    const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Analog>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                                    const opendnp3::ICollection<opendnp3::Indexed<opendnp3::Counter>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                              const opendnp3::ICollection<opendnp3::Indexed<opendnp3::FrozenCounter>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                         const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryOutputStatus>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                         const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogOutputStatus>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                                const opendnp3::ICollection<opendnp3::Indexed<opendnp3::OctetString>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                            const opendnp3::ICollection<opendnp3::Indexed<opendnp3::TimeAndInterval>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                         const opendnp3::ICollection<opendnp3::Indexed<opendnp3::BinaryCommandEvent>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                         const opendnp3::ICollection<opendnp3::Indexed<opendnp3::AnalogCommandEvent>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                               const opendnp3::ICollection<opendnp3::Indexed<opendnp3::SecurityStat>>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        )

        .def(
            "Process",
            (void (asiodnp3::PrintingSOEHandler::*)(const opendnp3::HeaderInfo&,
                                                    const opendnp3::ICollection<opendnp3::DNPTime>&))
            &asiodnp3::PrintingSOEHandler::Process,
            py::arg("info"), py::arg("values")
        );
}

#endif // PYDNP3_ASIODNP3
#endif
