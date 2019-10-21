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

#ifndef PYDNP3_OPENDNP3_APP_MEASUREMENTTYPES_H
#define PYDNP3_OPENDNP3_APP_MEASUREMENTTYPES_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/MeasurementTypes.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_MeasurementTypes(py::module &m)
{
    // ----- class: opendnp3::Binary -----
        py::class_<opendnp3::Binary, opendnp3::TypedMeasurement<bool>>(m, "Binary",
            "The Binary data type is for describing on-off (boolean) type values. \n"
            "Good examples of binaries are alarms, mode settings, enabled/disabled flags etc. \n"
            "Think of it as a status LED on a piece of equipment.")

            .def(py::init<>())

            .def(
                py::init<bool>(),
                py::arg("value")
            )

            .def(
                py::init<opendnp3::Flags>(),
                py::arg("flags")
            )

            .def(
                py::init<opendnp3::Flags, opendnp3::DNPTime>(),
                py::arg("flags"), py::arg("time")
            )

            .def(
                py::init<bool, opendnp3::Flags>(),
                py::arg("value"), py::arg("flags")
            )

            .def(
                py::init<bool, opendnp3::Flags, opendnp3::DNPTime>(),
                py::arg("value"), py::arg("flags"), py::arg("time")
            );

    // ----- class: opendnp3::DoubleBitBinary -----
        py::class_<opendnp3::DoubleBitBinary, opendnp3::TypedMeasurement<opendnp3::DoubleBit>>(m, "DoubleBitBinary",
            "The Double-bit Binary data type has two stable states, on and off, and an in transit state. \n"
            "Motor operated switches or binary valves are good examples.")

            .def(py::init<>())

            .def(
                py::init<opendnp3::DoubleBit>(),
                py::arg("value")
            )

            .def(
                py::init<opendnp3::Flags>(),
                py::arg("flags")
            )

            .def(
                py::init<opendnp3::Flags, opendnp3::DNPTime>(),
                py::arg("flags"), py::arg("time")
            )

            .def(
                py::init<opendnp3::DoubleBit, opendnp3::Flags>(),
                py::arg("value"), py::arg("flags")
            )

            .def(
                py::init<opendnp3::DoubleBit, opendnp3::Flags, opendnp3::DNPTime>(),
                py::arg("value"), py::arg("flags"), py::arg("time")
            );

    // ----- class: opendnp3::BinaryOutputStatus -----
        py::class_<opendnp3::BinaryOutputStatus, opendnp3::TypedMeasurement<bool>>(m, "BinaryOutputStatus",
            "BinaryOutputStatus is used for describing the current state of a control. \n"
            "It is very infrequently used and many masters don't provide any mechanisms for reading these values "
            "so their use is strongly discouraged, a Binary should be used instead.")

            .def(py::init<>())

            .def(
                py::init<bool>(),
                py::arg("value")
            )

            .def(
                py::init<opendnp3::Flags>(),
                py::arg("flags")
            )

            .def(
                py::init<opendnp3::Flags, opendnp3::DNPTime>(),
                py::arg("flags"), py::arg("time")
            )

            .def(
                py::init<bool, opendnp3::Flags>(),
                py::arg("value"), py::arg("flags")
            )

            .def(
                py::init<bool, opendnp3::Flags, opendnp3::DNPTime>(),
                py::arg("value"), py::arg("flags"), py::arg("time")
            );

    // ----- class: opendnp3::Analog -----
        py::class_<opendnp3::Analog, opendnp3::TypedMeasurement<double>>(m, "Analog",
            "Analogs are used for variable data points that usually reflect a real world value. \n"
            "Good examples are current, voltage, sensor readouts, etc. Think of a speedometer guage.")

            .def(py::init<>())

            .def(
                py::init<double>(),
                ":type value: double",
                py::arg("value")
            )

            .def(
                py::init<double, opendnp3::Flags>(),
                ":type value: double",
                py::arg("value"), py::arg("flags")
            )

            .def(
                py::init<double, opendnp3::Flags, opendnp3::DNPTime>(),
                ":type value: double",
                py::arg("value"), py::arg("flags"), py::arg("time")
            );

    // ----- class: opendnp3::Counter -----
        py::class_<opendnp3::Counter, opendnp3::TypedMeasurement<uint32_t>>(m, "Counter",
            "Counters are used for describing generally increasing values (non-negative!). \n"
            "Good examples are total power consumed, max voltage. Think odometer on a car.")

            .def(py::init<>())

            .def(
                py::init<uint32_t>(),
                ":type value: unsigned int",
                py::arg("value")
            )

            .def(
                py::init<uint32_t, opendnp3::Flags>(),
                ":type value: unsigned int",
                py::arg("value"), py::arg("flags")
            )

            .def(
                py::init<uint32_t, opendnp3::Flags, opendnp3::DNPTime>(),
                ":type value: unsigned int",
                py::arg("value"), py::arg("flags"), py::arg("time")
            );

    // ----- class: opendnp3::FrozenCounter -----
        py::class_<opendnp3::FrozenCounter, opendnp3::TypedMeasurement<uint32_t>>(m, "FrozenCounter",
            "Frozen counters are used to report the value of a counter point captured at the instant "
            "when the count is frozen.")

            .def(py::init<>())

            .def(
                py::init<uint32_t>(),
                ":type value: unsigned int",
                py::arg("value")
            )

            .def(
                py::init<uint32_t, opendnp3::Flags>(),
                ":type value: unsigned int",
                py::arg("value"), py::arg("flags")
            )

            .def(
                py::init<uint32_t, opendnp3::Flags, opendnp3::DNPTime>(),
                ":type value: unsigned int",
                py::arg("value"), py::arg("flags"), py::arg("time")
            );

    // ----- class: opendnp3::AnalogOutputStatus -----
        py::class_<opendnp3::AnalogOutputStatus, opendnp3::TypedMeasurement<double>>(m, "AnalogOutputStatus",
            "Describes the last set value of the set-point. \n"
            "Like the BinaryOutputStatus data type it is not well supported "
            "and its generally better practice to use an explicit analog.")

            .def(py::init<>())

            .def(
                py::init<double>(),
                ":type value: double",
                py::arg("value")
            )

            .def(
                py::init<double, opendnp3::Flags>(),
                ":type value: double",
                py::arg("value"), py::arg("flags")
            )

            .def(
                py::init<double, opendnp3::Flags, opendnp3::DNPTime>(),
                ":type value: double",
                py::arg("value"), py::arg("flags"), py::arg("time")
            );

    // ----- class: opendnp3::TimeAndInterval -----
        py::class_<opendnp3::TimeAndInterval>(m, "TimeAndInterval",
            "Maps to Group50Var4. \n"
            "This class is a bit of an outlier as an indexed type and is really only used in the DNP3 PV profile.")

            .def(py::init<>())

            .def(
                py::init<opendnp3::DNPTime, uint32_t, uint8_t>(),
                ":type interval: unsigned int \n"
                ":type units: unsigned char",
                py::arg("time"), py::arg("interval"), py::arg("units")
            )

            .def(
                py::init<opendnp3::DNPTime, uint32_t, opendnp3::IntervalUnits>(),
                ":type interval: unsigned int",
                py::arg("time"), py::arg("interval"), py::arg("units")
            )

            .def_readwrite(
                "time",
                &opendnp3::TimeAndInterval::time
            )

            .def_readwrite(
                "interval",
                &opendnp3::TimeAndInterval::interval,
                ":type interval: unsigned int"
            )

            .def_readwrite(
                "units",
                &opendnp3::TimeAndInterval::units,
                ":type units: unsigned char"
            )

            .def(
                "GetUnitsEnum",
                &opendnp3::TimeAndInterval::GetUnitsEnum
            );
}

#endif // PYDNP3_OPENDNP3
#endif
