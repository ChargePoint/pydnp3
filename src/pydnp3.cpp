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

#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>

#include <map>

namespace py = pybind11;

typedef std::function<py::module&(std::string const &)> ModuleGetter;

// Split pydnp3 into multiple compilation units to reduce memory requirements
void init_openpal(py::module &);
void init_opendnp3(py::module &);
void init_asiopal(py::module &);
void init_asiodnp3(py::module &);

PYBIND11_MODULE(pydnp3, root_module) {

    // -------------------- SET-UP --------------------
    root_module.doc() = "Python bindings for opendnp3 library";

    std::map<std::string, py::module> modules = {
        {"asiodnp3", root_module.def_submodule("asiodnp3", "Bindings for asiodnp3 namespace")},
        {"asiopal",  root_module.def_submodule("asiopal",  "Bindings for asiopal namespace")},
        {"opendnp3", root_module.def_submodule("opendnp3", "Bindings for opendnp3 namespace")},
        {"openpal",  root_module.def_submodule("openpal",  "Bindings for openpal namespace")}
    };

    ModuleGetter M = [&](std::string const &namespace_) -> py::module&
    {
        return (modules.find(namespace_))->second;
    };

    // -------------------- PYDNP3.OPENPAL --------------------
    py::module openpal = M("openpal");
    init_openpal(openpal);

    // -------------------- PYDNP3.OPENDNP3 --------------------
    py::module opendnp3 = M("opendnp3");
    init_opendnp3(opendnp3);

    // -------------------- PYDNP3.ASIOPAL --------------------
    py::module asiopal = M("asiopal");
    init_asiopal(asiopal);

    // -------------------- PYDNP3.ASIODNP3 --------------------
    py::module asiodnp3 = M("asiodnp3");
    init_asiodnp3(asiodnp3);
}