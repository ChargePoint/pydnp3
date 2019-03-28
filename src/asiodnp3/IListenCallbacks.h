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

#ifndef PYDNP3_ASIODNP3_ILISTENCALLBACKS_H
#define PYDNP3_ASIODNP3_ILISTENCALLBACKS_H
#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/IListenCallbacks.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class IListenCallbacks.
*/
    class PyIListenCallbacks : public IListenCallbacks
    {
    public:
        /* Inherit the constructors */
        using IListenCallbacks::IListenCallbacks;

        /* Trampoline for IListenCallbacks virtual functions */
        bool AcceptConnection(uint64_t sessionid, const std::string& ipaddress) override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IListenCallbacks,
                AcceptConnection,
                sessionid, ipaddress
            );
        }
        bool AcceptCertificate(uint64_t sessionid, const X509Info& info) override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IListenCallbacks,
                AcceptCertificate,
                sessionid, info
            );
        }
        openpal::TimeDuration GetFirstFrameTimeout() override {
            PYBIND11_OVERLOAD_PURE(
                openpal::TimeDuration,
                IListenCallbacks,
                GetFirstFrameTimeout,
            );
        }
        void OnFirstFrame(uint64_t sessionid,
                          const opendnp3::LinkHeaderFields& header,
                          ISessionAcceptor& acceptor) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IListenCallbacks,
                OnFirstFrame,
                sessionid, header, acceptor
            );
        }
        void OnConnectionClose(uint64_t sessionid, const std::shared_ptr<IMasterSession>& session) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IListenCallbacks,
                OnConnectionClose,
                sessionid, session
            );
        }
        void OnCertificateError(uint64_t sessionid, const X509Info& info, int error) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IListenCallbacks,
                OnCertificateError,
                sessionid, info, error
            )
        }
    };
}

void bind_IListenCallbacks(py::module &m)
{
    // ----- class: asiodnp3::IListenCallbacks -----
    py::class_<asiodnp3::IListenCallbacks, asiodnp3::PyIListenCallbacks>(m, "IListenCallbacks",
        "Callback interface invoked when a new connection is accepted.")

        .def(py::init<>())

        .def(
            "AcceptConnection",
            &asiodnp3::IListenCallbacks::AcceptConnection,
            "   Ask user code if the following connection should be accepted. \n"
            "   If true, the connection is accepted and a link frame parser is created to handle incoming frame data. \n"
            ":param sessionid: Incrementing id used to uniquely identify the session \n"
            ":param ipaddress: The IP address of the connecting host. Can optionally be used for connection filtering \n"
            ":type sessionid: unsigned long",
            py::arg("sessionid"), py::arg("ipaddress")
        )

        .def(
            "AcceptCertificate",
            &asiodnp3::IListenCallbacks::AcceptCertificate,
            "   Ask user code if the following preverified certificate should be accepted. \n"
            "   If true, the certificate should be accepted, false otherwise. \n"
            ":param sessionid: Incrementing id used to uniquely identify the session \n"
            ":param info: Information from the x509 certificate \n"
            ":type sessionid: unsigned long",
            py::arg("sessionid"), py::arg("info")
        )

        .def(
            "GetFirstFrameTimeout",
            &asiodnp3::IListenCallbacks::GetFirstFrameTimeout,
            ":return: the amount of time the session should wait for the first frame."
        )

        .def(
            "OnFirstFrame",
            &asiodnp3::IListenCallbacks::OnFirstFrame,
            "   Called when the first link-layer frame is received for a session. \n"
            ":type sessionid: unsigned long",
            py::arg("sessionid"), py::arg("header"), py::arg("acceptor")
        )

        .def(
            "OnConnectionClose",
            &asiodnp3::IListenCallbacks::OnConnectionClose,
            "   Called when a socket closes. \n"
            ":param sessionid: Incrementing id used to uniquely identify the session \n"
            ":param session: Possibly NULL shared_ptr to the master session if it was created \n"
            ":type sessionid: unsigned long",
            py::arg("sessionid"), py::arg("session")
        )

        .def(
            "OnCertificateError",
            &asiodnp3::IListenCallbacks::OnCertificateError,
            "   Called when a certificate fails verification. \n"
            ":param sessionid: Incrementing id used to uniquely identify the session \n"
            ":param info: Information from the x509 certificate \n"
            ":param error: Error code with reason for failed verification \n"
            ":type sessionid: unsigned long",
            py::arg("sessionid"), py::arg("info"), py::arg("error")
        );
}

#endif // PYDNP3_ASIODNP3
#endif
