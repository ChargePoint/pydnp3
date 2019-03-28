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

#ifndef PYDNP3_OPENDNP3_ALLHEADERS_H
#define PYDNP3_OPENDNP3_ALLHEADERS_H

#define PYDNP3_OPENDNP3

// ---------- OPENDNP3 HEADERS ----------
#include "app/parsing/ICollection.h"
#include "app/AnalogCommandEvent.h"
#include "app/AnalogOutput.h"
#include "app/AppConstants.h"
#include "app/BaseMeasurementTypes.h"
#include "app/BinaryCommandEvent.h"
#include "app/ClassField.h"
#include "app/ControlRelayOutputBlock.h"
#include "app/DNPTime.h"
#include "app/EventCells.h"
#include "app/EventTriggers.h"
#include "app/EventType.h"
#include "app/Flags.h"
#include "app/GroupVariationID.h"
#include "app/Indexed.h"
#include "app/IINField.h"
#include "app/ITransactable.h"
#include "app/MeasurementInfo.h"
#include "app/MeasurementTypes.h"
#include "app/MeasurementTypeSpecs.h"
#include "app/OctetData.h"
#include "app/OctetString.h"
#include "app/QualityMasks.h"
#include "app/SecurityStat.h"
#include "gen/AnalogOutputStatusQuality.h"
#include "gen/AnalogQuality.h"
#include "gen/AssignClassType.h"
#include "gen/Attributes.h"
#include "gen/AuthErrorCode.h"
#include "gen/BinaryOutputStatusQuality.h"
#include "gen/BinaryQuality.h"
#include "gen/CertificateType.h"
#include "gen/ChallengeReason.h"
#include "gen/ChannelState.h"
#include "gen/CommandPointState.h"
#include "gen/CommandStatus.h"
#include "gen/ConfigAuthMode.h"
#include "gen/ControlCode.h"
#include "gen/CounterQuality.h"
#include "gen/DoubleBit.h"
#include "gen/DoubleBitBinaryQuality.h"
#include "gen/EventAnalogOutputStatusVariation.h"
#include "gen/EventAnalogVariation.h"
#include "gen/EventBinaryOutputStatusVariation.h"
#include "gen/EventBinaryVariation.h"
#include "gen/EventCounterVariation.h"
#include "gen/EventDoubleBinaryVariation.h"
#include "gen/FrozenCounterQuality.h"
#include "gen/EventFrozenCounterVariation.h"
#include "gen/EventMode.h"
#include "gen/EventSecurityStatVariation.h"
#include "gen/FlagsType.h"
#include "gen/FlowControl.h"
#include "gen/FunctionCode.h"
#include "gen/GroupVariation.h"
#include "gen/HMACType.h"
#include "gen/IndexMode.h"
#include "gen/IntervalUnits.h"
#include "gen/KeyChangeMethod.h"
#include "gen/KeyStatus.h"
#include "gen/KeyWrapAlgorithm.h"
#include "gen/LinkFunction.h"
#include "gen/LinkStatus.h"
#include "gen/MasterTaskType.h"
#include "gen/OperateType.h"
#include "gen/Parity.h"
#include "gen/PointClass.h"
#include "gen/QualifierCode.h"
#include "gen/RestartMode.h"
#include "gen/RestartType.h"
#include "gen/SecurityStatIndex.h"
#include "gen/StaticAnalogOutputStatusVariation.h"
#include "gen/StaticAnalogVariation.h"
#include "gen/StaticBinaryOutputStatusVariation.h"
#include "gen/StaticBinaryVariation.h"
#include "gen/StaticCounterVariation.h"
#include "gen/StaticDoubleBinaryVariation.h"
#include "gen/StaticFrozenCounterVariation.h"
#include "gen/StaticSecurityStatVariation.h"
#include "gen/StaticTimeAndIntervalVariation.h"
#include "gen/StopBits.h"
#include "gen/StaticTypeBitmask.h"
#include "gen/TaskCompletion.h"
#include "gen/TimestampMode.h"
#include "gen/TimeSyncMode.h"
#include "gen/UserOperation.h"
#include "gen/UserRole.h"
#include "link/ILinkListener.h"
#include "link/LinkConfig.h"
#include "link/LinkHeaderFields.h"
#include "link/LinkStatistics.h"
#include "master/CommandCallbackT.h"
#include "master/CommandPointResult.h"
#include "master/CommandSet.h"
#include "master/HeaderInfo.h"
#include "master/HeaderTypes.h"
#include "master/ICommandCollection.h"
#include "master/ICommandProcessor.h"
#include "master/ICommandTaskResult.h"
#include "master/IMasterApplication.h"
#include "master/ISOEHandler.h"
#include "master/ITaskCallback.h"
#include "master/MasterParams.h"
#include "master/RestartOperationResult.h"
#include "master/TaskConfig.h"
#include "master/TaskId.h"
#include "master/TaskInfo.h"
#include "outstation/ApplicationIIN.h"
#include "outstation/Cell.h"
#include "outstation/DatabaseSizes.h"
#include "outstation/EventBufferConfig.h"
#include "outstation/ICommandHandler.h"
#include "outstation/IOutstationApplication.h"
#include "outstation/IUpdateHandler.h"
#include "outstation/MeasurementConfig.h"
#include "outstation/OutstationConfig.h"
#include "outstation/OutstationParams.h"
#include "outstation/SimpleCommandHandler.h"
#include "outstation/StaticTypeBitfield.h"
#include "LogLevels.h"
#include "StackStatistics.h"

#endif
