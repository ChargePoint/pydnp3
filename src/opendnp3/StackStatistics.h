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

#ifndef PYDNP3_OPENDNP3_STACKSTATISTICS_H
#define PYDNP3_OPENDNP3_STACKSTATISTICS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/StackStatistics.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;

void bind_StackStatistics(py::module &m)
{
	// ----- struct: opendnp3::StackStatistics -----
	py::class_<opendnp3::StackStatistics::Link>(m, "StackStatisticsLink")

	    .def(
	        py::init<uint32_t, uint32_t, uint32_t, uint32_t>(),
	        ":type numUnexpectedFrame: unsigned int \n"
	        ":type numBadMasterBit: unsigned int \n"
	        ":type numUnknownDestination: unsigned int \n"
	        ":type numUnknownSource: unsigned int",
	        py::arg("numUnexpectedFrame") = 0,
	        py::arg("numBadMasterBit") = 0,
	        py::arg("numUnknownDestination") = 0,
	        py::arg("numUnknownSource") = 0
	    )

	    .def_readwrite(
	        "numUnexpectedFrame",
	        &opendnp3::StackStatistics::Link::numUnexpectedFrame,
	        "   Number of unexpected frames. \n"
	        ":type numUnexpectedFrame: unsigned int"
	    )

	    .def_readwrite(
	        "numBadMasterBit",
	        &opendnp3::StackStatistics::Link::numBadMasterBit,
	        "   Frames received w/ wrong master bit. \n"
	        ":type numBadMasterBit: unsigned int"
	    )

	    .def_readwrite(
	        "numUnknownDestination",
	        &opendnp3::StackStatistics::Link::numUnknownDestination,
	        "   Frames received for an unknown destination. \n"
	        ":type numUnknownDestination: unsigned int"
	    )

	    .def_readwrite(
	        "numUnknownSource",
	        &opendnp3::StackStatistics::Link::numUnknownSource,
	        "   Frames received for an unknown source. \n"
	        ":type numUnknownSource: unsigned int"
	    );

	// ----- struct: opendnp3::StackStatisticsTransportRx -----
	py::class_<opendnp3::StackStatistics::Transport::Rx>(m, "StackStatisticsTransportRx")

	    .def(
	        py::init<uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>(),
	        ":type numTransportRx: unsigned int \n"
	        ":type numTransportErrorRx: unsigned int \n"
	        ":type numTransportBufferOverflow: unsigned int \n"
	        ":type numTransportDiscard: unsigned int \n"
	        ":type numTransportIgnore: unsigned int",
	        py::arg("numTransportRx") = 0,
	        py::arg("numTransportErrorRx") = 0,
	        py::arg("numTransportBufferOverflow") = 0,
	        py::arg("numTransportDiscard") = 0,
	        py::arg("numTransportIgnore") = 0
	    )

	    .def_readwrite(
	        "numTransportRx",
	        &opendnp3::StackStatistics::Transport::Rx::numTransportRx,
	        "   Number of valid TPDU's received. \n"
	        ":type numTransportRx: unsigned int"
	    )

	    .def_readwrite(
	        "numTransportErrorRx",
	        &opendnp3::StackStatistics::Transport::Rx::numTransportErrorRx,
	        "   Number of TPDUs dropped due to malformed contents. \n"
	        ":type numTransportErrorRx: unsigned int"
	    )

	    .def_readwrite(
	        "numTransportBufferOverflow",
	        &opendnp3::StackStatistics::Transport::Rx::numTransportBufferOverflow,
	        "   Number of times received data was too big for reassembly buffer. \n"
	        ":type numTransportBufferOverflow: unsigned int"
	    )

	    .def_readwrite(
	        "numTransportDiscard",
	        &opendnp3::StackStatistics::Transport::Rx::numTransportDiscard,
	        "   Number of times transport buffer is discard due to new FIR. \n"
	        ":type numTransportDiscard: unsigned int"
	    )

	    .def_readwrite(
	        "numTransportIgnore",
	        &opendnp3::StackStatistics::Transport::Rx::numTransportIgnore,
	        "   Number of segments ignored due to bad FIR/FIN or SEQ. \n"
	        ":type numTransportIgnore: unsigned int"
	    );

	// ----- struct: opendnp3::StackStatisticsTransportTx -----
	py::class_<opendnp3::StackStatistics::Transport::Tx>(m, "StackStatisticsTransportTx")

	    .def(
	        py::init<uint32_t>(),
	        ":type numTransportTx: unsigned int",
	        py::arg("numTransportTx") = 0
	    )

	    .def_readwrite(
	        "numTransportTx",
	        &opendnp3::StackStatistics::Transport::Tx::numTransportTx,
	        "   Number of TPDUs transmitted. \n"
	        ":type numTransportTx: unsigned int"
	    );

	// ----- struct: opendnp3::StackStatisticsTransport -----
	py::class_<opendnp3::StackStatistics::Transport>(m, "StackStatisticsTransport")

	    .def(py::init<>())

	    .def(
	        py::init<const opendnp3::StackStatistics::Transport::Rx&,
	                 const opendnp3::StackStatistics::Transport::Tx&>(),
	        py::arg("rx"), py::arg("tx")
	    )

	    .def_readwrite(
	        "rx",
	        &opendnp3::StackStatistics::Transport::rx
	    )

	    .def_readwrite(
	        "tx",
	        &opendnp3::StackStatistics::Transport::tx
	    );

	// ----- struct: opendnp3::StackStatistics -----
	py::class_<opendnp3::StackStatistics>(m, "StackStatistics",
	    "Statistics related to both a master or outstation session.")

	    .def(py::init<>())

	    .def(
	        py::init<const opendnp3::StackStatistics::Link &, const opendnp3::StackStatistics::Transport &>(),
	        py::arg("link"), py::arg("transport")
	    )

	    .def_readwrite(
	        "link",
	        &opendnp3::StackStatistics::link
	    )

	    .def_readwrite(
	        "transport",
	        &opendnp3::StackStatistics::transport
	    );
}

#endif // PYDNP3_OPENDNP3
#endif
