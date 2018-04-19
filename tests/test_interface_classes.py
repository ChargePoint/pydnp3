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


class TestInterfaceClasses():

    def test_constructors(self):
        """
            Create the interface class object and test if the object is not empty.
        """
        assert asiodnp3.IChannel() is not None
        assert asiodnp3.IChannelListener() is not None
        assert asiodnp3.IListenCallbacks() is not None
        assert asiodnp3.IMaster() is not None
        assert asiodnp3.IMasterOperations() is not None
        assert asiodnp3.IMasterScan() is not None
        assert asiodnp3.IMasterSession() is not None
        assert asiodnp3.IOutstation() is not None
        assert asiodnp3.ISessionAcceptor() is not None
        assert asiodnp3.IStack() is not None
        assert asiopal.IAsyncChannel(asiopal.Executor(asiopal.IO())) is not None
        assert asiopal.IChannelCallbacks() is not None
        assert asiopal.IListener() is not None
        assert asiopal.IO() is not None
        assert asiopal.IOpenDelayStrategy() is not None
        assert asiopal.IResource() is not None
        assert asiopal.IResourceManager() is not None
        assert opendnp3.IVisitorIndexedBinary() is not None
        assert opendnp3.IVisitorIndexedDoubleBitBinary() is not None
        assert opendnp3.IVisitorIndexedAnalog() is not None
        assert opendnp3.IVisitorIndexedCounter() is not None
        assert opendnp3.IVisitorIndexedFrozenCounter() is not None
        assert opendnp3.IVisitorIndexedBinaryOutputStatus() is not None
        assert opendnp3.IVisitorIndexedAnalogOutputStatus() is not None
        assert opendnp3.IVisitorIndexedOctetString() is not None
        assert opendnp3.IVisitorIndexedTimeAndInterval() is not None
        assert opendnp3.IVisitorIndexedBinaryCommandEvent() is not None
        assert opendnp3.IVisitorIndexedAnalogCommandEvent() is not None
        assert opendnp3.IVisitorIndexedSecurityStat() is not None
        assert opendnp3.IVisitorDNPTime() is not None
        assert opendnp3.IVisitorCommandPointResult() is not None
        assert opendnp3.ICollectionIndexedBinary() is not None
        assert opendnp3.ICollectionIndexedDoubleBitBinary() is not None
        assert opendnp3.ICollectionIndexedAnalog() is not None
        assert opendnp3.ICollectionIndexedCounter() is not None
        assert opendnp3.ICollectionIndexedFrozenCounter() is not None
        assert opendnp3.ICollectionIndexedBinaryOutputStatus() is not None
        assert opendnp3.ICollectionIndexedAnalogOutputStatus() is not None
        assert opendnp3.ICollectionIndexedOctetString() is not None
        assert opendnp3.ICollectionIndexedTimeAndInterval() is not None
        assert opendnp3.ICollectionIndexedBinaryCommandEvent() is not None
        assert opendnp3.ICollectionIndexedAnalogCommandEvent() is not None
        assert opendnp3.ICollectionIndexedSecurityStat() is not None
        assert opendnp3.ICollectionDNPTime() is not None
        assert opendnp3.ICollectionCommandPointResult() is not None
        assert opendnp3.ITransactable() is not None
        assert opendnp3.ILinkListener() is not None
        assert opendnp3.ICommandCollectionControlRelayOutputBlock() is not None
        assert opendnp3.ICommandCollectionAnalogOutputInt32() is not None
        assert opendnp3.ICommandCollectionAnalogOutputInt16() is not None
        assert opendnp3.ICommandCollectionAnalogOutputFloat32() is not None
        assert opendnp3.ICommandCollectionAnalogOutputDouble64() is not None
        assert opendnp3.ICommandProcessor() is not None
        assert opendnp3.ICommandTaskResult(opendnp3.TaskCompletion.SUCCESS) is not None
        assert opendnp3.IMasterApplication() is not None
        assert opendnp3.ISOEHandler() is not None
        assert opendnp3.ITaskCallback() is not None
        assert opendnp3.ICommandHandler() is not None
        assert opendnp3.IOutstationApplication() is not None
        assert opendnp3.IUpdateHandler() is not None
        assert openpal.IPhysicalLayerCallbacks() is not None
        assert openpal.IExecutor() is not None
        assert openpal.IMonotonicTimeSource() is not None
        assert openpal.ITimer() is not None
        assert openpal.ILogHandler() is not None

    def test_pure_virtual_functions(self):
        """
            Call the pure virtual function and test if it throws the correct exception error.
        """
        try:
            asiodnp3.IChannel().GetStatistics()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiodnp3.IChannelListener().OnStateChange(opendnp3.ChannelState.CLOSED)
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiodnp3.IListenCallbacks().AcceptConnection(123, "test")
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiodnp3.IMasterOperations().SetLogFilters(openpal.LogFilters())
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiodnp3.IMasterScan().Demand()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiodnp3.IMasterSession().GetStackStatistics()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiodnp3.IOutstation().SetRestartIIN()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiodnp3.IStack().Enable()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiopal.IOpenDelayStrategy().GetNextDelay(openpal.TimeDuration(), openpal.TimeDuration())
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            asiopal.IResource().Shutdown()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.IVisitorIndexedBinary().OnValue(opendnp3.IndexedBinary())
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.IVisitorDNPTime().OnValue(opendnp3.DNPTime())
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.IVisitorCommandPointResult().OnValue(opendnp3.CommandPointResult(
                100, 10, opendnp3.CommandPointState.INIT, opendnp3.CommandStatus.PROCESSING_LIMITED))
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ICollectionIndexedBinary().Count()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ICollectionDNPTime().Count()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ICollectionCommandPointResult().Count()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ITransactable().Start()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ICommandCollectionControlRelayOutputBlock().Add(opendnp3.ControlRelayOutputBlock(), 1)
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ICommandCollectionAnalogOutputDouble64().Add(opendnp3.AnalogOutputDouble64(), 1)
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ICommandTaskResult(opendnp3.TaskCompletion.SUCCESS).Count()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.IMasterApplication().Now()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ISOEHandler().Process(opendnp3.HeaderInfo(), opendnp3.ICollectionIndexedBinary())
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ITaskCallback().OnStart()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.ICommandHandler().Start()
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

        try:
            opendnp3.IUpdateHandler().Update(opendnp3.Binary(True), 1)
        except RuntimeError as err:
            assert "Tried to call pure virtual function" in str(err)

    def test_inline_virtual_functions(self):
        """
            Call the inline virtual function and test if it is called successful.
        """

        listener = opendnp3.ILinkListener()
        assert listener.OnStateChange(opendnp3.LinkStatus.RESET) is None
        assert listener.OnKeepAliveInitiated() is None
        assert listener.OnKeepAliveFailure() is None
        assert listener.OnKeepAliveSuccess() is None

        masterApplication = opendnp3.IMasterApplication()
        assert masterApplication.OnReceiveIIN(opendnp3.IINField(opendnp3.IINBit.ALL_STATIONS)) is None
        assert masterApplication.OnOpen() is None
        assert masterApplication.OnClose() is None
        assert masterApplication.AssignClassDuringStartup() == False
        # Methods inherited from ILinkListener
        assert masterApplication.OnStateChange(opendnp3.LinkStatus.RESET) is None
        assert masterApplication.OnKeepAliveInitiated() is None
        assert masterApplication.OnKeepAliveFailure() is None
        assert masterApplication.OnKeepAliveSuccess() is None

        outstationApplication = opendnp3.IOutstationApplication()
        assert outstationApplication.SupportsWriteAbsoluteTime() == False
        assert outstationApplication.WriteAbsoluteTime(openpal.UTCTimestamp()) == False
        assert outstationApplication.SupportsWriteTimeAndInterval() == False
        assert outstationApplication.WriteTimeAndInterval(opendnp3.ICollectionIndexedTimeAndInterval()) == False
        assert outstationApplication.SupportsAssignClass() == False
        assert outstationApplication.RecordClassAssignment(opendnp3.AssignClassType.AnalogInput,
                                                           opendnp3.PointClass.Class0, 1, 10) is None
        assert outstationApplication.ColdRestartSupport() == opendnp3.RestartMode.UNSUPPORTED
        assert outstationApplication.WarmRestartSupport() == opendnp3.RestartMode.UNSUPPORTED
        assert outstationApplication.ColdRestart() == 0xFFFF
        assert outstationApplication.WarmRestart() == 0xFFFF
        # Methods inherited from ILinkListener
        assert outstationApplication.OnStateChange(opendnp3.LinkStatus.RESET) is None
        assert outstationApplication.OnKeepAliveInitiated() is None
        assert outstationApplication.OnKeepAliveFailure() is None
        assert outstationApplication.OnKeepAliveSuccess() is None
