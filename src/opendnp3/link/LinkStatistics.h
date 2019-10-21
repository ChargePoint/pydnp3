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

#ifndef PYDNP3_OPENDNP3_LINK_LINKSTATISTICS_H
#define PYDNP3_OPENDNP3_LINK_LINKSTATISTICS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/link/LinkStatistics.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_LinkStatistics(py::module &m)
{
    // ----- struct: opendnp3::LinkStatisticsParser -----
    py::class_<opendnp3::LinkStatistics::Parser>(m, "LinkStatisticsParser")

        .def(
            py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>(),
            py::arg("numHeaderCrcError") = 0,
            py::arg("numBodyCrcError") = 0,
            py::arg("numLinkFrameRx") = 0,
            py::arg("numBadLength") = 0,
            py::arg("numBadFunctionCode") = 0,
            py::arg("numBadFCV") = 0,
            py::arg("numBadFCB") = 0
        )

        .def_readwrite(
            "numHeaderCrcError",
            &opendnp3::LinkStatistics::Parser::numHeaderCrcError,
            "   Number of frames discarded due to header CRC errors. \n"
            ":type numHeaderCrcError: unsigned int"
        )

        .def_readwrite(
            "numBodyCrcError",
            &opendnp3::LinkStatistics::Parser::numBodyCrcError,
            "   Number of frames discarded due to body CRC errors. \n"
            ":type numBodyCrcError: unsigned int"
        )

        .def_readwrite(
            "numLinkFrameRx",
            &opendnp3::LinkStatistics::Parser::numLinkFrameRx,
            "   Number of frames received. \n"
            ":type numLinkFrameRx: unsigned int"
        )

        .def_readwrite(
            "numBadLength",
            &opendnp3::LinkStatistics::Parser::numBadLength,
            "   Number of bad LEN fields received (malformed frame). \n"
            ":type numBadLength: unsigned int"
        )

        .def_readwrite(
            "numBadFunctionCode",
            &opendnp3::LinkStatistics::Parser::numBadFunctionCode,
            "   Number of bad function codes (malformed frame). \n"
            ":type numBadFunctionCode: unsigned int"
        )

        .def_readwrite(
            "numBadFCV",
            &opendnp3::LinkStatistics::Parser::numBadFCV,
            "   Number of FCV / function code mismatches (malformed frame). \n"
            ":type numBadFCV: unsigned int"
        )

        .def_readwrite(
            "numBadFCB",
            &opendnp3::LinkStatistics::Parser::numBadFCB,
            "   Number of frames w/ unexpected FCB bit set (malformed frame). \n"
            ":type numBadFCB: unsigned int"
        );

    // ----- struct: opendnp3::LinkStatisticsChannel -----
    py::class_<opendnp3::LinkStatistics::Channel>(m, "LinkStatisticsChannel")

        .def(
            py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>(),
            py::arg("numOpen") = 0,
            py::arg("numOpenFail") = 0,
            py::arg("numClose") = 0,
            py::arg("numBytesRx") = 0,
            py::arg("numBytesTx") = 0,
            py::arg("numLinkFrameTx") = 0
        )

        .def_readwrite(
            "numOpen",
            &opendnp3::LinkStatistics::Channel::numOpen,
            "   The number of times the channel has successfully opened. \n"
            ":type numOpen: unsigned int"
        )

        .def_readwrite(
            "numOpenFail",
            &opendnp3::LinkStatistics::Channel::numOpenFail,
            "   The number of times the channel has failed to open. \n"
            ":type numOpenFail: unsigned int"
        )

        .def_readwrite(
            "numClose",
            &opendnp3::LinkStatistics::Channel::numClose,
            "   The number of times the channel has closed either due to user intervention or an error. \n"
            ":type numClose: unsigned int"
        )

        .def_readwrite(
            "numBytesRx",
            &opendnp3::LinkStatistics::Channel::numBytesRx,
            "   The number of bytes received. \n"
            ":type numBytesRx: unsigned int"
        )

        .def_readwrite(
            "numBytesTx",
            &opendnp3::LinkStatistics::Channel::numBytesTx,
            "   The number of bytes transmitted. \n"
            ":type numBytesTx: unsigned int"
        )

        .def_readwrite(
            "numLinkFrameTx",
            &opendnp3::LinkStatistics::Channel::numLinkFrameTx,
            "   Number of frames transmitted. \n"
            ":type numLinkFrameTx: unsigned int"
        );

    // ----- struct: opendnp3::LinkStatistics -----
    py::class_<opendnp3::LinkStatistics>(m, "LinkStatistics",
        "Counters for the channel and the DNP3 link layer.")

        .def(py::init<>())

        .def(
            py::init<const opendnp3::LinkStatistics::Channel &, const opendnp3::LinkStatistics::Parser &>(),
            py::arg("channel"), py::arg("parser")
        )

        .def_readwrite(
            "channel",
            &opendnp3::LinkStatistics::channel,
            "Statistics for the communicaiton channel."
        )

        .def_readwrite(
            "parser",
            &opendnp3::LinkStatistics::parser,
            "Statistics for the link parser."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
