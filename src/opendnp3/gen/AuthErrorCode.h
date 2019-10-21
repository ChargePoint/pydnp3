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

#ifndef PYDNP3_OPENDNP3_GEN_AUTHERRORCODE_H
#define PYDNP3_OPENDNP3_GEN_AUTHERRORCODE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/AuthErrorCode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_AuthErrorCode(py::module &m)
{
    // ----- enum class: opendnp3::AuthErrorCode -----
    py::enum_<opendnp3::AuthErrorCode>(m, "AuthErrorCode",
        "Specifies the reason that an auth error message was transmitted.")

        .value(
            "AUTHENTICATION_FAILED",
            opendnp3::AuthErrorCode::AUTHENTICATION_FAILED,
            "Supplied auth information."
        )

		.value(
		    "AGGRESSIVE_MODE_UNSUPPORTED",
		    opendnp3::AuthErrorCode::AGGRESSIVE_MODE_UNSUPPORTED,
            "Aggressive mode not supported on this link."
		)

		.value(
		    "MAC_NOT_SUPPORTED",
		    opendnp3::AuthErrorCode::MAC_NOT_SUPPORTED,
            "The specified MAC algorithm is not supported."
		)

		.value(
		    "KEY_WRAP_NOT_SUPPORTED",
		    opendnp3::AuthErrorCode::KEY_WRAP_NOT_SUPPORTED,
            "The key-wrap algorithm is not supported."
		)

		.value(
		    "AUTHORIZATION_FAILED",
		    opendnp3::AuthErrorCode::AUTHORIZATION_FAILED,
            "Authentication passed, but that user not authorized for requested operation."
		)

		.value(
		    "UPDATE_KEY_METHOD_NOT_PERMITTED",
		    opendnp3::AuthErrorCode::UPDATE_KEY_METHOD_NOT_PERMITTED,
            "The outstation does not support specified key change method on this link."
		)

		.value(
		    "INVALID_SIGNATURE",
		    opendnp3::AuthErrorCode::INVALID_SIGNATURE,
            "The digital signature supplied in a user status change object was invalid."
		)

		.value(
		    "INVALID_CERTIFICATION_DATA",
		    opendnp3::AuthErrorCode::INVALID_CERTIFICATION_DATA,
            "The certification data supplied in a user status change object was invalid."
		)

		.value(
		    "UNKNOWN_USER",
		    opendnp3::AuthErrorCode::UNKNOWN_USER,
            "The master attempted to change the Update Key of a user without a valid prior user status change."
		)

		.value(
		    "MAX_SESSION_KEY_STATUS_REQUESTS_EXCEEDED",
		    opendnp3::AuthErrorCode::MAX_SESSION_KEY_STATUS_REQUESTS_EXCEEDED,
            "The master on a different association has requred session key status too often."
		)

		.value(
		    "UNKNOWN",
		    opendnp3::AuthErrorCode::UNKNOWN,
            "Unknown error code."
		);

	// ----- func: opendnp3::AuthErrorCodeToType -----
	m.def(
	    "AuthErrorCodeToType",
	    &opendnp3::AuthErrorCodeToType,
	    py::arg("code")
	);

	// ----- func: opendnp3::AuthErrorCodeFromType -----
	m.def(
	    "AuthErrorCodeFromType",
	    &opendnp3::AuthErrorCodeFromType,
	    ":type rawType: unsigned char",
	    py::arg("rawType")
	);

	// ----- func: opendnp3::AuthErrorCodeToString -----
	m.def(
	    "AuthErrorCodeToString",
	    &opendnp3::AuthErrorCodeToString,
	    py::arg("code")
	);
}

#endif // PYDNP3_OPENDNP3
#endif
