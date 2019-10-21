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

#ifndef PYDNP3_OPENPAL_CHANNEL_IPHYSICALLAYER_H
#define PYDNP3_OPENPAL_CHANNEL_IPHYSICALLAYER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/channel/IPhysicalLayer.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

namespace openpal
{
/**
* Overriding virtual functions from interface class IChannelState.
*/
    class PyIChannelState : public IChannelState
    {
    public:
        /* Inherit the constructors */
        using IChannelState::IChannelState;

        /* Trampoline for IChannelState virtual functions */
        bool CanOpen() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                CanOpen,
            );
        }
        bool CanClose() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                CanClose,
            );
        }
        bool CanRead() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                CanRead,
            );
        }
        bool CanWrite() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                CanWrite,
            );
        }
        bool IsReading() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                IsReading,
            );
        }
        bool IsWriting() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                IsWriting,
            );
        }
        bool IsClosing() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                IsClosing,
            );
        }
        bool IsClosed() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                IsClosed,
            );
        }
        bool IsOpening() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                IsOpening,
            );
        }
        bool IsOpen() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IChannelState,
                IsOpen,
            );
        }
    };

/**
* Overriding virtual functions from interface class PyIPhysicalLayer.
*/
    class PyIPhysicalLayer : public IPhysicalLayer
    {
        /* Inherit the constructors */
        using IPhysicalLayer::IPhysicalLayer;

        /* Trampoline for PyIPhysicalLayer virtual functions */
        void BeginOpen() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IPhysicalLayer,
                BeginOpen,
            );
        }
        void BeginClose() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IPhysicalLayer,
                BeginClose,
            );
        }
        void BeginWrite(const RSlice& arBuffer) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IPhysicalLayer,
                BeginWrite,
                arBuffer
            );
        }
        void BeginRead(WSlice& arBuffer) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IPhysicalLayer,
                BeginRead,
                arBuffer
            );
        }
        void SetHandler(IPhysicalLayerCallbacks* apHandler) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IPhysicalLayer,
                SetHandler,
                apHandler
            );
        }

        /* Trampoline for IChannelState virtual functions */
        bool CanOpen() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                CanOpen,
            );
        }
        bool CanClose() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                CanClose,
            );
        }
        bool CanRead() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                CanRead,
            );
        }
        bool CanWrite() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                CanWrite,
            );
        }
        bool IsReading() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                IsReading,
            );
        }
        bool IsWriting() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                IsWriting,
            );
        }
        bool IsClosing() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                IsClosing,
            );
        }
        bool IsClosed() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                IsClosed,
            );
        }
        bool IsOpening() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                IsOpening,
            );
        }
        bool IsOpen() const override {
            PYBIND11_OVERLOAD_PURE(
                bool,
                IPhysicalLayer,
                IsOpen,
            );
        }
    };
}

void bind_IPhysicalLayer(py::module &m)
{
    // ----- class: openpal::IChannelState -----
    py::class_<openpal::IChannelState, openpal::PyIChannelState>(m, "IChannelState")

        .def(py::init<>())

        .def(
            "CanOpen",
            &openpal::IChannelState::CanOpen
        )

        .def(
            "CanClose",
            &openpal::IChannelState::CanClose
        )

        .def(
            "CanRead",
            &openpal::IChannelState::CanRead
        );

        .def(
            "CanWrite",
            &openpal::IChannelState::CanWrite
        )

        .def(
            "IsReading",
            &openpal::IChannelState::IsReading,
            ":return: True if the layer is performing an async read"
        )

        .def(
            "IsWriting",
            &openpal::IChannelState::IsWriting,
            ":return: True if the layer is performing an async write"
        )

        .def(
            "IsClosing",
            &openpal::IChannelState::IsClosing,
            ":return: True if the layer is performing an asynchronously closing"
        )

        .def(
            "IsClosed",
            &openpal::IChannelState::IsClosed,
            ":return: True if the layer is in the closed with no other activity"
        )

        .def(
            "IsOpening",
            &openpal::IChannelState::IsOpening,
            ":return: True if the layer is performing an asynchronously opening"
        )

        .def(
            "IsOpen",
            &openpal::IChannelState::IsOpen,
            ":return: True if the layer is open for read/write"
        );

    // ----- class: openpal::IPhysicalLayer -----
    py::class_<openpal::IPhysicalLayer, openpal::PyIPhysicalLayer, openpal::IChannelState>(m, "IChannelState",
        "Defines an asynchronous interface for serial/tcp/?")

        .def(py::init<>())

        .def(
            "SetChannelStatistics",
            &openpal::IPhysicalLayer::SetChannelStatistics,
            "Tell the layer where to update its channel statistics.",
            py::arg("pChannelStatistics")
        )

        .def(
            "BeginOpen",
            &openpal::IPhysicalLayer::BeginOpen,
            "Starts an open operation. \n"
            "Callback is either IHandler::OnLowerLayerUp or IHandler::OnOpenFailure."
        )

        .def(
            "BeginClose",
            &openpal::IPhysicalLayer::BeginClose,
            "Starts a close operation. \n"
            "Callback is IHandler::OnLowerLayerDown. Callback occurs after all hronous operations have occured. "
            "If the user code has an outstanding read or write, those handlers will not be called."
        )

        .def(
            "BeginWrite",
            &openpal::IPhysicalLayer::BeginWrite,
            "   Starts a send operation. \n"
            "   Callback is IHandler::OnSendSuccess or a failure will result in the layer closing. \n"
            ":param arBuffer: The buffer from which the write operation will write data. The underlying buffer must "
            "remain available until the write callback or close occurs.",
            py::arg("arBuffer")
        )

        .def(
            "BeginRead",
            &openpal::IPhysicalLayer::BeginRead,
            "   Starts a read operation. \n"
            "   Use SetHandler to provide a callback that is called by OnReceive(const RSlice&) or a failure will "
            "result in the layer closing. \n"
            ":param arBuffer: Read into the underlying buffer defined by the wrapper. The underlying buffer must "
            "remain available until the read callback",
            py::arg("arBuffer")
        )

        .def(
            "SetHandler",
            &openpal::IPhysicalLayer::SetHandler,
            "   Set the handler interface for callbacks. A read interface has been added so the max size is no "
            "longer required."
            ":param apHandler: Class that will process asynchronous callbacks",
            py::arg("apHandler")
        );
}

#endif // PYDNP3_OPENPAL
#endif
