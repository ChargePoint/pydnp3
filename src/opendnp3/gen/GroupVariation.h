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

#ifndef PYDNP3_OPENDNP3_GEN_GROUPVARIATION_H
#define PYDNP3_OPENDNP3_GEN_GROUPVARIATION_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <opendnp3/gen/GroupVariation.h>

#ifdef PYDNP3_OPENDNP3

namespace py = pybind11;
using namespace std;

void bind_GroupVariation(py::module &m)
{
    // ----- enum class: opendnp3::GroupVariation -----
    py::enum_<opendnp3::GroupVariation>(m, "GroupVariation",
        "Comprehensive list of supported groups and variations.")

        .value("Group1Var0", opendnp3::GroupVariation::Group1Var0)
        .value("Group1Var1", opendnp3::GroupVariation::Group1Var1)
        .value("Group1Var2", opendnp3::GroupVariation::Group1Var2)
        .value("Group2Var0", opendnp3::GroupVariation::Group2Var0)
        .value("Group2Var1", opendnp3::GroupVariation::Group2Var1)
        .value("Group2Var2", opendnp3::GroupVariation::Group2Var2)
        .value("Group2Var3", opendnp3::GroupVariation::Group2Var3)
        .value("Group3Var0", opendnp3::GroupVariation::Group3Var0)
        .value("Group3Var1", opendnp3::GroupVariation::Group3Var1)
        .value("Group3Var2", opendnp3::GroupVariation::Group3Var2)
        .value("Group4Var0", opendnp3::GroupVariation::Group4Var0)
        .value("Group4Var1", opendnp3::GroupVariation::Group4Var1)
        .value("Group4Var2", opendnp3::GroupVariation::Group4Var2)
        .value("Group4Var3", opendnp3::GroupVariation::Group4Var3)
        .value("Group10Var0", opendnp3::GroupVariation::Group10Var0)
        .value("Group10Var1", opendnp3::GroupVariation::Group10Var1)
        .value("Group10Var2", opendnp3::GroupVariation::Group10Var2)
        .value("Group11Var0", opendnp3::GroupVariation::Group11Var0)
        .value("Group11Var1", opendnp3::GroupVariation::Group11Var1)
        .value("Group11Var2", opendnp3::GroupVariation::Group11Var2)
        .value("Group12Var0", opendnp3::GroupVariation::Group12Var0)
        .value("Group12Var1", opendnp3::GroupVariation::Group12Var1)
        .value("Group13Var1", opendnp3::GroupVariation::Group13Var1)
        .value("Group13Var2", opendnp3::GroupVariation::Group13Var2)
        .value("Group20Var0", opendnp3::GroupVariation::Group20Var0)
        .value("Group20Var1", opendnp3::GroupVariation::Group20Var1)
        .value("Group20Var2", opendnp3::GroupVariation::Group20Var2)
        .value("Group20Var5", opendnp3::GroupVariation::Group20Var5)
        .value("Group20Var6", opendnp3::GroupVariation::Group20Var6)
        .value("Group21Var0", opendnp3::GroupVariation::Group21Var0)
        .value("Group21Var1", opendnp3::GroupVariation::Group21Var1)
        .value("Group21Var2", opendnp3::GroupVariation::Group21Var2)
        .value("Group21Var5", opendnp3::GroupVariation::Group21Var5)
        .value("Group21Var6", opendnp3::GroupVariation::Group21Var6)
        .value("Group21Var9", opendnp3::GroupVariation::Group21Var9)
        .value("Group21Var10", opendnp3::GroupVariation::Group21Var10)
        .value("Group22Var0", opendnp3::GroupVariation::Group22Var0)
        .value("Group22Var1", opendnp3::GroupVariation::Group22Var1)
        .value("Group22Var2", opendnp3::GroupVariation::Group22Var2)
        .value("Group22Var5", opendnp3::GroupVariation::Group22Var5)
        .value("Group22Var6", opendnp3::GroupVariation::Group22Var6)
        .value("Group23Var0", opendnp3::GroupVariation::Group23Var0)
        .value("Group23Var1", opendnp3::GroupVariation::Group23Var1)
        .value("Group23Var2", opendnp3::GroupVariation::Group23Var2)
        .value("Group23Var5", opendnp3::GroupVariation::Group23Var5)
        .value("Group23Var6", opendnp3::GroupVariation::Group23Var6)
        .value("Group30Var0", opendnp3::GroupVariation::Group30Var0)
        .value("Group30Var1", opendnp3::GroupVariation::Group30Var1)
        .value("Group30Var2", opendnp3::GroupVariation::Group30Var2)
        .value("Group30Var3", opendnp3::GroupVariation::Group30Var3)
        .value("Group30Var4", opendnp3::GroupVariation::Group30Var4)
        .value("Group30Var5", opendnp3::GroupVariation::Group30Var5)
        .value("Group30Var6", opendnp3::GroupVariation::Group30Var6)
        .value("Group32Var0", opendnp3::GroupVariation::Group32Var0)
        .value("Group32Var1", opendnp3::GroupVariation::Group32Var1)
        .value("Group32Var2", opendnp3::GroupVariation::Group32Var2)
        .value("Group32Var3", opendnp3::GroupVariation::Group32Var3)
        .value("Group32Var4", opendnp3::GroupVariation::Group32Var4)
        .value("Group32Var5", opendnp3::GroupVariation::Group32Var5)
        .value("Group32Var6", opendnp3::GroupVariation::Group32Var6)
        .value("Group32Var7", opendnp3::GroupVariation::Group32Var7)
        .value("Group32Var8", opendnp3::GroupVariation::Group32Var8)
        .value("Group40Var0", opendnp3::GroupVariation::Group40Var0)
        .value("Group40Var1", opendnp3::GroupVariation::Group40Var1)
        .value("Group40Var2", opendnp3::GroupVariation::Group40Var2)
        .value("Group40Var3", opendnp3::GroupVariation::Group40Var3)
        .value("Group40Var4", opendnp3::GroupVariation::Group40Var4)            
        .value("Group41Var0", opendnp3::GroupVariation::Group41Var0)
        .value("Group41Var1", opendnp3::GroupVariation::Group41Var1)
        .value("Group41Var2", opendnp3::GroupVariation::Group41Var2)
        .value("Group41Var3", opendnp3::GroupVariation::Group41Var3)
        .value("Group41Var4", opendnp3::GroupVariation::Group41Var4)
        .value("Group42Var0", opendnp3::GroupVariation::Group42Var0)
        .value("Group42Var1", opendnp3::GroupVariation::Group42Var1)
        .value("Group42Var2", opendnp3::GroupVariation::Group42Var2)
        .value("Group42Var3", opendnp3::GroupVariation::Group42Var3)
        .value("Group42Var4", opendnp3::GroupVariation::Group42Var4)
        .value("Group42Var5", opendnp3::GroupVariation::Group42Var5)
        .value("Group42Var6", opendnp3::GroupVariation::Group42Var6)
        .value("Group42Var7", opendnp3::GroupVariation::Group42Var7)
        .value("Group42Var8", opendnp3::GroupVariation::Group42Var8)
        .value("Group43Var1", opendnp3::GroupVariation::Group43Var1)
        .value("Group43Var2", opendnp3::GroupVariation::Group43Var2)
        .value("Group43Var3", opendnp3::GroupVariation::Group43Var3)
        .value("Group43Var4", opendnp3::GroupVariation::Group43Var4)
        .value("Group43Var5", opendnp3::GroupVariation::Group43Var5)
        .value("Group43Var6", opendnp3::GroupVariation::Group43Var6)
        .value("Group43Var7", opendnp3::GroupVariation::Group43Var7)
        .value("Group43Var8", opendnp3::GroupVariation::Group43Var8)
        .value("Group50Var1", opendnp3::GroupVariation::Group50Var1)
        .value("Group50Var3", opendnp3::GroupVariation::Group50Var3)
        .value("Group50Var4", opendnp3::GroupVariation::Group50Var4)
        .value("Group51Var1", opendnp3::GroupVariation::Group51Var1)
        .value("Group51Var2", opendnp3::GroupVariation::Group51Var2)
        .value("Group52Var1", opendnp3::GroupVariation::Group52Var1)
        .value("Group52Var2", opendnp3::GroupVariation::Group52Var2)
        .value("Group60Var1", opendnp3::GroupVariation::Group60Var1)
        .value("Group60Var2", opendnp3::GroupVariation::Group60Var2)
        .value("Group60Var3", opendnp3::GroupVariation::Group60Var3)
        .value("Group60Var4", opendnp3::GroupVariation::Group60Var4)
        .value("Group70Var1", opendnp3::GroupVariation::Group70Var1)
        .value("Group70Var2", opendnp3::GroupVariation::Group70Var2)
        .value("Group70Var3", opendnp3::GroupVariation::Group70Var3)
        .value("Group70Var4", opendnp3::GroupVariation::Group70Var4)
        .value("Group70Var5", opendnp3::GroupVariation::Group70Var5)
        .value("Group70Var6", opendnp3::GroupVariation::Group70Var6)
        .value("Group70Var7", opendnp3::GroupVariation::Group70Var7)
        .value("Group70Var8", opendnp3::GroupVariation::Group70Var8)
        .value("Group80Var1", opendnp3::GroupVariation::Group80Var1)
        .value("Group110Var0", opendnp3::GroupVariation::Group110Var0)
        .value("Group111Var0", opendnp3::GroupVariation::Group111Var0)
        .value("Group112Var0", opendnp3::GroupVariation::Group112Var0)
        .value("Group113Var0", opendnp3::GroupVariation::Group113Var0)
        .value("Group120Var1", opendnp3::GroupVariation::Group120Var1)
        .value("Group120Var2", opendnp3::GroupVariation::Group120Var2)
        .value("Group120Var3", opendnp3::GroupVariation::Group120Var3)
        .value("Group120Var4", opendnp3::GroupVariation::Group120Var4)
        .value("Group120Var5", opendnp3::GroupVariation::Group120Var5)
        .value("Group120Var6", opendnp3::GroupVariation::Group120Var6)
        .value("Group120Var7", opendnp3::GroupVariation::Group120Var7)
        .value("Group120Var8", opendnp3::GroupVariation::Group120Var8)
        .value("Group120Var9", opendnp3::GroupVariation::Group120Var9)
        .value("Group120Var10", opendnp3::GroupVariation::Group120Var10)
        .value("Group120Var11", opendnp3::GroupVariation::Group120Var11)
        .value("Group120Var12", opendnp3::GroupVariation::Group120Var12)
        .value("Group120Var13", opendnp3::GroupVariation::Group120Var13)
        .value("Group120Var14", opendnp3::GroupVariation::Group120Var14)
        .value("Group120Var15", opendnp3::GroupVariation::Group120Var15)
        .value("Group121Var0", opendnp3::GroupVariation::Group121Var0)
        .value("Group121Var1", opendnp3::GroupVariation::Group121Var1)
        .value("Group122Var0", opendnp3::GroupVariation::Group122Var0)
        .value("Group122Var1", opendnp3::GroupVariation::Group122Var1)
        .value("Group122Var2", opendnp3::GroupVariation::Group122Var2)
        .value("UNKNOWN", opendnp3::GroupVariation::UNKNOWN);
    
    // ----- function: opendnp3::GroupVariationToType -----
    m.def(
        "GroupVariationToType",
        &opendnp3::GroupVariationToType,
        py::arg("gv")
    );
    
    // ----- function: opendnp3::GroupVariationFromType -----
    m.def(
        "GroupVariationFromType",
        &opendnp3::GroupVariationFromType,
        ":type rawType: unsigned short",
        py::arg("rawType")
    );
    
    // ----- function: opendnp3::GroupVariationToString -----
    m.def(
        "GroupVariationToString",
        &opendnp3::GroupVariationToString,
        py::arg("gv")
    );
}

#endif // PYDNP3_OPENDNP3
#endif
