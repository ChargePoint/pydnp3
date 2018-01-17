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
from pydnp3 import opendnp3 as opendnp3
from pydnp3 import openpal as openpal


class TestEnumClasses():

    def test_enumerations(self):
        """
            Test if the enumeration exists.
        """
        assert asiodnp3.Error is not None
        assert openpal.FloatByteOrderValue is not None
        assert opendnp3.EventType is not None
        assert opendnp3.EventClass is not None
        assert opendnp3.IINBit is not None
        assert opendnp3.AnalogOutputStatusQuality is not None
        assert opendnp3.AnalogQuality is not None
        assert opendnp3.AssignClassType is not None
        assert opendnp3.AuthErrorCode is not None
        assert opendnp3.BinaryOutputStatusQuality is not None
        assert opendnp3.BinaryQuality is not None
        assert opendnp3.ChallengeReason is not None
        assert opendnp3.ChannelState is not None
        assert opendnp3.CommandPointState is not None
        assert opendnp3.CommandStatus is not None
        assert opendnp3.ConfigAuthMode is not None
        assert opendnp3.ControlCode is not None
        assert opendnp3.CounterQuality is not None
        assert opendnp3.DoubleBit is not None
        assert opendnp3.DoubleBitBinaryQuality is not None
        assert opendnp3.EventAnalogOutputStatusVariation is not None
        assert opendnp3.EventAnalogVariation is not None
        assert opendnp3.EventBinaryOutputStatusVariation is not None
        assert opendnp3.EventBinaryVariation is not None
        assert opendnp3.EventCounterVariation is not None
        assert opendnp3.EventDoubleBinaryVariation is not None
        assert opendnp3.EventFrozenCounterVariation is not None
        assert opendnp3.EventMode is not None
        assert opendnp3.EventSecurityStatVariation is not None
        assert opendnp3.FlagsType is not None
        assert opendnp3.FlowControl is not None
        assert opendnp3.FrozenCounterQuality is not None
        assert opendnp3.FunctionCode is not None
        assert opendnp3.GroupVariation is not None
        assert opendnp3.HMACType is not None
        assert opendnp3.IndexMode is not None
        assert opendnp3.IntervalUnits is not None
        assert opendnp3.KeyChangeMethod is not None
        assert opendnp3.KeyStatus is not None
        assert opendnp3.KeyWrapAlgorithm is not None
        assert opendnp3.LinkFunction is not None
        assert opendnp3.LinkStatus is not None
        assert opendnp3.MasterTaskType is not None
        assert opendnp3.OperateType is not None
        assert opendnp3.Parity is not None
        assert opendnp3.PointClass is not None
        assert opendnp3.QualifierCode is not None
        assert opendnp3.RestartMode is not None
        assert opendnp3.RestartType is not None
        assert opendnp3.SecurityStatIndex is not None
        assert opendnp3.StaticAnalogOutputStatusVariation is not None
        assert opendnp3.StaticAnalogVariation is not None
        assert opendnp3.StaticBinaryOutputStatusVariation is not None
        assert opendnp3.StaticBinaryVariation is not None
        assert opendnp3.StaticCounterVariation is not None
        assert opendnp3.StaticDoubleBinaryVariation is not None
        assert opendnp3.StaticFrozenCounterVariation is not None
        assert opendnp3.StaticSecurityStatVariation is not None
        assert opendnp3.StaticTimeAndIntervalVariation is not None
        assert opendnp3.StaticTypeBitmask is not None
        assert opendnp3.StopBits is not None
        assert opendnp3.TaskCompletion is not None
        assert opendnp3.TimestampMode is not None
        assert opendnp3.TimeSyncMode is not None
        assert opendnp3.UserOperation is not None
        assert opendnp3.UserRole is not None

    def test_enum_type_from_type(self):
        """
            Convert the enumeration member to raw type, then convert back that raw type to enumeration member,
            and test if it returns the same thing.
        """
        rawAuthErrorCode = opendnp3.AuthErrorCodeToType(opendnp3.AuthErrorCode.UNKNOWN_USER)
        assert opendnp3.AuthErrorCodeFromType(rawAuthErrorCode) == opendnp3.AuthErrorCode.UNKNOWN_USER

        rawCertificateType = opendnp3.CertificateTypeToType(opendnp3.CertificateType.ATTRIBUTE_CERTIFICATE)
        assert opendnp3.CertificateTypeFromType(rawCertificateType) == opendnp3.CertificateType.ATTRIBUTE_CERTIFICATE

        rawChallengeReason = opendnp3.ChallengeReasonToType(opendnp3.ChallengeReason.UNKNOWN)
        assert opendnp3.ChallengeReasonFromType(rawChallengeReason) == opendnp3.ChallengeReason.UNKNOWN

        rawCommandStatus = opendnp3.CommandStatusToType(opendnp3.CommandStatus.ALREADY_COMPLETE)
        assert opendnp3.CommandStatusFromType(rawCommandStatus) == opendnp3.CommandStatus.ALREADY_COMPLETE

        rawControlCode = opendnp3.ControlCodeToType(opendnp3.ControlCode.TRIP_PULSE_ON)
        assert opendnp3.ControlCodeFromType(rawControlCode) == opendnp3.ControlCode.TRIP_PULSE_ON

        rawDoubleBit = opendnp3.DoubleBitToType(opendnp3.DoubleBit.DETERMINED_ON)
        assert opendnp3.DoubleBitFromType(rawDoubleBit) == opendnp3.DoubleBit.DETERMINED_ON

        rawFlagsType = opendnp3.FlagsTypeToType(opendnp3.FlagsType.Counter)
        assert opendnp3.FlagsTypeFromType(rawFlagsType) == opendnp3.FlagsType.Counter

        rawFlowControl = opendnp3.FlowControlToType(opendnp3.FlowControl.XONXOFF)
        assert opendnp3.FlowControlFromType(rawFlowControl) == opendnp3.FlowControl.XONXOFF

        rawFunctionCode = opendnp3.FunctionCodeToType(opendnp3.FunctionCode.AUTH_RESPONSE)
        assert opendnp3.FunctionCodeFromType(rawFunctionCode) == opendnp3.FunctionCode.AUTH_RESPONSE

        rawGroupVariation = opendnp3.GroupVariationToType(opendnp3.GroupVariation.Group40Var4)
        assert opendnp3.GroupVariationFromType(rawGroupVariation) == opendnp3.GroupVariation.Group40Var4

        rawHMACType = opendnp3.HMACTypeToType(opendnp3.HMACType.AES_GMAC)
        assert opendnp3.HMACTypeFromType(rawHMACType) == opendnp3.HMACType.AES_GMAC

        rawIntervalUnits = opendnp3.IntervalUnitsToType(opendnp3.IntervalUnits.NoRepeat)
        assert opendnp3.IntervalUnitsFromType(rawIntervalUnits) == opendnp3.IntervalUnits.NoRepeat

        rawKeyChangeMethod = opendnp3.KeyChangeMethodToType(opendnp3.KeyChangeMethod.UNDEFINED)
        assert opendnp3.KeyChangeMethodFromType(rawKeyChangeMethod) == opendnp3.KeyChangeMethod.UNDEFINED

        rawKeyStatus = opendnp3.KeyStatusToType(opendnp3.KeyStatus.OK)
        assert opendnp3.KeyStatusFromType(rawKeyStatus) == opendnp3.KeyStatus.OK

        rawKeyWrapAlgorithm = opendnp3.KeyWrapAlgorithmToType(opendnp3.KeyWrapAlgorithm.AES_256)
        assert opendnp3.KeyWrapAlgorithmFromType(rawKeyWrapAlgorithm) == opendnp3.KeyWrapAlgorithm.AES_256

        rawLinkFunction = opendnp3.LinkFunctionToType(opendnp3.LinkFunction.SEC_NACK)
        assert opendnp3.LinkFunctionFromType(rawLinkFunction) == opendnp3.LinkFunction.SEC_NACK

        rawParity = opendnp3.ParityToType(opendnp3.Parity.Even)
        assert opendnp3.ParityFromType(rawParity) == opendnp3.Parity.Even

        rawQualifierCode = opendnp3.QualifierCodeToType(opendnp3.QualifierCode.UINT8_CNT)
        assert opendnp3.QualifierCodeFromType(rawQualifierCode) == opendnp3.QualifierCode.UINT8_CNT

        rawStopBits = opendnp3.StopBitsToType(opendnp3.StopBits.One)
        assert opendnp3.StopBitsFromType(rawStopBits) == opendnp3.StopBits.One

        rawUserOperation = opendnp3.UserOperationToType(opendnp3.UserOperation.OP_ADD)
        assert opendnp3.UserOperationFromType(rawUserOperation) == opendnp3.UserOperation.OP_ADD

        rawUserRole = opendnp3.UserRoleToType(opendnp3.UserRole.ENGINEER)
        assert opendnp3.UserRoleFromType(rawUserRole) == opendnp3.UserRole.ENGINEER

    def test_enum_type_to_string(self):
        """
            Convert the enumeration member to string, and test is it returns the correct string.
        """
        assert opendnp3.AuthErrorCodeToString(opendnp3.AuthErrorCode.AUTHORIZATION_FAILED) == "AUTHORIZATION_FAILED"
        assert opendnp3.CertificateTypeToString(opendnp3.CertificateType.ID_CERTIFICATE) == "ID_CERTIFICATE"
        assert opendnp3.ChallengeReasonToString(opendnp3.ChallengeReason.CRITICAL) == "CRITICAL"
        assert opendnp3.ChannelStateToString(opendnp3.ChannelState.CLOSED) == "CLOSED"
        assert opendnp3.CommandPointStateToString(opendnp3.CommandPointState.SELECT_SUCCESS) == "SELECT_SUCCESS"
        assert opendnp3.CommandStatusToString(opendnp3.CommandStatus.DOWNSTREAM_FAIL) == "DOWNSTREAM_FAIL"
        assert opendnp3.ControlCodeToString(opendnp3.ControlCode.LATCH_ON) == "LATCH_ON"
        assert opendnp3.DoubleBitToString(opendnp3.DoubleBit.INTERMEDIATE) == "INTERMEDIATE"
        assert opendnp3.FlagsTypeToString(opendnp3.FlagsType.DoubleBinaryInput) == "DoubleBinaryInput"
        assert opendnp3.FlowControlToString(opendnp3.FlowControl.Hardware) == "Hardware"
        assert opendnp3.FunctionCodeToString(opendnp3.FunctionCode.GET_FILE_INFO) == "GET_FILE_INFO"
        assert opendnp3.GroupVariationToString(opendnp3.GroupVariation.Group1Var0) == "Binary Input - Any Variation"
        assert opendnp3.HMACTypeToString(opendnp3.HMACType.NO_MAC_VALUE) == "NO_MAC_VALUE"
        assert opendnp3.IntervalUnitsToString(opendnp3.IntervalUnits.Months9) == "Months9"
        assert opendnp3.KeyChangeMethodToString(opendnp3.KeyChangeMethod.AES_128_SHA1_HMAC) == "AES_128_SHA1_HMAC"
        assert opendnp3.KeyStatusToString(opendnp3.KeyStatus.COMM_FAIL) == "COMM_FAIL"
        assert opendnp3.KeyWrapAlgorithmToString(opendnp3.KeyWrapAlgorithm.AES_128) == "AES_128"
        assert opendnp3.LinkFunctionToString(opendnp3.LinkFunction.PRI_CONFIRMED_USER_DATA) == "PRI_CONFIRMED_USER_DATA"
        assert opendnp3.MasterTaskTypeToString(opendnp3.MasterTaskType.CLEAR_RESTART) == "CLEAR_RESTART"
        assert opendnp3.ParityToString(opendnp3.Parity.Odd) == "Odd"
        assert opendnp3.QualifierCodeToString(opendnp3.QualifierCode.UINT8_START_STOP) == "8-bit start stop"
        assert opendnp3.StopBitsToString(opendnp3.StopBits.OnePointFive) == "OnePointFive"
        assert opendnp3.TaskCompletionToString(opendnp3.TaskCompletion.FAILURE_BAD_RESPONSE) == "FAILURE_BAD_RESPONSE"
        assert opendnp3.UserOperationToString(opendnp3.UserOperation.OP_UNDEFINED) == "OP_UNDEFINED"
        assert opendnp3.UserRoleToString(opendnp3.UserRole.VIEWER) == "VIEWER"
