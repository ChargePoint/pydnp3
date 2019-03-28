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

#ifndef PYDNP3_ASIODNP3_ICHANNELLISTENER_H
#define PYDNP3_ASIODNP3_ICHANNELLISTENER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/IChannelListener.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class IChannelListener.
*/
    class PyIChannelListener : public IChannelListener
    {
    public:
        /* Inherit the constructors */
        using IChannelListener::IChannelListener;

        /* Trampoline for IChannelListener virtual functions */
        void OnStateChange(opendnp3::ChannelState state) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IChannelListener,
                OnStateChange,
                state
            );
        }
    };
}

void bind_IChannelListener(py::module &m)
{
    // ----- class: asiodnp3::IChannelListener -----
    py::class_<asiodnp3::IChannelListener,
               asiodnp3::PyIChannelListener,
               std::shared_ptr<asiodnp3::IChannelListener>>(m, "IChannelListener",
        "Callback interface for receiving information about a running channel.")

        .def(py::init<>())

        .def(
            "OnStateChange",
            &asiodnp3::IChannelListener::OnStateChange,
            "Receive callbacks for state transitions on the channels executor.",
            py::arg("state")
        );
}

#endif // PYDNP3_ASIODNP3
#endif
