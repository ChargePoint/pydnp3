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

#include "asiodnp3/AllHeaders.h"

namespace py = pybind11;

void init_asiodnp3(py::module &asiodnp3)
{
    // -------------------- PYDNP3.OPENDNP3 --------------------
    bind_ConsoleLogger(asiodnp3);
    bind_IStack(asiodnp3);                      // GIL release: enable, disable
    bind_IMasterScan(asiodnp3);
    bind_IMasterOperations(asiodnp3);
    bind_IMaster(asiodnp3);
    bind_Updates(asiodnp3);
    bind_IOutstation(asiodnp3);
    bind_MasterStackConfig(asiodnp3);
    bind_DatabaseConfig(asiodnp3);
    bind_OutstationStackConfig(asiodnp3);
    bind_IChannel(asiodnp3);                    // GIL release: AddMaster, AddOutstation
    bind_IChannelListener(asiodnp3);
    bind_IMasterSession(asiodnp3);
    bind_ISessionAcceptor(asiodnp3);
    bind_X509Info(asiodnp3);
    bind_IListenCallbacks(asiodnp3);
    bind_DNP3Manager(asiodnp3);                 // GIL release: AddTCPClient, AddTCPServer, Shutdown
    bind_PrintingSOEHandler(asiodnp3);
    bind_DefaultMasterApplication(asiodnp3);
    bind_DefaultListenCallbacks(asiodnp3);
    bind_ErrorCodes(asiodnp3);                  //@todo: referenced unknown base type "std::error_category"
    bind_MasterTCPServer(asiodnp3);
    bind_PrintingChannelListener(asiodnp3);
    bind_PrintingCommandCallback(asiodnp3);
    bind_UpdateBuilder(asiodnp3);
}