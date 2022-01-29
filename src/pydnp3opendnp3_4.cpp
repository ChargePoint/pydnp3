#include "pydnp3opendnp3_4.hpp"

#define PYDNP3_OPENDNP3

#include "opendnp3/outstation/MeasurementConfig.h"
#include "opendnp3/app/MeasurementTypeSpecs.h"
#include "opendnp3/app/OctetData.h"
#include "opendnp3/app/OctetString.h"
#include "opendnp3/outstation/ApplicationIIN.h"
#include "opendnp3/outstation/Cell.h"
#include "opendnp3/outstation/DatabaseSizes.h"
#include "opendnp3/outstation/EventBufferConfig.h"
#include "opendnp3/outstation/ICommandHandler.h"
#include "opendnp3/outstation/IOutstationApplication.h"
#include "opendnp3/outstation/IUpdateHandler.h"
#include "opendnp3/outstation/StaticTypeBitfield.h"
#include "opendnp3/outstation/OutstationParams.h"
#include "opendnp3/outstation/OutstationConfig.h"
#include "opendnp3/outstation/SimpleCommandHandler.h"
#include "opendnp3/master/CommandPointResult.h"
#include "opendnp3/master/ICommandTaskResult.h"
#include "opendnp3/master/CommandCallbackT.h"
#include "opendnp3/master/ICommandCollection.h"
#include "opendnp3/master/CommandSet.h"
#include "opendnp3/master/HeaderInfo.h"
#include "opendnp3/master/HeaderTypes.h"
#include "opendnp3/master/TaskId.h"
#include "opendnp3/master/ITaskCallback.h"
#include "opendnp3/master/TaskConfig.h"
#include "opendnp3/master/ICommandProcessor.h"
#include "opendnp3/master/TaskInfo.h"
#include "opendnp3/master/IMasterApplication.h"
#include "opendnp3/master/ISOEHandler.h"
#include "opendnp3/master/MasterParams.h"
#include "opendnp3/master/RestartOperationResult.h"

namespace py = pybind11;

void init_opendnp3_4(py::module &opendnp3)
{
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
}
