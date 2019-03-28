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

#include "openpal/AllHeaders.h"

namespace py = pybind11;

void init_openpal(py::module &openpal)
{
    // -------------------- PYDNP3.OPENPAL --------------------
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
}