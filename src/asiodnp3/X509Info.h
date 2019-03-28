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

#ifndef PYDNP3_ASIODNP3_X509INFO_H
#define PYDNP3_ASIODNP3_X509INFO_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/X509Info.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

void bind_X509Info(py::module &m)
{
    // ----- class: asiodnp3::X509Info -----
    py::class_<asiodnp3::X509Info>(m, "X509Info",
        "Select information from a preverified x509 certificate that user can can inspect an optionally reject.")

        .def(
            py::init<int, const openpal::RSlice, std::string>(),
            py::arg("depth"), py::arg("sha1thumbprint"), py::arg("subjectName")
        )

        .def_readwrite(
            "depth",
            &asiodnp3::X509Info::depth,
            "The depth of the certificate in the chain."
        )

        .def_readwrite(
            "sha1thumbprint",
            &asiodnp3::X509Info::sha1thumbprint,
            "The sha1 thumbprint."
        )

        .def_readwrite(
            "subjectName",
            &asiodnp3::X509Info::subjectName,
            "The extracted subject name."
        );
}

#endif // PYDNP3_ASIODNP3
#endif
