# -*- coding: utf-8 -*- {{{
# vim: set fenc=utf-8 ft=python sw=4 ts=4 sts=4 et:
#
# Copyright 2018, Kisensum.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Neither Kisensum, nor any of its employees, nor any jurisdiction or
# organization that has cooperated in the development of these materials,
# makes any warranty, express or implied, or assumes any legal liability
# or responsibility for the accuracy, completeness, or usefulness or any
# information, apparatus, product, software, or process disclosed, or
# represents that its use would not infringe privately owned rights.
# Reference herein to any specific commercial product, process, or service
# by trade name, trademark, manufacturer, or otherwise does not necessarily
# constitute or imply its endorsement, recommendation, or favoring by Kisensum.
# }}}

from pydnp3 import asiodnp3 as asiodnp3
from pydnp3 import asiopal as asiopal
from pydnp3 import opendnp3 as opendnp3
from pydnp3 import openpal as openpal


class TestTemplate():
    """
        Test functions return instance of template class.
    """
    def test_AnalogOutput(self):
        assert type(opendnp3.AnalogOutput(1)) == opendnp3.AnalogOutput_Int16
        assert type(opendnp3.AnalogOutput(99999)) == opendnp3.AnalogOutput_Int32
        assert type(opendnp3.AnalogOutput(1.22)) == opendnp3.AnalogOutput_Float

    def test_HasSize(self):
        assert type(openpal.HasSize(1)) == openpal.HasSizeUint16
        assert type(openpal.HasSize(99999)) == openpal.HasSizeUint32

    def test_Indexed(self):
        assert type(opendnp3.WithIndex(opendnp3.Binary(), 0)) == opendnp3.IndexedBinary
        assert type(opendnp3.WithIndex(opendnp3.DoubleBitBinary(), 0)) == opendnp3.IndexedDoubleBitBinary
        assert type(opendnp3.WithIndex(opendnp3.Analog(), 0)) == opendnp3.IndexedAnalog
        assert type(opendnp3.WithIndex(opendnp3.Counter(), 0)) == opendnp3.IndexedCounter
        assert type(opendnp3.WithIndex(opendnp3.FrozenCounter(), 0)) == opendnp3.IndexedFrozenCounter
        assert type(opendnp3.WithIndex(opendnp3.BinaryOutputStatus(), 0)) == opendnp3.IndexedBinaryOutputStatus
        assert type(opendnp3.WithIndex(opendnp3.AnalogOutputStatus(), 0)) == opendnp3.IndexedAnalogOutputStatus
        assert type(opendnp3.WithIndex(opendnp3.OctetString(), 0)) == opendnp3.IndexedOctetString
        assert type(opendnp3.WithIndex(opendnp3.TimeAndInterval(), 0)) == opendnp3.IndexedTimeAndInterval
        assert type(opendnp3.WithIndex(opendnp3.BinaryCommandEvent(), 0)) == opendnp3.IndexedBinaryCommandEvent
        assert type(opendnp3.WithIndex(opendnp3.AnalogCommandEvent(), 0)) == opendnp3.IndexedAnalogCommandEvent
        assert type(opendnp3.WithIndex(opendnp3.SecurityStat(), 0)) == opendnp3.IndexedSecurityStat
        assert type(opendnp3.WithIndex(opendnp3.ControlRelayOutputBlock(), 0)) == opendnp3.IndexedControlRelayOutputBlock
        assert type(opendnp3.WithIndex(opendnp3.AnalogOutputInt16(), 0)) == opendnp3.IndexedAnalogOutputInt16
        assert type(opendnp3.WithIndex(opendnp3.AnalogOutputInt32(), 0)) == opendnp3.IndexedAnalogOutputInt32
        assert type(opendnp3.WithIndex(opendnp3.AnalogOutputFloat32(), 0)) == opendnp3.IndexedAnalogOutputFloat32
        assert type(opendnp3.WithIndex(opendnp3.AnalogOutputDouble64(), 0)) == opendnp3.IndexedAnalogOutputDouble64

    def test_ArrayView(self):
        assert type(openpal.ArrayView(opendnp3.BinaryConfig(), 1)) == openpal.ArrayViewBinaryConfig
        assert type(openpal.ArrayView(opendnp3.DoubleBitBinaryConfig(), 1)) == openpal.ArrayViewDoubleBitBinaryConfig
        assert type(openpal.ArrayView(opendnp3.AnalogConfig(), 1)) == openpal.ArrayViewAnalogConfig
        assert type(openpal.ArrayView(opendnp3.CounterConfig(), 1)) == openpal.ArrayViewCounterConfig
        assert type(openpal.ArrayView(opendnp3.FrozenCounterConfig(), 1)) == openpal.ArrayViewFrozenCounterConfig
        assert type(openpal.ArrayView(opendnp3.BOStatusConfig(), 1)) == openpal.ArrayViewBOStatusConfig
        assert type(openpal.ArrayView(opendnp3.AOStatusConfig(), 1)) == openpal.ArrayViewAOStatusConfig
        assert type(openpal.ArrayView(opendnp3.TimeAndIntervalConfig(), 1)) == openpal.ArrayViewTimeAndIntervalConfig
