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

#ifndef PYDNP3_OPENDNP3_GEN_INTERVALUNITS_H
#define PYDNP3_OPENDNP3_GEN_INTERVALUNITS_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/IntervalUnits.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_IntervalUnits(py::module &m)
{
    // ----- enum class: opendnp3::IntervalUnits -----
    py::enum_<opendnp3::IntervalUnits>(m, "IntervalUnits",
        "Time internal units.")

        .value(
            "NoRepeat",
            opendnp3::IntervalUnits::NoRepeat,
            "The outstation does not repeat the action regardless of the value in the interval count."
        )

        .value(
            "Milliseconds",
            opendnp3::IntervalUnits::Milliseconds,
            "The interval is always counted relative to the start time and is constant regardless of the clock time "
            "set at the outstation."
        )

        .value(
            "Seconds",
            opendnp3::IntervalUnits::Seconds,
            "At the same millisecond within the second that is specified in the start time."
        )

        .value(
            "Minutes",
            opendnp3::IntervalUnits::Minutes,
            "At the same second and millisecond within the minute that is specified in the start time."
        )

        .value(
            "Hours",
            opendnp3::IntervalUnits::Hours,
            "At the same minute, second and millisecond within the hour that is specified in the start time."
        )

        .value(
            "Days",
            opendnp3::IntervalUnits::Days,
            "At the same time of day that is specified in the start time."
        )

        .value(
            "Weeks",
            opendnp3::IntervalUnits::Weeks,
            "On the same day of the week at the same time of day that is specified in the start time."
        )

        .value(
            "Months7",
            opendnp3::IntervalUnits::Months7,
            "On the same day of each month at the same time of day that is specified in the start time."
        )

        .value(
            "Months8",
            opendnp3::IntervalUnits::Months8,
            "At the same time of day on the same day of the week after the beginning of the month as the day "
            "specified in the start time."
        )

        .value(
            "Months9",
            opendnp3::IntervalUnits::Months9,
            "Months on Same Day of Week from End of Month - The outstation shall interpret this setting as "
            "in Months8, but the day of the week shall be measured from the end of the month."
        )

        .value(
            "Seasons",
            opendnp3::IntervalUnits::Seasons,
            "The definition of a season is specific to the outstation."
        )

        .value(
            "Undefined",
            opendnp3::IntervalUnits::Undefined,
            "11-127 are reserved for future use."
        );
    
    // ----- function: opendnp3::IntervalUnitsToType -----
    m.def(
        "IntervalUnitsToType",
        &opendnp3::IntervalUnitsToType,
        py::arg("units")
    );
    
    // ----- function: opendnp3::IntervalUnitsFromType -----
    m.def(
        "IntervalUnitsFromType",
        &opendnp3::IntervalUnitsFromType,
        ":type rawType: unsigned char",
        py::arg("rawType")
    );
    
    // ----- function: opendnp3::IntervalUnitsToString -----
    m.def(
        "IntervalUnitsToString",
        &opendnp3::IntervalUnitsToString,
        py::arg("units")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
