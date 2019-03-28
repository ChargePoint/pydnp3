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

#ifndef PYDNP3_OPENDNP3_MASTER_MASTERPARAMS_H
#define PYDNP3_OPENDNP3_MASTER_MASTERPARAMS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/master/MasterParams.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_MasterParams(py::module &m)
{
    // ----- class:opendnp3::MasterParams -----
    py::class_<opendnp3::MasterParams>(m, "MasterParams",
        "Configuration information for the dnp3 master.")

        .def(
            py::init<>(),
            "Default constructor."
        )

        .def_readwrite(
            "responseTimeout",
            &opendnp3::MasterParams::responseTimeout,
            "Application layer response timeout."
        )

        .def_readwrite(
            "timeSyncMode",
            &opendnp3::MasterParams::timeSyncMode,
            "If true, the master will do time syncs when it sees the time IIN bit from the outstation."
        )

        .def_readwrite(
            "disableUnsolOnStartup",
            &opendnp3::MasterParams::disableUnsolOnStartup,
            "If true, the master will disable unsol on startup for all 3 classes."
        )

        .def_readwrite(
            "ignoreRestartIIN",
            &opendnp3::MasterParams::ignoreRestartIIN,
            "If true, the master will not clear the restart IIN bit in response to detecting it set."
        )

        .def_readwrite(
            "unsolClassMask",
            &opendnp3::MasterParams::unsolClassMask,
            "Bitwise mask used determine which classes are enabled for unsol, if 0 unsol is not enabled."
        )

        .def_readwrite(
            "startupIntegrityClassMask",
            &opendnp3::MasterParams::startupIntegrityClassMask,
            "Which classes should be requested in a startup integrity scan, defaults to 3/2/1/0. \n"
            "A mask equal to 0 means no startup integrity scan will be performed."
        )

        .def_readwrite(
            "integrityOnEventOverflowIIN",
            &opendnp3::MasterParams::integrityOnEventOverflowIIN,
            "Defines whether an integrity scan will be performed when the EventBufferOverflow IIN is detected."
        )

        .def_readwrite(
            "eventScanOnEventsAvailableClassMask",
            &opendnp3::MasterParams::eventScanOnEventsAvailableClassMask,
            "Which classes should be requested in an event scan when detecting corresponding events available IIN."
        )

        .def_readwrite(
            "taskRetryPeriod",
            &opendnp3::MasterParams::taskRetryPeriod,
            "Time delay before retrying a failed task."
        )

        .def_readwrite(
            "maxTaskRetryPeriod",
            &opendnp3::MasterParams::maxTaskRetryPeriod,
            "Maximum time delay before retrying a failed task. Backs off exponentially from taskRetryPeriod."
        )

        .def_readwrite(
            "taskStartTimeout",
            &opendnp3::MasterParams::taskStartTimeout,
            "Time delay before failing a non-recurring task (e.g. commands) that cannot start."
        )

        .def_readwrite(
            "maxTxFragSize",
            &opendnp3::MasterParams::maxTxFragSize,
            "   Maximum APDU tx size in bytes. \n"
            ":type maxTxFragSize: unsigned int"
        )

        .def_readwrite(
            "maxRxFragSize",
            &opendnp3::MasterParams::maxRxFragSize,
            "   Maximum APDU rx size in bytes. \n"
            ":type maxRxFragSize: unsigned int"
        );
}

#endif // PYDNP3_OPENDNP3
#endif
