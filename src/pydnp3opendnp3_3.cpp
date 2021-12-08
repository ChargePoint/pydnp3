#include "pydnp3opendnp3_3.hpp"

#define PYDNP3_OPENDNP3

#include "opendnp3/gen/TaskCompletion.h"
#include "opendnp3/gen/TimeSyncMode.h"
#include "opendnp3/gen/TimestampMode.h"
#include "opendnp3/gen/UserOperation.h"
#include "opendnp3/gen/UserRole.h"
#include "opendnp3/link/ILinkListener.h"
#include "opendnp3/link/LinkConfig.h"
#include "opendnp3/link/LinkHeaderFields.h"
#include "opendnp3/link/LinkStatistics.h"
#include "opendnp3/app/GroupVariationID.h"
#include "opendnp3/app/parsing/ICollection.h"
#include "opendnp3/app/DNPTime.h"
#include "opendnp3/app/AnalogCommandEvent.h"
#include "opendnp3/app/AnalogOutput.h"
#include "opendnp3/app/AppConstants.h"
#include "opendnp3/app/QualityMasks.h"
#include "opendnp3/app/Flags.h"
#include "opendnp3/app/BaseMeasurementTypes.h"
#include "opendnp3/app/BinaryCommandEvent.h"
#include "opendnp3/app/EventType.h"
#include "opendnp3/app/ClassField.h"
#include "opendnp3/app/ControlRelayOutputBlock.h"
#include "opendnp3/app/EventCells.h"
#include "opendnp3/app/EventTriggers.h"
#include "opendnp3/app/IINField.h"
#include "opendnp3/app/ITransactable.h"
#include "opendnp3/app/Indexed.h"
#include "opendnp3/app/MeasurementTypes.h"
#include "opendnp3/app/SecurityStat.h"
#include "opendnp3/app/MeasurementInfo.h"

namespace py = pybind11;

void init_opendnp3_3(py::module &opendnp3)
{
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
}

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
