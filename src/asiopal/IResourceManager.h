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

#ifndef PYDNP3_ASIOPAL_IRESOURCEMANAGER_H
#define PYDNP3_ASIOPAL_IRESOURCEMANAGER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <asiopal/IResourceManager.h>

#ifdef PYDNP3_ASIOPAL

namespace py = pybind11;
using namespace std;

namespace asiopal
{
/**
* Overriding virtual functions from interface class IResource.
*/
    struct PyIResource : public IResource
    {
    public:
        /* Inherit the constructors */
        using IResource::IResource;

        /* Trampoline for IResource virtual functions */
        void Shutdown() override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IResource,
                Shutdown,
            );
        }
    };

/**
* Overriding virtual functions from interface class IResourceManager.
*/
    struct PyIResourceManager : public IResourceManager
    {
    public:
        /* Inherit the constructors */
        using IResourceManager::IResourceManager;

        /* Trampoline for IResourceManager virtual functions */
        void Detach(const std::shared_ptr<IResource>& resource) override {
            PYBIND11_OVERLOAD_PURE(
                void,
                IResourceManager,
                Detach,
                resource
            );
        }
    };
}

void bind_IResourceManager(py::module &m)
{
    // ----- struct: asiopal::IResource -----
	py::class_<asiopal::IResource, asiopal::PyIResource, std::shared_ptr<asiopal::IResource>>(m, "IResource",
	    "Anything that can be shutdown.")

	    .def(py::init<>())

        .def(
            "Shutdown",
            &asiopal::IResource::Shutdown,
            py::call_guard<py::gil_scoped_release>()
        );

    // ----- struct: asiopal::IResourceManager -----
	py::class_<asiopal::IResourceManager,
	           asiopal::PyIResourceManager,
	           std::shared_ptr<asiopal::IResourceManager>>(m, "IResourceManager")

	    .def(py::init<>())

        .def(
            "Detach",
            &asiopal::IResourceManager::Detach,
            "Notify the handler that the resource is shutting down, and it doesn't have to track it anymore."
        );
}

#endif // PYDNP3_ASIOPAL
#endif
