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

#ifndef PYDNP3_OPENPAL_ALLHEADERS_H
#define PYDNP3_OPENPAL_ALLHEADERS_H

#define PYDNP3_OPENPAL

namespace openpal {
    class UInt48Type;
}

namespace opendnp3 {
    typedef openpal::UInt48Type DNPTime;
}

// ---------- OPENPAL HEADERS ----------
//#include "channel/IPhysicalLayer.h"                   //missing "ChannelStatistics.h" file
#include "channel/IPhysicalLayerCallbacks.h"
#include "container/Array.h"
#include "container/ArrayView.h"
#include "container/Buffer.h"
#include "container/HasSize.h"
#include "container/LinkedList.h"
#include "container/Pair.h"
#include "container/Queue.h"
#include "container/RingBuffer.h"
#include "container/RSlice.h"
#include "container/SecureBuffer.h"
#include "container/Settable.h"
#include "container/StaticBuffer.h"
#include "container/WSlice.h"
#include "executor/IExecutor.h"
#include "executor/IMonotonicTimeSource.h"
#include "executor/ITimer.h"
#include "executor/IUTCTimeSource.h"
#include "executor/MonotonicTimestamp.h"
#include "executor/TimeDuration.h"
#include "executor/TimerRef.h"
#include "executor/UTCTimestamp.h"
#include "logging/ILogHandler.h"
#include "logging/LogEntry.h"
#include "logging/LogFilters.h"
#include "logging/Logger.h"
#include "logging/LogLevels.h"
#include "logging/StringFormatting.h"
#include "serialization/DoubleFloat.h"
#include "serialization/FloatByteOrder.h"
#include "serialization/Format.h"
#include "serialization/Parse.h"
#include "serialization/Serialization.h"
#include "serialization/SerializationTemplatesLE.h"
#include "serialization/Serializer.h"
#include "serialization/SingleFloat.h"
#include "util/Comparisons.h"
#include "util/Finally.h"
#include "util/Limits.h"
#include "util/SequenceNum.h"
#include "util/ToHex.h"
#include "util/Uncopyable.h"
#include "Configure.h"

#endif
