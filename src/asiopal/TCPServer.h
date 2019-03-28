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

#ifndef PYDNP3_ASIOPAL_TCPSERVER_H
#define PYDNP3_ASIOPAL_TCPSERVER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiopal/TCPServer.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal
{
/**
* Overriding virtual functions from interface class TCPServer.
*/
    class PyTCPServer : public TCPServer
    {
    public:
        /* Inherit the constructors */
        using TCPServer::TCPServer;

        /* Trampoline for TCPServer virtual functions */
        void OnShutdown() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                TCPServer,
                OnShutdown,
            );
        }
        void AcceptConnection(uint64_t sessionid,
                              const std::shared_ptr<Executor>& executor,
                              asio::ip::tcp::socket socket) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                TCPServer,
                AcceptConnection,
                sessionid, executor, socket
            );
        }
    };
}

void bind_TCPServer(py::module &m)
{
    // ----- class: asiopal::TCPServer -----
    py::class_<asiopal::TCPServer,
               asiopal::PyTCPServer,
               asiopal::IListener,
               std::shared_ptr<asiopal::TCPServer>>(m, "TCPServer",
        "Binds and listens on an IPv4 TCP port. \n"
        "Meant to be used exclusively as a shared_ptr.")

        .def(
            py::init<const openpal::Logger&,
                     const std::shared_ptr<asiopal::Executor>&,
                     const asiopal::IPEndpoint&,
                     std::error_code&>(),
            py::arg("logger"), py::arg("executor"), py::arg("endpoint"), py::arg("ec")
        )

        .def(
            "Shutdown",
            &asiopal::TCPServer::Shutdown,
            "Implement IListener."
        );
}

#endif // PYDNP3_ASIOPAL
#endif
