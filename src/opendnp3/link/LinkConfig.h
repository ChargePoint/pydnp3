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

#ifndef PYDNP3_OPENDNP3_LINK_LINKCONFIG_H
#define PYDNP3_OPENDNP3_LINK_LINKCONFIG_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/link/LinkConfig.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_LinkConfig(py::module &m)
{
    // ----- struct: opendnp3::LinkConfig -----
    py::class_<opendnp3::LinkConfig>(m, "LinkConfig",
        "Configuration for the dnp3 link layer.")

        .def(
            py::init<bool, bool, uint32_t, uint16_t, uint16_t, openpal::TimeDuration, openpal::TimeDuration>(),
            ":type NumRetry: unsigned int \n"
            ":type LocalAddr: unsigned short \n"
            ":type RemoteAddr: unsigned short",
            py::arg("IsMaster"), py::arg("UseConfirms"), py::arg("NumRetry"), py::arg("LocalAddr"),
            py::arg("RemoteAddr"), py::arg("Timeout"), py::arg("KeepAliveTimeout")
        )

        .def(
            py::init<bool, bool>(),
            py::arg("IsMaster"), py::arg("UseConfirms")
        )

        .def_readwrite(
            "IsMaster",
            &opendnp3::LinkConfig::IsMaster,
            "The master/outstation bit set on all messages."
        )

        .def_readwrite(
            "UseConfirms",
            &opendnp3::LinkConfig::UseConfirms,
            "If true, the link layer will send data requesting confirmation."
        )

        .def_readwrite(
            "NumRetry",
            &opendnp3::LinkConfig::NumRetry,
            "   The number of retry attempts the link will attempt after the initial try. \n"
            ":type NumRetry: unsigned int"
        )

        .def_readwrite(
            "LocalAddr",
            &opendnp3::LinkConfig::LocalAddr,
            "   Dnp3 address of the local device. \n"
            ":type LocalAddr: unsigned short"
        )

        .def_readwrite(
            "RemoteAddr",
            &opendnp3::LinkConfig::RemoteAddr,
            "   Dnp3 address of the remote device. \n"
            ":type RemoteAddr: unsigned short"
        )

        .def_readwrite(
            "Timeout",
            &opendnp3::LinkConfig::Timeout,
            "The response timeout in milliseconds for confirmed requests."
        )

        .def_readwrite(
            "KeepAliveTimeout",
            &opendnp3::LinkConfig::KeepAliveTimeout,
            "The interval for keep-alive messages (link status requests) \n"
            "If set to TimeDuration::Max(), the keep-alive is disabled."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
