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

#ifndef PYDNP3_OPENDNP3_APP_PARSING_ICOLLECTION_H
#define PYDNP3_OPENDNP3_APP_PARSING_ICOLLECTION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/app/Indexed.h>
#include <opendnp3/app/parsing/ICollection.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

namespace openpal {
    class UInt48Type;
}

namespace opendnp3
{
    class Analog;
    class AnalogCommandEvent;
    class AnalogOutputStatus;
    class Binary;
    class BinaryCommandEvent;
    class BinaryOutputStatus;
    class CommandPointResult;
    class Counter;
    class DoubleBitBinary;
    class FrozenCounter;
    class OctetString;
    class TimeAndInterval;
    class SecurityStat;
    typedef openpal::UInt48Type DNPTime;

/**
* Overriding virtual functions from interface class IVisitor<T>.
*/
    template <class T>
    class PyIVisitor : public IVisitor<T>
    {
    public:
        /* Trampoline for IVisitor virtual functions */
        void OnValue(const T& value) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IVisitor<T>,
                OnValue,
                value
            );
        }
    };

/**
* Overriding virtual functions from interface class ICollection<T>.
*/
    template <class T>
    class PyICollection : public ICollection<T>
    {
    public:
        /* Trampoline for ICollection virtual functions */
        size_t Count() const override {
            PYBIND11_OVERLOAD_PURE(
                size_t,
                ICollection<T>,
                Count,
            );
        }
        void Foreach(IVisitor<T>& visitor) const override {
            PYBIND11_OVERLOAD_PURE(
                void,
                ICollection<T>,
                Foreach,
                visitor
            );
        }
    };
}

template <class T>
void declareIVisitor(py::module &m, string const & type)
{
    // ----- class: opendnp3::IVisitor<T> -----
    py::class_<opendnp3::IVisitor<T>, opendnp3::PyIVisitor<T>>(m, ("IVisitor" + type).c_str(),
        "Abstract way of visiting elements of a collection.")

        .def(py::init<>())

        .def(
            "OnValue",
            &opendnp3::IVisitor<T>::OnValue,
            py::arg("value")
        );
}

template <class T, class Fun>
void declareFunctorVisitor(py::module &m, string const & type)
{
    // ----- class: opendnp3::FunctorVisitor<T, Fun> -----
    py::class_<opendnp3::FunctorVisitor<T, Fun>, opendnp3::IVisitor<T>>(m, ("FunctorVisitor" + type).c_str(),
        "A visitor implemented as an abstract functor")

        .def(
            py::init<const Fun&>(),
            py::arg("fun")
        )

        .def(
            "OnValue",
            &opendnp3::FunctorVisitor<T, Fun>::OnValue,
            py::arg("value")
        );
}


template <class T>
void declareICollection(py::module &m, string const & type)
{
    typedef std::function<void(const T&)> Fun;

    declareIVisitor<T>(m, type);

    // ----- class: opendnp3::ICollection<T> -----
    py::class_<opendnp3::ICollection<T>, opendnp3::PyICollection<T>>(m, ("ICollection" + type).c_str(),
        "An interface representing an abstract immutable collection of things of type T. \n"
        "The user can only read these values via callback to receive each element.")

        .def(py::init<>())

        .def(
            "Count",
            &opendnp3::ICollection<T>::Count,
            "The number of elements in the collection."
        )

        .def(
            "Foreach",
            &opendnp3::ICollection<T>::Foreach,
            "Visit all the elements of a collection.",
            py::arg("visitor")
        )

        .def(
            "ReadOnlyValue",
            &opendnp3::ICollection<T>::ReadOnlyValue,
            "Retrieve the only value from the collection.",
            py::arg("value")
        )

        .def(
            "ForeachItem",
            [](opendnp3::ICollection<T>& self, const Fun& fun)
            {
                opendnp3::FunctorVisitor<T, Fun> visitor(fun);
                self.Foreach(visitor);
            },
            "Visit all of the elements of a collection.",
            py::arg("callback")
        );
}

void bind_ICollection(py::module &m)
{
    declareICollection<opendnp3::Indexed<opendnp3::Binary>>(m, "IndexedBinary");
    declareICollection<opendnp3::Indexed<opendnp3::DoubleBitBinary>>(m, "IndexedDoubleBitBinary");
    declareICollection<opendnp3::Indexed<opendnp3::Analog>>(m, "IndexedAnalog");
    declareICollection<opendnp3::Indexed<opendnp3::Counter>>(m, "IndexedCounter");
    declareICollection<opendnp3::Indexed<opendnp3::FrozenCounter>>(m, "IndexedFrozenCounter");
    declareICollection<opendnp3::Indexed<opendnp3::BinaryOutputStatus>>(m, "IndexedBinaryOutputStatus");
    declareICollection<opendnp3::Indexed<opendnp3::AnalogOutputStatus>>(m, "IndexedAnalogOutputStatus");
    declareICollection<opendnp3::Indexed<opendnp3::OctetString>>(m, "IndexedOctetString");
    declareICollection<opendnp3::Indexed<opendnp3::TimeAndInterval>>(m, "IndexedTimeAndInterval");
    declareICollection<opendnp3::Indexed<opendnp3::BinaryCommandEvent>>(m, "IndexedBinaryCommandEvent");
    declareICollection<opendnp3::Indexed<opendnp3::AnalogCommandEvent>>(m, "IndexedAnalogCommandEvent");
    declareICollection<opendnp3::Indexed<opendnp3::SecurityStat>>(m, "IndexedSecurityStat");
    declareICollection<opendnp3::DNPTime>(m, "DNPTime");
    declareICollection<opendnp3::CommandPointResult>(m, "CommandPointResult");
}

#endif // PYDNP3_OPENDNP3
#endif
