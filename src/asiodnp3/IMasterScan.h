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

#ifndef PYDNP3_ASIODNP3_IMASTERSCAN_H
#define PYDNP3_ASIODNP3_IMASTERSCAN_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/IMasterScan.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class IMasterScan.
*/
    class PyIMasterScan : public IMasterScan
    {
        /* Inherit the constructors */
        using IMasterScan::IMasterScan;

        /* Trampoline for IMasterScan virtual functions */
        void Demand() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IMasterScan,
                Demand,
            );
        }
    };
}

void bind_IMasterScan(py::module &m)
{
    // ----- class: asiodnp3::IMasterScan -----
    py::class_<asiodnp3::IMasterScan, asiodnp3::PyIMasterScan, std::shared_ptr<asiodnp3::IMasterScan>>(m, "IMasterScan",
        "Interface for interacting with a permanently bound scan.")

        .def(py::init<>())

        .def(
            "Demand",
            &asiodnp3::IMasterScan::Demand,
            "Request that the scan be performed as soon as possible."
        );
}

#endif // PYDNP3_ASIODNP3
#endif
