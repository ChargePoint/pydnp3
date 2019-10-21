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

#ifndef PYDNP3_OPENDNP3_GEN_KEYWRAPALGORITHM_H
#define PYDNP3_OPENDNP3_GEN_KEYWRAPALGORITHM_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/KeyWrapAlgorithm.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_KeyWrapAlgorithm(py::module &m)
{
    // ----- enum class: opendnp3::KeyWrapAlgorithm -----
    py::enum_<opendnp3::KeyWrapAlgorithm>(m, "KeyWrapAlgorithm",
        "Enumerates possible key-wrap algorithms.")

        .value(
            "AES_128",
            opendnp3::KeyWrapAlgorithm::AES_128,
            "AES 128 Key Wrap Algorithm."
        )

		.value(
		    "AES_256",
		    opendnp3::KeyWrapAlgorithm::AES_256,
		    "AES 256 Key Wrap Algorithm."
		)

		.value(
		    "UNDEFINED",
		    opendnp3::KeyWrapAlgorithm::UNDEFINED
		);

    // ----- function: opendnp3::KeyWrapAlgorithmToType -----
    m.def(
        "KeyWrapAlgorithmToType",
        &opendnp3::KeyWrapAlgorithmToType
    );

    // ----- function: opendnp3::KeyWrapAlgorithmFromType -----
    m.def(
        "KeyWrapAlgorithmFromType",
        &opendnp3::KeyWrapAlgorithmFromType,
        ":rawType: unsigned char",
        py::arg("rawType")
    );

    // ----- function: opendnp3::KeyWrapAlgorithmToString -----
    m.def(
        "KeyWrapAlgorithmToString",
        &opendnp3::KeyWrapAlgorithmToString
    );
}

#endif // PYDNP3_OPENDNP3
#endif
