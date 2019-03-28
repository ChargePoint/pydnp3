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

#ifndef PYDNP3_OPENDNP3_OUTSTATION_DATABASESIZES_H
#define PYDNP3_OPENDNP3_OUTSTATION_DATABASESIZES_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/outstation/DatabaseSizes.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_DatabaseSizes(py::module &m)
{
    // ----- struct class: opendnp3::DatabaseSizes -----
    py::class_<opendnp3::DatabaseSizes>(m, "DatabaseSizes",
        "Specifies the number and type of measurements in an outstation database.")

        .def(
            py::init(&opendnp3::DatabaseSizes::Empty),
            "Default constructor: set all arguments to 0."
        )

        .def(py::init<uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t, uint16_t>(),
             ":type numBinary: unsigned short \n"
             ":type numDoubleBinary: unsigned short \n"
             ":type numAnalog: unsigned short \n"
             ":type numCounter: unsigned short \n"
             ":type numFrozenCounter: unsigned short \n"
             ":type numBinaryOutputStatus: unsigned short \n"
             ":type numAnalogOutputStatus: unsigned short \n"
             ":type numTimeAndInterval: unsigned short",
             py::arg("numBinary"), py::arg("numDoubleBinary"), py::arg("numAnalog"), py::arg("numCounter"),
             py::arg("numFrozenCounter"), py::arg("numBinaryOutputStatus"), py::arg("numAnalogOutputStatus"),
             py::arg("numTimeAndInterval"))

        .def_readwrite(
            "numBinary",
            &opendnp3::DatabaseSizes::numBinary,
            ":type numBinary: unsigned short"
        )

        .def_readwrite(
            "numDoubleBinary",
            &opendnp3::DatabaseSizes::numDoubleBinary,
            ":type numDoubleBinary: unsigned short"
        )

        .def_readwrite(
            "numAnalog",
            &opendnp3::DatabaseSizes::numAnalog,
            ":type DatabaseSizes: unsigned short"
        )

        .def_readwrite(
            "numCounter",
            &opendnp3::DatabaseSizes::numCounter,
            ":type numCounter: unsigned short"
        )

        .def_readwrite(
            "numFrozenCounter",
            &opendnp3::DatabaseSizes::numFrozenCounter,
            ":type numFrozenCounter: unsigned short"
        )

        .def_readwrite(
            "numBinaryOutputStatus",
            &opendnp3::DatabaseSizes::numBinaryOutputStatus,
            ":type numBinaryOutputStatus: unsigned short"
        )

        .def_readwrite(
            "numAnalogOutputStatus",
            &opendnp3::DatabaseSizes::numAnalogOutputStatus,
            ":type numAnalogOutputStatus: unsigned short"
        )

        .def_readwrite(
            "numTimeAndInterval",
            &opendnp3::DatabaseSizes::numTimeAndInterval,
            ":type numTimeAndInterval: unsigned short"
        )

        .def_static(
            "BinaryOnly",
            &opendnp3::DatabaseSizes::BinaryOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "DoubleBinaryOnly",
            &opendnp3::DatabaseSizes::DoubleBinaryOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "AnalogOnly",
            &opendnp3::DatabaseSizes::AnalogOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "CounterOnly",
            &opendnp3::DatabaseSizes::CounterOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "FrozenCounterOnly",
            &opendnp3::DatabaseSizes::FrozenCounterOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "BinaryOutputStatusOnly",
            &opendnp3::DatabaseSizes::BinaryOutputStatusOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "AnalogOutputStatusOnly",
            &opendnp3::DatabaseSizes::AnalogOutputStatusOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "TimeAndIntervalOnly",
            &opendnp3::DatabaseSizes::TimeAndIntervalOnly,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "AllTypes",
            &opendnp3::DatabaseSizes::AllTypes,
            ":type count: unsigned short",
            py::arg("count")
        )

        .def_static(
            "Empty", &opendnp3::DatabaseSizes::Empty
        );
}

#endif // PYDNP3_OPENDNP3
#endif
