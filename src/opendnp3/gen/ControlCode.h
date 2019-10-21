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

#ifndef PYDNP3_OPENDNP3_GEN_CONTROLCODE_H
#define PYDNP3_OPENDNP3_GEN_CONTROLCODE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/ControlCode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_ControlCode(py::module &m)
{
    // ----- enum class: opendnp3::ControlCode -----
        py::enum_<opendnp3::ControlCode>(m, "ControlCode",
            "Defines the interoperable values of the Control Code. \n"
            "Refer to pages 506-510 of 1815 for a full description.")

            .value(
                "NUL",
                opendnp3::ControlCode::NUL,
                "Does not initiate an action or change an in-progress or pending command."
            )

            .value(
                "NUL_CANCEL",
                opendnp3::ControlCode::NUL_CANCEL,
                "Cancel in-progress and pending commands. Take no additional action."
            )

            .value(
                "PULSE_ON",
                opendnp3::ControlCode::PULSE_ON,
                "For activation model, set output to active for the duration of the On-time. "
                "For both complementary models, return NOT_SUPPORTED status."
            )

            .value(
                "PULSE_ON_CANCEL",
                opendnp3::ControlCode::PULSE_ON_CANCEL,
                "Cancel in-progress and pending commands, process the remainder of the fields as "
                "if the control code were PULSE_ON."
            )

            .value(
                "PULSE_OFF",
                opendnp3::ControlCode::PULSE_OFF,
                "Non-interoperable code. Do not use for new applications. Return NOT_SUPPORTED."
            )

            .value(
                "PULSE_OFF_CANCEL",
                opendnp3::ControlCode::PULSE_OFF_CANCEL,
                "Non-interoperable code. Do not use for new applications. Cancel in-progress and pending commands, "
                "process remainder of fields as if the control code were PULSE_OFF."
            )

            .value(
                "LATCH_ON",
                opendnp3::ControlCode::LATCH_ON,
                "For activation model, set output to active for the duration of the On-time. "
                "For complementary latch model, set the output to active. For complementary two-output model, "
                "set the close output to active for the duration of the On-time."
            )

            .value(
                "LATCH_ON_CANCEL",
                opendnp3::ControlCode::LATCH_ON_CANCEL,
                "Cancel in-progress and pending commands, process the remainder of the fields as "
                "if the control code were LATCH_ON."
            )

            .value(
                "LATCH_OFF",
                opendnp3::ControlCode::LATCH_OFF,
                "For activation model, set output to active for the duration of the On-time. "
                "For complementary latch model, set the output to inactive. For complementary two-output model, "
                "set the trip output to active for the duration of the On-time."
            )

            .value(
                "LATCH_OFF_CANCEL",
                opendnp3::ControlCode::LATCH_OFF_CANCEL,
                "Cancel in-progress and pending commands, process the remainder of the fields as "
                "if the control code were LATCH_OFF."
            )

            .value(
                "CLOSE_PULSE_ON",
                opendnp3::ControlCode::CLOSE_PULSE_ON,
                "For activation model, set output to active for the duration of the On-time. "
                "For complementary latch model, set the output to active. For complementary two-output model, "
                "set the close output to active for the duration of the On-time."
            )

            .value(
                "CLOSE_PULSE_ON_CANCEL",
                opendnp3::ControlCode::CLOSE_PULSE_ON_CANCEL,
                "Cancel in-progress and pending commands, process the remainder of the fields as "
                "if the control code were CLOSE_PULSE_ON."
            )

            .value(
                "TRIP_PULSE_ON",
                opendnp3::ControlCode::TRIP_PULSE_ON,
                "For activation model, set output to active for the duration of the On-time. "
                "For complementary latch model, set the output to inactive. For complementary two-output model, "
                "set the trip output to active for the duration of the On-time."
            )

            .value(
                "TRIP_PULSE_ON_CANCEL",
                opendnp3::ControlCode::TRIP_PULSE_ON_CANCEL,
                "Cancel in-progress and pending commands, process the remainder of the fields as "
                "if the control code were TRIP_PULSE_ON."
            )

            .value(
                "UNDEFINED",
                opendnp3::ControlCode::UNDEFINED,
                "Undefined command (used by DNP standard)."
            );

    // ----- function: opendnp3::ControlCodeToType -----
    m.def(
        "ControlCodeToType",
        &opendnp3::ControlCodeToType,
        py::arg("code")
    );

    // ----- function: opendnp3::ControlCodeFromType -----
    m.def(
        "ControlCodeFromType",
        &opendnp3::ControlCodeFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );

    // ----- function: opendnp3::ControlCodeToString -----
    m.def(
        "ControlCodeToString",
        &opendnp3::ControlCodeToString,
        py::arg("code")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
