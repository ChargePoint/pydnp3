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

#ifndef PYDNP3_OPENDNP3_GEN_FUNCTIONCODE_H
#define PYDNP3_OPENDNP3_GEN_FUNCTIONCODE_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/FunctionCode.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_FunctionCode(py::module &m)
{
    // ----- enum class: opendnp3::FunctionCode -----
    py::enum_<opendnp3::FunctionCode>(m, "FunctionCode",
        "Application layer function code enumeration.")

        .value(
            "CONFIRM",
            opendnp3::FunctionCode::CONFIRM,
            "Master sends this to an outstation to confirm the receipt of an Application Layer fragment."
        )

        .value(
            "READ",
            opendnp3::FunctionCode::READ,
            "Outstation shall return the data specified by the objects in the request."
        )

        .value(
            "WRITE",
            opendnp3::FunctionCode::WRITE,
            "Outstation shall store the data specified by the objects in the request."
        )

        .value(
            "SELECT",
            opendnp3::FunctionCode::SELECT,
            "Outstation shall select (or arm) the output points specified by the objects in the request "
            "in preparation for a subsequent operate command."
        )

        .value(
            "OPERATE",
            opendnp3::FunctionCode::OPERATE,
            "Outstation shall activate the output points selected (or armed) by a previous select "
            "function code command."
        )

        .value(
            "DIRECT_OPERATE",
            opendnp3::FunctionCode::DIRECT_OPERATE,
            "Outstation shall immediately actuate the output points specified by the objects in the request."
        )

        .value(
            "DIRECT_OPERATE_NR",
            opendnp3::FunctionCode::DIRECT_OPERATE_NR,
            "Same as DIRECT_OPERATE but outstation shall not send a response."
        )

        .value(
            "IMMED_FREEZE",
            opendnp3::FunctionCode::IMMED_FREEZE,
            "Outstation shall copy the point data values specified by the objects in the request to a separate "
            "freeze buffer."
        )

        .value(
            "IMMED_FREEZE_NR",
            opendnp3::FunctionCode::IMMED_FREEZE_NR,
            "Same as IMMED_FREEZE but outstation shall not send a response."
        )

        .value(
            "FREEZE_CLEAR",
            opendnp3::FunctionCode::FREEZE_CLEAR,
            "Outstation shall copy the point data values specified by the objects in the request into a separate "
            "freeze buffer and then clear the values."
        )

        .value(
            "FREEZE_CLEAR_NR",
            opendnp3::FunctionCode::FREEZE_CLEAR_NR,
            "Same as FREEZE_CLEAR but outstation shall not send a response."
        )

        .value(
            "FREEZE_AT_TIME",
            opendnp3::FunctionCode::FREEZE_AT_TIME,
            "Outstation shall copy the point data values specified by the objects in the request to a "
            "separate freeze buffer at the time and/or time intervals specified in a special time data information object."
        )

        .value(
            "FREEZE_AT_TIME_NR",
            opendnp3::FunctionCode::FREEZE_AT_TIME_NR,
            "Same as FREEZE_AT_TIME but outstation shall not send a response."
        )

        .value(
            "COLD_RESTART",
            opendnp3::FunctionCode::COLD_RESTART,
            "Outstation shall perform a complete reset of all hardware and software in the device."
        )

        .value(
            "WARM_RESTART",
            opendnp3::FunctionCode::WARM_RESTART,
            "Outstation shall reset only portions of the device."
        )

        .value(
            "INITIALIZE_DATA",
            opendnp3::FunctionCode::INITIALIZE_DATA,
            "Obsolete-Do not use for new designs."
        )

        .value(
            "INITIALIZE_APPLICATION",
            opendnp3::FunctionCode::INITIALIZE_APPLICATION,
            "Outstation shall place the applications specified by the objects in the request into the ready "
            "to run state."
        )

        .value(
            "START_APPLICATION",
            opendnp3::FunctionCode::START_APPLICATION,
            "Outstation shall start running the applications specified by the objects in the request."
        )

        .value(
            "STOP_APPLICATION",
            opendnp3::FunctionCode::STOP_APPLICATION,
            "Outstation shall stop running the applications specified by the objects in the request."
        )

        .value(
            "SAVE_CONFIGURATION",
            opendnp3::FunctionCode::SAVE_CONFIGURATION,
            "This code is deprecated-Do not use for new designs."
        )

        .value(
            "ENABLE_UNSOLICITED",
            opendnp3::FunctionCode::ENABLE_UNSOLICITED,
            "Enables outstation to initiate unsolicited responses from points specified by the objects in the request."
        )

        .value(
            "DISABLE_UNSOLICITED",
            opendnp3::FunctionCode::DISABLE_UNSOLICITED,
            "Prevents outstation from initiating unsolicited responses from points specified by the objects "
            "in the request."
        )

        .value(
            "ASSIGN_CLASS",
            opendnp3::FunctionCode::ASSIGN_CLASS,
            "Outstation shall assign the events generated by the points specified by the objects in the request "
            "to one of the classes."
        )

        .value(
            "DELAY_MEASURE",
            opendnp3::FunctionCode::DELAY_MEASURE,
            "Outstation shall report the time it takes to process and initiate the transmission of its response."
        )

        .value(
            "RECORD_CURRENT_TIME",
            opendnp3::FunctionCode::RECORD_CURRENT_TIME,
            "Outstation shall save the time when the last octet of this message is received."
        )

        .value(
            "OPEN_FILE",
            opendnp3::FunctionCode::OPEN_FILE,
            "Outstation shall open a file."
        )

        .value(
            "CLOSE_FILE",
            opendnp3::FunctionCode::CLOSE_FILE,
            "Outstation shall close a file."
        )

        .value(
            "DELETE_FILE",
            opendnp3::FunctionCode::DELETE_FILE,
            "Outstation shall delete a file."
        )

        .value(
            "GET_FILE_INFO",
            opendnp3::FunctionCode::GET_FILE_INFO,
            "Outstation shall retrieve information about a file."
        )

        .value(
            "AUTHENTICATE_FILE",
            opendnp3::FunctionCode::AUTHENTICATE_FILE,
            "Outstation shall return a file authentication key."
        )

        .value(
            "ABORT_FILE",
            opendnp3::FunctionCode::ABORT_FILE,
            "Outstation shall abort a file transfer operation."
        )

        .value(
            "AUTH_REQUEST",
            opendnp3::FunctionCode::AUTH_REQUEST,
            "The master uses this function code when sending authentication requests to the outstation."
        )

        .value(
            "AUTH_REQUEST_NO_ACK",
            opendnp3::FunctionCode::AUTH_REQUEST_NO_ACK,
            "The master uses this function code when sending authentication requests to the outstation that "
            "do no require acknowledgement."
        )

        .value(
            "RESPONSE",
            opendnp3::FunctionCode::RESPONSE,
            "Master shall interpret this fragment as an Application Layer response to an ApplicationLayer request."
        )

        .value(
            "UNSOLICITED_RESPONSE",
            opendnp3::FunctionCode::UNSOLICITED_RESPONSE,
            "Master shall interpret this fragment as an unsolicited response that was not prompted by "
            "an explicit request."
        )

        .value(
            "AUTH_RESPONSE",
            opendnp3::FunctionCode::AUTH_RESPONSE,
            "The outstation uses this function code to issue authentication messages to the master."
        )

        .value(
            "UNKNOWN",
            opendnp3::FunctionCode::UNKNOWN,
            "Unknown function code. Used internally in opendnp3 to indicate the code didn't match anything known."
        );

    // ----- function: opendnp3::FunctionCodeToType -----
    m.def(
        "FunctionCodeToType",
        &opendnp3::FunctionCodeToType,
        py::arg("code")
    );
    
    // ----- function: opendnp3::FunctionCodeFromType -----
    m.def(
        "FunctionCodeFromType",
        &opendnp3::FunctionCodeFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );
    
    // ----- function: opendnp3::FunctionCodeToString -----
    m.def(
        "FunctionCodeToString",
        &opendnp3::FunctionCodeToString,
        py::arg("code")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
