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

#ifndef PYDNP3_OPENDNP3_GEN_HMACTYPE_H
#define PYDNP3_OPENDNP3_GEN_HMACTYPE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/HMACType.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_HMACType(py::module &m)
{
    // ----- enum class: opendnp3::HMACType -----
    py::enum_<opendnp3::HMACType>(m, "HMACType",
        "Enumerates possible algorithms used to calculate the HMAC.")

        .value(
            "NO_MAC_VALUE",
            opendnp3::HMACType::NO_MAC_VALUE,
            "No HMAC value in this message."
        )

		.value(
		    "HMAC_SHA1_TRUNC_10",
		    opendnp3::HMACType::HMAC_SHA1_TRUNC_10,
            "Networked version of SHA1."
		)

		.value(
		    "HMAC_SHA256_TRUNC_8",
		    opendnp3::HMACType::HMAC_SHA256_TRUNC_8,
            "Serial version of SHA256."
		)

		.value(
		    "HMAC_SHA256_TRUNC_16",
		    opendnp3::HMACType::HMAC_SHA256_TRUNC_16,
            "Networked version of SHA256."
		)

		.value(
		    "HMAC_SHA1_TRUNC_8",
		    opendnp3::HMACType::HMAC_SHA1_TRUNC_8,
            "Serial version of SHA1."
		)

		.value(
		    "AES_GMAC",
		    opendnp3::HMACType::AES_GMAC,
            "12 octet output for serial or network."
		)

		.value(
		    "UNKNOWN",
		    opendnp3::HMACType::UNKNOWN,
            "Unknown HMAC algorithm."
		);

    // ----- function: opendnp3::HMACTypeToType -----
    m.def(
        "HMACTypeToType",
        &opendnp3::HMACTypeToType
    );

    // ----- function: opendnp3::HMACTypeFromType -----
    m.def(
        "HMACTypeFromType",
        &opendnp3::HMACTypeFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );

    // ----- function: opendnp3::HMACTypeToString -----
    m.def(
        "HMACTypeToString",
        &opendnp3::HMACTypeToString
    );
}

#endif // PYDNP3_OPENDNP3
#endif
