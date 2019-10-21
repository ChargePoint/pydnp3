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

#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>

#include <pybind11/pybind11.h>

#include "asiopal/AllHeaders.h"

namespace py = pybind11;

void init_asiopal(py::module &asiopal)
{
    // -------------------- PYDNP3.ASIOPAL --------------------
    bind_SerialTypes(asiopal);
    bind_ASIOSerialHelpers(asiopal);
    bind_IOpenDelayStrategy(asiopal);
    bind_ChannelRetry(asiopal);
    bind_IO(asiopal);
    bind_SteadyClock(asiopal);
    bind_Executor(asiopal);
    bind_IChannelCallbacks(asiopal);
    bind_IAsyncChannel(asiopal);
    bind_IResourceManager(asiopal);             // GIL release: Shutdown
    bind_IListener(asiopal);
    bind_IPEndpoint(asiopal);
    bind_LoggingConnectionCondition(asiopal);
    bind_ResourceManager(asiopal);
    bind_SerialChannel(asiopal);
    bind_SocketChannel(asiopal);                //@todo: init, Create (error: call to implicitly-deleted copy constructor)
    bind_SocketHelpers(asiopal);
    bind_Synchronized(asiopal);
    bind_TCPClient(asiopal);
    bind_TCPServer(asiopal);
    bind_TLSConfig(asiopal);
    bind_ThreadPool(asiopal);
    bind_TimeConversions(asiopal);
    bind_Timer(asiopal);
    bind_UTCTimeSource(asiopal);
}