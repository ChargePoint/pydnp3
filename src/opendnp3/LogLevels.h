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

#include <pybind11/pybind11.h>
#include <python2.7/Python.h>

#include <opendnp3/LogLevels.h>

namespace py = pybind11;
using namespace std;

class flags {};
class levels {};

void bind_OpendnpLogLevels(py::module &m)
{
    // ----- constants: opendnp3::flags -----
    py::class_<flags>flags_cls(m, "flags");
    flags_cls.attr("EVENT") = &opendnp3::flags::EVENT;
    flags_cls.attr("ERR") = &opendnp3::flags::ERR;
    flags_cls.attr("WARN") = &opendnp3::flags::WARN;
    flags_cls.attr("INFO") = &opendnp3::flags::INFO;
    flags_cls.attr("DBG") = &opendnp3::flags::DBG;
    flags_cls.attr("LINK_RX") = &opendnp3::flags::LINK_RX;
    flags_cls.attr("LINK_RX_HEX") = &opendnp3::flags::LINK_RX_HEX;
    flags_cls.attr("LINK_TX") = &opendnp3::flags::LINK_TX;
    flags_cls.attr("LINK_TX_HEX") = &opendnp3::flags::LINK_TX_HEX;
    flags_cls.attr("TRANSPORT_RX") = &opendnp3::flags::TRANSPORT_RX;
    flags_cls.attr("TRANSPORT_TX") = &opendnp3::flags::TRANSPORT_TX;
    flags_cls.attr("APP_HEADER_RX") = &opendnp3::flags::APP_HEADER_RX;
    flags_cls.attr("APP_HEADER_TX") = &opendnp3::flags::APP_HEADER_TX;
    flags_cls.attr("APP_OBJECT_RX") = &opendnp3::flags::APP_OBJECT_RX;
    flags_cls.attr("APP_OBJECT_TX") = &opendnp3::flags::APP_OBJECT_TX;
    flags_cls.attr("APP_HEX_RX") = &opendnp3::flags::APP_HEX_RX;
    flags_cls.attr("APP_HEX_TX") = &opendnp3::flags::APP_HEX_TX;

    // ----- constants: opendnp3::level -----
    py::class_<levels>levels_cls(m, "levels");
    levels_cls.attr("NOTHING") = &opendnp3::levels::NOTHING;
    levels_cls.attr("ALL") = &opendnp3::levels::ALL;
    levels_cls.attr("NORMAL") = &opendnp3::levels::NORMAL;
    levels_cls.attr("ALL_APP_COMMS") = &opendnp3::levels::ALL_APP_COMMS;
    levels_cls.attr("ALL_COMMS") = &opendnp3::levels::ALL_COMMS;

    // ----- func: LogFlagToString -----
    m.def("LogFlagToString", &opendnp3::LogFlagToString);
}