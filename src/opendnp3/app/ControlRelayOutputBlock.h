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

#ifndef PYDNP3_OPENDNP3_APP_CONTROLRELAYOUTPUTBLOCK_H
#define PYDNP3_OPENDNP3_APP_CONTROLRELAYOUTPUTBLOCK_H


#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/ControlRelayOutputBlock.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_ControlRelayOutputBlock(py::module &m)
{
    // ----- class: opendnp3::ControlRelayOutputBlock -----
    py::class_<opendnp3::ControlRelayOutputBlock,
               std::shared_ptr<opendnp3::ControlRelayOutputBlock>>(m, "ControlRelayOutputBlock",
        "Describes an incoming control request from the master. \n"
        "It is the applications responsibility to handle the request and return an approiate status code. \n"
        "The PULSE_CLOSE and PULSE_TRIP ControlCodes require setting the mOnTimeMS, mOffTimeMS and mCount variables, "
        "otherwise just use the defaults.")

        .def(
            py::init<opendnp3::ControlCode, uint8_t, uint32_t, uint32_t, opendnp3::CommandStatus>(),
            "   Primary constructor where the control code is set by enumeration. \n"
            ":param count: defaults to 1 \n"
            ":param onTimeMS: defaults to 100 \n"
            ":param offTimeMS: defaults to 100 \n"
            ":param status: defaults to opendnp3.ControlCode.LATCH_ON",
            py::arg("functionCode") = opendnp3::ControlCode::LATCH_ON,
            py::arg("count") = 1,
            py::arg("onTimeMS") = 100,
            py::arg("offTimeMS") = 100,
            py::arg("status") = opendnp3::CommandStatus::SUCCESS
        )

        .def(
            py::init<uint8_t, uint8_t, uint32_t, uint32_t, opendnp3::CommandStatus>(),
            "   Overloaded constructor that allows the user to set a raw control code for non-standard codes. \n"
            ":param count: defaults to 1 \n"
            ":param onTimeMS: defaults to 100 \n"
            ":param offTimeMS: defaults to 100 \n"
            ":param status: defaults to opendnp3.ControlCode.LATCH_ON",
            py::arg("rawCode"),
            py::arg("count") = 1,
            py::arg("onTimeMS") = 100,
            py::arg("offTimeMS") = 100,
            py::arg("status") = opendnp3::CommandStatus::SUCCESS
        )

        .def_readwrite(
            "functionCode",
            &opendnp3::ControlRelayOutputBlock::functionCode,
            "Allows matching of exact code."
        )

        .def_readwrite(
            "rawCode",
            &opendnp3::ControlRelayOutputBlock::rawCode,
            "The raw code in bytes."
        )

        .def_readwrite(
            "count",
            &opendnp3::ControlRelayOutputBlock::count,
            "The number of times to repeat the operation."
        )

        .def_readwrite(
            "onTimeMS",
            &opendnp3::ControlRelayOutputBlock::onTimeMS,
            "The on time for the pulse train."
        )

        .def_readwrite(
            "offTimeMS",
            &opendnp3::ControlRelayOutputBlock::offTimeMS,
            "The off time for the pulse train."
        )

        .def_readwrite(
            "status",
            &opendnp3::ControlRelayOutputBlock::status,
            "Status of the resulting operation."
        )

        .def(
            "ValuesEqual",
            &opendnp3::ControlRelayOutputBlock::ValuesEqual
        )

        .def(
            "__eq__",
            &opendnp3::ControlRelayOutputBlock::operator==,
            "Equality comparision."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
