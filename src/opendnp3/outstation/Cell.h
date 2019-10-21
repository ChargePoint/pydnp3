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

#ifndef PYDNP3_OPENDNP3_OUTSTATION_CELL_H
#define PYDNP3_OPENDNP3_OUTSTATION_CELL_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/outstation/Cell.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

template <class Spec>
void declareCell(py::module &m, string const & type)
{
    // ----- struct: opendnp3::SelectedValue<Spec> -----
    py::class_<opendnp3::SelectedValue<Spec>>(m, ("SelectedValue" + type).c_str(),
        "Type used to record whether a value is requested in a response.")

        .def(py::init<>())

        .def_readwrite(
            "selected",
            &opendnp3::SelectedValue<Spec>::selected
        )

        .def_readwrite(
            "value",
            &opendnp3::SelectedValue<Spec>::value
        )

        .def_readwrite(
            "variation",
            &opendnp3::SelectedValue<Spec>::variation
        );

    // ----- struct: opendnp3::Cell<Spec> -----
    py::class_<opendnp3::Cell<Spec>>(m, ("Cell" + type).c_str(),
        "Holds particular measurement type in the database.")

        .def(py::init<>())

        .def_readwrite(
            "value",
            &opendnp3::Cell<Spec>::value,
            "Current value."
        )

        .def_readwrite(
            "config",
            &opendnp3::Cell<Spec>::config,
            "Configuration."
        )

        .def_readwrite(
            "event",
            &opendnp3::Cell<Spec>::event,
            "Event cell."
        )

        .def_readwrite(
            "selection",
            &opendnp3::Cell<Spec>::selection,
            "Selected value."
        );
}

void bind_Cell(py::module &m)
{
}

#endif // PYDNP3_OPENDNP3
#endif
