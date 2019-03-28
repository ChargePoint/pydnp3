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

#ifndef PYDNP3_OPENDNP3_LINK_ILINKLISTENER_H
#define PYDNP3_OPENDNP3_LINK_ILINKLISTENER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/link/ILinkListener.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3
{
/**
* Overriding virtual functions from interface class ILinkListener.
*/
    class PyILinkListener : public ILinkListener
    {
    public:
        /* Inherit the constructors */
        using ILinkListener::ILinkListener;

        /* Trampoline for ILinkListener virtual functions */
        void OnStateChange(LinkStatus value) override {
            PYBIND11_OVERLOAD(
                void,
                ILinkListener,
                OnStateChange,
                value
            );
        }
        void OnKeepAliveInitiated() override {
            PYBIND11_OVERLOAD(
                void,
                ILinkListener,
                OnKeepAliveInitiated,
            );
        }
        void OnKeepAliveFailure() override {
            PYBIND11_OVERLOAD(
                void,
                ILinkListener,
                OnKeepAliveFailure,
            );
        }
        void OnKeepAliveSuccess() override {
            PYBIND11_OVERLOAD(
                void,
                ILinkListener,
                OnKeepAliveSuccess,
            );
        }
    };
}

void bind_ILinkListener(py::module &m)
{
    // ----- class: opendnp3::ILinkListener -----
    py::class_<opendnp3::ILinkListener,
               opendnp3::PyILinkListener,
               std::shared_ptr<opendnp3::ILinkListener>>(m, "ILinkListener",
        "Various optional callbacks that can be received for the link layer.")

        .def(py::init<>())

        .def(
            "OnStateChange",
            &opendnp3::ILinkListener::OnStateChange,
            "Called when a the reset/unreset status of the link layer changes.",
            py::arg("value")
        )

        .def(
            "OnKeepAliveInitiated",
            &opendnp3::ILinkListener::OnKeepAliveInitiated,
            "Called when the keep alive timer elapses. This doesn't denote a keep-alive failure, "
            "it's just a notification."
        )

        .def(
            "OnKeepAliveFailure",
            &opendnp3::ILinkListener::OnKeepAliveFailure,
            "Called when a keep alive message (request link status) receives no response."
        )

        .def(
            "OnKeepAliveSuccess",
            &opendnp3::ILinkListener::OnKeepAliveSuccess,
            "Called when a keep alive message receives a valid response."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
