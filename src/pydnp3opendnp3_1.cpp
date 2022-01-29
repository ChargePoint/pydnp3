#include "pydnp3opendnp3_1.hpp"

#define PYDNP3_OPENDNP3

#include "opendnp3/LogLevels.h"
#include "opendnp3/StackStatistics.h"
#include "opendnp3/gen/AnalogOutputStatusQuality.h"
#include "opendnp3/gen/AnalogQuality.h"
#include "opendnp3/gen/AssignClassType.h"
#include "opendnp3/gen/GroupVariation.h"
#include "opendnp3/gen/Attributes.h"
#include "opendnp3/gen/AuthErrorCode.h"
#include "opendnp3/gen/BinaryOutputStatusQuality.h"
#include "opendnp3/gen/BinaryQuality.h"
#include "opendnp3/gen/CertificateType.h"
#include "opendnp3/gen/ChallengeReason.h"
#include "opendnp3/gen/ChannelState.h"
#include "opendnp3/gen/CommandPointState.h"
#include "opendnp3/gen/CommandStatus.h"
#include "opendnp3/gen/ConfigAuthMode.h"
#include "opendnp3/gen/ControlCode.h"
#include "opendnp3/gen/CounterQuality.h"
#include "opendnp3/gen/DoubleBit.h"
#include "opendnp3/gen/DoubleBitBinaryQuality.h"
#include "opendnp3/gen/EventAnalogOutputStatusVariation.h"
#include "opendnp3/gen/EventAnalogVariation.h"
#include "opendnp3/gen/EventBinaryOutputStatusVariation.h"
#include "opendnp3/gen/EventBinaryVariation.h"
#include "opendnp3/gen/EventCounterVariation.h"
#include "opendnp3/gen/EventDoubleBinaryVariation.h"
#include "opendnp3/gen/EventFrozenCounterVariation.h"
#include "opendnp3/gen/EventMode.h"
#include "opendnp3/gen/EventSecurityStatVariation.h"
#include "opendnp3/gen/FlagsType.h"

namespace py = pybind11;

void init_opendnp3_1(py::module &opendnp3)
{
    // -------------------- PYDNP3.OPENDNP3 --------------------
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
}

// void init_opendnp3_2(py::module &opendnp3)
// {
//     bind_FlowControl(opendnp3);
//     bind_FrozenCounterQuality(opendnp3);
//     bind_FunctionCode(opendnp3);
//     bind_HMACType(opendnp3);
//     bind_IndexMode(opendnp3);
//     bind_IntervalUnits(opendnp3);
//     bind_KeyChangeMethod(opendnp3);
//     bind_KeyStatus(opendnp3);
//     bind_KeyWrapAlgorithm(opendnp3);
//     bind_LinkFunction(opendnp3);
//     bind_LinkStatus(opendnp3);
//     bind_MasterTaskType(opendnp3);
//     bind_OperateType(opendnp3);
//     bind_Parity(opendnp3);
//     bind_PointClass(opendnp3);
//     bind_QualifierCode(opendnp3);
//     bind_RestartMode(opendnp3);
//     bind_RestartType(opendnp3);
//     bind_SecurityStatIndex(opendnp3);
//     bind_StaticAnalogOutputStatusVariation(opendnp3);
//     bind_StaticAnalogVariation(opendnp3);
//     bind_StaticBinaryOutputStatusVariation(opendnp3);
//     bind_StaticBinaryVariation(opendnp3);
//     bind_StaticCounterVariation(opendnp3);
//     bind_StaticDoubleBinaryVariation(opendnp3);
//     bind_StaticFrozenCounterVariation(opendnp3);
//     bind_StaticSecurityStatVariation(opendnp3);
//     bind_StaticTimeAndIntervalVariation(opendnp3);
//     bind_StaticTypeBitmask(opendnp3);
//     bind_StopBits(opendnp3);
// }

// void init_opendnp3_3(py::module &opendnp3)
// {
//     bind_TaskCompletion(opendnp3);
//     bind_TimeSyncMode(opendnp3);
//     bind_TimestampMode(opendnp3);
//     bind_UserOperation(opendnp3);
//     bind_UserRole(opendnp3);
//     bind_ILinkListener(opendnp3);
//     bind_LinkConfig(opendnp3);
//     bind_LinkHeaderFields(opendnp3);
//     bind_LinkStatistics(opendnp3);
//     bind_GroupVariationID(opendnp3);
//     bind_ICollection(opendnp3);
//     bind_DNPTime(opendnp3);
//     bind_AnalogCommandEvent(opendnp3);
//     bind_AnalogOutput(opendnp3);
//     bind_AppConstants(opendnp3);
//     bind_QualityMasks(opendnp3);
//     bind_Flags(opendnp3);
//     bind_BaseMeasurementTypes(opendnp3);
//     bind_BinaryCommandEvent(opendnp3);
//     bind_EventType(opendnp3);
//     bind_ClassField(opendnp3);
//     bind_ControlRelayOutputBlock(opendnp3);
//     bind_EventCells(opendnp3);                  //@todo: DeadbandEventCell
//     bind_EventTriggers(opendnp3);
//     bind_IINField(opendnp3);
//     bind_ITransactable(opendnp3);
//     bind_Indexed(opendnp3);
//     bind_MeasurementTypes(opendnp3);
//     bind_SecurityStat(opendnp3);
//     bind_MeasurementInfo(opendnp3);
// }

// void init_opendnp3_4(py::module &opendnp3)
// {
//     bind_MeasurementConfig(opendnp3);
//     bind_MeasurementTypeSpecs(opendnp3);
//     bind_OctetData(opendnp3);
//     bind_OctetString(opendnp3);
//     bind_ApplicationIIN(opendnp3);
//     bind_Cell(opendnp3);
//     bind_DatabaseSizes(opendnp3);
//     bind_EventBufferConfig(opendnp3);
//     bind_ICommandHandler(opendnp3);
//     bind_IOutstationApplication(opendnp3);
//     bind_IUpdateHandler(opendnp3);
//     bind_StaticTypeBitfield(opendnp3);
//     bind_OutstationParams(opendnp3);
//     bind_OutstationConfig(opendnp3);
//     bind_SimpleCommandHandler(opendnp3);
//     bind_CommandPointResult(opendnp3);
//     bind_ICommandTaskResult(opendnp3);
//     bind_CommandCallbackT(opendnp3);
//     bind_ICommandCollection(opendnp3);
//     bind_CommandSet(opendnp3);
//     bind_HeaderInfo(opendnp3);
//     bind_HeaderTypes(opendnp3);
//     bind_TaskId(opendnp3);
//     bind_ITaskCallback(opendnp3);
//     bind_TaskConfig(opendnp3);
//     bind_ICommandProcessor(opendnp3);
//     bind_TaskInfo(opendnp3);
//     bind_IMasterApplication(opendnp3);
//     bind_ISOEHandler(opendnp3);
//     bind_MasterParams(opendnp3);
//     bind_RestartOperationResult(opendnp3);
// }
