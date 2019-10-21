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

#ifndef PYDNP3_ASIODNP3_UPDATEBUILDER_H
#define PYDNP3_ASIODNP3_UPDATEBUILDER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/UpdateBuilder.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_UpdateBuilder(py::module &m)
{
    // ----- class: asiodnp3::UpdateBuilder -----
    py::class_<asiodnp3::UpdateBuilder>(m, "UpdateBuilder")

        .def(py::init<>())

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::Binary& meas,
               uint16_t index,
               opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index, mode);},
            ":param mode: defaults to opendnp3.EventMode.Detect \n"
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect
        )

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::DoubleBitBinary& meas,
               uint16_t index,
               opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index, mode);},
            ":param mode: defaults to opendnp3.EventMode.Detect \n"
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect
        )

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::Analog& meas,
               uint16_t index,
               opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index, mode);},
            ":param mode: defaults to opendnp3.EventMode.Detect \n"
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect
        )

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::Counter& meas,
               uint16_t index,
               opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index, mode);},
            ":param mode: defaults to opendnp3.EventMode.Detect \n"
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect
        )

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::FrozenCounter& meas,
               uint16_t index,
               opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index, mode);},
            ":param mode: defaults to opendnp3.EventMode.Detect \n"
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect
        )

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::BinaryOutputStatus& meas,
               uint16_t index,
               opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index, mode);},
            ":param mode: defaults to opendnp3.EventMode.Detect \n"
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect
        )

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::AnalogOutputStatus& meas,
               uint16_t index,
               opendnp3::EventMode mode) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index, mode);},
            ":param mode: defaults to opendnp3.EventMode.Detect \n"
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index"), py::arg("mode") = opendnp3::EventMode::Detect
        )

        .def(
            "Update",
            [](asiodnp3::UpdateBuilder &self,
               const opendnp3::TimeAndInterval& meas,
               uint16_t index) -> asiodnp3::UpdateBuilder & {return self.Update(meas, index);},
            ":type index: unsigned short",
            py::arg("measurement"), py::arg("index")
        )

        .def(
            "Modify",
            &asiodnp3::UpdateBuilder::Modify,
            ":type start: unsigned short \n"
            ":type stop: unsigned short \n"
            ":type flags: unsigned char",
            py::arg("type"), py::arg("start"), py::arg("stop"), py::arg("flags")
        )

        .def(
            "Build",
            &asiodnp3::UpdateBuilder::Build
        );
}

#endif // PYDNP3_ASIODNP3
#endif
