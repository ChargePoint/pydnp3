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

#ifndef PYDNP3_ASIOPAL_ALLHEADERS_H
#define PYDNP3_ASIOPAL_ALLHEADERS_H

// For this compilation unit, include the header file
// related to asiopal
#define PYDNP3_ASIOPAL

// ---------- ASIOPAL HEADERS ----------
#include "ASIOSerialHelpers.h"
#include "ChannelRetry.h"
#include "Executor.h"
#include "IAsyncChannel.h"
#include "IChannelCallbacks.h"
#include "IListener.h"
#include "IO.h"
#include "IOpenDelayStrategy.h"
#include "IPEndpoint.h"
#include "IResourceManager.h"
#include "LoggingConnectionCondition.h"
#include "ResourceManager.h"
#include "SerialChannel.h"
#include "SerialTypes.h"
#include "SocketChannel.h"
#include "SocketHelpers.h"
#include "SteadyClock.h"
#include "Synchronized.h"
#include "TCPClient.h"
#include "TCPServer.h"
#include "ThreadPool.h"
#include "TimeConversions.h"
#include "Timer.h"
#include "TLSConfig.h"
#include "UTCTimeSource.h"

#endif
