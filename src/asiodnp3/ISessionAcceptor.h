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

#ifndef PYDNP3_ASIODNP3_ISESSIONACCEPTOR_H
#define PYDNP3_ASIODNP3_ISESSIONACCEPTOR_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiodnp3/ISessionAcceptor.h>

#ifdef PYDNP3_ASIODNP3

namespace py = pybind11;

namespace asiodnp3
{
/**
* Overriding virtual functions from interface class ISessionAcceptor.
*/
    class PyISessionAcceptor : public ISessionAcceptor
    {
    public:
        /* Inherit the constructors */
        using ISessionAcceptor::ISessionAcceptor;

        /* Trampoline for ISessionAcceptor virtual functions */
        std::shared_ptr<IMasterSession> AcceptSession(const std::string& sessionid,
	                                                  std::shared_ptr<opendnp3::ISOEHandler> SOEHandler,
	                                                  std::shared_ptr<opendnp3::IMasterApplication> application,
	                                                  const MasterStackConfig& config) override {
            PYBIND11_OVERLOAD_PURE(
                std::shared_ptr<IMasterSession>,
                ISessionAcceptor,
                AcceptSession,
                sessionid, SOEHandler, application, config
            );
        }
    };
}

void bind_ISessionAcceptor(py::module &m)
{
    // ----- class: asiodnp3::ISessionAcceptor -----
    py::class_<asiodnp3::ISessionAcceptor, asiodnp3::PyISessionAcceptor>(m, "ISessionAcceptor",
        "Callback interface invoked when a new connection is accepted")

        .def(py::init<>())

        .def(
            "AcceptSession",
            &asiodnp3::ISessionAcceptor::AcceptSession,
            ":return: shared_ptr to asiodnp3.IMasterSession",
            py::arg("sessionid"), py::arg("SOEHandler"), py::arg("application"), py::arg("config")
        );
}

#endif // PYDNP3_ASIODNP3
#endif
