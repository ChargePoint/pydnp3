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


class TestConstructors():

    def test_default_constructors(self):
        """
            Create the class object with default values for instance variable and test if the object is not empty.
        """
        assert asiodnp3.ConsoleLogger() is not None
        assert asiodnp3.DefaultListenCallbacks() is not None
        assert asiodnp3.DefaultMasterApplication() is not None
        assert asiodnp3.MasterStackConfig() is not None
        assert asiodnp3.PrintingChannelListener is not None
        assert asiodnp3.PrintingSOEHandler() is not None
        assert asiodnp3.UpdateBuilder() is not None
        assert asiopal.ChannelRetry() is not None
        assert asiopal.ResourceManager() is not None
        assert asiopal.SerialSettings() is not None
        assert asiopal.steady_clock_t() is not None
        assert opendnp3.AnalogCommandEvent() is not None
        assert opendnp3.AnalogOutputInt16() is not None
        assert opendnp3.AnalogOutputInt32() is not None
        assert opendnp3.AnalogOutputFloat32() is not None
        assert opendnp3.AnalogOutputDouble64() is not None
        assert opendnp3.BinaryCommandEvent() is not None
        assert opendnp3.ClassField() is not None
        assert opendnp3.ControlRelayOutputBlock() is not None
        assert opendnp3.DNPTime() is not None
        assert opendnp3.Flags() is not None
        assert opendnp3.GroupVariationID() is not None
        assert opendnp3.IndexedBinary() is not None
        assert opendnp3.IndexedDoubleBitBinary() is not None
        assert opendnp3.IndexedAnalog() is not None
        assert opendnp3.IndexedCounter() is not None
        assert opendnp3.IndexedFrozenCounter() is not None
        assert opendnp3.IndexedBinaryOutputStatus() is not None
        assert opendnp3.IndexedAnalogOutputStatus() is not None
        assert opendnp3.IndexedOctetString() is not None
        assert opendnp3.IndexedTimeAndInterval() is not None
        assert opendnp3.IndexedBinaryCommandEvent() is not None
        assert opendnp3.IndexedAnalogCommandEvent() is not None
        assert opendnp3.IndexedSecurityStat() is not None
        assert opendnp3.IndexedControlRelayOutputBlock() is not None
        assert opendnp3.IndexedAnalogOutputInt16() is not None
        assert opendnp3.IndexedAnalogOutputInt32() is not None
        assert opendnp3.IndexedAnalogOutputFloat32() is not None
        assert opendnp3.IndexedAnalogOutputDouble64() is not None
        assert opendnp3.Binary() is not None
        assert opendnp3.DoubleBitBinary() is not None
        assert opendnp3.BinaryOutputStatus() is not None
        assert opendnp3.Analog() is not None
        assert opendnp3.Counter() is not None
        assert opendnp3.FrozenCounter() is not None
        assert opendnp3.AnalogOutputStatus() is not None
        assert opendnp3.TimeAndInterval() is not None
        assert opendnp3.OctetData() is not None
        assert opendnp3.OctetString() is not None
        assert opendnp3.SecurityStat() is not None
        assert opendnp3.LinkHeaderFields() is not None
        assert opendnp3.LinkStatistics() is not None
        assert opendnp3.CommandSet() is not None
        assert opendnp3.HeaderInfo() is not None
        assert opendnp3.StartStopRangeUint8() is not None
        assert opendnp3.StartStopRangeUint16() is not None
        assert opendnp3.CountUint8() is not None
        assert opendnp3.CountUint16() is not None
        assert opendnp3.HeaderUnion() is not None
        assert opendnp3.Header() is not None
        assert opendnp3.MasterParams() is not None
        assert opendnp3.RestartOperationResult() is not None
        assert opendnp3.TaskConfig() is not None
        assert opendnp3.ApplicationIIN() is not None
        assert opendnp3.DatabaseSizes() is not None
        assert opendnp3.EventBufferConfig() is not None
        assert opendnp3.OutstationConfig() is not None
        assert opendnp3.OutstationParams() is not None
        assert opendnp3.StaticTypeBitField() is not None
        assert opendnp3.StackStatistics() is not None
        assert opendnp3.IINField() is not None
        assert openpal.ArrayBinaryConfig() is not None
        assert openpal.ArrayDoubleBitBinaryConfig() is not None
        assert openpal.ArrayAnalogConfig() is not None
        assert openpal.ArrayCounterConfig() is not None
        assert openpal.ArrayFrozenCounterConfig() is not None
        assert openpal.ArrayBOStatusConfig() is not None
        assert openpal.ArrayAOStatusConfig() is not None
        assert openpal.ArrayTimeAndIntervalConfig() is not None
        assert openpal.ArrayBuffer() is not None
        assert openpal.ArrayViewBinaryConfig() is not None
        assert openpal.ArrayViewDoubleBitBinaryConfig() is not None
        assert openpal.ArrayViewAnalogConfig() is not None
        assert openpal.ArrayViewCounterConfig() is not None
        assert openpal.ArrayViewFrozenCounterConfig() is not None
        assert openpal.ArrayViewBOStatusConfig() is not None
        assert openpal.ArrayViewAOStatusConfig() is not None
        assert openpal.ArrayViewTimeAndIntervalConfig() is not None
        assert openpal.ArrayViewBuffer() is not None
        assert openpal.Buffer() is not None
        assert openpal.RingBuffer16() is not None
        assert openpal.RSlice() is not None
        assert openpal.SecureBuffer() is not None
        assert openpal.SettableRSlice() is not None
        assert openpal.SettableWSlice() is not None
        assert openpal.StaticBuffer4() is not None
        assert openpal.StaticBuffer14() is not None
        assert openpal.StaticBuffer100() is not None
        assert openpal.StaticBuffer292() is not None
        assert openpal.WSlice() is not None
        assert openpal.MonotonicTimestamp() is not None
        assert openpal.TimeDurationBase() is not None
        assert openpal.TimeDuration() is not None
        assert openpal.UTCTimestamp() is not None
        assert openpal.LogFilters() is not None
        assert openpal.Logger() is not None
        assert openpal.SerializerBinary() is not None
        assert openpal.SerializerDoubleBitBinary() is not None
        assert openpal.SerializerBinaryOutputStatus() is not None
        assert openpal.SerializerAnalog() is not None
        assert openpal.SerializerCounter() is not None
        assert openpal.SerializerFrozenCounter() is not None
        assert openpal.SerializerAnalogOutputStatus() is not None
        assert openpal.SerializerTimeAndInterval() is not None
        assert openpal.SerializerAnalogOutputInt16() is not None
        assert openpal.SerializerAnalogOutputInt32() is not None
        assert openpal.SerializerAnalogOutputFloat32() is not None
        assert openpal.SerializerAnalogOutputDouble64() is not None

    def test_passing_args(self):
        """
            Create the class object with defined arguments and test if the object is not empty.
        """
        assert asiodnp3.ConsoleLogger(True) is not None
        assert asiodnp3.DatabaseConfig(opendnp3.DatabaseSizes()) is not None
        assert asiodnp3.DNP3Manager(1) is not None
        assert asiodnp3.DNP3Manager(1, asiodnp3.ConsoleLogger().Create()) is not None
        assert asiodnp3.OutstationStackConfig(opendnp3.DatabaseSizes()) is not None
        assert asiodnp3.X509Info(1, openpal.RSlice(), "test") is not None
        assert asiopal.ChannelRetry(openpal.TimeDuration(), openpal.TimeDuration()) is not None
        assert asiopal.ChannelRetry(openpal.TimeDuration(), openpal.TimeDuration(),
                                    asiopal.IOpenDelayStrategy()) is not None
        assert asiopal.Executor(asiopal.IO()) is not None
        assert asiopal.IPEndpoint("127.0.0.1", 502) is not None
        assert asiopal.LoggingConnectionCondition(openpal.Logger()) is not None
        assert asiopal.SerialChannel(asiopal.Executor(asiopal.IO())) is not None
        assert asiopal.TCPClient(openpal.Logger(),
                                 asiopal.Executor(asiopal.IO()),
                                 asiopal.IPEndpoint("127.0.0.1", 502),
                                 "adapter") is not None
        assert asiopal.ThreadPool(openpal.Logger(), asiopal.IO(), 1) is not None
        assert asiopal.TLSConfig("~/files/peerCert", "~/files/localCert", "~/files/privateKey") is not None
        assert opendnp3.AnalogOutputInt16(1, opendnp3.CommandStatus.TIMEOUT) is not None
        assert opendnp3.AnalogOutputInt32(1, opendnp3.CommandStatus.FORMAT_ERROR) is not None
        assert opendnp3.AnalogOutputFloat32(1, opendnp3.CommandStatus.ALREADY_ACTIVE) is not None
        assert opendnp3.AnalogOutputDouble64(1, opendnp3.CommandStatus.LOCAL) is not None
        assert opendnp3.BinaryCommandEvent(opendnp3.Flags()) is not None
        assert opendnp3.BinaryCommandEvent(opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.BinaryCommandEvent(True, opendnp3.CommandStatus.TOO_MANY_OPS) is not None
        assert opendnp3.BinaryCommandEvent(False, opendnp3.CommandStatus.NOT_AUTHORIZED, opendnp3.DNPTime()) is not None
        assert opendnp3.ClassField(opendnp3.PointClass.Class0) is not None
        assert opendnp3.ClassField(1) is not None
        assert opendnp3.ClassField(True, False, True, False) is not None
        assert opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON, 1, 100, 100,
                                                opendnp3.CommandStatus.AUTOMATION_INHIBIT) is not None
        assert opendnp3.ControlRelayOutputBlock(0x1, 1, 100, 100, opendnp3.CommandStatus.AUTOMATION_INHIBIT) is not None
        assert opendnp3.GroupVariationID(0x10, 0x1) is not None
        assert opendnp3.IINField(opendnp3.IINBit.ALL_STATIONS) is not None
        assert opendnp3.IndexedBinary(opendnp3.Binary(), 1) is not None
        assert opendnp3.IndexedDoubleBitBinary(opendnp3.DoubleBitBinary(), 1) is not None
        assert opendnp3.IndexedAnalog(opendnp3.Analog(), 1) is not None
        assert opendnp3.IndexedCounter(opendnp3.Counter(), 1) is not None
        assert opendnp3.IndexedFrozenCounter(opendnp3.FrozenCounter(), 1) is not None
        assert opendnp3.IndexedBinaryOutputStatus(opendnp3.BinaryOutputStatus(), 1) is not None
        assert opendnp3.IndexedAnalogOutputStatus(opendnp3.AnalogOutputStatus(), 1) is not None
        assert opendnp3.IndexedOctetString(opendnp3.OctetString(), 1) is not None
        assert opendnp3.IndexedTimeAndInterval(opendnp3.TimeAndInterval(), 1) is not None
        assert opendnp3.IndexedBinaryCommandEvent(opendnp3.BinaryCommandEvent(), 1) is not None
        assert opendnp3.IndexedAnalogCommandEvent(opendnp3.AnalogCommandEvent(), 1) is not None
        assert opendnp3.IndexedSecurityStat(opendnp3.SecurityStat(), 1) is not None
        assert opendnp3.IndexedControlRelayOutputBlock(opendnp3.ControlRelayOutputBlock(), 1) is not None
        assert opendnp3.IndexedAnalogOutputInt16(opendnp3.AnalogOutputInt16(), 1) is not None
        assert opendnp3.IndexedAnalogOutputInt32(opendnp3.AnalogOutputInt32(), 1) is not None
        assert opendnp3.IndexedAnalogOutputFloat32(opendnp3.AnalogOutputFloat32(), 1) is not None
        assert opendnp3.IndexedAnalogOutputDouble64(opendnp3.AnalogOutputDouble64(), 1) is not None
        assert opendnp3.Binary(True) is not None
        assert opendnp3.Binary(opendnp3.Flags()) is not None
        assert opendnp3.Binary(opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.Binary(False, opendnp3.Flags()) is not None
        assert opendnp3.Binary(True, opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.DoubleBitBinary(opendnp3.DoubleBit(1), opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.BinaryOutputStatus(False, opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.Analog(1.2, opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.Counter(100, opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.FrozenCounter(2000, opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.AnalogOutputStatus(109.68, opendnp3.Flags(), opendnp3.DNPTime()) is not None
        assert opendnp3.TimeAndInterval(opendnp3.DNPTime(), 10, 0x1) is not None
        assert opendnp3.TimeAndInterval(opendnp3.DNPTime(), 10, opendnp3.IntervalUnits.Seconds) is not None
        assert opendnp3.OctetData(openpal.RSlice()) is not None
        assert opendnp3.OctetString(openpal.RSlice()) is not None
        assert opendnp3.SecurityStat(opendnp3.SecurityStatValue(), 0x1, opendnp3.DNPTime()) is not None
        assert opendnp3.SecurityStat(0x1, 10, 100) is not None
        assert opendnp3.SecurityStat(0x1, 10, 100, opendnp3.DNPTime()) is not None
        assert opendnp3.LinkConfig(True, True) is not None
        assert opendnp3.LinkConfig(True, False, 100, 10, 10, openpal.TimeDuration(), openpal.TimeDuration()) is not None
        assert opendnp3.LinkHeaderFields(opendnp3.LinkFunction.INVALID, False, True, False, 10, 10) is not None
        assert opendnp3.LinkStatistics(opendnp3.LinkStatisticsChannel(), opendnp3.LinkStatisticsParser()) is not None
        assert opendnp3.CommandPointResult(100, 10, opendnp3.CommandPointState.INIT,
                                           opendnp3.CommandStatus.PROCESSING_LIMITED) is not None
        assert opendnp3.HeaderInfo(opendnp3.GroupVariation.Group10Var0, opendnp3.QualifierCode.UINT8_CNT,
                                   opendnp3.TimestampMode.SYNCHRONIZED, 100) is not None
        assert opendnp3.RestartOperationResult(opendnp3.TaskCompletion.SUCCESS, openpal.TimeDuration()) is not None
        assert opendnp3.DatabaseSizes(0, 1, 2, 3, 4, 5, 6, 7) is not None
        assert opendnp3.EventBufferConfig(0, 1, 2, 3, 4, 5, 6, 7) is not None
        assert opendnp3.OutstationConfig(opendnp3.OutstationParams(), opendnp3.EventBufferConfig()) is not None
        assert opendnp3.OutstationParams(opendnp3.IndexMode.Contiguous, 0x3, openpal.TimeDuration(),
                                         openpal.TimeDuration(), openpal.TimeDuration(), openpal.TimeDuration(),
                                         10, 20, True, opendnp3.StaticTypeBitField(), opendnp3.ClassField()) is not None
        assert opendnp3.SimpleCommandHandler(opendnp3.CommandStatus.SUCCESS) is not None
        assert opendnp3.StaticTypeBitField(1) is not None
        assert opendnp3.StackStatistics(opendnp3.StackStatisticsLink(), opendnp3.StackStatisticsTransport()) is not None
        assert openpal.ArrayBinaryConfig(1) is not None
        assert openpal.ArrayDoubleBitBinaryConfig(1) is not None
        assert openpal.ArrayAnalogConfig(1) is not None
        assert openpal.ArrayCounterConfig(1) is not None
        assert openpal.ArrayFrozenCounterConfig(1) is not None
        assert openpal.ArrayBOStatusConfig(1) is not None
        assert openpal.ArrayAOStatusConfig(1) is not None
        assert openpal.ArrayTimeAndIntervalConfig(1) is not None
        assert openpal.ArrayBuffer(10) is not None
        assert openpal.Buffer(27) is not None
        assert openpal.Buffer(openpal.RSlice()) is not None
        assert openpal.LinkedListInt(5) is not None
        assert openpal.PairInt(5, 10) is not None
        assert openpal.RSlice(0xFF, 100) is not None
        assert openpal.SecureBuffer(10) is not None
        assert openpal.SecureBuffer(openpal.RSlice()) is not None
        assert openpal.WSlice(0x30, 20) is not None
        assert openpal.MonotonicTimestamp(100) is not None
        assert openpal.UTCTimestamp(900) is not None
        assert openpal.LogEntry("123", openpal.LogFilters(), "location 1", "test") is not None
        assert openpal.LogFilters(20) is not None
        assert openpal.LoggerSettings("234", openpal.LogFilters())

    def test_passing_kwargs(self):
        """
            Create the class object with defined kwargs and test if the object is not empty.
        """
        assert opendnp3.AnalogOutputInt16(status=opendnp3.CommandStatus.SUCCESS) is not None
        assert opendnp3.AnalogOutputInt32(status=opendnp3.CommandStatus.NO_SELECT) is not None
        assert opendnp3.AnalogOutputFloat32(status=opendnp3.CommandStatus.NOT_SUPPORTED) is not None
        assert opendnp3.AnalogOutputDouble64(status=opendnp3.CommandStatus.HARDWARE_ERROR) is not None
        assert opendnp3.ControlRelayOutputBlock(functionCode=opendnp3.ControlCode.NUL) is not None
        assert opendnp3.ControlRelayOutputBlock(rawCode=0xFF) is not None
        assert opendnp3.ControlRelayOutputBlock(rawCode=0xFF, status=opendnp3.CommandStatus.BLOCKED) is not None
        assert opendnp3.GroupVariationID(variation=0x2) is not None
        assert opendnp3.EventBufferConfig(maxDoubleBinaryEvents=5) is not None
        assert opendnp3.EventBufferConfig(maxFrozenCounterEvents=4) is not None
        assert opendnp3.EventBufferConfig(maxAnalogOutputStatusEvents=10) is not None
        assert opendnp3.EventBufferConfig(maxBinaryEvents=1, maxAnalogEvents=3, maxCounterEvents=2) is not None
        assert opendnp3.OutstationParams(indexMode=opendnp3.IndexMode.Contiguous) is not None
        assert opendnp3.OutstationParams(typesAllowedInClass0=opendnp3.StaticTypeBitField()) is not None
        assert opendnp3.OutstationParams(unsolClassMask=opendnp3.ClassField()) is not None
        assert opendnp3.OutstationParams(maxTxFragSize=20, maxRxFragSize=30, allowUnsolicited=True) is not None
        assert opendnp3.StartStopRangeUint8(stop=10) is not None
        assert opendnp3.StartStopRangeUint16(stop=20) is not None
        assert opendnp3.CountUint8(value=3) is not None
        assert opendnp3.CountUint16(value=27) is not None

        # CommandSet passing a list
        crob = opendnp3.ControlRelayOutputBlock(opendnp3.ControlCode.LATCH_ON)
        assert opendnp3.CommandSet(items=[opendnp3.WithIndex(crob, 0),
                                          opendnp3.WithIndex(crob, 1)]) is not None
