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

#ifndef PYDNP3_OPENDNP3_APP_ITRANSACTABLE_H
#define PYDNP3_OPENDNP3_APP_ITRANSACTABLE_H


#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/ITransactable.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace opendnp3
{
/**
* Overriding virtual functions from interface class ITransactable.
*/
    class PyITransactable : public ITransactable
    {
    public:
        /* Trampoline for ITransactable virtual functions */
        void Start() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ITransactable,
                Start,
            );
        }
        void End() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ITransactable,
                End,
            )
        }
    };

    class PubITransactable : public ITransactable
    {
    public:
        /* Make ITransactable protected member functions public */
        using ITransactable::Start;
        using ITransactable::End;
    };
}


void bind_ITransactable(py::module &m)
{
    // ----- class: opendnp3::ITransactable -----
    py::class_<opendnp3::ITransactable,
               opendnp3::PyITransactable,
               std::shared_ptr<opendnp3::ITransactable>>(m, "ITransactable",
        "Something that can be performed atomically or needing Start()/End() signals.")

        .def(py::init<>())

        .def(
            "Start",
            &opendnp3::PubITransactable::Start
        )

        .def(
            "End",
            &opendnp3::PubITransactable::End
        );

    // ----- class: opendnp3::Transaction -----
    py::class_<opendnp3::Transaction, std::shared_ptr<opendnp3::Transaction>>(m, "Transaction",
        "Uses RAII to safely perform a transaction.")

        .def(
            py::init<opendnp3::ITransactable&>(),
            py::arg("transactable")
        )

        .def(
            py::init<opendnp3::ITransactable*>(),
            py::arg("pTransactable")
        )

        .def_static(
            "Start",
            &opendnp3::Transaction::Start,
            py::arg("pTransactable")
        )

        .def_static(
            "End",
            &opendnp3::Transaction::End,
            py::arg("pTransactable")
        )

        .def_static(
            "Apply",
            &opendnp3::Transaction::Apply<void, opendnp3::ITransactable&, std::function<void(const opendnp3::Transaction&)>>,
            py::arg("transactable"), py::arg("fun")
        );
}

#endif // PYDNP3_OPENDNP3
#endif
