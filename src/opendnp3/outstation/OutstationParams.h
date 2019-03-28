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

#ifndef PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONPARAMS_H
#define PYDNP3_OPENDNP3_OUTSTATION_OUTSTATIONPARAMS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/outstation/OutstationParams.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_OutstationParams(py::module &m)
{
    // ----- struct: opendnp3::OutstationParams -----
    py::class_<opendnp3::OutstationParams>(m, "OutstationParams",
        "Static configuration parameters for an outstation session.")

        .def(
            py::init<opendnp3::IndexMode, uint8_t, openpal::TimeDuration, openpal::TimeDuration, openpal::TimeDuration,
                     openpal::TimeDuration, uint32_t, uint32_t, bool, opendnp3::StaticTypeBitField,
                     opendnp3::ClassField>(),
            ":type maxControlsPerRequest: unsigned char \n"
            ":type maxTxFragSize: unsigned int \n"
            ":type maxRxFragSize: unsigned int",
            py::arg("indexMode") = opendnp3::IndexMode::Contiguous,
            py::arg("maxControlsPerRequest") = 16,
            py::arg("selectTimeout") = openpal::TimeDuration::Seconds(10),
            py::arg("solConfirmTimeout") = opendnp3::DEFAULT_APP_TIMEOUT,
            py::arg("unsolConfirmTimeout") = opendnp3::DEFAULT_APP_TIMEOUT,
            py::arg("unsolRetryTimeout") = opendnp3::DEFAULT_APP_TIMEOUT,
            py::arg("maxTxFragSize") = opendnp3::DEFAULT_MAX_APDU_SIZE,
            py::arg("maxRxFragSize") = opendnp3::DEFAULT_MAX_APDU_SIZE,
            py::arg("allowUnsolicited") = false,
            py::arg("typesAllowedInClass0") = opendnp3::StaticTypeBitField::AllTypes(),
            py::arg("unsolClassMask") = opendnp3::ClassField::None()
        )

        .def_readwrite(
            "indexMode",
            &opendnp3::OutstationParams::indexMode,
            "Controls the index mode (defaults to contiguous)."
        )

        .def_readwrite(
            "maxControlsPerRequest",
            &opendnp3::OutstationParams::maxControlsPerRequest,
            "   The maximum number of controls the outstation will attempt to process from a single APDU. \n"
            ":type maxControlsPerRequest: unsigned char"
        )

        .def_readwrite(
            "selectTimeout",
            &opendnp3::OutstationParams::selectTimeout,
            "How long the outstation will allow an operate to proceed after a prior select."
        )

        .def_readwrite(
            "solConfirmTimeout",
            &opendnp3::OutstationParams::solConfirmTimeout,
            "Timeout for solicited confirms."
        )

        .def_readwrite(
            "unsolConfirmTimeout",
            &opendnp3::OutstationParams::unsolConfirmTimeout,
            "Timeout for unsolicited confirms."
        )

        .def_readwrite(
            "unsolRetryTimeout",
            &opendnp3::OutstationParams::unsolRetryTimeout,
            "Timeout for unsolicited retries."
        )

        .def_readwrite(
            "maxTxFragSize",
            &opendnp3::OutstationParams::maxTxFragSize,
            "   The maximum fragment size the outstation will use for fragments it sends. \n"
            ":type maxTxFragSize: unsigned int"
        )

        .def_readwrite(
            "maxRxFragSize",
            &opendnp3::OutstationParams::maxRxFragSize,
            "   The maximum fragment size the outstation will be able to receive. \n"
            ":type maxRxFragSize: unsigned int"
        )

        .def_readwrite(
            "allowUnsolicited",
            &opendnp3::OutstationParams::allowUnsolicited,
            "Global enabled/ disable for unsolicited messages. If false, the NULL unsolicited message is not even sent."
        )

        .def_readwrite(
            "typesAllowedInClass0",
            &opendnp3::OutstationParams::typesAllowedInClass0,
            "A bitmask type that specifies the types allowed in a class 0 reponse."
        )

        .def_readwrite(
            "unsolClassMask",
            &opendnp3::OutstationParams::unsolClassMask,
            "Class mask for unsolicted, default to 0 as unsolicited has to be enabled."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
