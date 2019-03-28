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

#ifndef PYDNP3_OPENDNP3_APP_ANALOGOUTPUT_H
#define PYDNP3_OPENDNP3_APP_ANALOGOUTPUT_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/AnalogOutput.h>

namespace py = pybind11;
using namespace std;

#ifdef PYDNP3_OPENDNP3

template <typename T>
void declareAnalogOutput(py::module &m, string const & type)
{
    // ----- class: opendnp3::AnalogOutput<T> -----
    py::class_<opendnp3::AnalogOutput<T>,
               std::shared_ptr<opendnp3::AnalogOutput<T>>>(m, ("AnalogOutput_" + type).c_str(),
        "The object to represent a setpoint request from the master. \n"
        "Think of this like turning a dial on the front of a machine to desired setting.")

        .def(
            py::init<T, opendnp3::CommandStatus>(),
            ":param value: defaults to 0 \n"
            ":param status: defaults to opendnp3.CommandStatus.SUCCESS",
            py::arg("value") = 0,
            py::arg("status") = opendnp3::CommandStatus::SUCCESS
        )

        .def(
            "ValuesEqual",
            &opendnp3::AnalogOutput<T>::ValuesEqual,
            py::arg("lhs")
        )

        .def_readwrite(
            "value",
            &opendnp3::AnalogOutput<T>::value
        )

        .def_readwrite(
            "status",
            &opendnp3::AnalogOutput<T>::status,
            "The status value defaults to CS_SUCCESS for requests."
        );

    // ----- func: opendnp3::AnalogOutput -----
    m.def(
        "AnalogOutput",
        [](T value, opendnp3::CommandStatus status){
            return opendnp3::AnalogOutput<T>(value, status);
        },
        "Return instance of class AnalogOutput<T>",
        py::arg("value") = 0,
        py::arg("status") = opendnp3::CommandStatus::SUCCESS
    );
}

void bind_AnalogOutput(py::module &m)
{
    declareAnalogOutput<int16_t>(m, "Int16");
    declareAnalogOutput<int32_t>(m, "Int32");
    declareAnalogOutput<float>(m, "Float");
    declareAnalogOutput<double>(m, "Double");

    // ----- class: opendnp3::AnalogOutputInt16 -----  
    py::class_<opendnp3::AnalogOutputInt16,
               opendnp3::AnalogOutput<int16_t>,
               std::shared_ptr<opendnp3::AnalogOutputInt16>>(m, "AnalogOutputInt16",
        "16-bit signed integer analog output. The underlying serialization is Group41, Variation 2.")

        .def(
            py::init<int16_t, opendnp3::CommandStatus>(),
            ":param value: defaults to 0 \n"
            ":param status: defaults to opendnp3.CommandStatus.SUCCESS",
            py::arg("value") = 0, py::arg("status") = opendnp3::CommandStatus::SUCCESS
        )

        .def(
            "__eq__",
            &opendnp3::AnalogOutputInt16::operator==,
            "Equality comparision."
        );
    
    // ----- class: opendnp3::AnalogOutputInt32 -----  
    py::class_<opendnp3::AnalogOutputInt32,
               opendnp3::AnalogOutput<int32_t>,
               std::shared_ptr<opendnp3::AnalogOutputInt32>>(m, "AnalogOutputInt32",
        "32-bit signed integer analog output. The underlying serialization is Group41, Variation 1.")

        .def(
            py::init<int32_t, opendnp3::CommandStatus>(),
            ":param value: defaults to 0 \n"
            ":param status: defaults to opendnp3.CommandStatus.SUCCESS",
            py::arg("value") = 0, py::arg("status") = opendnp3::CommandStatus::SUCCESS
        )

        .def(
            "__eq__",
            &opendnp3::AnalogOutputInt32::operator==,
            "Equality comparision."
        );
    
    // ----- class: opendnp3::AnalogOutputFloat32 -----  
    py::class_<opendnp3::AnalogOutputFloat32,
               opendnp3::AnalogOutput<float>,
               std::shared_ptr<opendnp3::AnalogOutputFloat32>>(m, "AnalogOutputFloat32",
        "Single precision analog output. The underlying serialization is Group41, Variation 3.")

        .def(
            py::init<float, opendnp3::CommandStatus>(),
            ":param value: defaults to 0 \n"
            ":param status: defaults to opendnp3.CommandStatus.SUCCESS",
            py::arg("value") = 0, py::arg("status") = opendnp3::CommandStatus::SUCCESS
        )

        .def(
            "__eq__",
            &opendnp3::AnalogOutputFloat32::operator==,
            "Equality comparision."
        );
    
    // ----- class: opendnp3::AnalogOutputDouble64 -----  
    py::class_<opendnp3::AnalogOutputDouble64,
               opendnp3::AnalogOutput<double>,
               std::shared_ptr<opendnp3::AnalogOutputDouble64>>(m, "AnalogOutputDouble64",
        "Double precision analog output. The underlying serialization is Group41, Variation 3")

        .def(
            py::init<double, opendnp3::CommandStatus>(),
            ":param value: defaults to 0 \n"
            ":param status: defaults to opendnp3.CommandStatus.SUCCESS",
            py::arg("value") = 0, py::arg("status") = opendnp3::CommandStatus::SUCCESS
        )

        .def(
            "__eq__",
            &opendnp3::AnalogOutputDouble64::operator==,
            "Equality comparision."
        );
}

#endif // PYDNP3_OPENDNP3
#endif
