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

from pydnp3 import opendnp3 as opendnp3
from pydnp3 import openpal as openpal


class TestOperators():
    """
        Test operators: ==, >, <, |, |=, &=, ~, ()
    """

    def test_eq(self):
        assert opendnp3.AnalogCommandEvent() == opendnp3.AnalogCommandEvent(0.0, opendnp3.CommandStatus.SUCCESS)
        assert opendnp3.AnalogOutputInt16() == opendnp3.AnalogOutputInt16(0, opendnp3.CommandStatus.SUCCESS)
        assert opendnp3.AnalogOutputInt32() == opendnp3.AnalogOutputInt32(0, opendnp3.CommandStatus.SUCCESS)
        assert opendnp3.AnalogOutputFloat32() == opendnp3.AnalogOutputFloat32(0.0, opendnp3.CommandStatus.SUCCESS)
        assert opendnp3.AnalogOutputDouble64() == opendnp3.AnalogOutputDouble64(0.0, opendnp3.CommandStatus.SUCCESS)
        assert opendnp3.BinaryCommandEvent() == opendnp3.BinaryCommandEvent(opendnp3.Flags(0))
        assert opendnp3.ControlRelayOutputBlock() == opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON)
        assert opendnp3.IINField() == opendnp3.IINField(0x0, 0x0)
        assert openpal.__eq__(openpal.TimeDuration(), openpal.TimeDuration())
        assert openpal.__eq__(openpal.MonotonicTimestamp(), openpal.MonotonicTimestamp(0))

    def test_greater_than(self):
        assert openpal.__gt__(openpal.MonotonicTimestamp(120), openpal.MonotonicTimestamp(60))

    def test_less_than(self):
        assert openpal.__lt__(openpal.MonotonicTimestamp(120), openpal.MonotonicTimestamp(360))

    def test_IINField_or(self):
        assert (opendnp3.IINField(0x0, 0x0) | opendnp3.IINField(0x0, 0x1)) == opendnp3.IINField(0x0, 0x1)

    def test_IINField_ior(self):
        field = opendnp3.IINField(0x0, 0x0)
        field |= opendnp3.IINField(0x0, 0x1)
        assert field == opendnp3.IINField(0x0, 0x1)

    def test_IINField_and(self):
        assert (opendnp3.IINField(0x1, 0x1) & opendnp3.IINField(0x1, 0x0)) == opendnp3.IINField(0x1, 0x0)

    def test_IINField_iand(self):
        field = opendnp3.IINField(0x1, 0x1)
        field &= opendnp3.IINField(0x1, 0x0)
        assert field == opendnp3.IINField(0x1, 0x0)

    def test_IINField_invert(self):
        assert ~opendnp3.IINField(0x1, 0x0) == opendnp3.IINField(0xFE, 0xFF)

    def test_buffer_call(self):
        assert openpal.Buffer()() is not None