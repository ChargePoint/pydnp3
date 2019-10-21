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

#ifndef PYDNP3_ASIOPAL_SERIALTYPES_H
#define PYDNP3_ASIOPAL_SERIALTYPES_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiopal/SerialTypes.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

void bind_SerialTypes(py::module &m)
{
    // ----- class: asiopal::SerialSettings -----
    py::class_<asiopal::SerialSettings>(m, "SerialSettings",
        "Settings structure for the serial port.")

        .def(
            py::init<>(),
            "Defaults to the familiar 9600 8/N/1, no flow control."
        )

        .def_readwrite(
            "deviceName",
            &asiopal::SerialSettings::deviceName,
            "name of the port, i.e. COM1 or /dev/tty0."
        )

        .def_readwrite(
            "baud",
            &asiopal::SerialSettings::baud,
            "Baud rate of the port, i.e. 9600 or 57600."
        )

        .def_readwrite(
            "dataBits",
            &asiopal::SerialSettings::dataBits,
            "Data bits, usually 8."
        )

        .def_readwrite(
            "stopBits",
            &asiopal::SerialSettings::stopBits,
            "Stop bits, usually set to 1."
        )

        .def_readwrite(
            "parity",
            &asiopal::SerialSettings::parity,
            "Parity setting for the port, usually PAR_NONE."
        )

        .def_readwrite(
            "flowType",
            &asiopal::SerialSettings::flowType,
            "Flow control setting, usually FLOW_NONE."
        )

        .def_readwrite(
            "asyncOpenDelay",
            &asiopal::SerialSettings::asyncOpenDelay,
            "Some physical layers need time to settle so that the first tx isn't lost."
        );
}

#endif // PYDNP3_ASIOPAL
#endif
