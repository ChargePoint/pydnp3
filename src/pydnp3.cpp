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

#include <map>

#include "AllHeaders.h"

namespace py = pybind11;

typedef std::function<py::module&(std::string const &)> ModuleGetter;

PYBIND11_MODULE(pydnp3, root_module) {

    // -------------------- SET-UP --------------------
    root_module.doc() = "Python bindings for opendnp3 library";

    std::map<std::string, py::module> modules = {
        {"asiodnp3", root_module.def_submodule("asiodnp3", "Bindings for asiodnp3 namespace")},
        {"asiopal",  root_module.def_submodule("asiopal",  "Bindings for asiopal namespace")},
        {"opendnp3", root_module.def_submodule("opendnp3", "Bindings for opendnp3 namespace")},
        {"openpal",  root_module.def_submodule("openpal",  "Bindings for openpal namespace")}
    };

    ModuleGetter M = [&](std::string const &namespace_) -> py::module&
    {
        return (modules.find(namespace_))->second;
    };

    // -------------------- PYDNP3.OPENPAL --------------------

    py::module openpal = M("openpal");

    bind_Configure(openpal);
    bind_Comparisons(openpal);
    bind_Uncopyable(openpal);
    bind_Finally(openpal);
    bind_Limits(openpal);
    bind_SequenceNum(openpal);
    bind_ToHex(openpal);
    bind_HasSize(openpal);
    bind_ArrayView(openpal);
    bind_Array(openpal);
    bind_RSlice(openpal);
    bind_WSlice(openpal);
    bind_Buffer(openpal);
    bind_LinkedList(openpal);
    bind_Pair(openpal);
    bind_Queue(openpal);
    bind_RingBuffer(openpal);
    bind_SecureBuffer(openpal);
    bind_Settable(openpal);
    bind_StaticBuffer(openpal);
    //bind_IPhysicalLayer(openpal);             //@todo: can't include "ChannelStatistics.h"
    bind_IPhysicalLayerCallbacks(openpal);
    bind_TimeDuration(openpal);
    bind_MonotonicTimestamp(openpal);
    bind_ITimer(openpal);
    bind_IMonotonicTimeSource(openpal);
    bind_IExecutor(openpal);
    bind_UTCTimestamp(openpal);
    bind_IUTCTimeSource(openpal);
    bind_TimerRef(openpal);
    bind_LogFilters(openpal);
    bind_LogEntry(openpal);
    bind_ILogHandler(openpal);
    bind_OpenpalLogLevels(openpal);
    bind_Logger(openpal);
    bind_StringFormatting(openpal);
    bind_DoubleFloat(openpal);
    bind_FloatByteOrder(openpal);
    bind_Format(openpal);
    bind_Parse(openpal);
    bind_SerializationTemplatesLE(openpal);     //already defined: Int16, UInt16, Int32, UInt32 (bind_Serialization)
    bind_SingleFloat(openpal);
    bind_Serialization(openpal);
    bind_Serializer(openpal);

    // -------------------- PYDNP3.OPENDNP3 --------------------

    py::module opendnp3 = M("opendnp3");

    bind_OpendnpLogLevels(opendnp3);
    bind_StackStatistics(opendnp3);
    bind_AnalogOutputStatusQuality(opendnp3);
    bind_AnalogQuality(opendnp3);
    bind_AssignClassType(opendnp3);
    bind_GroupVariation(opendnp3);
    bind_Attributes(opendnp3);
    bind_AuthErrorCode(opendnp3);
    bind_BinaryOutputStatusQuality(opendnp3);
    bind_BinaryQuality(opendnp3);
    bind_CertificateType(opendnp3);
    bind_ChallengeReason(opendnp3);
    bind_ChannelState(opendnp3);
    bind_CommandPointState(opendnp3);
    bind_CommandStatus(opendnp3);
    bind_ConfigAuthMode(opendnp3);
    bind_ControlCode(opendnp3);
    bind_CounterQuality(opendnp3);
    bind_DoubleBit(opendnp3);
    bind_DoubleBitBinaryQuality(opendnp3);
    bind_EventAnalogOutputStatusVariation(opendnp3);
    bind_EventAnalogVariation(opendnp3);
    bind_EventBinaryOutputStatusVariation(opendnp3);
    bind_EventBinaryVariation(opendnp3);
    bind_EventCounterVariation(opendnp3);
    bind_EventDoubleBinaryVariation(opendnp3);
    bind_EventFrozenCounterVariation(opendnp3);
    bind_EventMode(opendnp3);
    bind_EventSecurityStatVariation(opendnp3);
    bind_FlagsType(opendnp3);
    bind_FlowControl(opendnp3);
    bind_FrozenCounterQuality(opendnp3);
    bind_FunctionCode(opendnp3);
    bind_HMACType(opendnp3);
    bind_IndexMode(opendnp3);
    bind_IntervalUnits(opendnp3);
    bind_KeyChangeMethod(opendnp3);
    bind_KeyStatus(opendnp3);
    bind_KeyWrapAlgorithm(opendnp3);
    bind_LinkFunction(opendnp3);
    bind_LinkStatus(opendnp3);
    bind_MasterTaskType(opendnp3);
    bind_OperateType(opendnp3);
    bind_Parity(opendnp3);
    bind_PointClass(opendnp3);
    bind_QualifierCode(opendnp3);
    bind_RestartMode(opendnp3);
    bind_RestartType(opendnp3);
    bind_SecurityStatIndex(opendnp3);
    bind_StaticAnalogOutputStatusVariation(opendnp3);
    bind_StaticAnalogVariation(opendnp3);
    bind_StaticBinaryOutputStatusVariation(opendnp3);
    bind_StaticBinaryVariation(opendnp3);
    bind_StaticCounterVariation(opendnp3);
    bind_StaticDoubleBinaryVariation(opendnp3);
    bind_StaticFrozenCounterVariation(opendnp3);
    bind_StaticSecurityStatVariation(opendnp3);
    bind_StaticTimeAndIntervalVariation(opendnp3);
    bind_StaticTypeBitmask(opendnp3);
    bind_StopBits(opendnp3);
    bind_TaskCompletion(opendnp3);
    bind_TimeSyncMode(opendnp3);
    bind_TimestampMode(opendnp3);
    bind_UserOperation(opendnp3);
    bind_UserRole(opendnp3);
    bind_ILinkListener(opendnp3);
    bind_LinkConfig(opendnp3);
    bind_LinkHeaderFields(opendnp3);
    bind_LinkStatistics(opendnp3);
    bind_GroupVariationID(opendnp3);
    bind_ICollection(opendnp3);
    bind_DNPTime(opendnp3);
    bind_AnalogCommandEvent(opendnp3);
    bind_AnalogOutput(opendnp3);
    bind_AppConstants(opendnp3);
    bind_QualityMasks(opendnp3);
    bind_Flags(opendnp3);
    bind_BaseMeasurementTypes(opendnp3);
    bind_BinaryCommandEvent(opendnp3);
    bind_EventType(opendnp3);
    bind_ClassField(opendnp3);
    bind_ControlRelayOutputBlock(opendnp3);
    bind_EventCells(opendnp3);                  //@todo: DeadbandEventCell
    bind_EventTriggers(opendnp3);
    bind_IINField(opendnp3);
    bind_ITransactable(opendnp3);
    bind_Indexed(opendnp3);
    bind_MeasurementTypes(opendnp3);
    bind_SecurityStat(opendnp3);
    bind_MeasurementInfo(opendnp3);
    bind_MeasurementConfig(opendnp3);
    bind_MeasurementTypeSpecs(opendnp3);
    bind_OctetData(opendnp3);
    bind_OctetString(opendnp3);
    bind_ApplicationIIN(opendnp3);
    bind_Cell(opendnp3);
    bind_DatabaseSizes(opendnp3);
    bind_EventBufferConfig(opendnp3);
    bind_ICommandHandler(opendnp3);
    bind_IOutstationApplication(opendnp3);
    bind_IUpdateHandler(opendnp3);
    bind_StaticTypeBitfield(opendnp3);
    bind_OutstationParams(opendnp3);
    bind_OutstationConfig(opendnp3);
    bind_SimpleCommandHandler(opendnp3);
    bind_CommandPointResult(opendnp3);
    bind_ICommandTaskResult(opendnp3);
    bind_CommandCallbackT(opendnp3);
    bind_ICommandCollection(opendnp3);
    bind_CommandSet(opendnp3);
    bind_HeaderInfo(opendnp3);
    bind_HeaderTypes(opendnp3);
    bind_TaskId(opendnp3);
    bind_ITaskCallback(opendnp3);
    bind_TaskConfig(opendnp3);
    bind_ICommandProcessor(opendnp3);
    bind_TaskInfo(opendnp3);
    bind_IMasterApplication(opendnp3);
    bind_ISOEHandler(opendnp3);
    bind_MasterParams(opendnp3);
    bind_RestartOperationResult(opendnp3);

    // -------------------- PYDNP3.ASIOPAL --------------------

    py::module asiopal = M("asiopal");

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

    // -------------------- PYDNP3.ASIODNP3 --------------------

    py::module asiodnp3 = M("asiodnp3");

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