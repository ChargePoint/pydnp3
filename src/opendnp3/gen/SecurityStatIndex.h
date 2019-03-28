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

#ifndef PYDNP3_OPENDNP3_GEN_SECURITYSTATINDEX_H
#define PYDNP3_OPENDNP3_GEN_SECURITYSTATINDEX_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/SecurityStatIndex.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_SecurityStatIndex(py::module &m)
{
    // ----- enum class: opendnp3::SecurityStatIndex -----
    py::enum_<opendnp3::SecurityStatIndex>(m, "SecurityStatIndex",
        "Indices of the SA security statistics.")

        .value(
            "UNEXPECTED_MESSAGES",
            opendnp3::SecurityStatIndex::UNEXPECTED_MESSAGES,
            "The other device has responded with a message that was not the expected next step in the state machine."
        )

		.value(
		    "AUTHORIZATION_FAILURES",
		    opendnp3::SecurityStatIndex::AUTHORIZATION_FAILURES,
		    "The other device has replied with the correct authentication information, so the user is authentic, "
		    "but the user is not authorized to perform the requested operation."
		)

		.value(
		    "AUTHENTICATION_FAILURES",
		    opendnp3::SecurityStatIndex::AUTHENTICATION_FAILURES,
		    "The other device has provided invalid authentication information such as an incorrect MAC."
		)

		.value(
		    "REPLY_TIMEOUTS",
		    opendnp3::SecurityStatIndex::REPLY_TIMEOUTS,
		    " The other device has not replied within the configured time required."
		)

		.value(
		    "REKEYS_DUE_TO_AUTH_FAILUE",
		    opendnp3::SecurityStatIndex::REKEYS_DUE_TO_AUTH_FAILUE,
		    "An Authentication Failure has occurred that causes the master station to change the session keys."
		)

		.value(
		    "TOTAL_MESSAGES_TX",
		    opendnp3::SecurityStatIndex::TOTAL_MESSAGES_TX,
		    "The device sends an Application Layer fragment."
		)

		.value(
		    "TOTAL_MESSAGES_RX",
		    opendnp3::SecurityStatIndex::TOTAL_MESSAGES_RX,
		    "The device receives an Application Layer fragment."
		)

		.value(
		    "CRITICAL_MESSAGES_TX",
		    opendnp3::SecurityStatIndex::CRITICAL_MESSAGES_TX,
		    "The device receives a Challenge message or transmits an Aggressive Mode Request message."
		)

		.value(
		    "CRITICAL_MESSAGES_RX",
		    opendnp3::SecurityStatIndex::CRITICAL_MESSAGES_RX,
		    "The device transmits a Challenge message or receives an Aggressive Mode Request message."
		)

		.value(
		    "DISCARED_MESSAGES",
		    opendnp3::SecurityStatIndex::DISCARED_MESSAGES,
		    "The device discards a received message."
		)

		.value(
		    "ERROR_MESSAGES_TX",
		    opendnp3::SecurityStatIndex::ERROR_MESSAGES_TX,
		    "The device has sent a fragment containing an Error object indicating an authentication failure "
		    "or potential configuration error."
		)

		.value(
		    "ERROR_MESSAGES_RX",
		    opendnp3::SecurityStatIndex::ERROR_MESSAGES_RX,
		    "The device has received an Error object."
		)

		.value(
		    "SUCCESSFUL_AUTHS",
		    opendnp3::SecurityStatIndex::SUCCESSFUL_AUTHS,
		    "The device successfully authenticates a message."
		)

		.value(
		    "SESSION_KEY_CHANGES",
		    opendnp3::SecurityStatIndex::SESSION_KEY_CHANGES,
		    "A users session key is successfully changed."
		)

		.value(
		    "FAILED_SESSION_KEY_CHANGES",
		    opendnp3::SecurityStatIndex::FAILED_SESSION_KEY_CHANGES,
		    "A failure occurs while changing a session key."
		)

		.value(
		    "UPDATE_KEY_CHANGES",
		    opendnp3::SecurityStatIndex::UPDATE_KEY_CHANGES,
		    "The master and authority change the Update Key for a user."
		)

		.value(
		    "FAILED_UPDATE_KEY_CHANGES",
		    opendnp3::SecurityStatIndex::FAILED_UPDATE_KEY_CHANGES,
		    "The master and authority fail to change the Update Key for a user."
		)

		.value(
		    "REKEYS_DUE_TO_RESTART",
		    opendnp3::SecurityStatIndex::REKEYS_DUE_TO_RESTART,
		    "Only used by a master. Set to zero in outstations. The master rekeyed the session keys because "
		    "the outstation restarted."
		);
}

#endif // PYDNP3_OPENDNP3
#endif
