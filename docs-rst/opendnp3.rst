
pydnp3.opendnp3
***************

Bindings for opendnp3 namespace

**class pydnp3.opendnp3.AOStatusConfig**

   Bases: `pydnp3.opendnp3.DeadbandConfigAnalogOutputStatusInfo
   <#pydnp3.opendnp3.DeadbandConfigAnalogOutputStatusInfo>`_

   **__init__(self: pydnp3.opendnp3.AOStatusConfig) -> None**

**class pydnp3.opendnp3.Analog**

   Bases: `pydnp3.opendnp3.TypedMeasurementDouble
   <#pydnp3.opendnp3.TypedMeasurementDouble>`_

   Analogs are used for variable data points that usually reflect a
   real world value.  Good examples are current, voltage, sensor
   readouts, etc. Think of a speedometer guage.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.Analog) -> None

      2. __init__(self: pydnp3.opendnp3.Analog, value: float) -> None

      1. __init__(self: pydnp3.opendnp3.Analog, value: float, flags:
         pydnp3.opendnp3.Flags) -> None

      1. __init__(self: pydnp3.opendnp3.Analog, value: float, flags:
         pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime) -> None

**class pydnp3.opendnp3.AnalogCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   Occurs when an outstation receives and analog command. Maps to
   Group43.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.AnalogCommandEvent) -> None

      2. __init__(self: pydnp3.opendnp3.AnalogCommandEvent, value:
         float, status: pydnp3.opendnp3.CommandStatus) -> None

      1. __init__(self: pydnp3.opendnp3.AnalogCommandEvent, value:
         float, status: pydnp3.opendnp3.CommandStatus, time:
         pydnp3.opendnp3.DNPTime) -> None

   ``property value``

**class pydnp3.opendnp3.AnalogConfig**

   Bases: `pydnp3.opendnp3.DeadbandConfigAnalogInfo
   <#pydnp3.opendnp3.DeadbandConfigAnalogInfo>`_

   **__init__(self: pydnp3.opendnp3.AnalogConfig) -> None**

**pydnp3.opendnp3.AnalogOutput(*args, **kwargs)**

   Overloaded function.

   1. AnalogOutput(value: int = 0, status:
      pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS) ->
      pydnp3.opendnp3.AnalogOutput_Int16

   Return instance of class AnalogOutput<T>

   1. AnalogOutput(value: int = 0, status:
      pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS) ->
      pydnp3.opendnp3.AnalogOutput_Int32

   Return instance of class AnalogOutput<T>

   1. AnalogOutput(value: float = 0, status:
      pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS) ->
      pydnp3.opendnp3.AnalogOutput_Float

   Return instance of class AnalogOutput<T>

   1. AnalogOutput(value: float = 0, status:
      pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS) ->
      pydnp3.opendnp3.AnalogOutput_Double

   Return instance of class AnalogOutput<T>

**class pydnp3.opendnp3.AnalogOutputDouble64**

   Bases: `pydnp3.opendnp3.AnalogOutput_Double
   <#pydnp3.opendnp3.AnalogOutput_Double>`_

   Double precision analog output. The underlying serialization is
   Group41, Variation 3

   **__init__(self: pydnp3.opendnp3.AnalogOutputDouble64, value: float
   = 0, status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS)
   -> None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

**class pydnp3.opendnp3.AnalogOutputFloat32**

   Bases: `pydnp3.opendnp3.AnalogOutput_Float
   <#pydnp3.opendnp3.AnalogOutput_Float>`_

   Single precision analog output. The underlying serialization is
   Group41, Variation 3.

   **__init__(self: pydnp3.opendnp3.AnalogOutputFloat32, value: float
   = 0, status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS)
   -> None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

**class pydnp3.opendnp3.AnalogOutputInt16**

   Bases: `pydnp3.opendnp3.AnalogOutput_Int16
   <#pydnp3.opendnp3.AnalogOutput_Int16>`_

   16-bit signed integer analog output. The underlying serialization
   is Group41, Variation 2.

   **__init__(self: pydnp3.opendnp3.AnalogOutputInt16, value: int = 0,
   status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS) ->
   None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

**class pydnp3.opendnp3.AnalogOutputInt32**

   Bases: `pydnp3.opendnp3.AnalogOutput_Int32
   <#pydnp3.opendnp3.AnalogOutput_Int32>`_

   32-bit signed integer analog output. The underlying serialization
   is Group41, Variation 1.

   **__init__(self: pydnp3.opendnp3.AnalogOutputInt32, value: int = 0,
   status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS) ->
   None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

**class pydnp3.opendnp3.AnalogOutputStatus**

   Bases: `pydnp3.opendnp3.TypedMeasurementDouble
   <#pydnp3.opendnp3.TypedMeasurementDouble>`_

   Describes the last set value of the set-point.  Like the
   BinaryOutputStatus data type it is not well supported and its
   generally better practice to use an explicit analog.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.AnalogOutputStatus) -> None

      2. __init__(self: pydnp3.opendnp3.AnalogOutputStatus, value:
         float) -> None

      1. __init__(self: pydnp3.opendnp3.AnalogOutputStatus, value:
         float, flags: pydnp3.opendnp3.Flags) -> None

      1. __init__(self: pydnp3.opendnp3.AnalogOutputStatus, value:
         float, flags: pydnp3.opendnp3.Flags, time:
         pydnp3.opendnp3.DNPTime) -> None

**class pydnp3.opendnp3.AnalogOutputStatusQuality**

   Bases: ``pybind11_builtins.pybind11_object``

   Quality field bitmask for analog output status values

   Members:

      ONLINE : Set when the data is good, meaning that rest of the
      system can trust the value.

      RESTART : The quality all points get before we have established
      communication (or populated) the point.

      COMM_LOST : Set if communication has been lost with the source
      of the data (after establishing contact).

      REMOTE_FORCED : Set if the value is being forced to a fake value
      somewhere in the system.

      LOCAL_FORCED : Set if the value is being forced to a fake value
      on the original device.

      OVERRANGE : Set if a hardware input etc. is out of range and we
      are using a place holder value.

      REFERENCE_ERR : Set if calibration or reference voltage has been
      lost meaning readings are questionable.

      RESERVED : Reserved bit.

   **__init__(self: pydnp3.opendnp3.AnalogOutputStatusQuality, arg0:
   int) -> None**

**class pydnp3.opendnp3.AnalogOutput_Double**

   Bases: ``pybind11_builtins.pybind11_object``

   The object to represent a setpoint request from the master.  Think
   of this like turning a dial on the front of a machine to desired
   setting.

   **ValuesEqual(self: pydnp3.opendnp3.AnalogOutput_Double, lhs:
   pydnp3.opendnp3.AnalogOutput_Double) -> bool**

   **__init__(self: pydnp3.opendnp3.AnalogOutput_Double, value: float
   = 0, status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS)
   -> None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

   ``property status``

      The status value defaults to CS_SUCCESS for requests.

**class pydnp3.opendnp3.AnalogOutput_Float**

   Bases: ``pybind11_builtins.pybind11_object``

   The object to represent a setpoint request from the master.  Think
   of this like turning a dial on the front of a machine to desired
   setting.

   **ValuesEqual(self: pydnp3.opendnp3.AnalogOutput_Float, lhs:
   pydnp3.opendnp3.AnalogOutput_Float) -> bool**

   **__init__(self: pydnp3.opendnp3.AnalogOutput_Float, value: float =
   0, status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS)
   -> None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

   ``property status``

      The status value defaults to CS_SUCCESS for requests.

**class pydnp3.opendnp3.AnalogOutput_Int16**

   Bases: ``pybind11_builtins.pybind11_object``

   The object to represent a setpoint request from the master.  Think
   of this like turning a dial on the front of a machine to desired
   setting.

   **ValuesEqual(self: pydnp3.opendnp3.AnalogOutput_Int16, lhs:
   pydnp3.opendnp3.AnalogOutput_Int16) -> bool**

   **__init__(self: pydnp3.opendnp3.AnalogOutput_Int16, value: int =
   0, status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS)
   -> None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

   ``property status``

      The status value defaults to CS_SUCCESS for requests.

**class pydnp3.opendnp3.AnalogOutput_Int32**

   Bases: ``pybind11_builtins.pybind11_object``

   The object to represent a setpoint request from the master.  Think
   of this like turning a dial on the front of a machine to desired
   setting.

   **ValuesEqual(self: pydnp3.opendnp3.AnalogOutput_Int32, lhs:
   pydnp3.opendnp3.AnalogOutput_Int32) -> bool**

   **__init__(self: pydnp3.opendnp3.AnalogOutput_Int32, value: int =
   0, status: pydnp3.opendnp3.CommandStatus = CommandStatus.SUCCESS)
   -> None**

      :Parameters:
         *  **value** – defaults to 0

         *  **status** – defaults to opendnp3.CommandStatus.SUCCESS

   ``property status``

      The status value defaults to CS_SUCCESS for requests.

**class pydnp3.opendnp3.AnalogQuality**

   Bases: ``pybind11_builtins.pybind11_object``

   Quality field bitmask for analog values.

   Members:

      ONLINE : Set when the data is good, meaning that rest of the
      system can trust the value.

      RESTART : The quality all points get before we have established
      communication (or populated) the point.

      COMM_LOST : Set if communication has been lost with the source
      of the data (after establishing contact).

      REMOTE_FORCED : Set if the value is being forced to a fake value
      somewhere in the system.

      LOCAL_FORCED : Sett if the value is being forced to a fake value
      on the original device.

      OVERRANGE : Set if a hardware input etc. is out of range and we
      are using a place holder value.

      REFERENCE_ERR : Set if calibration or reference voltage has been
      lost meaning readings are questionable.

      RESERVED : Reserved bit.

   **__init__(self: pydnp3.opendnp3.AnalogQuality, arg0: int) ->
   None**

**class pydnp3.opendnp3.ApplicationIIN**

   Bases: ``pybind11_builtins.pybind11_object``

   Some IIN bits are necessarily controlled by the outstation
   application, not the underlying protocol stack.  This structure
   describes the state of the bits controllable by the application.

   **ToIIN(self: pydnp3.opendnp3.ApplicationIIN) ->
   `pydnp3.opendnp3.IINField <#pydnp3.opendnp3.IINField>`_**

   **__init__(self: pydnp3.opendnp3.ApplicationIIN) -> None**

**class pydnp3.opendnp3.AssignClassType**

   Bases: ``pybind11_builtins.pybind11_object``

   Groups that can be used inconjunction with the ASSIGN_CLASS
   function code.

   Members:

      BinaryInput

      DoubleBinaryInput

      Counter

      FrozenCounter

      AnalogInput

      BinaryOutputStatus

      AnalogOutputStatus

   **__init__(self: pydnp3.opendnp3.AssignClassType, arg0: int) ->
   None**

**class pydnp3.opendnp3.AuthErrorCode**

   Bases: ``pybind11_builtins.pybind11_object``

   Specifies the reason that an auth error message was transmitted.

   Members:

      AUTHENTICATION_FAILED : Supplied auth information.

      AGGRESSIVE_MODE_UNSUPPORTED : Aggressive mode not supported on
      this link.

      MAC_NOT_SUPPORTED : The specified MAC algorithm is not
      supported.

      KEY_WRAP_NOT_SUPPORTED : The key-wrap algorithm is not
      supported.

      AUTHORIZATION_FAILED : Authentication passed, but that user not
      authorized for requested operation.

      UPDATE_KEY_METHOD_NOT_PERMITTED : The outstation does not
      support specified key change method on this link.

      INVALID_SIGNATURE : The digital signature supplied in a user
      status change object was invalid.

      INVALID_CERTIFICATION_DATA : The certification data supplied in
      a user status change object was invalid.

      UNKNOWN_USER : The master attempted to change the Update Key of
      a user without a valid prior user status change.

      MAX_SESSION_KEY_STATUS_REQUESTS_EXCEEDED : The master on a
      different association has requred session key status too often.

      UNKNOWN : Unknown error code.

   **__init__(self: pydnp3.opendnp3.AuthErrorCode, arg0: int) ->
   None**

**pydnp3.opendnp3.AuthErrorCodeFromType(rawType: int) ->
`pydnp3.opendnp3.AuthErrorCode <#pydnp3.opendnp3.AuthErrorCode>`_**

**pydnp3.opendnp3.AuthErrorCodeToString(code:
pydnp3.opendnp3.AuthErrorCode) -> str**

**pydnp3.opendnp3.AuthErrorCodeToType(code:
pydnp3.opendnp3.AuthErrorCode) -> int**

**class pydnp3.opendnp3.BOStatusConfig**

   Bases: `pydnp3.opendnp3.EventConfigBinaryOutputStatusInfo
   <#pydnp3.opendnp3.EventConfigBinaryOutputStatusInfo>`_

   **__init__(self: pydnp3.opendnp3.BOStatusConfig) -> None**

**class pydnp3.opendnp3.Binary**

   Bases: `pydnp3.opendnp3.TypedMeasurementBool
   <#pydnp3.opendnp3.TypedMeasurementBool>`_

   The Binary data type is for describing on-off (boolean) type
   values.  Good examples of binaries are alarms, mode settings,
   enabled/disabled flags etc.  Think of it as a status LED on a piece
   of equipment.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.Binary) -> None

      2. __init__(self: pydnp3.opendnp3.Binary, value: bool) -> None

      3. __init__(self: pydnp3.opendnp3.Binary, flags:
         pydnp3.opendnp3.Flags) -> None

      4. __init__(self: pydnp3.opendnp3.Binary, flags:
         pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime) -> None

      5. __init__(self: pydnp3.opendnp3.Binary, value: bool, flags:
         pydnp3.opendnp3.Flags) -> None

      6. __init__(self: pydnp3.opendnp3.Binary, value: bool, flags:
         pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime) -> None

**class pydnp3.opendnp3.BinaryCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   Maps to Group13Var1/2.

   **GetFlags(self: pydnp3.opendnp3.BinaryCommandEvent) ->
   `pydnp3.opendnp3.Flags <#pydnp3.opendnp3.Flags>`_**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.BinaryCommandEvent) -> None

      2. __init__(self: pydnp3.opendnp3.BinaryCommandEvent, flags:
         pydnp3.opendnp3.Flags) -> None

      3. __init__(self: pydnp3.opendnp3.BinaryCommandEvent, flags:
         pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime) -> None

      4. __init__(self: pydnp3.opendnp3.BinaryCommandEvent, value:
         bool, status: pydnp3.opendnp3.CommandStatus) -> None

      5. __init__(self: pydnp3.opendnp3.BinaryCommandEvent, value:
         bool, status: pydnp3.opendnp3.CommandStatus, time:
         pydnp3.opendnp3.DNPTime) -> None

**class pydnp3.opendnp3.BinaryConfig**

   Bases: `pydnp3.opendnp3.EventConfigBinaryInfo
   <#pydnp3.opendnp3.EventConfigBinaryInfo>`_

   **__init__(self: pydnp3.opendnp3.BinaryConfig) -> None**

**class pydnp3.opendnp3.BinaryOutputStatus**

   Bases: `pydnp3.opendnp3.TypedMeasurementBool
   <#pydnp3.opendnp3.TypedMeasurementBool>`_

   BinaryOutputStatus is used for describing the current state of a
   control.  It is very infrequently used and many masters don’t
   provide any mechanisms for reading these values so their use is
   strongly discouraged, a Binary should be used instead.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.BinaryOutputStatus) -> None

      2. __init__(self: pydnp3.opendnp3.BinaryOutputStatus, value:
         bool) -> None

      3. __init__(self: pydnp3.opendnp3.BinaryOutputStatus, flags:
         pydnp3.opendnp3.Flags) -> None

      4. __init__(self: pydnp3.opendnp3.BinaryOutputStatus, flags:
         pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime) -> None

      5. __init__(self: pydnp3.opendnp3.BinaryOutputStatus, value:
         bool, flags: pydnp3.opendnp3.Flags) -> None

      6. __init__(self: pydnp3.opendnp3.BinaryOutputStatus, value:
         bool, flags: pydnp3.opendnp3.Flags, time:
         pydnp3.opendnp3.DNPTime) -> None

**class pydnp3.opendnp3.BinaryOutputStatusQuality**

   Bases: ``pybind11_builtins.pybind11_object``

   Quality field bitmask for binary output status values.

   Members:

      ONLINE : Set when the data is good, meaning that rest of the
      system can trust the value.

      RESTART : The quality all points get before we have established
      communication (or populated) the point.

      COMM_LOST : Set if communication has been lost with the source
      of the data (after establishing contact).

      REMOTE_FORCED : Set if the value is being forced to a fake value
      somewhere in the system.

      LOCAL_FORCED : Set if the value is being forced to a fake value
      on the original device.

      RESERVED1 : Reserved bit 1.

      RESERVED2 : Reserved bit 2.

      STATE : State bit.

   **__init__(self: pydnp3.opendnp3.BinaryOutputStatusQuality, arg0:
   int) -> None**

**class pydnp3.opendnp3.BinaryQuality**

   Bases: ``pybind11_builtins.pybind11_object``

   Quality field bitmask for binary values.

   Members:

      ONLINE : Set when the data is good, meaning that rest of the
      system can trust the value.

      RESTART : The quality all points get before we have established
      communication (or populated) the point.

      COMM_LOST : Set if communication has been lost with the source
      of the data (after establishing contact)

      REMOTE_FORCED : Set if the value is being forced to a fake value
      somewhere in the system.

      LOCAL_FORCED : Set if the value is being forced to a fake value
      on the original device.

      CHATTER_FILTER : Set if the value is oscillating very quickly
      and some events are being suppressed.

      RESERVED : Reserved bit.

      STATE : State bit.

   **__init__(self: pydnp3.opendnp3.BinaryQuality, arg0: int) ->
   None**

**class pydnp3.opendnp3.CertificateType**

   Bases: ``pybind11_builtins.pybind11_object``

   Specifies the reason that an auth error message was transmitted

   Members:

      ID_CERTIFICATE : ID certificate.

      ATTRIBUTE_CERTIFICATE : Attribute certificate.

      UNKNOWN : Unknown certificate type.

   **__init__(self: pydnp3.opendnp3.CertificateType, arg0: int) ->
   None**

**pydnp3.opendnp3.CertificateTypeFromType(rawType: int) ->
`pydnp3.opendnp3.CertificateType
<#pydnp3.opendnp3.CertificateType>`_**

**pydnp3.opendnp3.CertificateTypeToString(certificateType:
pydnp3.opendnp3.CertificateType) -> str**

**pydnp3.opendnp3.CertificateTypeToType(certificateType:
pydnp3.opendnp3.CertificateType) -> int**

**class pydnp3.opendnp3.ChallengeReason**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumerates reasons for a sec-auth challenge

   Members:

      CRITICAL : Challenging a critical function.

      UNKNOWN : Unknown reason

   **__init__(self: pydnp3.opendnp3.ChallengeReason, arg0: int) ->
   None**

**pydnp3.opendnp3.ChallengeReasonFromType(rawType: int) ->
`pydnp3.opendnp3.ChallengeReason
<#pydnp3.opendnp3.ChallengeReason>`_**

**pydnp3.opendnp3.ChallengeReasonToString(reason:
pydnp3.opendnp3.ChallengeReason) -> str**

**pydnp3.opendnp3.ChallengeReasonToType(reason:
pydnp3.opendnp3.ChallengeReason) -> int**

**class pydnp3.opendnp3.ChannelState**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration for possible states of a channel.

   Members:

      CLOSED : Offline and idle.

      OPENING : Trying to open.

      OPEN : Open.

      SHUTDOWN : Stopped and will never do anything again.

   **__init__(self: pydnp3.opendnp3.ChannelState, arg0: int) -> None**

**pydnp3.opendnp3.ChannelStateToString(state:
pydnp3.opendnp3.ChannelState) -> str**

**class pydnp3.opendnp3.ClassField**

   Bases: ``pybind11_builtins.pybind11_object``

   Specifies a set of event classes e.g. some subset of {0, 1, 2, 3}.

   **AllClasses() -> `pydnp3.opendnp3.ClassField
   <#pydnp3.opendnp3.ClassField>`_**

   **AllEventClasses() -> `pydnp3.opendnp3.ClassField
   <#pydnp3.opendnp3.ClassField>`_**

   **Clear(self: pydnp3.opendnp3.ClassField, field:
   pydnp3.opendnp3.ClassField) -> `None
   <#pydnp3.opendnp3.ClassField.None>`_**

   **GetBitfield(self: pydnp3.opendnp3.ClassField) -> int**

   **HasAnyClass(self: pydnp3.opendnp3.ClassField) -> bool**

   **HasClass0(self: pydnp3.opendnp3.ClassField) -> bool**

   **HasClass1(self: pydnp3.opendnp3.ClassField) -> bool**

   **HasClass2(self: pydnp3.opendnp3.ClassField) -> bool**

   **HasClass3(self: pydnp3.opendnp3.ClassField) -> bool**

   **HasEventClass(self: pydnp3.opendnp3.ClassField) -> bool**

   **HasEventType(self: pydnp3.opendnp3.ClassField, arg0:
   pydnp3.opendnp3.EventClass) -> bool**

   **Intersects(self: pydnp3.opendnp3.ClassField, other:
   pydnp3.opendnp3.ClassField) -> bool**

   **IsEmpty(self: pydnp3.opendnp3.ClassField) -> bool**

   **None() -> `pydnp3.opendnp3.ClassField
   <#pydnp3.opendnp3.ClassField>`_**

   **OnlyEventClasses(self: pydnp3.opendnp3.ClassField) ->
   `pydnp3.opendnp3.ClassField <#pydnp3.opendnp3.ClassField>`_**

   **Set(*args, **kwargs)**

      Overloaded function.

      1. Set(self: pydnp3.opendnp3.ClassField, field:
         pydnp3.opendnp3.ClassField) -> None

      2. Set(self: pydnp3.opendnp3.ClassField, pc:
         pydnp3.opendnp3.PointClass) -> None

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.ClassField) -> None

      2. __init__(self: pydnp3.opendnp3.ClassField, pc:
         pydnp3.opendnp3.PointClass) -> None

      3. __init__(self: pydnp3.opendnp3.ClassField, mask: int) -> None

      4. __init__(self: pydnp3.opendnp3.ClassField, class0: bool,
         class1: bool, class2: bool, class3: bool) -> None

**class pydnp3.opendnp3.CommandPointResult**

   Bases: ``pybind11_builtins.pybind11_object``

   Represents the result of a command operation on a particular point.

   **Equals(self: pydnp3.opendnp3.CommandPointResult, other:
   pydnp3.opendnp3.CommandPointResult) -> bool**

      Check the result for equality against another value.

   **__init__(self: pydnp3.opendnp3.CommandPointResult, headerIndex:
   int, index: int, state: pydnp3.opendnp3.CommandPointState, status:
   pydnp3.opendnp3.CommandStatus) -> None**

         Fully construct based on all members.

   ``property headerIndex``

      The index of the header when request was made (0-based).  :type
      headerIndex: unsigned int

   ``property index``

      The index of the command that was requested.  :type index:
      unsigned short

   ``property state``

      The final state of the command operation on this point.

   ``property status``

      The response value. This is only valid if state == SUCCESS or
      state == SELECT_FAIL.

**class pydnp3.opendnp3.CommandPointState**

   Bases: ``pybind11_builtins.pybind11_object``

   List the various states that an individual command object can be in
   after an SBO or direct operate request.

   Members:

      INIT : No corresponding response was ever received for this
      command point.

      SELECT_SUCCESS : A response to a select request was received and
      matched, but the operate did not complete.

      SELECT_MISMATCH : A response to a select operation did not
      contain the same value that was sent.

      SELECT_FAIL : A response to a select operation contained a
      command status other than success.

      OPERATE_FAIL : A response to an operate or direct operate did
      not match the request.

      SUCCESS : A matching response was received to the operate.

   **__init__(self: pydnp3.opendnp3.CommandPointState, arg0: int) ->
   None**

**pydnp3.opendnp3.CommandPointStateToString(state:
pydnp3.opendnp3.CommandPointState) -> str**

**class pydnp3.opendnp3.CommandSet**

   Bases: ``pybind11_builtins.pybind11_object``

   Provides a mechanism for building a set of one or more command
   headers.

   **Add(*args, **kwargs)**

      Overloaded function.

      1. Add(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedControlRelayOutputBlock]) -> None

      2. Add(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputInt16]) -> None

      3. Add(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputInt32]) -> None

      4. Add(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputFloat32]) -> None

      5. Add(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputDouble64]) -> None

   **StartHeader(*args, **kwargs)**

      Overloaded function.

      1. StartHeader(self: pydnp3.opendnp3.CommandSet) ->
         pydnp3.opendnp3.ICommandCollectionControlRelayOutputBlock

      Begin a header of the parameterized type.

      1. StartHeader(self: pydnp3.opendnp3.CommandSet) ->
         pydnp3.opendnp3.ICommandCollectionAnalogOutputInt16

      Begin a header of the parameterized type.

      1. StartHeader(self: pydnp3.opendnp3.CommandSet) ->
         pydnp3.opendnp3.ICommandCollectionAnalogOutputInt32

      Begin a header of the parameterized type.

      1. StartHeader(self: pydnp3.opendnp3.CommandSet) ->
         pydnp3.opendnp3.ICommandCollectionAnalogOutputFloat32

      Begin a header of the parameterized type.

      1. StartHeader(self: pydnp3.opendnp3.CommandSet) ->
         pydnp3.opendnp3.ICommandCollectionAnalogOutputDouble64

      Begin a header of the parameterized type.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.CommandSet) -> None

      Contrsuct an empty command set.

      1. __init__(self: pydnp3.opendnp3.CommandSet, arg0:
         pydnp3.opendnp3.CommandSet) -> None

      Construct a new command set and take ownership of the headers in
      argument.

      1. __init__(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedControlRelayOutputBlock]) -> None

      Construct a command set from a list of CROB.

      1. __init__(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputInt16]) -> None

      Construct a command set from a list of AOInt16.

      1. __init__(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputInt32]) -> None

      Construct a command set from a list of AOInt32.

      1. __init__(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputFloat32]) -> None

      Construct a command set from a list of AOFloat32.

      1. __init__(self: pydnp3.opendnp3.CommandSet, items:
         List[pydnp3.opendnp3.IndexedAnalogOutputDouble64]) -> None

      Construct a command set from a list of AODouble64.

**class pydnp3.opendnp3.CommandStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   An enumeration of result codes received from an outstation in
   response to command request.  These correspond to those defined in
   the DNP3 standard.

   Members:

      SUCCESS : Command was accepted, initiated, or queued.

      TIMEOUT : Command timed out before completing.

      NO_SELECT : Command requires being selected before operate,
      configuration issue.

      FORMAT_ERROR : Bad control code or timing values.

      NOT_SUPPORTED : Command is not implemented.

      ALREADY_ACTIVE : Command is all ready in progress or its all
      ready in that mode.

      HARDWARE_ERROR : Something is stopping the command, often a
      local/remote interlock.

      LOCAL : The function governed by the control is in local only
      control.

      TOO_MANY_OPS : The command has been done too often and has been
      throttled.

      NOT_AUTHORIZED : The command was rejected because the device
      denied it or an RTU intercepted it.

      AUTOMATION_INHIBIT : Command not accepted because it was
      prevented or inhibited by a local automation process, such as
      interlocking logic or synchrocheck.

      PROCESSING_LIMITED : Command not accepted because the device
      cannot process any more activities than are presently in
      progress.

      OUT_OF_RANGE : Command not accepted because the value is outside
      the acceptable range permitted for this point.

      DOWNSTREAM_LOCAL : Command not accepted because the outstation
      is forwarding the request to another downstream device which
      reported LOCAL.

      ALREADY_COMPLETE : Command not accepted because the outstation
      has already completed the requested operation.

      BLOCKED : Command not accepted because the requested function is
      specifically blocked at the outstation.

      CANCELLED : Command not accepted because the operation was
      cancelled.

      BLOCKED_OTHER_MASTER : Command not accepted because another
      master is communicating with the outstation and has exclusive
      rights to operate this control point

      DOWNSTREAM_FAIL : Command not accepted because the outstation is
      forwarding the request to another downstream device which cannot
      be reached or is otherwise incapable of performing the request.

      NON_PARTICIPATING : (Deprecated) indicates the outstation shall
      not issue or perform the control operation.

      UNDEFINED : 10 to 126 are currently reserved.

   **__init__(self: pydnp3.opendnp3.CommandStatus, arg0: int) ->
   None**

**pydnp3.opendnp3.CommandStatusFromType(rawType: int) ->
`pydnp3.opendnp3.CommandStatus <#pydnp3.opendnp3.CommandStatus>`_**

**pydnp3.opendnp3.CommandStatusToString(status:
pydnp3.opendnp3.CommandStatus) -> str**

**pydnp3.opendnp3.CommandStatusToType(status:
pydnp3.opendnp3.CommandStatus) -> int**

**class pydnp3.opendnp3.ConfigAuthMode**

   Bases: ``pybind11_builtins.pybind11_object``

   Configuration enum for the authentication mode.

   Members:

      NONE : No authentication.

      SAV5 : Secure authentication version 5.

   **__init__(self: pydnp3.opendnp3.ConfigAuthMode, arg0: int) ->
   None**

**class pydnp3.opendnp3.ControlCode**

   Bases: ``pybind11_builtins.pybind11_object``

   Defines the interoperable values of the Control Code.  Refer to
   pages 506-510 of 1815 for a full description.

   Members:

      NUL : Does not initiate an action or change an in-progress or
      pending command.

      NUL_CANCEL : Cancel in-progress and pending commands. Take no
      additional action.

      PULSE_ON : For activation model, set output to active for the
      duration of the On-time. For both complementary models, return
      NOT_SUPPORTED status.

      PULSE_ON_CANCEL : Cancel in-progress and pending commands,
      process the remainder of the fields as if the control code were
      PULSE_ON.

      PULSE_OFF : Non-interoperable code. Do not use for new
      applications. Return NOT_SUPPORTED.

      PULSE_OFF_CANCEL : Non-interoperable code. Do not use for new
      applications. Cancel in-progress and pending commands, process
      remainder of fields as if the control code were PULSE_OFF.

      LATCH_ON : For activation model, set output to active for the
      duration of the On-time. For complementary latch model, set the
      output to active. For complementary two-output model, set the
      close output to active for the duration of the On-time.

      LATCH_ON_CANCEL : Cancel in-progress and pending commands,
      process the remainder of the fields as if the control code were
      LATCH_ON.

      LATCH_OFF : For activation model, set output to active for the
      duration of the On-time. For complementary latch model, set the
      output to inactive. For complementary two-output model, set the
      trip output to active for the duration of the On-time.

      LATCH_OFF_CANCEL : Cancel in-progress and pending commands,
      process the remainder of the fields as if the control code were
      LATCH_OFF.

      CLOSE_PULSE_ON : For activation model, set output to active for
      the duration of the On-time. For complementary latch model, set
      the output to active. For complementary two-output model, set
      the close output to active for the duration of the On-time.

      CLOSE_PULSE_ON_CANCEL : Cancel in-progress and pending commands,
      process the remainder of the fields as if the control code were
      CLOSE_PULSE_ON.

      TRIP_PULSE_ON : For activation model, set output to active for
      the duration of the On-time. For complementary latch model, set
      the output to inactive. For complementary two-output model, set
      the trip output to active for the duration of the On-time.

      TRIP_PULSE_ON_CANCEL : Cancel in-progress and pending commands,
      process the remainder of the fields as if the control code were
      TRIP_PULSE_ON.

      UNDEFINED : Undefined command (used by DNP standard).

   **__init__(self: pydnp3.opendnp3.ControlCode, arg0: int) -> None**

**pydnp3.opendnp3.ControlCodeFromType(rawType: int) ->
`pydnp3.opendnp3.ControlCode <#pydnp3.opendnp3.ControlCode>`_**

**pydnp3.opendnp3.ControlCodeToString(code:
pydnp3.opendnp3.ControlCode) -> str**

**pydnp3.opendnp3.ControlCodeToType(code: pydnp3.opendnp3.ControlCode)
-> int**

**class pydnp3.opendnp3.ControlRelayOutputBlock**

   Bases: ``pybind11_builtins.pybind11_object``

   Describes an incoming control request from the master.  It is the
   applications responsibility to handle the request and return an
   approiate status code.  The PULSE_CLOSE and PULSE_TRIP ControlCodes
   require setting the mOnTimeMS, mOffTimeMS and mCount variables,
   otherwise just use the defaults.

   **ValuesEqual(self: pydnp3.opendnp3.ControlRelayOutputBlock, arg0:
   pydnp3.opendnp3.ControlRelayOutputBlock) -> bool**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.ControlRelayOutputBlock,
         functionCode: pydnp3.opendnp3.ControlCode =
         ControlCode.LATCH_ON, count: int = 1, onTimeMS: int = 100,
         offTimeMS: int = 100, status: pydnp3.opendnp3.CommandStatus =
         CommandStatus.SUCCESS) -> None

         Primary constructor where the control code is set by
         enumeration.

      :Parameters:
         *  **count** – defaults to 1

         *  **onTimeMS** – defaults to 100

         *  **offTimeMS** – defaults to 100

         *  **status** – defaults to opendnp3.ControlCode.LATCH_ON

      1. __init__(self: pydnp3.opendnp3.ControlRelayOutputBlock,
         rawCode: int, count: int = 1, onTimeMS: int = 100, offTimeMS:
         int = 100, status: pydnp3.opendnp3.CommandStatus =
         CommandStatus.SUCCESS) -> None

         Overloaded constructor that allows the user to set a raw
         control code for non-standard codes.

      :Parameters:
         *  **count** – defaults to 1

         *  **onTimeMS** – defaults to 100

         *  **offTimeMS** – defaults to 100

         *  **status** – defaults to opendnp3.ControlCode.LATCH_ON

   ``property count``

      The number of times to repeat the operation.

   ``property functionCode``

      Allows matching of exact code.

   ``property offTimeMS``

      The off time for the pulse train.

   ``property onTimeMS``

      The on time for the pulse train.

   ``property rawCode``

      The raw code in bytes.

   ``property status``

      Status of the resulting operation.

**class pydnp3.opendnp3.CountUint16**

   Bases: ``pybind11_builtins.pybind11_object``

   A template for an integer count.

   **__init__(self: pydnp3.opendnp3.CountUint16, value: int = 0) ->
   None**

**class pydnp3.opendnp3.CountUint8**

   Bases: ``pybind11_builtins.pybind11_object``

   A template for an integer count.

   **__init__(self: pydnp3.opendnp3.CountUint8, value: int = 0) ->
   None**

**class pydnp3.opendnp3.Counter**

   Bases: `pydnp3.opendnp3.TypedMeasurementUint32
   <#pydnp3.opendnp3.TypedMeasurementUint32>`_

   Counters are used for describing generally increasing values
   (non-negative!).  Good examples are total power consumed, max
   voltage. Think odometer on a car.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.Counter) -> None

      2. __init__(self: pydnp3.opendnp3.Counter, value: int) -> None

      1. __init__(self: pydnp3.opendnp3.Counter, value: int, flags:
         pydnp3.opendnp3.Flags) -> None

      1. __init__(self: pydnp3.opendnp3.Counter, value: int, flags:
         pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime) -> None

**class pydnp3.opendnp3.CounterConfig**

   Bases: `pydnp3.opendnp3.DeadbandConfigCounterInfo
   <#pydnp3.opendnp3.DeadbandConfigCounterInfo>`_

   **__init__(self: pydnp3.opendnp3.CounterConfig) -> None**

**class pydnp3.opendnp3.CounterQuality**

   Bases: ``pybind11_builtins.pybind11_object``

   Quality field bitmask for counter values.

   Members:

      ONLINE : Set when the data is good, meaning that rest of the
      system can trust the value.

      RESTART : The quality all points get before we have established
      communication (or populated) the point.

      COMM_LOST : Set if communication has been lost with the source
      of the data (after establishing contact).

      REMOTE_FORCED : Set if the value is being forced to a fake value
      somewhere in the system.

      LOCAL_FORCED : Set if the value is being forced to a fake value
      on the original device.

      ROLLOVER : Deprecated flag that indicates value has rolled over.

      DISCONTINUITY : Indicates an unusual change in value.

      RESERVED : Reserved bit.

   **__init__(self: pydnp3.opendnp3.CounterQuality, arg0: int) ->
   None**

**class pydnp3.opendnp3.DatabaseSizes**

   Bases: ``pybind11_builtins.pybind11_object``

   Specifies the number and type of measurements in an outstation
   database.

   **AllTypes(count: int) -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **AnalogOnly(count: int) -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **AnalogOutputStatusOnly(count: int) ->
   `pydnp3.opendnp3.DatabaseSizes <#pydnp3.opendnp3.DatabaseSizes>`_**

   **BinaryOnly(count: int) -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **BinaryOutputStatusOnly(count: int) ->
   `pydnp3.opendnp3.DatabaseSizes <#pydnp3.opendnp3.DatabaseSizes>`_**

   **CounterOnly(count: int) -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **DoubleBinaryOnly(count: int) -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **Empty() -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **FrozenCounterOnly(count: int) -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **TimeAndIntervalOnly(count: int) -> `pydnp3.opendnp3.DatabaseSizes
   <#pydnp3.opendnp3.DatabaseSizes>`_**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.DatabaseSizes) -> None

      Default constructor: set all arguments to 0.

      1. __init__(self: pydnp3.opendnp3.DatabaseSizes, numBinary: int,
         numDoubleBinary: int, numAnalog: int, numCounter: int,
         numFrozenCounter: int, numBinaryOutputStatus: int,
         numAnalogOutputStatus: int, numTimeAndInterval: int) -> None

   ``property numAnalog``

   ``property numAnalogOutputStatus``

   ``property numBinary``

   ``property numBinaryOutputStatus``

   ``property numCounter``

   ``property numDoubleBinary``

   ``property numFrozenCounter``

   ``property numTimeAndInterval``

**pydnp3.opendnp3.DeadbandConfig(*args, **kwargs)**

   Overloaded function.

   1. DeadbandConfig() -> pydnp3.opendnp3.DeadbandConfigAnalogInfo

   Return instance of class DeadbandConfig<Info>

   1. DeadbandConfig() -> pydnp3.opendnp3.DeadbandConfigCounterInfo

   Return instance of class DeadbandConfig<Info>

   1. DeadbandConfig() ->
      pydnp3.opendnp3.DeadbandConfigFrozenCounterInfo

   Return instance of class DeadbandConfig<Info>

   1. DeadbandConfig() ->
      pydnp3.opendnp3.DeadbandConfigAnalogOutputStatusInfo

   Return instance of class DeadbandConfig<Info>

**class pydnp3.opendnp3.DeadbandConfigAnalogInfo**

   Bases: `pydnp3.opendnp3.EventConfigAnalogInfo
   <#pydnp3.opendnp3.EventConfigAnalogInfo>`_

   **__init__(self: pydnp3.opendnp3.DeadbandConfigAnalogInfo) ->
   None**

**class pydnp3.opendnp3.DeadbandConfigAnalogOutputStatusInfo**

   Bases: `pydnp3.opendnp3.EventConfigAnalogOutputStatusInfo
   <#pydnp3.opendnp3.EventConfigAnalogOutputStatusInfo>`_

   **__init__(self:
   pydnp3.opendnp3.DeadbandConfigAnalogOutputStatusInfo) -> None**

**class pydnp3.opendnp3.DeadbandConfigCounterInfo**

   Bases: `pydnp3.opendnp3.EventConfigCounterInfo
   <#pydnp3.opendnp3.EventConfigCounterInfo>`_

   **__init__(self: pydnp3.opendnp3.DeadbandConfigCounterInfo) ->
   None**

**class pydnp3.opendnp3.DeadbandConfigFrozenCounterInfo**

   Bases: `pydnp3.opendnp3.EventConfigFrozenCounterInfo
   <#pydnp3.opendnp3.EventConfigFrozenCounterInfo>`_

   **__init__(self: pydnp3.opendnp3.DeadbandConfigFrozenCounterInfo)
   -> None**

**class pydnp3.opendnp3.DefaultOutstationApplication**

   Bases: `pydnp3.opendnp3.IOutstationApplication
   <#pydnp3.opendnp3.IOutstationApplication>`_

   A singleton with default setting useful for examples.

   **Create() -> `pydnp3.opendnp3.IOutstationApplication
   <#pydnp3.opendnp3.IOutstationApplication>`_**

      :Returns:
         shared_ptr to opendnp3.IOutstationApplication

   **__init__(self: pydnp3.opendnp3.DefaultOutstationApplication) ->
   None**

**class pydnp3.opendnp3.DoubleBit**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration for possible states of a double bit value.

   Members:

      INTERMEDIATE : Transitioning between end conditions.

      DETERMINED_OFF : End condition, determined to be OFF.

      DETERMINED_ON : End condition, determined to be ON.

      INDETERMINATE : Abnormal or custom condition

   **__init__(self: pydnp3.opendnp3.DoubleBit, arg0: int) -> None**

**class pydnp3.opendnp3.DoubleBitBinary**

   Bases: `pydnp3.opendnp3.TypedMeasurementDoubleBit
   <#pydnp3.opendnp3.TypedMeasurementDoubleBit>`_

   The Double-bit Binary data type has two stable states, on and off,
   and an in transit state.  Motor operated switches or binary valves
   are good examples.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.DoubleBitBinary) -> None

      2. __init__(self: pydnp3.opendnp3.DoubleBitBinary, value:
         pydnp3.opendnp3.DoubleBit) -> None

      3. __init__(self: pydnp3.opendnp3.DoubleBitBinary, flags:
         pydnp3.opendnp3.Flags) -> None

      4. __init__(self: pydnp3.opendnp3.DoubleBitBinary, flags:
         pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime) -> None

      5. __init__(self: pydnp3.opendnp3.DoubleBitBinary, value:
         pydnp3.opendnp3.DoubleBit, flags: pydnp3.opendnp3.Flags) ->
         None

      6. __init__(self: pydnp3.opendnp3.DoubleBitBinary, value:
         pydnp3.opendnp3.DoubleBit, flags: pydnp3.opendnp3.Flags,
         time: pydnp3.opendnp3.DNPTime) -> None

**class pydnp3.opendnp3.DoubleBitBinaryConfig**

   Bases: `pydnp3.opendnp3.EventConfigDoubleBitBinaryInfo
   <#pydnp3.opendnp3.EventConfigDoubleBitBinaryInfo>`_

   **__init__(self: pydnp3.opendnp3.DoubleBitBinaryConfig) -> None**

**class pydnp3.opendnp3.DoubleBitBinaryQuality**

   Bases: ``pybind11_builtins.pybind11_object``

   Quality field bitmask for double bit binary values.

   Members:

      ONLINE : Set when the data is good, meaning that rest of the
      system can trust the value.

      RESTART : The quality all points get before we have established
      communication (or populated) the point.

      COMM_LOST : Set if communication has been lost with the source
      of the data (after establishing contact).

      REMOTE_FORCED : Set if the value is being forced to a fake value
      somewhere in the system.

      LOCAL_FORCED : Set if the value is being forced to a fake value
      on the original device.

      CHATTER_FILTER : Set if the value is oscillating very quickly
      and some events are being suppressed.

      STATE1 : State bit 1.

      STATE2 : State bit 2.

   **__init__(self: pydnp3.opendnp3.DoubleBitBinaryQuality, arg0: int)
   -> None**

**pydnp3.opendnp3.DoubleBitFromType(rawType: int) ->
`pydnp3.opendnp3.DoubleBit <#pydnp3.opendnp3.DoubleBit>`_**

   type rawType: unsigned char

**pydnp3.opendnp3.DoubleBitToString(db: pydnp3.opendnp3.DoubleBit) ->
str**

**pydnp3.opendnp3.DoubleBitToType(db: pydnp3.opendnp3.DoubleBit) ->
int**

**class pydnp3.opendnp3.EventAnalogOutputStatusVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group42Var1

   Group42Var2

   Group42Var3

   Group42Var4

   Group42Var5

   Group42Var6

   Group42Var7

   Group42Var8

   **__init__(self: pydnp3.opendnp3.EventAnalogOutputStatusVariation,
   arg0: int) -> None**

**class pydnp3.opendnp3.EventAnalogVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group32Var1

   Group32Var2

   Group32Var3

   Group32Var4

   Group32Var5

   Group32Var6

   Group32Var7

   Group32Var8

   **__init__(self: pydnp3.opendnp3.EventAnalogVariation, arg0: int)
   -> None**

**class pydnp3.opendnp3.EventBinaryOutputStatusVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group11Var1

   Group11Var2

   **__init__(self: pydnp3.opendnp3.EventBinaryOutputStatusVariation,
   arg0: int) -> None**

**class pydnp3.opendnp3.EventBinaryVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group2Var1

   Group2Var2

   Group2Var3

   **__init__(self: pydnp3.opendnp3.EventBinaryVariation, arg0: int)
   -> None**

**class pydnp3.opendnp3.EventBufferConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   Configuration of maximum event counts per event type.  The
   underlying implementation uses a *preallocated* heap buffer to
   store events until they are transmitted to the master.  The size of
   this buffer is proportional to the TotalEvents() method, i.e. the
   sum of the maximum events for each type.  Implementations should
   configure the buffers to store a reasonable number events given the
   polling frequency and memory restrictions of the target platform.

   **AllTypes(sizes: int) -> `pydnp3.opendnp3.EventBufferConfig
   <#pydnp3.opendnp3.EventBufferConfig>`_**

         Construct the class using the same maximum for all types.
         This is mainly used for demo purposes.  You probably don’t
         want to use this method unless your implementation actually
         reports every type.

   **GetMaxEventsForType(self: pydnp3.opendnp3.EventBufferConfig,
   type: pydnp3.opendnp3.EventType) -> int**

      Retrieve the number of events using a type enumeration.

   **TotalEvents(self: pydnp3.opendnp3.EventBufferConfig) -> int**

      :Returns:
         the sum of all event count maximums (number of elements in
         preallocated buffer)

   **__init__(self: pydnp3.opendnp3.EventBufferConfig,
   maxBinaryEvents: int = 0, maxDoubleBinaryEvents: int = 0,
   maxAnalogEvents: int = 0, maxCounterEvents: int = 0,
   maxFrozenCounterEvents: int = 0, maxBinaryOutputStatusEvents: int =
   0, maxAnalogOutputStatusEvents: int = 0,
   maxSecurityStatisticEvents: int = 0) -> None**

         Construct the class specifying the maximum number of events
         for each type individually.

   ``property maxAnalogEvents``

      The number of analog events the outstation will buffer before
      overflowing.  :type : unsigned short

   ``property maxAnalogOutputStatusEvents``

      The number of analog output status events the outstation will
      buffer before overflowing.  :type maxAnalogOutputStatusEvents:
      unsigned short

   ``property maxBinaryEvents``

      The number of binary events the outstation will buffer before
      overflowing.  :type maxBinaryEvents: unsigned short

   ``property maxBinaryOutputStatusEvents``

      The number of binary output status events the outstation will
      buffer before overflowing.  :type maxBinaryOutputStatusEvents:
      unsigned short

   ``property maxCounterEvents``

      The number of counter events the outstation will buffer before
      overflowing.  :type maxAnalogEvents: unsigned short

   ``property maxDoubleBinaryEvents``

      The number of double bit binary events the outstation will
      buffer before overflowing.  :type maxDoubleBinaryEvents:
      unsigned short

   ``property maxFrozenCounterEvents``

      The number of frozen counter events the outstation will buffer
      before overflowing.  :type maxFrozenCounterEvents: unsigned
      short

   ``property maxSecurityStatisticEvents``

      The number of security statistic events the outstation will
      buffer before overflowing.  :type maxSecurityStatisticEvents:
      unsigned short

**class pydnp3.opendnp3.EventCellBaseBinaryOutputStatusSpec**

   Bases: ``pybind11_builtins.pybind11_object``

   Base class for different types of event metadata.

   **SetEventValue(self:
   pydnp3.opendnp3.EventCellBaseBinaryOutputStatusSpec, value:
   opendnp3::BinaryOutputStatus) -> None**

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.EventCellBaseBinarySpec**

   Bases: ``pybind11_builtins.pybind11_object``

   Base class for different types of event metadata.

   **SetEventValue(self: pydnp3.opendnp3.EventCellBaseBinarySpec,
   value: opendnp3::Binary) -> None**

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.EventCellBaseDoubleBitBinarySpec**

   Bases: ``pybind11_builtins.pybind11_object``

   Base class for different types of event metadata.

   **SetEventValue(self:
   pydnp3.opendnp3.EventCellBaseDoubleBitBinarySpec, value:
   opendnp3::DoubleBitBinary) -> None**

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.EventClass**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   EC1

   EC2

   EC3

   **__init__(self: pydnp3.opendnp3.EventClass, arg0: int) -> None**

**pydnp3.opendnp3.EventConfig(*args, **kwargs)**

   Overloaded function.

   1. EventConfig() -> pydnp3.opendnp3.EventConfigBinaryInfo

   Return instance of class EventConfig<Info>

   1. EventConfig() -> pydnp3.opendnp3.EventConfigDoubleBitBinaryInfo

   Return instance of class EventConfig<Info>

   1. EventConfig() -> pydnp3.opendnp3.EventConfigAnalogInfo

   Return instance of class EventConfig<Info>

   1. EventConfig() -> pydnp3.opendnp3.EventConfigCounterInfo

   Return instance of class EventConfig<Info>

   1. EventConfig() -> pydnp3.opendnp3.EventConfigFrozenCounterInfo

   Return instance of class EventConfig<Info>

   1. EventConfig() ->
      pydnp3.opendnp3.EventConfigBinaryOutputStatusInfo

   Return instance of class EventConfig<Info>

   1. EventConfig() ->
      pydnp3.opendnp3.EventConfigAnalogOutputStatusInfo

   Return instance of class EventConfig<Info>

**class pydnp3.opendnp3.EventConfigAnalogInfo**

   Bases: `pydnp3.opendnp3.StaticConfigAnalogInfo
   <#pydnp3.opendnp3.StaticConfigAnalogInfo>`_

   **__init__(self: pydnp3.opendnp3.EventConfigAnalogInfo) -> None**

**class pydnp3.opendnp3.EventConfigAnalogOutputStatusInfo**

   Bases: `pydnp3.opendnp3.StaticConfigAnalogOutputStatusInfo
   <#pydnp3.opendnp3.StaticConfigAnalogOutputStatusInfo>`_

   **__init__(self: pydnp3.opendnp3.EventConfigAnalogOutputStatusInfo)
   -> None**

**class pydnp3.opendnp3.EventConfigBinaryInfo**

   Bases: `pydnp3.opendnp3.StaticConfigBinaryInfo
   <#pydnp3.opendnp3.StaticConfigBinaryInfo>`_

   **__init__(self: pydnp3.opendnp3.EventConfigBinaryInfo) -> None**

**class pydnp3.opendnp3.EventConfigBinaryOutputStatusInfo**

   Bases: `pydnp3.opendnp3.StaticConfigBinaryOutputStatusInfo
   <#pydnp3.opendnp3.StaticConfigBinaryOutputStatusInfo>`_

   **__init__(self: pydnp3.opendnp3.EventConfigBinaryOutputStatusInfo)
   -> None**

**class pydnp3.opendnp3.EventConfigCounterInfo**

   Bases: `pydnp3.opendnp3.StaticConfigCounterInfo
   <#pydnp3.opendnp3.StaticConfigCounterInfo>`_

   **__init__(self: pydnp3.opendnp3.EventConfigCounterInfo) -> None**

**class pydnp3.opendnp3.EventConfigDoubleBitBinaryInfo**

   Bases: `pydnp3.opendnp3.StaticConfigDoubleBitBinaryInfo
   <#pydnp3.opendnp3.StaticConfigDoubleBitBinaryInfo>`_

   **__init__(self: pydnp3.opendnp3.EventConfigDoubleBitBinaryInfo) ->
   None**

**class pydnp3.opendnp3.EventConfigFrozenCounterInfo**

   Bases: `pydnp3.opendnp3.StaticConfigFrozenCounterInfo
   <#pydnp3.opendnp3.StaticConfigFrozenCounterInfo>`_

   **__init__(self: pydnp3.opendnp3.EventConfigFrozenCounterInfo) ->
   None**

**class pydnp3.opendnp3.EventCounterVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group22Var1

   Group22Var2

   Group22Var5

   Group22Var6

   **__init__(self: pydnp3.opendnp3.EventCounterVariation, arg0: int)
   -> None**

**class pydnp3.opendnp3.EventDoubleBinaryVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group4Var1

   Group4Var2

   Group4Var3

   **__init__(self: pydnp3.opendnp3.EventDoubleBinaryVariation, arg0:
   int) -> None**

**class pydnp3.opendnp3.EventFrozenCounterVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group23Var1

   Group23Var2

   Group23Var5

   Group23Var6

   **__init__(self: pydnp3.opendnp3.EventFrozenCounterVariation, arg0:
   int) -> None**

**class pydnp3.opendnp3.EventMode**

   Bases: ``pybind11_builtins.pybind11_object``

   Describes how a transaction behaves with respect to event
   generation.

   Members:

      Detect : Detect events using the specific mechanism for that
      type.

      Force : Force the creation of an event bypassing detection
      mechanism.

      Suppress : Never produce an event regardless of changes.

   **__init__(self: pydnp3.opendnp3.EventMode, arg0: int) -> None**

**class pydnp3.opendnp3.EventSecurityStatVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group122Var1

   Group122Var2

   **__init__(self: pydnp3.opendnp3.EventSecurityStatVariation, arg0:
   int) -> None**

**class pydnp3.opendnp3.EventType**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Binary

   Analog

   Counter

   FrozenCounter

   DoubleBitBinary

   BinaryOutputStatus

   AnalogOutputStatus

   SecurityStat

   **__init__(self: pydnp3.opendnp3.EventType, arg0: int) -> None**

**class pydnp3.opendnp3.Flags**

   Bases: ``pybind11_builtins.pybind11_object``

   Measurement Flags.

   **IsSet(*args, **kwargs)**

      Overloaded function.

      1. IsSet(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.BinaryQuality) -> bool

      2. IsSet(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.AnalogQuality) -> bool

      3. IsSet(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.CounterQuality) -> bool

      4. IsSet(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.FrozenCounterQuality) -> bool

      5. IsSet(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.BinaryOutputStatusQuality) -> bool

      6. IsSet(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.AnalogOutputStatusQuality) -> bool

   **Set(*args, **kwargs)**

      Overloaded function.

      1. Set(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.BinaryQuality) -> None

      2. Set(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.AnalogQuality) -> None

      3. Set(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.CounterQuality) -> None

      4. Set(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.FrozenCounterQuality) -> None

      5. Set(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.BinaryOutputStatusQuality) -> None

      6. Set(self: pydnp3.opendnp3.Flags, flag:
         pydnp3.opendnp3.AnalogOutputStatusQuality) -> None

   **__init__(self: pydnp3.opendnp3.Flags, value: int = 0) -> None**

      :Parameters:
         **value** (*unsigned char*) – defaults to 0

   ``property value``

**class pydnp3.opendnp3.FlagsType**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumerates all types that have flags.

   Members:

      DoubleBinaryInput

      Counter

      FrozenCounter

      AnalogInput

      BinaryOutputStatus

      AnalogOutputStatus

      BinaryInput

   **__init__(self: pydnp3.opendnp3.FlagsType, arg0: int) -> None**

**pydnp3.opendnp3.FlagsTypeFromType(rawType: int) ->
`pydnp3.opendnp3.FlagsType <#pydnp3.opendnp3.FlagsType>`_**

**pydnp3.opendnp3.FlagsTypeToString(flagsType:
pydnp3.opendnp3.FlagsType) -> str**

**pydnp3.opendnp3.FlagsTypeToType(flagsType:
pydnp3.opendnp3.FlagsType) -> int**

**class pydnp3.opendnp3.FlowControl**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration for setting serial port flow control.

   Members:

      Hardware

      XONXOFF

      None

   **__init__(self: pydnp3.opendnp3.FlowControl, arg0: int) -> None**

**pydnp3.opendnp3.FlowControlFromType(rawType: int) ->
`pydnp3.opendnp3.FlowControl <#pydnp3.opendnp3.FlowControl>`_**

**pydnp3.opendnp3.FlowControlToString(flowControl:
pydnp3.opendnp3.FlowControl) -> str**

**pydnp3.opendnp3.FlowControlToType(flowControl:
pydnp3.opendnp3.FlowControl) -> int**

**class pydnp3.opendnp3.FrozenCounter**

   Bases: `pydnp3.opendnp3.TypedMeasurementUint32
   <#pydnp3.opendnp3.TypedMeasurementUint32>`_

   Frozen counters are used to report the value of a counter point
   captured at the instant when the count is frozen.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.FrozenCounter) -> None

      2. __init__(self: pydnp3.opendnp3.FrozenCounter, value: int) ->
         None

      1. __init__(self: pydnp3.opendnp3.FrozenCounter, value: int,
         flags: pydnp3.opendnp3.Flags) -> None

      1. __init__(self: pydnp3.opendnp3.FrozenCounter, value: int,
         flags: pydnp3.opendnp3.Flags, time: pydnp3.opendnp3.DNPTime)
         -> None

**class pydnp3.opendnp3.FrozenCounterConfig**

   Bases: `pydnp3.opendnp3.DeadbandConfigFrozenCounterInfo
   <#pydnp3.opendnp3.DeadbandConfigFrozenCounterInfo>`_

   **__init__(self: pydnp3.opendnp3.FrozenCounterConfig) -> None**

**class pydnp3.opendnp3.FrozenCounterQuality**

   Bases: ``pybind11_builtins.pybind11_object``

   Quality field bitmask for frozen counter values.

   Members:

      ONLINE : Set when the data is good, meaning that rest of the
      system can trust the value.

      RESTART : The quality all points get before we have established
      communication (or populated) the point.

      COMM_LOST : Set if communication has been lost with the source
      of the data (after establishing contact).

      REMOTE_FORCED : Set if the value is being forced to a fake value
      somewhere in the system.

      LOCAL_FORCED : Set if the value is being forced to a fake value
      on the original device.

      ROLLOVER : Deprecated flag that indicates value has rolled over.

      DISCONTINUITY : Indicates an unusual change in value.

      RESERVED : Reserved bit.

   **__init__(self: pydnp3.opendnp3.FrozenCounterQuality, arg0: int)
   -> None**

**class pydnp3.opendnp3.FunctionCode**

   Bases: ``pybind11_builtins.pybind11_object``

   Application layer function code enumeration.

   Members:

      CONFIRM : Master sends this to an outstation to confirm the
      receipt of an Application Layer fragment.

      READ : Outstation shall return the data specified by the objects
      in the request.

      WRITE : Outstation shall store the data specified by the objects
      in the request.

      SELECT : Outstation shall select (or arm) the output points
      specified by the objects in the request in preparation for a
      subsequent operate command.

      OPERATE : Outstation shall activate the output points selected
      (or armed) by a previous select function code command.

      DIRECT_OPERATE : Outstation shall immediately actuate the output
      points specified by the objects in the request.

      DIRECT_OPERATE_NR : Same as DIRECT_OPERATE but outstation shall
      not send a response.

      IMMED_FREEZE : Outstation shall copy the point data values
      specified by the objects in the request to a separate freeze
      buffer.

      IMMED_FREEZE_NR : Same as IMMED_FREEZE but outstation shall not
      send a response.

      FREEZE_CLEAR : Outstation shall copy the point data values
      specified by the objects in the request into a separate freeze
      buffer and then clear the values.

      FREEZE_CLEAR_NR : Same as FREEZE_CLEAR but outstation shall not
      send a response.

      FREEZE_AT_TIME : Outstation shall copy the point data values
      specified by the objects in the request to a separate freeze
      buffer at the time and/or time intervals specified in a special
      time data information object.

      FREEZE_AT_TIME_NR : Same as FREEZE_AT_TIME but outstation shall
      not send a response.

      COLD_RESTART : Outstation shall perform a complete reset of all
      hardware and software in the device.

      WARM_RESTART : Outstation shall reset only portions of the
      device.

      INITIALIZE_DATA : Obsolete-Do not use for new designs.

      INITIALIZE_APPLICATION : Outstation shall place the applications
      specified by the objects in the request into the ready to run
      state.

      START_APPLICATION : Outstation shall start running the
      applications specified by the objects in the request.

      STOP_APPLICATION : Outstation shall stop running the
      applications specified by the objects in the request.

      SAVE_CONFIGURATION : This code is deprecated-Do not use for new
      designs.

      ENABLE_UNSOLICITED : Enables outstation to initiate unsolicited
      responses from points specified by the objects in the request.

      DISABLE_UNSOLICITED : Prevents outstation from initiating
      unsolicited responses from points specified by the objects in
      the request.

      ASSIGN_CLASS : Outstation shall assign the events generated by
      the points specified by the objects in the request to one of the
      classes.

      DELAY_MEASURE : Outstation shall report the time it takes to
      process and initiate the transmission of its response.

      RECORD_CURRENT_TIME : Outstation shall save the time when the
      last octet of this message is received.

      OPEN_FILE : Outstation shall open a file.

      CLOSE_FILE : Outstation shall close a file.

      DELETE_FILE : Outstation shall delete a file.

      GET_FILE_INFO : Outstation shall retrieve information about a
      file.

      AUTHENTICATE_FILE : Outstation shall return a file
      authentication key.

      ABORT_FILE : Outstation shall abort a file transfer operation.

      AUTH_REQUEST : The master uses this function code when sending
      authentication requests to the outstation.

      AUTH_REQUEST_NO_ACK : The master uses this function code when
      sending authentication requests to the outstation that do no
      require acknowledgement.

      RESPONSE : Master shall interpret this fragment as an
      Application Layer response to an ApplicationLayer request.

      UNSOLICITED_RESPONSE : Master shall interpret this fragment as
      an unsolicited response that was not prompted by an explicit
      request.

      AUTH_RESPONSE : The outstation uses this function code to issue
      authentication messages to the master.

      UNKNOWN : Unknown function code. Used internally in opendnp3 to
      indicate the code didn’t match anything known.

   **__init__(self: pydnp3.opendnp3.FunctionCode, arg0: int) -> None**

**pydnp3.opendnp3.FunctionCodeFromType(rawType: int) ->
`pydnp3.opendnp3.FunctionCode <#pydnp3.opendnp3.FunctionCode>`_**

**pydnp3.opendnp3.FunctionCodeToString(code:
pydnp3.opendnp3.FunctionCode) -> str**

**pydnp3.opendnp3.FunctionCodeToType(code:
pydnp3.opendnp3.FunctionCode) -> int**

**class pydnp3.opendnp3.GroupVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Comprehensive list of supported groups and variations.

   Members:

      Group1Var0

      Group1Var1

      Group1Var2

      Group2Var0

      Group2Var1

      Group2Var2

      Group2Var3

      Group3Var0

      Group3Var1

      Group3Var2

      Group4Var0

      Group4Var1

      Group4Var2

      Group4Var3

      Group10Var0

      Group10Var1

      Group10Var2

      Group11Var0

      Group11Var1

      Group11Var2

      Group12Var0

      Group12Var1

      Group13Var1

      Group13Var2

      Group20Var0

      Group20Var1

      Group20Var2

      Group20Var5

      Group20Var6

      Group21Var0

      Group21Var1

      Group21Var2

      Group21Var5

      Group21Var6

      Group21Var9

      Group21Var10

      Group22Var0

      Group22Var1

      Group22Var2

      Group22Var5

      Group22Var6

      Group23Var0

      Group23Var1

      Group23Var2

      Group23Var5

      Group23Var6

      Group30Var0

      Group30Var1

      Group30Var2

      Group30Var3

      Group30Var4

      Group30Var5

      Group30Var6

      Group32Var0

      Group32Var1

      Group32Var2

      Group32Var3

      Group32Var4

      Group32Var5

      Group32Var6

      Group32Var7

      Group32Var8

      Group40Var0

      Group40Var1

      Group40Var2

      Group40Var3

      Group40Var4

      Group41Var0

      Group41Var1

      Group41Var2

      Group41Var3

      Group41Var4

      Group42Var0

      Group42Var1

      Group42Var2

      Group42Var3

      Group42Var4

      Group42Var5

      Group42Var6

      Group42Var7

      Group42Var8

      Group43Var1

      Group43Var2

      Group43Var3

      Group43Var4

      Group43Var5

      Group43Var6

      Group43Var7

      Group43Var8

      Group50Var1

      Group50Var3

      Group50Var4

      Group51Var1

      Group51Var2

      Group52Var1

      Group52Var2

      Group60Var1

      Group60Var2

      Group60Var3

      Group60Var4

      Group70Var1

      Group70Var2

      Group70Var3

      Group70Var4

      Group70Var5

      Group70Var6

      Group70Var7

      Group70Var8

      Group80Var1

      Group110Var0

      Group111Var0

      Group112Var0

      Group113Var0

      Group120Var1

      Group120Var2

      Group120Var3

      Group120Var4

      Group120Var5

      Group120Var6

      Group120Var7

      Group120Var8

      Group120Var9

      Group120Var10

      Group120Var11

      Group120Var12

      Group120Var13

      Group120Var14

      Group120Var15

      Group121Var0

      Group121Var1

      Group122Var0

      Group122Var1

      Group122Var2

      UNKNOWN

   **__init__(self: pydnp3.opendnp3.GroupVariation, arg0: int) ->
   None**

**pydnp3.opendnp3.GroupVariationFromType(rawType: int) ->
`pydnp3.opendnp3.GroupVariation <#pydnp3.opendnp3.GroupVariation>`_**

**class pydnp3.opendnp3.GroupVariationID**

   Bases: ``pybind11_builtins.pybind11_object``

   Simple uint8_t/uint8_t tuple for group and variation.

   **__init__(self: pydnp3.opendnp3.GroupVariationID, group: int =
   255, variation: int = 255) -> None**

      :Parameters:
         *  **group** (*unsigned char*) – defaults to 0xFF

         *  **variation** – defaults to 0xFF

   ``property group``

   ``property variation``

**pydnp3.opendnp3.GroupVariationToString(gv:
pydnp3.opendnp3.GroupVariation) -> str**

**pydnp3.opendnp3.GroupVariationToType(gv:
pydnp3.opendnp3.GroupVariation) -> int**

**class pydnp3.opendnp3.HMACType**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumerates possible algorithms used to calculate the HMAC.

   Members:

      NO_MAC_VALUE : No HMAC value in this message.

      HMAC_SHA1_TRUNC_10 : Networked version of SHA1.

      HMAC_SHA256_TRUNC_8 : Serial version of SHA256.

      HMAC_SHA256_TRUNC_16 : Networked version of SHA256.

      HMAC_SHA1_TRUNC_8 : Serial version of SHA1.

      AES_GMAC : 12 octet output for serial or network.

      UNKNOWN : Unknown HMAC algorithm.

   **__init__(self: pydnp3.opendnp3.HMACType, arg0: int) -> None**

**pydnp3.opendnp3.HMACTypeFromType(rawType: int) ->
`pydnp3.opendnp3.HMACType <#pydnp3.opendnp3.HMACType>`_**

**pydnp3.opendnp3.HMACTypeToString(arg0: pydnp3.opendnp3.HMACType) ->
str**

**pydnp3.opendnp3.HMACTypeToType(arg0: pydnp3.opendnp3.HMACType) ->
int**

**pydnp3.opendnp3.HasAbsoluteTime(gv: pydnp3.opendnp3.GroupVariation)
-> bool**

**pydnp3.opendnp3.HasFlags(gv: pydnp3.opendnp3.GroupVariation) ->
bool**

**pydnp3.opendnp3.HasRelativeTime(gv: pydnp3.opendnp3.GroupVariation)
-> bool**

**class pydnp3.opendnp3.Header**

   Bases: ``pybind11_builtins.pybind11_object``

   Class used to specify a header type.

   **AllObjects(group: int, variation: int) -> `pydnp3.opendnp3.Header
   <#pydnp3.opendnp3.Header>`_**

      Create an all objects (0x06) header.

   **Count16(group: int, variation: int, count: int) ->
   `pydnp3.opendnp3.Header <#pydnp3.opendnp3.Header>`_**

      Create a 16-bit count header (0x08).

   **Count8(group: int, variation: int, count: int) ->
   `pydnp3.opendnp3.Header <#pydnp3.opendnp3.Header>`_**

      Create a 8-bit count header (0x07).

   **From(pointClass: pydnp3.opendnp3.PointClass) ->
   `pydnp3.opendnp3.Header <#pydnp3.opendnp3.Header>`_**

      Create an all objects (0x06) header.

   **Range16(group: int, variation: int, start: int, stop: int) ->
   `pydnp3.opendnp3.Header <#pydnp3.opendnp3.Header>`_**

      Create a 16-bit start stop header (0x01).

   **Range8(group: int, variation: int, start: int, stop: int) ->
   `pydnp3.opendnp3.Header <#pydnp3.opendnp3.Header>`_**

      Create a 8-bit start stop header (0x00).

   **WriteTo(self: pydnp3.opendnp3.Header, writer:
   pydnp3.opendnp3.HeaderWriter) -> bool**

   **__init__(self: pydnp3.opendnp3.Header) -> None**

**class pydnp3.opendnp3.HeaderInfo**

   Bases: ``pybind11_builtins.pybind11_object``

   Simple structure used in the ISOEHandler callbacks to return
   information about the associated header.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.HeaderInfo) -> None

      2. __init__(self: pydnp3.opendnp3.HeaderInfo, gv:
         pydnp3.opendnp3.GroupVariation, qualifier:
         pydnp3.opendnp3.QualifierCode, tsmode:
         pydnp3.opendnp3.TimestampMode, headerIndex: int) -> None

   ``property flagsValid``

      True if the flags on the value were present on underlying type,
      false if online is just assumed.

   ``property gv``

      The group/variation enumeration for the header.

   ``property headerIndex``

      The 0-based index of the header within the ASDU.  :type
      headerIndex: unsigned int

   ``property isEventVariation``

      True if the specfied variation is an event variation.

   ``property qualifier``

      The qualifier code enumeration for the header.

   ``property tsmode``

      Enumeration that provides information about the validity of
      timestamps on the associated objects.

**class pydnp3.opendnp3.HeaderType**

   Bases: ``pybind11_builtins.pybind11_object``

   An enumeration that defines the type of object header.

   Members:

      AllObjects

      Ranged8

      Ranged16

      LimitedCount8

      LimitedCount16

   **__init__(self: pydnp3.opendnp3.HeaderType, arg0: int) -> None**

**class pydnp3.opendnp3.HeaderUnion**

   Bases: ``pybind11_builtins.pybind11_object``

   Union type that holds information for a single header type.

   **__init__(self: pydnp3.opendnp3.HeaderUnion) -> None**

**class pydnp3.opendnp3.ICollectionCommandPointResult**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionCommandPointResult) ->
   int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionCommandPointResult,
   visitor: pydnp3.opendnp3.IVisitorCommandPointResult) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self: pydnp3.opendnp3.ICollectionCommandPointResult,
   callback: Callable[[opendnp3::CommandPointResult], None]) -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionCommandPointResult, value:
   opendnp3::CommandPointResult) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionCommandPointResult) ->
   None**

**class pydnp3.opendnp3.ICollectionDNPTime**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionDNPTime) -> int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionDNPTime, visitor:
   pydnp3.opendnp3.IVisitorDNPTime) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self: pydnp3.opendnp3.ICollectionDNPTime, callback:
   Callable[[openpal::UInt48Type], None]) -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self: pydnp3.opendnp3.ICollectionDNPTime, value:
   openpal::UInt48Type) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionDNPTime) -> None**

**class pydnp3.opendnp3.ICollectionIndexedAnalog**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedAnalog) -> int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedAnalog, visitor:
   pydnp3.opendnp3.IVisitorIndexedAnalog) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self: pydnp3.opendnp3.ICollectionIndexedAnalog,
   callback: Callable[[opendnp3::Indexed<opendnp3::Analog>], None]) ->
   None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self: pydnp3.opendnp3.ICollectionIndexedAnalog,
   value: opendnp3::Indexed<opendnp3::Analog>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedAnalog) ->
   None**

**class pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent)
   -> int**

      The number of elements in the collection.

   **Foreach(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent, visitor:
   pydnp3.opendnp3.IVisitorIndexedAnalogCommandEvent) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent, callback:
   Callable[[opendnp3::Indexed<opendnp3::AnalogCommandEvent>], None])
   -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent, value:
   opendnp3::Indexed<opendnp3::AnalogCommandEvent>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent) -> None**

**class pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus)
   -> int**

      The number of elements in the collection.

   **Foreach(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus, visitor:
   pydnp3.opendnp3.IVisitorIndexedAnalogOutputStatus) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus, callback:
   Callable[[opendnp3::Indexed<opendnp3::AnalogOutputStatus>], None])
   -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus, value:
   opendnp3::Indexed<opendnp3::AnalogOutputStatus>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self:
   pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus) -> None**

**class pydnp3.opendnp3.ICollectionIndexedBinary**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedBinary) -> int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedBinary, visitor:
   pydnp3.opendnp3.IVisitorIndexedBinary) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self: pydnp3.opendnp3.ICollectionIndexedBinary,
   callback: Callable[[opendnp3::Indexed<opendnp3::Binary>], None]) ->
   None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self: pydnp3.opendnp3.ICollectionIndexedBinary,
   value: opendnp3::Indexed<opendnp3::Binary>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedBinary) ->
   None**

**class pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent)
   -> int**

      The number of elements in the collection.

   **Foreach(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent, visitor:
   pydnp3.opendnp3.IVisitorIndexedBinaryCommandEvent) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent, callback:
   Callable[[opendnp3::Indexed<opendnp3::BinaryCommandEvent>], None])
   -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent, value:
   opendnp3::Indexed<opendnp3::BinaryCommandEvent>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent) -> None**

**class pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus)
   -> int**

      The number of elements in the collection.

   **Foreach(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus, visitor:
   pydnp3.opendnp3.IVisitorIndexedBinaryOutputStatus) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus, callback:
   Callable[[opendnp3::Indexed<opendnp3::BinaryOutputStatus>], None])
   -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus, value:
   opendnp3::Indexed<opendnp3::BinaryOutputStatus>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self:
   pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus) -> None**

**class pydnp3.opendnp3.ICollectionIndexedCounter**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedCounter) -> int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedCounter, visitor:
   pydnp3.opendnp3.IVisitorIndexedCounter) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self: pydnp3.opendnp3.ICollectionIndexedCounter,
   callback: Callable[[opendnp3::Indexed<opendnp3::Counter>], None])
   -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self: pydnp3.opendnp3.ICollectionIndexedCounter,
   value: opendnp3::Indexed<opendnp3::Counter>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedCounter) ->
   None**

**class pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary) ->
   int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary,
   visitor: pydnp3.opendnp3.IVisitorIndexedDoubleBitBinary) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self:
   pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary, callback:
   Callable[[opendnp3::Indexed<opendnp3::DoubleBitBinary>], None]) ->
   None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary, value:
   opendnp3::Indexed<opendnp3::DoubleBitBinary>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary)
   -> None**

**class pydnp3.opendnp3.ICollectionIndexedFrozenCounter**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedFrozenCounter) ->
   int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedFrozenCounter,
   visitor: pydnp3.opendnp3.IVisitorIndexedFrozenCounter) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self:
   pydnp3.opendnp3.ICollectionIndexedFrozenCounter, callback:
   Callable[[opendnp3::Indexed<opendnp3::FrozenCounter>], None]) ->
   None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedFrozenCounter, value:
   opendnp3::Indexed<opendnp3::FrozenCounter>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedFrozenCounter)
   -> None**

**class pydnp3.opendnp3.ICollectionIndexedOctetString**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedOctetString) ->
   int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedOctetString,
   visitor: pydnp3.opendnp3.IVisitorIndexedOctetString) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self: pydnp3.opendnp3.ICollectionIndexedOctetString,
   callback: Callable[[opendnp3::Indexed<opendnp3::OctetString>],
   None]) -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedOctetString, value:
   opendnp3::Indexed<opendnp3::OctetString>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedOctetString) ->
   None**

**class pydnp3.opendnp3.ICollectionIndexedSecurityStat**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedSecurityStat) ->
   int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedSecurityStat,
   visitor: pydnp3.opendnp3.IVisitorIndexedSecurityStat) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self: pydnp3.opendnp3.ICollectionIndexedSecurityStat,
   callback: Callable[[opendnp3::Indexed<opendnp3::SecurityStat>],
   None]) -> None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedSecurityStat, value:
   opendnp3::Indexed<opendnp3::SecurityStat>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedSecurityStat) ->
   None**

**class pydnp3.opendnp3.ICollectionIndexedTimeAndInterval**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface representing an abstract immutable collection of
   things of type T.  The user can only read these values via callback
   to receive each element.

   **Count(self: pydnp3.opendnp3.ICollectionIndexedTimeAndInterval) ->
   int**

      The number of elements in the collection.

   **Foreach(self: pydnp3.opendnp3.ICollectionIndexedTimeAndInterval,
   visitor: pydnp3.opendnp3.IVisitorIndexedTimeAndInterval) -> None**

      Visit all the elements of a collection.

   **ForeachItem(self:
   pydnp3.opendnp3.ICollectionIndexedTimeAndInterval, callback:
   Callable[[opendnp3::Indexed<opendnp3::TimeAndInterval>], None]) ->
   None**

      Visit all of the elements of a collection.

   **ReadOnlyValue(self:
   pydnp3.opendnp3.ICollectionIndexedTimeAndInterval, value:
   opendnp3::Indexed<opendnp3::TimeAndInterval>) -> bool**

      Retrieve the only value from the collection.

   **__init__(self: pydnp3.opendnp3.ICollectionIndexedTimeAndInterval)
   -> None**

**class pydnp3.opendnp3.ICommandCollectionAnalogOutputDouble64**

   Bases: ``pybind11_builtins.pybind11_object``

   A collection type for command to which the user can add by type and
   index.

   **Add(self: pydnp3.opendnp3.ICommandCollectionAnalogOutputDouble64,
   command: pydnp3.opendnp3.AnalogOutputDouble64, index: int) ->
   `pydnp3.opendnp3.ICommandCollectionAnalogOutputDouble64
   <#pydnp3.opendnp3.ICommandCollectionAnalogOutputDouble64>`_**

   **__init__(self:
   pydnp3.opendnp3.ICommandCollectionAnalogOutputDouble64) -> None**

**class pydnp3.opendnp3.ICommandCollectionAnalogOutputFloat32**

   Bases: ``pybind11_builtins.pybind11_object``

   A collection type for command to which the user can add by type and
   index.

   **Add(self: pydnp3.opendnp3.ICommandCollectionAnalogOutputFloat32,
   command: pydnp3.opendnp3.AnalogOutputFloat32, index: int) ->
   `pydnp3.opendnp3.ICommandCollectionAnalogOutputFloat32
   <#pydnp3.opendnp3.ICommandCollectionAnalogOutputFloat32>`_**

   **__init__(self:
   pydnp3.opendnp3.ICommandCollectionAnalogOutputFloat32) -> None**

**class pydnp3.opendnp3.ICommandCollectionAnalogOutputInt16**

   Bases: ``pybind11_builtins.pybind11_object``

   A collection type for command to which the user can add by type and
   index.

   **Add(self: pydnp3.opendnp3.ICommandCollectionAnalogOutputInt16,
   command: pydnp3.opendnp3.AnalogOutputInt16, index: int) ->
   `pydnp3.opendnp3.ICommandCollectionAnalogOutputInt16
   <#pydnp3.opendnp3.ICommandCollectionAnalogOutputInt16>`_**

   **__init__(self:
   pydnp3.opendnp3.ICommandCollectionAnalogOutputInt16) -> None**

**class pydnp3.opendnp3.ICommandCollectionAnalogOutputInt32**

   Bases: ``pybind11_builtins.pybind11_object``

   A collection type for command to which the user can add by type and
   index.

   **Add(self: pydnp3.opendnp3.ICommandCollectionAnalogOutputInt32,
   command: pydnp3.opendnp3.AnalogOutputInt32, index: int) ->
   `pydnp3.opendnp3.ICommandCollectionAnalogOutputInt32
   <#pydnp3.opendnp3.ICommandCollectionAnalogOutputInt32>`_**

   **__init__(self:
   pydnp3.opendnp3.ICommandCollectionAnalogOutputInt32) -> None**

**class pydnp3.opendnp3.ICommandCollectionControlRelayOutputBlock**

   Bases: ``pybind11_builtins.pybind11_object``

   A collection type for command to which the user can add by type and
   index.

   **Add(self:
   pydnp3.opendnp3.ICommandCollectionControlRelayOutputBlock, command:
   pydnp3.opendnp3.ControlRelayOutputBlock, index: int) ->
   `pydnp3.opendnp3.ICommandCollectionControlRelayOutputBlock
   <#pydnp3.opendnp3.ICommandCollectionControlRelayOutputBlock>`_**

   **__init__(self:
   pydnp3.opendnp3.ICommandCollectionControlRelayOutputBlock) ->
   None**

**class pydnp3.opendnp3.ICommandHandler**

   Bases: `pydnp3.opendnp3.ITransactable
   <#pydnp3.opendnp3.ITransactable>`_

   Interface used to dispatch SELECT / OPERATE / DIRECT OPERATE
   (Binary/Analog output) from the outstation to application code.
   The ITransactable sub-interface is used to determine the start and
   end of an ASDU containing commands.

   **Operate(*args, **kwargs)**

      Overloaded function.

      1. Operate(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.ControlRelayOutputBlock, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

         Operate a ControlRelayOutputBlock - group 12 variation 1.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

         *  **opType** – the operation type the outstation received

      :Returns:
         result of request

      1. Operate(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt16, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

         Ask if the application supports a 16 bit analog output -
         group 41 variation 2.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

         *  **opType** – the operation type the outstation received

      :Returns:
         result of request

      1. Operate(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt32, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

         Operate a 32 bit analog output - group 41 variation 1.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

         *  **opType** – the operation type the outstation received

      :Returns:
         result of request

      1. Operate(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputFloat32, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

         Operate a single precision, floating point analog output -
         group 41 variation 3.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

         *  **opType** – the operation type the outstation received

      :Returns:
         result of request

      1. Operate(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputDouble64, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

         Operate a double precision, floating point analog output -
         group 41 variation 4.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

         *  **opType** – the operation type the outstation received

      :Returns:
         result of request

   **Select(*args, **kwargs)**

      Overloaded function.

      1. Select(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.ControlRelayOutputBlock, index: int) ->
         pydnp3.opendnp3.CommandStatus

         Ask if the application supports a ControlRelayOutputBlock -
         group 12 variation 1.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

      :Returns:
         result of request

      1. Select(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt16, index: int) ->
         pydnp3.opendnp3.CommandStatus

         Ask if the application supports a 16 bit analog output -
         group 41 variation 2.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

      :Returns:
         result of request

      1. Select(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt32, index: int) ->
         pydnp3.opendnp3.CommandStatus

         Ask if the application supports a 32 bit analog output -
         group 41 variation 1.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

      :Returns:
         result of request

      1. Select(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputFloat32, index: int) ->
         pydnp3.opendnp3.CommandStatus

         Ask if the application supports a single precision, floating
         point analog output - group 41 variation 3.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

      :Returns:
         result of request

      1. Select(self: pydnp3.opendnp3.ICommandHandler, command:
         pydnp3.opendnp3.AnalogOutputDouble64, index: int) ->
         pydnp3.opendnp3.CommandStatus

         Ask if the application supports a double precision, floating
         point analog output - group 41 variation 4.

      :Parameters:
         *  **command** – command to operate

         *  **index** (*unsigned short*) – index of the command

      :Returns:
         result of request

   **__init__(self: pydnp3.opendnp3.ICommandHandler) -> None**

**class pydnp3.opendnp3.ICommandProcessor**

   Bases: ``pybind11_builtins.pybind11_object``

   Interface used to dispatch SELECT / OPERATE / DIRECT OPERATE from
   application code to a master.

   **DirectOperate(*args, **kwargs)**

      Overloaded function.

      1. DirectOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.ControlRelayOutputBlock, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d321cf0>) ->
         None

      2. DirectOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputInt16, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d324070>) ->
         None

      3. DirectOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputInt32, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d317270>) ->
         None

      4. DirectOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputFloat32, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d317330>) ->
         None

      5. DirectOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputDouble64, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756db2e9b0>) ->
         None

         Direct operate a single command.

      :Parameters:
         *  **command** – Command to operate

         *  **index** – in dex of the command

         *  **callback** – callback that will be invoked upon
            completion or failure

         *  **config** – optional configuration that controls normal
            callbacks and allows the user to be specified for SA

      1. DirectOperate(self: pydnp3.opendnp3.ICommandProcessor,
         commands: pydnp3.opendnp3.CommandSet, callback:
         Callable[[pydnp3.opendnp3.ICommandTaskResult], None], config:
         pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig
         object at 0x7f756d317bb0>) -> None

         Direct operate a set of commands.

      :Parameters:
         *  **commands** – Set of command headers

         *  **callback** – callback that will be invoked upon
            completion or failure

         *  **config** – optional configuration that controls normal
            callbacks and allows the user to be specified for SA

   **SelectAndOperate(*args, **kwargs)**

      Overloaded function.

      1. SelectAndOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.ControlRelayOutputBlock, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756dc7c030>) ->
         None

      2. SelectAndOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputInt16, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d321db0>) ->
         None

      3. SelectAndOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputInt32, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d321e70>) ->
         None

      4. SelectAndOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputFloat32, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d321e30>) ->
         None

      5. SelectAndOperate(self: pydnp3.opendnp3.ICommandProcessor,
         command: pydnp3.opendnp3.AnalogOutputDouble64, index: int,
         callback: Callable[[pydnp3.opendnp3.ICommandTaskResult],
         None], config: pydnp3.opendnp3.TaskConfig =
         <pydnp3.opendnp3.TaskConfig object at 0x7f756d321df0>) ->
         None

         Select and operate a single command.

      :Parameters:
         *  **command** – Command to operate

         *  **index** – in dex of the command

         *  **callback** – callback that will be invoked upon
            completion or failure

         *  **config** – optional configuration that controls normal
            callbacks and allows the user to be specified for SA

      1. SelectAndOperate(self: pydnp3.opendnp3.ICommandProcessor,
         commands: pydnp3.opendnp3.CommandSet, callback:
         Callable[[pydnp3.opendnp3.ICommandTaskResult], None], config:
         pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig
         object at 0x7f756d317470>) -> None

         Select and operate a set of commands.

      :Parameters:
         *  **commands** – Set of command headers

         *  **callback** – callback that will be invoked upon
            completion or failure

         *  **config** – optional configuration that controls normal
            callbacks and allows the user to be specified for SA

   **__init__(self: pydnp3.opendnp3.ICommandProcessor) -> None**

**class pydnp3.opendnp3.ICommandTaskResult**

   Bases: `pydnp3.opendnp3.ICollectionCommandPointResult
   <#pydnp3.opendnp3.ICollectionCommandPointResult>`_

   Abstract result type returned via callback to a command operation.
   Provides the TaskCompleton summary value and access to a collection
   of flatten results.  A result value is provided for every object in
   every header specified in the CommandSet used to start the
   operation.

   **__init__(self: pydnp3.opendnp3.ICommandTaskResult, summary:
   pydnp3.opendnp3.TaskCompletion) -> None**

   ``property summary``

      A summary result for the entire task.

**class pydnp3.opendnp3.IINBit**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   ALL_STATIONS

   CLASS1_EVENTS

   CLASS2_EVENTS

   CLASS3_EVENTS

   NEED_TIME

   LOCAL_CONTROL

   DEVICE_TROUBLE

   DEVICE_RESTART

   FUNC_NOT_SUPPORTED

   OBJECT_UNKNOWN

   PARAM_ERROR

   EVENT_BUFFER_OVERFLOW

   ALREADY_EXECUTING

   CONFIG_CORRUPT

   RESERVED1

   RESERVED2

   **__init__(self: pydnp3.opendnp3.IINBit, arg0: int) -> None**

**class pydnp3.opendnp3.IINField**

   Bases: ``pybind11_builtins.pybind11_object``

   DNP3 two-byte IIN field.

   **Any(self: pydnp3.opendnp3.IINField) -> bool**

   **Clear(self: pydnp3.opendnp3.IINField) -> None**

   **ClearBit(self: pydnp3.opendnp3.IINField, bit:
   pydnp3.opendnp3.IINBit) -> None**

   **Empty() -> `pydnp3.opendnp3.IINField
   <#pydnp3.opendnp3.IINField>`_**

   **HasRequestError(self: pydnp3.opendnp3.IINField) -> bool**

   **IsClear(self: pydnp3.opendnp3.IINField, bit:
   pydnp3.opendnp3.IINBit) -> bool**

   **IsSet(self: pydnp3.opendnp3.IINField, bit:
   pydnp3.opendnp3.IINBit) -> bool**

   ``property LSB``

   ``property MSB``

   **SetBit(self: pydnp3.opendnp3.IINField, bit:
   pydnp3.opendnp3.IINBit) -> None**

   **SetBitToValue(self: pydnp3.opendnp3.IINField, bit:
   pydnp3.opendnp3.IINBit, value: bool) -> None**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IINField, bit:
         pydnp3.opendnp3.IINBit) -> None

      2. __init__(self: pydnp3.opendnp3.IINField, aLSB: int = 0, aMSB:
         int = 0) -> None

**class pydnp3.opendnp3.ILinkListener**

   Bases: ``pybind11_builtins.pybind11_object``

   Various optional callbacks that can be received for the link layer.

   **OnKeepAliveFailure(self: pydnp3.opendnp3.ILinkListener) -> None**

      Called when a keep alive message (request link status) receives
      no response.

   **OnKeepAliveInitiated(self: pydnp3.opendnp3.ILinkListener) ->
   None**

      Called when the keep alive timer elapses. This doesn’t denote a
      keep-alive failure, it’s just a notification.

   **OnKeepAliveSuccess(self: pydnp3.opendnp3.ILinkListener) -> None**

      Called when a keep alive message receives a valid response.

   **OnStateChange(self: pydnp3.opendnp3.ILinkListener, value:
   pydnp3.opendnp3.LinkStatus) -> None**

      Called when a the reset/unreset status of the link layer
      changes.

   **__init__(self: pydnp3.opendnp3.ILinkListener) -> None**

**class pydnp3.opendnp3.IMasterApplication**

   Bases: `pydnp3.opendnp3.ILinkListener
   <#pydnp3.opendnp3.ILinkListener>`_, `pydnp3.openpal.IUTCTimeSource
   <openpal.rst#pydnp3.openpal.IUTCTimeSource>`_

   Interface for all master application callback info except for
   measurement values.

   **AssignClassDuringStartup(self:
   pydnp3.opendnp3.IMasterApplication) -> bool**

      Return true if the master should do an assign class task during
      startup handshaking.

   **ConfigureAssignClassRequest(self:
   pydnp3.opendnp3.IMasterApplication, fun:
   Callable[[pydnp3.opendnp3.Header], None]) -> None**

      Configure the request headers for assign class.  Only called if
      AssignClassDuringStartup returns true.  The user only needs to
      call the function for each header type to be written.

   **OnClose(self: pydnp3.opendnp3.IMasterApplication) -> None**

      Called when the application layer is closed.

   **OnOpen(self: pydnp3.opendnp3.IMasterApplication) -> None**

      Called when the application layer is opened.

   **OnReceiveIIN(self: pydnp3.opendnp3.IMasterApplication, iin:
   pydnp3.opendnp3.IINField) -> None**

      Called when a response or unsolicited response is receive from
      the outstation.

   **OnTaskComplete(self: pydnp3.opendnp3.IMasterApplication, info:
   pydnp3.opendnp3.TaskInfo) -> None**

      Task completion notification.

   **OnTaskStart(self: pydnp3.opendnp3.IMasterApplication, type:
   pydnp3.opendnp3.MasterTaskType, id: pydnp3.opendnp3.TaskId) ->
   None**

      Task start notification.

   **__init__(self: pydnp3.opendnp3.IMasterApplication) -> None**

**class pydnp3.opendnp3.IOutstationApplication**

   Bases: `pydnp3.opendnp3.ILinkListener
   <#pydnp3.opendnp3.ILinkListener>`_

   Interface for all outstation application callback info except for
   control requests.

   **ColdRestart(self: pydnp3.opendnp3.IOutstationApplication) ->
   int**

      The outstation should perform a complete restart.  (See the DNP3
      specification for a complete descripton of normal behavior.)
      Return number of seconds or milliseconds until restart is
      complete. The value is interpreted based on the Restart Mode
      returned from ColdRestartSupport().

   **ColdRestartSupport(self: pydnp3.opendnp3.IOutstationApplication)
   -> `pydnp3.opendnp3.RestartMode <#pydnp3.opendnp3.RestartMode>`_**

      Query the outstation for the cold restart mode it supports.

   **GetApplicationIIN(self: pydnp3.opendnp3.IOutstationApplication)
   -> `pydnp3.opendnp3.ApplicationIIN
   <#pydnp3.opendnp3.ApplicationIIN>`_**

      Returns the application-controlled IIN field.

   **RecordClassAssignment(self:
   pydnp3.opendnp3.IOutstationApplication, type:
   pydnp3.opendnp3.AssignClassType, clazz: pydnp3.opendnp3.PointClass,
   start: int, stop: int) -> None**

         Called if SupportsAssignClass returns true.  The type and
         range are pre-validated against the outstation’s database and
         class assignments are automatically applied internally.  This
         callback allows user code to persist the changes to
         non-volatile memory.:type start: unsigned short

   **SupportsAssignClass(self: pydnp3.opendnp3.IOutstationApplication)
   -> bool**

      True if the outstation supports the assign class function code.
      If this function returns false, the assign class callbacks will
      never be called and the outstation will return IIN 2.1
      (FUNC_NOT_SUPPORTED) when it receives this function code.

   **SupportsWriteAbsoluteTime(self:
   pydnp3.opendnp3.IOutstationApplication) -> bool**

      Queries whether the the outstation supports absolute time
      writes.  If this function returns false, WriteAbsoluteTime will
      never be called and the outstation will return IIN 2.1
      (FUNC_NOT_SUPPORTED).

   **SupportsWriteTimeAndInterval(self:
   pydnp3.opendnp3.IOutstationApplication) -> bool**

      Queries whether the outstation supports the writing of
      TimeAndInterval.  If this function returns false,
      WriteTimeAndInterval will never be called and the outstation
      will return IIN 2.1 (FUNC_NOT_SUPPORTED) when it receives this
      request.

   **WarmRestart(self: pydnp3.opendnp3.IOutstationApplication) ->
   int**

      The outstation should perform a partial restart of only the DNP3
      application.  (See the DNP3 specification for a complete
      descripton of normal behavior.)  Return number of seconds or
      milliseconds until restart is complete. The value is interpreted
      based on the Restart Mode returned from WarmRestartSupport().

   **WarmRestartSupport(self: pydnp3.opendnp3.IOutstationApplication)
   -> `pydnp3.opendnp3.RestartMode <#pydnp3.opendnp3.RestartMode>`_**

      Query the outstation for the warm restart mode it supports.

   **WriteAbsoluteTime(self: pydnp3.opendnp3.IOutstationApplication,
   timestamp: pydnp3.openpal.UTCTimestamp) -> bool**

      Write the time to outstation, only called if
      SupportsWriteAbsoluteTime return true.  Return boolean value
      indicating if the time value supplied was accepted. Returning
      false will cause the outstation to set IIN 2.3 (PARAM_ERROR) in
      its response.  The outstation should clear its NEED_TIME field
      when handling this response.

   **WriteTimeAndInterval(self:
   pydnp3.opendnp3.IOutstationApplication, values:
   pydnp3.opendnp3.ICollectionIndexedTimeAndInterval) -> bool**

      Write one or more TimeAndInterval values. Only called if
      SupportsWriteTimeAndInterval returns true.  The outstation
      application code is reponsible for updating TimeAndInterval
      values in the database if this behavior is desired.  Return
      boolean value indicating if the values supplied were accepted.
      Returning false will cause the outstation to set IIN 2.3
      (PARAM_ERROR) in its response.

   **__init__(self: pydnp3.opendnp3.IOutstationApplication) -> None**

**class pydnp3.opendnp3.ISOEHandler**

   Bases: `pydnp3.opendnp3.ITransactable
   <#pydnp3.opendnp3.ITransactable>`_

   An interface for Sequence-Of-Events (SOE) callbacks from a master
   stack to the application layer.  A call is made to the appropriate
   member method for every measurement value in an ASDU.  The
   HeaderInfo class provides information about the object header
   associated with the value.

   **Process(*args, **kwargs)**

      Overloaded function.

      1. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedBinary) -> None

      2. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary) -> None

      3. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedAnalog) -> None

      4. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedCounter) -> None

      5. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedFrozenCounter) -> None

      6. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus) -> None

      7. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus) -> None

      8. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedOctetString) -> None

      9. Process(self: pydnp3.opendnp3.ISOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedTimeAndInterval) -> None

      10. Process(self: pydnp3.opendnp3.ISOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent) ->
          None

      11. Process(self: pydnp3.opendnp3.ISOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent) ->
          None

      12. Process(self: pydnp3.opendnp3.ISOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionIndexedSecurityStat) -> None

      13. Process(self: pydnp3.opendnp3.ISOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionDNPTime) -> None

   **__init__(self: pydnp3.opendnp3.ISOEHandler) -> None**

**class pydnp3.opendnp3.ITaskCallback**

   Bases: ``pybind11_builtins.pybind11_object``

   Callbacks for when a task starts and completes.

   **OnComplete(self: pydnp3.opendnp3.ITaskCallback, result:
   pydnp3.opendnp3.TaskCompletion) -> None**

      Called when the task succeeds or fails.

   **OnDestroyed(self: pydnp3.opendnp3.ITaskCallback) -> None**

      Called when the task no longer exists and no more calls will be
      made to OnStart/OnComplete.

   **OnStart(self: pydnp3.opendnp3.ITaskCallback) -> None**

      Called when the task starts running.

   **__init__(self: pydnp3.opendnp3.ITaskCallback) -> None**

**class pydnp3.opendnp3.ITransactable**

   Bases: ``pybind11_builtins.pybind11_object``

   Something that can be performed atomically or needing Start()/End()
   signals.

   **End(self: pydnp3.opendnp3.ITransactable) -> None**

   **Start(self: pydnp3.opendnp3.ITransactable) -> None**

   **__init__(self: pydnp3.opendnp3.ITransactable) -> None**

**class pydnp3.opendnp3.IUpdateHandler**

   Bases: ``pybind11_builtins.pybind11_object``

   An interface used to update measurement values.

   **Modify(self: pydnp3.opendnp3.IUpdateHandler, type:
   pydnp3.opendnp3.FlagsType, start: int, stop: int, flags: int) ->
   bool**

         Update the flags of a measurement without changing it’s
         value.

      :Parameters:
         *  **type** – enumeration specifiy the type to change

         *  **start** (*unsigned short*) – the start index at which to
            begin changing flags

         *  **stop** (*unsigned short*) – the stop index at which to
            end changing flags

         *  **flags** – the new value of the flags

   **Update(*args, **kwargs)**

      Overloaded function.

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.Binary, index: int, mode:
         pydnp3.opendnp3.EventMode = EventMode.Detect) -> bool

         Update a Binary measurement.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** – index of the measurement

      :param mode Describes how event generation is handled for this
      method  :type index: unsigned short  :return: true if the value
      exists and it was updated

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.DoubleBitBinary, index: int, mode:
         pydnp3.opendnp3.EventMode = EventMode.Detect) -> bool

         Update a DoubleBitBinary measurement.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** – index of the measurement

      :param mode Describes how event generation is handled for this
      method  :type index: unsigned short  :return: true if the value
      exists and it was updated

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.Analog, index: int, mode:
         pydnp3.opendnp3.EventMode = EventMode.Detect) -> bool

         Update a Analog measurement.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** – index of the measurement

      :param mode Describes how event generation is handled for this
      method  :type index: unsigned short  :return: true if the value
      exists and it was updated

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.Counter, index: int, mode:
         pydnp3.opendnp3.EventMode = EventMode.Detect) -> bool

         Update a Counter measurement.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** – index of the measurement

      :param mode Describes how event generation is handled for this
      method  :type index: unsigned short  :return: true if the value
      exists and it was updated

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.FrozenCounter, index: int, mode:
         pydnp3.opendnp3.EventMode = EventMode.Detect) -> bool

         Update a FrozenCounter measurement.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** – index of the measurement

      :param mode Describes how event generation is handled for this
      method  :type index: unsigned short  :return: true if the value
      exists and it was updated

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.BinaryOutputStatus, index: int, mode:
         pydnp3.opendnp3.EventMode = EventMode.Detect) -> bool

         Update a BinaryOutputStatus measurement.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** – index of the measurement

      :param mode Describes how event generation is handled for this
      method  :type index: unsigned short  :return: true if the value
      exists and it was updated

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.AnalogOutputStatus, index: int, mode:
         pydnp3.opendnp3.EventMode = EventMode.Detect) -> bool

         Update a AnalogOutputStatus measurement.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** – index of the measurement

      :param mode Describes how event generation is handled for this
      method  :type index: unsigned short  :return: true if the value
      exists and it was updated

      1. Update(self: pydnp3.opendnp3.IUpdateHandler, measurement:
         pydnp3.opendnp3.TimeAndInterval, index: int) -> bool

         Update a TimeAndInterval valueindex.

      :Parameters:
         *  **meas** – measurement to be processed

         *  **index** (*unsigned short*) – index of the measurement

      :Returns:
         true if the value exists and it was updated

   **__init__(self: pydnp3.opendnp3.IUpdateHandler) -> None**

**class pydnp3.opendnp3.IVisitorCommandPointResult**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorCommandPointResult, value:
   opendnp3::CommandPointResult) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorCommandPointResult) ->
   None**

**class pydnp3.opendnp3.IVisitorDNPTime**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorDNPTime, value:
   openpal::UInt48Type) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorDNPTime) -> None**

**class pydnp3.opendnp3.IVisitorIndexedAnalog**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedAnalog, value:
   opendnp3::Indexed<opendnp3::Analog>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedAnalog) -> None**

**class pydnp3.opendnp3.IVisitorIndexedAnalogCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedAnalogCommandEvent,
   value: opendnp3::Indexed<opendnp3::AnalogCommandEvent>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedAnalogCommandEvent)
   -> None**

**class pydnp3.opendnp3.IVisitorIndexedAnalogOutputStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedAnalogOutputStatus,
   value: opendnp3::Indexed<opendnp3::AnalogOutputStatus>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedAnalogOutputStatus)
   -> None**

**class pydnp3.opendnp3.IVisitorIndexedBinary**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedBinary, value:
   opendnp3::Indexed<opendnp3::Binary>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedBinary) -> None**

**class pydnp3.opendnp3.IVisitorIndexedBinaryCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedBinaryCommandEvent,
   value: opendnp3::Indexed<opendnp3::BinaryCommandEvent>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedBinaryCommandEvent)
   -> None**

**class pydnp3.opendnp3.IVisitorIndexedBinaryOutputStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedBinaryOutputStatus,
   value: opendnp3::Indexed<opendnp3::BinaryOutputStatus>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedBinaryOutputStatus)
   -> None**

**class pydnp3.opendnp3.IVisitorIndexedCounter**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedCounter, value:
   opendnp3::Indexed<opendnp3::Counter>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedCounter) -> None**

**class pydnp3.opendnp3.IVisitorIndexedDoubleBitBinary**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedDoubleBitBinary,
   value: opendnp3::Indexed<opendnp3::DoubleBitBinary>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedDoubleBitBinary) ->
   None**

**class pydnp3.opendnp3.IVisitorIndexedFrozenCounter**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedFrozenCounter,
   value: opendnp3::Indexed<opendnp3::FrozenCounter>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedFrozenCounter) ->
   None**

**class pydnp3.opendnp3.IVisitorIndexedOctetString**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedOctetString, value:
   opendnp3::Indexed<opendnp3::OctetString>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedOctetString) ->
   None**

**class pydnp3.opendnp3.IVisitorIndexedSecurityStat**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedSecurityStat, value:
   opendnp3::Indexed<opendnp3::SecurityStat>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedSecurityStat) ->
   None**

**class pydnp3.opendnp3.IVisitorIndexedTimeAndInterval**

   Bases: ``pybind11_builtins.pybind11_object``

   Abstract way of visiting elements of a collection.

   **OnValue(self: pydnp3.opendnp3.IVisitorIndexedTimeAndInterval,
   value: opendnp3::Indexed<opendnp3::TimeAndInterval>) -> None**

   **__init__(self: pydnp3.opendnp3.IVisitorIndexedTimeAndInterval) ->
   None**

**class pydnp3.opendnp3.IndexConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   All entries have this information.

   **__init__(self: pydnp3.opendnp3.IndexConfig, vIndex: int = 0) ->
   None**

   ``property vIndex``

      Virtual index for discontiguous data, as opposed to the raw
      array index.

**class pydnp3.opendnp3.IndexMode**

   Bases: ``pybind11_builtins.pybind11_object``

   Select contiguous or dis-contiguous index mode.

   Members:

      Contiguous : Indices are contiguous. Most efficient as direct
      indexing is used.

      Discontiguous : Indices are dis-contiguous. Resorts to binary
      search to find raw index.

   **__init__(self: pydnp3.opendnp3.IndexMode, arg0: int) -> None**

**class pydnp3.opendnp3.IndexedAnalog**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedAnalog) -> None

      2. __init__(self: pydnp3.opendnp3.IndexedAnalog, value:
         opendnp3::Analog, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedAnalogCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedAnalogCommandEvent) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedAnalogCommandEvent,
         value: pydnp3.opendnp3.AnalogCommandEvent, index: int = 0) ->
         None

   ``property index``

**class pydnp3.opendnp3.IndexedAnalogOutputDouble64**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputDouble64)
         -> None

      2. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputDouble64,
         value: pydnp3.opendnp3.AnalogOutputDouble64, index: int = 0)
         -> None

   ``property index``

**class pydnp3.opendnp3.IndexedAnalogOutputFloat32**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputFloat32) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputFloat32,
         value: pydnp3.opendnp3.AnalogOutputFloat32, index: int = 0)
         -> None

   ``property index``

**class pydnp3.opendnp3.IndexedAnalogOutputInt16**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputInt16) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputInt16,
         value: pydnp3.opendnp3.AnalogOutputInt16, index: int = 0) ->
         None

   ``property index``

**class pydnp3.opendnp3.IndexedAnalogOutputInt32**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputInt32) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputInt32,
         value: pydnp3.opendnp3.AnalogOutputInt32, index: int = 0) ->
         None

   ``property index``

**class pydnp3.opendnp3.IndexedAnalogOutputStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputStatus) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedAnalogOutputStatus,
         value: opendnp3::AnalogOutputStatus, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedBinary**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedBinary) -> None

      2. __init__(self: pydnp3.opendnp3.IndexedBinary, value:
         opendnp3::Binary, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedBinaryCommandEvent**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedBinaryCommandEvent) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedBinaryCommandEvent,
         value: pydnp3.opendnp3.BinaryCommandEvent, index: int = 0) ->
         None

   ``property index``

**class pydnp3.opendnp3.IndexedBinaryOutputStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedBinaryOutputStatus) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedBinaryOutputStatus,
         value: opendnp3::BinaryOutputStatus, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedControlRelayOutputBlock**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self:
         pydnp3.opendnp3.IndexedControlRelayOutputBlock) -> None

      2. __init__(self:
         pydnp3.opendnp3.IndexedControlRelayOutputBlock, value:
         pydnp3.opendnp3.ControlRelayOutputBlock, index: int = 0) ->
         None

   ``property index``

**class pydnp3.opendnp3.IndexedCounter**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedCounter) -> None

      2. __init__(self: pydnp3.opendnp3.IndexedCounter, value:
         opendnp3::Counter, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedDoubleBitBinary**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedDoubleBitBinary) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedDoubleBitBinary, value:
         opendnp3::DoubleBitBinary, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedFrozenCounter**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedFrozenCounter) -> None

      2. __init__(self: pydnp3.opendnp3.IndexedFrozenCounter, value:
         opendnp3::FrozenCounter, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedOctetString**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedOctetString) -> None

      2. __init__(self: pydnp3.opendnp3.IndexedOctetString, value:
         opendnp3::OctetString, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedSecurityStat**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedSecurityStat) -> None

      2. __init__(self: pydnp3.opendnp3.IndexedSecurityStat, value:
         opendnp3::SecurityStat, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IndexedTimeAndInterval**

   Bases: ``pybind11_builtins.pybind11_object``

   A simple tuple for pairing Values with an index.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.IndexedTimeAndInterval) ->
         None

      2. __init__(self: pydnp3.opendnp3.IndexedTimeAndInterval, value:
         opendnp3::TimeAndInterval, index: int = 0) -> None

   ``property index``

**class pydnp3.opendnp3.IntervalUnits**

   Bases: ``pybind11_builtins.pybind11_object``

   Time internal units.

   Members:

      NoRepeat : The outstation does not repeat the action regardless
      of the value in the interval count.

      Milliseconds : The interval is always counted relative to the
      start time and is constant regardless of the clock time set at
      the outstation.

      Seconds : At the same millisecond within the second that is
      specified in the start time.

      Minutes : At the same second and millisecond within the minute
      that is specified in the start time.

      Hours : At the same minute, second and millisecond within the
      hour that is specified in the start time.

      Days : At the same time of day that is specified in the start
      time.

      Weeks : On the same day of the week at the same time of day that
      is specified in the start time.

      Months7 : On the same day of each month at the same time of day
      that is specified in the start time.

      Months8 : At the same time of day on the same day of the week
      after the beginning of the month as the day specified in the
      start time.

      Months9 : Months on Same Day of Week from End of Month - The
      outstation shall interpret this setting as in Months8, but the
      day of the week shall be measured from the end of the month.

      Seasons : The definition of a season is specific to the
      outstation.

      Undefined : 11-127 are reserved for future use.

   **__init__(self: pydnp3.opendnp3.IntervalUnits, arg0: int) ->
   None**

**pydnp3.opendnp3.IntervalUnitsFromType(rawType: int) ->
`pydnp3.opendnp3.IntervalUnits <#pydnp3.opendnp3.IntervalUnits>`_**

**pydnp3.opendnp3.IntervalUnitsToString(units:
pydnp3.opendnp3.IntervalUnits) -> str**

**pydnp3.opendnp3.IntervalUnitsToType(units:
pydnp3.opendnp3.IntervalUnits) -> int**

**pydnp3.opendnp3.IsEvent(gv: pydnp3.opendnp3.GroupVariation) ->
bool**

**class pydnp3.opendnp3.KeyChangeMethod**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumerates possible algorithms for changing the update key.

   Members:

      AES_128_SHA1_HMAC

      AES_256_SHA256_HMAC

      AES_256_AES_GMAC

      RSA_1024_DSA_SHA1_HMAC_SHA1

      RSA_2048_DSA_SHA256_HMAC_SHA256

      RSA_3072_DSA_SHA256_HMAC_SHA256

      RSA_2048_DSA_SHA256_AES_GMAC

      RSA_3072_DSA_SHA256_AES_GMAC

      UNDEFINED

   **__init__(self: pydnp3.opendnp3.KeyChangeMethod, arg0: int) ->
   None**

**pydnp3.opendnp3.KeyChangeMethodFromType(rawType: int) ->
`pydnp3.opendnp3.KeyChangeMethod
<#pydnp3.opendnp3.KeyChangeMethod>`_**

**pydnp3.opendnp3.KeyChangeMethodToString(arg0:
pydnp3.opendnp3.KeyChangeMethod) -> str**

**pydnp3.opendnp3.KeyChangeMethodToType(arg0:
pydnp3.opendnp3.KeyChangeMethod) -> int**

**class pydnp3.opendnp3.KeyStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   Describes the status of the two session keys as known by the
   outstation.

   Members:

      OK : Session keys are valid.

      NOT_INIT : Sessions keys are not valid due to no init or
      interval expiration.

      COMM_FAIL : Session keys are not valid due to communications
      failure.

      AUTH_FAIL : Session keys are not valid due to an authentication
      failure

      UNDEFINED

   **__init__(self: pydnp3.opendnp3.KeyStatus, arg0: int) -> None**

**pydnp3.opendnp3.KeyStatusFromType(rawType: int) ->
`pydnp3.opendnp3.KeyStatus <#pydnp3.opendnp3.KeyStatus>`_**

**pydnp3.opendnp3.KeyStatusToString(status: pydnp3.opendnp3.KeyStatus)
-> str**

**pydnp3.opendnp3.KeyStatusToType(status: pydnp3.opendnp3.KeyStatus)
-> int**

**class pydnp3.opendnp3.KeyWrapAlgorithm**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumerates possible key-wrap algorithms.

   Members:

      AES_128 : AES 128 Key Wrap Algorithm.

      AES_256 : AES 256 Key Wrap Algorithm.

      UNDEFINED

   **__init__(self: pydnp3.opendnp3.KeyWrapAlgorithm, arg0: int) ->
   None**

**pydnp3.opendnp3.KeyWrapAlgorithmFromType(rawType: int) ->
`pydnp3.opendnp3.KeyWrapAlgorithm
<#pydnp3.opendnp3.KeyWrapAlgorithm>`_**

   :RawType:
      unsigned char

**pydnp3.opendnp3.KeyWrapAlgorithmToString(arg0:
pydnp3.opendnp3.KeyWrapAlgorithm) -> str**

**pydnp3.opendnp3.KeyWrapAlgorithmToType(arg0:
pydnp3.opendnp3.KeyWrapAlgorithm) -> int**

**class pydnp3.opendnp3.LinkConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   Configuration for the dnp3 link layer.

   ``property IsMaster``

      The master/outstation bit set on all messages.

   ``property KeepAliveTimeout``

      The interval for keep-alive messages (link status requests)  If
      set to TimeDuration::Max(), the keep-alive is disabled.

   ``property LocalAddr``

      Dnp3 address of the local device.  :type LocalAddr: unsigned
      short

   ``property NumRetry``

      The number of retry attempts the link will attempt after the
      initial try.  :type NumRetry: unsigned int

   ``property RemoteAddr``

      Dnp3 address of the remote device.  :type RemoteAddr: unsigned
      short

   ``property Timeout``

      The response timeout in milliseconds for confirmed requests.

   ``property UseConfirms``

      If true, the link layer will send data requesting confirmation.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.LinkConfig, IsMaster: bool,
         UseConfirms: bool, NumRetry: int, LocalAddr: int, RemoteAddr:
         int, Timeout: pydnp3.openpal.TimeDuration, KeepAliveTimeout:
         pydnp3.openpal.TimeDuration) -> None

      1. __init__(self: pydnp3.opendnp3.LinkConfig, IsMaster: bool,
         UseConfirms: bool) -> None

**class pydnp3.opendnp3.LinkFunction**

   Bases: ``pybind11_builtins.pybind11_object``

   Link layer function code enumeration.

   Members:

      PRI_RESET_LINK_STATES

      PRI_TEST_LINK_STATES

      PRI_CONFIRMED_USER_DATA

      PRI_UNCONFIRMED_USER_DATA

      PRI_REQUEST_LINK_STATUS

      SEC_ACK

      SEC_NACK

      SEC_LINK_STATUS

      SEC_NOT_SUPPORTED

      INVALID

   **__init__(self: pydnp3.opendnp3.LinkFunction, arg0: int) -> None**

**pydnp3.opendnp3.LinkFunctionFromType(rawType: int) ->
`pydnp3.opendnp3.LinkFunction <#pydnp3.opendnp3.LinkFunction>`_**

**pydnp3.opendnp3.LinkFunctionToString(linkFunction:
pydnp3.opendnp3.LinkFunction) -> str**

**pydnp3.opendnp3.LinkFunctionToType(linkFunction:
pydnp3.opendnp3.LinkFunction) -> int**

**class pydnp3.opendnp3.LinkStatistics**

   Bases: ``pybind11_builtins.pybind11_object``

   Counters for the channel and the DNP3 link layer.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.LinkStatistics) -> None

      2. __init__(self: pydnp3.opendnp3.LinkStatistics, channel:
         pydnp3.opendnp3.LinkStatisticsChannel, parser:
         pydnp3.opendnp3.LinkStatisticsParser) -> None

   ``property channel``

      Statistics for the communicaiton channel.

   ``property parser``

      Statistics for the link parser.

**class pydnp3.opendnp3.LinkStatus**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration for reset/unreset states of a link layer

   Members:

      UNRESET : DOWN.

      RESET : UP.

   **__init__(self: pydnp3.opendnp3.LinkStatus, arg0: int) -> None**

**pydnp3.opendnp3.LinkStatusToString(linkStatus:
pydnp3.opendnp3.LinkStatus) -> str**

**pydnp3.opendnp3.LogFlagToString(flag: int) -> str**

**class pydnp3.opendnp3.MasterParams**

   Bases: ``pybind11_builtins.pybind11_object``

   Configuration information for the dnp3 master.

   **__init__(self: pydnp3.opendnp3.MasterParams) -> None**

      Default constructor.

   ``property disableUnsolOnStartup``

      If true, the master will disable unsol on startup for all 3
      classes.

   ``property eventScanOnEventsAvailableClassMask``

      Which classes should be requested in an event scan when
      detecting corresponding events available IIN.

   ``property ignoreRestartIIN``

      If true, the master will not clear the restart IIN bit in
      response to detecting it set.

   ``property integrityOnEventOverflowIIN``

      Defines whether an integrity scan will be performed when the
      EventBufferOverflow IIN is detected.

   ``property maxRxFragSize``

      Maximum APDU rx size in bytes.  :type maxRxFragSize: unsigned
      int

   ``property maxTaskRetryPeriod``

      Maximum time delay before retrying a failed task. Backs off
      exponentially from taskRetryPeriod.

   ``property maxTxFragSize``

      Maximum APDU tx size in bytes.  :type maxTxFragSize: unsigned
      int

   ``property responseTimeout``

      Application layer response timeout.

   ``property startupIntegrityClassMask``

      Which classes should be requested in a startup integrity scan,
      defaults to 3/2/1/0.  A mask equal to 0 means no startup
      integrity scan will be performed.

   ``property taskRetryPeriod``

      Time delay before retrying a failed task.

   ``property taskStartTimeout``

      Time delay before failing a non-recurring task (e.g. commands)
      that cannot start.

   ``property timeSyncMode``

      If true, the master will do time syncs when it sees the time IIN
      bit from the outstation.

   ``property unsolClassMask``

      Bitwise mask used determine which classes are enabled for unsol,
      if 0 unsol is not enabled.

**class pydnp3.opendnp3.MasterTaskType**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration of internal tasks.

   Members:

      CLEAR_RESTART

      DISABLE_UNSOLICITED

      ASSIGN_CLASS

      STARTUP_INTEGRITY_POLL

      NON_LAN_TIME_SYNC

      LAN_TIME_SYNC

      ENABLE_UNSOLICITED

      AUTO_EVENT_SCAN

      USER_TASK

   **__init__(self: pydnp3.opendnp3.MasterTaskType, arg0: int) ->
   None**

**pydnp3.opendnp3.MasterTaskTypeToString(arg0:
pydnp3.opendnp3.MasterTaskType) -> str**

**class pydnp3.opendnp3.Measurement**

   Bases: ``pybind11_builtins.pybind11_object``

   Base class shared by all of the DataPoint types.

   **__init__(*args, **kwargs)**

   ``property flags``

      Bitfield that stores type specific quality information.

   ``property time``

      Timestamp associated with the measurement.

**class pydnp3.opendnp3.OctetData**

   Bases: ``pybind11_builtins.pybind11_object``

   A base-class for bitstrings containing up to 255 bytes

   **ToRSlice(self: pydnp3.opendnp3.OctetData) ->
   `pydnp3.openpal.RSlice <openpal.rst#pydnp3.openpal.RSlice>`_**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.OctetData) -> None

      2. __init__(self: pydnp3.opendnp3.OctetData, input:
         pydnp3.openpal.RSlice) -> None

**class pydnp3.opendnp3.OctetString**

   Bases: `pydnp3.opendnp3.OctetData <#pydnp3.opendnp3.OctetData>`_

   Respresents group 110/111 objects.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.OctetString) -> None

      2. __init__(self: pydnp3.opendnp3.OctetString, data:
         pydnp3.opendnp3.OctetString) -> None

      3. __init__(self: pydnp3.opendnp3.OctetString, buffer:
         pydnp3.openpal.RSlice) -> None

**class pydnp3.opendnp3.OperateType**

   Bases: ``pybind11_builtins.pybind11_object``

   Various ways that an outstation can receive a request to operate a
   BO or AO point.

   Members:

      SELECT_BEFORE_OPERATE : The outstation received a valid prior
      SELECT followed by OPERATE.

      DIRECT_OPERATE : The outstation received a direct operate
      request.

      DIRECT_OPERATE_NO_ACK : The outstation received a direct operate
      no ack request.

   **__init__(self: pydnp3.opendnp3.OperateType, arg0: int) -> None**

**class pydnp3.opendnp3.OutstationConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   Configuration information for a dnp3 outstation (outstation).  Used
   as both input describing the startup configuration of the
   outstation, and as configuration state of mutable properties (i.e.
   unsolicited responses).  Major feature areas are unsolicited
   responses, time synchronization requests, event buffer limits, and
   the DNP3 object/variations to use by default when the master
   requests class data or variation 0.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.OutstationConfig) -> None

      2. __init__(self: pydnp3.opendnp3.OutstationConfig, params:
         pydnp3.opendnp3.OutstationParams, eventBufferConfig:
         pydnp3.opendnp3.EventBufferConfig) -> None

   ``property eventBufferConfig``

      Describes the sizes in the event buffer.

   ``property params``

      Various parameters that govern outstation behavior.

**class pydnp3.opendnp3.OutstationParams**

   Bases: ``pybind11_builtins.pybind11_object``

   Static configuration parameters for an outstation session.

   **__init__(self: pydnp3.opendnp3.OutstationParams, indexMode:
   pydnp3.opendnp3.IndexMode = IndexMode.Contiguous,
   maxControlsPerRequest: int = 16, selectTimeout:
   pydnp3.openpal.TimeDuration = <pydnp3.openpal.TimeDuration object
   at 0x7f756d3135b0>, solConfirmTimeout: pydnp3.openpal.TimeDuration
   = <pydnp3.openpal.TimeDuration object at 0x7f756db0f4f0>,
   unsolConfirmTimeout: pydnp3.openpal.TimeDuration =
   <pydnp3.openpal.TimeDuration object at 0x7f756db0f4f0>,
   unsolRetryTimeout: pydnp3.openpal.TimeDuration =
   <pydnp3.openpal.TimeDuration object at 0x7f756db0f4f0>,
   maxTxFragSize: int = 2048, maxRxFragSize: int = 2048,
   allowUnsolicited: bool = False, typesAllowedInClass0:
   pydnp3.opendnp3.StaticTypeBitField =
   <pydnp3.opendnp3.StaticTypeBitField object at 0x7f756d313570>,
   unsolClassMask: pydnp3.opendnp3.ClassField =
   <pydnp3.opendnp3.ClassField object at 0x7f756d313530>) -> None**

   ``property allowUnsolicited``

      Global enabled/ disable for unsolicited messages. If false, the
      NULL unsolicited message is not even sent.

   ``property indexMode``

      Controls the index mode (defaults to contiguous).

   ``property maxControlsPerRequest``

      The maximum number of controls the outstation will attempt to
      process from a single APDU.  :type maxControlsPerRequest:
      unsigned char

   ``property maxRxFragSize``

      The maximum fragment size the outstation will be able to
      receive.  :type maxRxFragSize: unsigned int

   ``property maxTxFragSize``

      The maximum fragment size the outstation will use for fragments
      it sends.  :type maxTxFragSize: unsigned int

   ``property selectTimeout``

      How long the outstation will allow an operate to proceed after a
      prior select.

   ``property solConfirmTimeout``

      Timeout for solicited confirms.

   ``property typesAllowedInClass0``

      A bitmask type that specifies the types allowed in a class 0
      reponse.

   ``property unsolClassMask``

      Class mask for unsolicted, default to 0 as unsolicited has to be
      enabled.

   ``property unsolConfirmTimeout``

      Timeout for unsolicited confirms.

   ``property unsolRetryTimeout``

      Timeout for unsolicited retries.

**class pydnp3.opendnp3.Parity**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration for setting serial port parity.

   Members:

      Even

      Odd

      None

   **__init__(self: pydnp3.opendnp3.Parity, arg0: int) -> None**

**pydnp3.opendnp3.ParityFromType(rawType: int) ->
`pydnp3.opendnp3.Parity <#pydnp3.opendnp3.Parity>`_**

**pydnp3.opendnp3.ParityToString(parity: pydnp3.opendnp3.Parity) ->
str**

**pydnp3.opendnp3.ParityToType(parity: pydnp3.opendnp3.Parity) ->
int**

**class pydnp3.opendnp3.PointClass**

   Bases: ``pybind11_builtins.pybind11_object``

   Class assignment for a measurement point.

   Members:

      Class0 : No event class assignment.

      Class1 : Assigned to event class 1.

      Class2 : Assigned to event class 2.

      Class3 : Assigned to event class 3.

   **__init__(self: pydnp3.opendnp3.PointClass, arg0: int) -> None**

**class pydnp3.opendnp3.QualifierCode**

   Bases: ``pybind11_builtins.pybind11_object``

   Object header range/prefix as a single enumeration.

   Members:

      UINT8_START_STOP

      UINT16_START_STOP

      ALL_OBJECTS

      UINT8_CNT

      UINT16_CNT

      UINT8_CNT_UINT8_INDEX

      UINT16_CNT_UINT16_INDEX

      UINT16_FREE_FORMAT

      UNDEFINED

   **__init__(self: pydnp3.opendnp3.QualifierCode, arg0: int) ->
   None**

**pydnp3.opendnp3.QualifierCodeFromType(rawType: int) ->
`pydnp3.opendnp3.QualifierCode <#pydnp3.opendnp3.QualifierCode>`_**

**pydnp3.opendnp3.QualifierCodeToString(code:
pydnp3.opendnp3.QualifierCode) -> str**

**pydnp3.opendnp3.QualifierCodeToType(code:
pydnp3.opendnp3.QualifierCode) -> int**

**class pydnp3.opendnp3.RestartMode**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration describing restart mode support of an outstation.

   Members:

      UNSUPPORTED : Device does not support restart.

      SUPPORTED_DELAY_FINE : Supports restart, and time returned is a
      fine time delay.

      SUPPORTED_DELAY_COARSE : Supports restart, and time returned is
      a coarse time delay.

   **__init__(self: pydnp3.opendnp3.RestartMode, arg0: int) -> None**

**class pydnp3.opendnp3.RestartType**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration describing restart operation to perform on an
   outstation.

   Members:

      COLD : Full reboot.

      WARM : Warm reboot of process only.

   **__init__(self: pydnp3.opendnp3.RestartType, arg0: int) -> None**

**class pydnp3.opendnp3.SecurityStat**

   Bases: ``pybind11_builtins.pybind11_object``

   SA security statistic object as used by the API.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.SecurityStat) -> None

      2. __init__(self: pydnp3.opendnp3.SecurityStat, value:
         pydnp3.opendnp3.SecurityStatValue, quality: int, time:
         pydnp3.opendnp3.DNPTime) -> None

      1. __init__(self: pydnp3.opendnp3.SecurityStat, quality: int,
         assocId: int, count: int) -> None

      1. __init__(self: pydnp3.opendnp3.SecurityStat, quality: int,
         assocId: int, count: int, time: pydnp3.opendnp3.DNPTime) ->
         None

   ``property quality``

**class pydnp3.opendnp3.SecurityStatConfig**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   **__init__(self: pydnp3.opendnp3.SecurityStatConfig) -> None**

**class pydnp3.opendnp3.SecurityStatIndex**

   Bases: ``pybind11_builtins.pybind11_object``

   Indices of the SA security statistics.

   Members:

      UNEXPECTED_MESSAGES : The other device has responded with a
      message that was not the expected next step in the state
      machine.

      AUTHORIZATION_FAILURES : The other device has replied with the
      correct authentication information, so the user is authentic,
      but the user is not authorized to perform the requested
      operation.

      AUTHENTICATION_FAILURES : The other device has provided invalid
      authentication information such as an incorrect MAC.

      REPLY_TIMEOUTS :  The other device has not replied within the
      configured time required.

      REKEYS_DUE_TO_AUTH_FAILUE : An Authentication Failure has
      occurred that causes the master station to change the session
      keys.

      TOTAL_MESSAGES_TX : The device sends an Application Layer
      fragment.

      TOTAL_MESSAGES_RX : The device receives an Application Layer
      fragment.

      CRITICAL_MESSAGES_TX : The device receives a Challenge message
      or transmits an Aggressive Mode Request message.

      CRITICAL_MESSAGES_RX : The device transmits a Challenge message
      or receives an Aggressive Mode Request message.

      DISCARED_MESSAGES : The device discards a received message.

      ERROR_MESSAGES_TX : The device has sent a fragment containing an
      Error object indicating an authentication failure or potential
      configuration error.

      ERROR_MESSAGES_RX : The device has received an Error object.

      SUCCESSFUL_AUTHS : The device successfully authenticates a
      message.

      SESSION_KEY_CHANGES : A users session key is successfully
      changed.

      FAILED_SESSION_KEY_CHANGES : A failure occurs while changing a
      session key.

      UPDATE_KEY_CHANGES : The master and authority change the Update
      Key for a user.

      FAILED_UPDATE_KEY_CHANGES : The master and authority fail to
      change the Update Key for a user.

      REKEYS_DUE_TO_RESTART : Only used by a master. Set to zero in
      outstations. The master rekeyed the session keys because the
      outstation restarted.

   **__init__(self: pydnp3.opendnp3.SecurityStatIndex, arg0: int) ->
   None**

**class pydnp3.opendnp3.SimpleCommandHandler**

   Bases: `pydnp3.opendnp3.ICommandHandler
   <#pydnp3.opendnp3.ICommandHandler>`_

   Mock ICommandHandler used for examples and demos.

   **Operate(*args, **kwargs)**

      Overloaded function.

      1. Operate(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.ControlRelayOutputBlock, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

      1. Operate(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt16, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

      1. Operate(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt32, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

      1. Operate(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputFloat32, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

      1. Operate(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputDouble64, index: int, opType:
         pydnp3.opendnp3.OperateType) -> pydnp3.opendnp3.CommandStatus

   **Select(*args, **kwargs)**

      Overloaded function.

      1. Select(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.ControlRelayOutputBlock, index: int) ->
         pydnp3.opendnp3.CommandStatus

      1. Select(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt16, index: int) ->
         pydnp3.opendnp3.CommandStatus

      1. Select(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputInt32, index: int) ->
         pydnp3.opendnp3.CommandStatus

      1. Select(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputFloat32, index: int) ->
         pydnp3.opendnp3.CommandStatus

      1. Select(self: pydnp3.opendnp3.SimpleCommandHandler, command:
         pydnp3.opendnp3.AnalogOutputDouble64, index: int) ->
         pydnp3.opendnp3.CommandStatus

   **__init__(self: pydnp3.opendnp3.SimpleCommandHandler, arg0:
   pydnp3.opendnp3.CommandStatus) -> None**

      :Parameters:
         **status** – The status value to return in response to all
         commands

   ``property numEnd``

   ``property numOperate``

   ``property numSelect``

   ``property numStart``

**class pydnp3.opendnp3.SimpleEventCellBinaryOutputStatusSpec**

   Bases: `pydnp3.opendnp3.EventCellBaseBinaryOutputStatusSpec
   <#pydnp3.opendnp3.EventCellBaseBinaryOutputStatusSpec>`_

   Metatype without a deadband.

   **IsEvent(self:
   pydnp3.opendnp3.SimpleEventCellBinaryOutputStatusSpec, config:
   opendnp3::BOStatusConfig, newValue: opendnp3::BinaryOutputStatus)
   -> bool**

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.SimpleEventCellBinarySpec**

   Bases: `pydnp3.opendnp3.EventCellBaseBinarySpec
   <#pydnp3.opendnp3.EventCellBaseBinarySpec>`_

   Metatype without a deadband.

   **IsEvent(self: pydnp3.opendnp3.SimpleEventCellBinarySpec, config:
   opendnp3::BinaryConfig, newValue: opendnp3::Binary) -> bool**

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.SimpleEventCellDoubleBitBinarySpec**

   Bases: `pydnp3.opendnp3.EventCellBaseDoubleBitBinarySpec
   <#pydnp3.opendnp3.EventCellBaseDoubleBitBinarySpec>`_

   Metatype without a deadband.

   **IsEvent(self: pydnp3.opendnp3.SimpleEventCellDoubleBitBinarySpec,
   config: opendnp3::DoubleBitBinaryConfig, newValue:
   opendnp3::DoubleBitBinary) -> bool**

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.StackStatistics**

   Bases: ``pybind11_builtins.pybind11_object``

   Statistics related to both a master or outstation session.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.StackStatistics) -> None

      2. __init__(self: pydnp3.opendnp3.StackStatistics, link:
         pydnp3.opendnp3.StackStatisticsLink, transport:
         pydnp3.opendnp3.StackStatisticsTransport) -> None

**class pydnp3.opendnp3.StartStopRangeUint16**

   Bases: ``pybind11_builtins.pybind11_object``

   A template for a integer range.

   **__init__(self: pydnp3.opendnp3.StartStopRangeUint16, start: int =
   0, stop: int = 0) -> None**

**class pydnp3.opendnp3.StartStopRangeUint8**

   Bases: ``pybind11_builtins.pybind11_object``

   A template for a integer range.

   **__init__(self: pydnp3.opendnp3.StartStopRangeUint8, start: int =
   0, stop: int = 0) -> None**

**class pydnp3.opendnp3.StaticAnalogOutputStatusVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group40Var1

   Group40Var2

   Group40Var3

   Group40Var4

   **__init__(self: pydnp3.opendnp3.StaticAnalogOutputStatusVariation,
   arg0: int) -> None**

**class pydnp3.opendnp3.StaticAnalogVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group30Var1

   Group30Var2

   Group30Var3

   Group30Var4

   Group30Var5

   Group30Var6

   **__init__(self: pydnp3.opendnp3.StaticAnalogVariation, arg0: int)
   -> None**

**class pydnp3.opendnp3.StaticBinaryOutputStatusVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group10Var2

   **__init__(self: pydnp3.opendnp3.StaticBinaryOutputStatusVariation,
   arg0: int) -> None**

**class pydnp3.opendnp3.StaticBinaryVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group1Var1

   Group1Var2

   **__init__(self: pydnp3.opendnp3.StaticBinaryVariation, arg0: int)
   -> None**

**pydnp3.opendnp3.StaticConfig(*args, **kwargs)**

   Overloaded function.

   1. StaticConfig() -> pydnp3.opendnp3.StaticConfigBinaryInfo

   Return instance of class StaticConfig<Info>

   1. StaticConfig() ->
      pydnp3.opendnp3.StaticConfigDoubleBitBinaryInfo

   Return instance of class StaticConfig<Info>

   1. StaticConfig() -> pydnp3.opendnp3.StaticConfigAnalogInfo

   Return instance of class StaticConfig<Info>

   1. StaticConfig() -> pydnp3.opendnp3.StaticConfigCounterInfo

   Return instance of class StaticConfig<Info>

   1. StaticConfig() -> pydnp3.opendnp3.StaticConfigFrozenCounterInfo

   Return instance of class StaticConfig<Info>

   1. StaticConfig() ->
      pydnp3.opendnp3.StaticConfigBinaryOutputStatusInfo

   Return instance of class StaticConfig<Info>

   1. StaticConfig() ->
      pydnp3.opendnp3.StaticConfigAnalogOutputStatusInfo

   Return instance of class StaticConfig<Info>

   1. StaticConfig() ->
      pydnp3.opendnp3.StaticConfigTimeAndIntervalInfo

   Return instance of class StaticConfig<Info>

**class pydnp3.opendnp3.StaticConfigAnalogInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self: pydnp3.opendnp3.StaticConfigAnalogInfo) -> None**

**class pydnp3.opendnp3.StaticConfigAnalogOutputStatusInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self:
   pydnp3.opendnp3.StaticConfigAnalogOutputStatusInfo) -> None**

**class pydnp3.opendnp3.StaticConfigBinaryInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self: pydnp3.opendnp3.StaticConfigBinaryInfo) -> None**

**class pydnp3.opendnp3.StaticConfigBinaryOutputStatusInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self:
   pydnp3.opendnp3.StaticConfigBinaryOutputStatusInfo) -> None**

**class pydnp3.opendnp3.StaticConfigCounterInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self: pydnp3.opendnp3.StaticConfigCounterInfo) -> None**

**class pydnp3.opendnp3.StaticConfigDoubleBitBinaryInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self: pydnp3.opendnp3.StaticConfigDoubleBitBinaryInfo)
   -> None**

**class pydnp3.opendnp3.StaticConfigFrozenCounterInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self: pydnp3.opendnp3.StaticConfigFrozenCounterInfo) ->
   None**

**class pydnp3.opendnp3.StaticConfigTimeAndIntervalInfo**

   Bases: `pydnp3.opendnp3.IndexConfig
   <#pydnp3.opendnp3.IndexConfig>`_

   All entries have this information.

   **__init__(self: pydnp3.opendnp3.StaticConfigTimeAndIntervalInfo)
   -> None**

**class pydnp3.opendnp3.StaticCounterVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group20Var1

   Group20Var2

   Group20Var5

   Group20Var6

   **__init__(self: pydnp3.opendnp3.StaticCounterVariation, arg0: int)
   -> None**

**class pydnp3.opendnp3.StaticDoubleBinaryVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group3Var2

   **__init__(self: pydnp3.opendnp3.StaticDoubleBinaryVariation, arg0:
   int) -> None**

**class pydnp3.opendnp3.StaticFrozenCounterVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group21Var1

   Group21Var2

   Group21Var5

   Group21Var6

   Group21Var9

   Group21Var10

   **__init__(self: pydnp3.opendnp3.StaticFrozenCounterVariation,
   arg0: int) -> None**

**class pydnp3.opendnp3.StaticSecurityStatVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group121Var1

   **__init__(self: pydnp3.opendnp3.StaticSecurityStatVariation, arg0:
   int) -> None**

**class pydnp3.opendnp3.StaticTimeAndIntervalVariation**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   Group50Var4

   **__init__(self: pydnp3.opendnp3.StaticTimeAndIntervalVariation,
   arg0: int) -> None**

**class pydnp3.opendnp3.StaticTypeBitField**

   Bases: ``pybind11_builtins.pybind11_object``

   A bitfield that describes a subset of all static types.  E.g.
   {Binary, Analog} or {Analog, Counter, FrozenCounter}

   **AllTypes() -> `pydnp3.opendnp3.StaticTypeBitField
   <#pydnp3.opendnp3.StaticTypeBitField>`_**

   **Except(self: pydnp3.opendnp3.StaticTypeBitField, type:
   pydnp3.opendnp3.StaticTypeBitmask) ->
   `pydnp3.opendnp3.StaticTypeBitField
   <#pydnp3.opendnp3.StaticTypeBitField>`_**

   **IsSet(self: pydnp3.opendnp3.StaticTypeBitField, type:
   pydnp3.opendnp3.StaticTypeBitmask) -> bool**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.StaticTypeBitField) -> None

      2. __init__(self: pydnp3.opendnp3.StaticTypeBitField, mask: int)
         -> None

      type mask: unsigned short

**class pydnp3.opendnp3.StaticTypeBitmask**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   BinaryInput

   DoubleBinaryInput

   Counter

   FrozenCounter

   AnalogInput

   BinaryOutputStatus

   AnalogOutputStatus

   TimeAndInterval

   **__init__(self: pydnp3.opendnp3.StaticTypeBitmask, arg0: int) ->
   None**

**class pydnp3.opendnp3.StopBits**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumeration for setting serial port stop bits.

   Members:

      One

      OnePointFive

      Two

      None

   **__init__(self: pydnp3.opendnp3.StopBits, arg0: int) -> None**

**pydnp3.opendnp3.StopBitsFromType(rawType: int) ->
`pydnp3.opendnp3.StopBits <#pydnp3.opendnp3.StopBits>`_**

**pydnp3.opendnp3.StopBitsToString(stopBits: pydnp3.opendnp3.StopBits)
-> str**

**pydnp3.opendnp3.StopBitsToType(stopBits: pydnp3.opendnp3.StopBits)
-> int**

**class pydnp3.opendnp3.SuccessCommandHandler**

   Bases: `pydnp3.opendnp3.SimpleCommandHandler
   <#pydnp3.opendnp3.SimpleCommandHandler>`_

   A singleton command handler that always returns success.

   **Create() -> `pydnp3.opendnp3.ICommandHandler
   <#pydnp3.opendnp3.ICommandHandler>`_**

      :Returns:
         shared_ptr to opendnp3.ICommandHandler

   **__init__(self: pydnp3.opendnp3.SuccessCommandHandler) -> None**

**class pydnp3.opendnp3.TaskCompletion**

   Bases: ``pybind11_builtins.pybind11_object``

   Enum that describes if a master task succeeded or failed.

   Members:

      SUCCESS : A valid response was received from the outstation.

      FAILURE_BAD_RESPONSE : A response was received from the
      outstation, but it was not valid.

      FAILURE_RESPONSE_TIMEOUT : The task request did not receive a
      response within the timeout.

      FAILURE_START_TIMEOUT : The start timeout expired before the
      task could begin running.

      FAILURE_MESSAGE_FORMAT_ERROR : The task failed because the
      master was unable to format the request.

      FAILURE_NO_COMMS : There is no communication with the
      outstation, so the task was not attempted.

   **__init__(self: pydnp3.opendnp3.TaskCompletion, arg0: int) ->
   None**

**pydnp3.opendnp3.TaskCompletionToString(arg0:
pydnp3.opendnp3.TaskCompletion) -> str**

**class pydnp3.opendnp3.TaskConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   Object containing multiple fields for configuring tasks.

   **Default() -> `pydnp3.opendnp3.TaskConfig
   <#pydnp3.opendnp3.TaskConfig>`_**

   **With(arg0: pydnp3.opendnp3.ITaskCallback) ->
   `pydnp3.opendnp3.TaskConfig <#pydnp3.opendnp3.TaskConfig>`_**

      Syntax sugar for building configs.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.TaskConfig, taskId:
         pydnp3.opendnp3.TaskId, pCallback:
         pydnp3.opendnp3.ITaskCallback) -> None

      2. __init__(self: pydnp3.opendnp3.TaskConfig) -> None

      Default constructor.

**class pydnp3.opendnp3.TaskId**

   Bases: ``pybind11_builtins.pybind11_object``

   Interface that represents a running master.

   **Defined(id: int) -> `pydnp3.opendnp3.TaskId
   <#pydnp3.opendnp3.TaskId>`_**

   **GetId(self: pydnp3.opendnp3.TaskId) -> int**

   **IsDefined(self: pydnp3.opendnp3.TaskId) -> bool**

   **Undefined() -> `pydnp3.opendnp3.TaskId
   <#pydnp3.opendnp3.TaskId>`_**

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.TaskInfo**

   Bases: ``pybind11_builtins.pybind11_object``

   Struct that provides information about a completed or failed task.

   **__init__(self: pydnp3.opendnp3.TaskInfo, type:
   pydnp3.opendnp3.MasterTaskType, result:
   pydnp3.opendnp3.TaskCompletion, id: pydnp3.opendnp3.TaskId) ->
   None**

**class pydnp3.opendnp3.TimeAndInterval**

   Bases: ``pybind11_builtins.pybind11_object``

   Maps to Group50Var4.  This class is a bit of an outlier as an
   indexed type and is really only used in the DNP3 PV profile.

   **GetUnitsEnum(self: pydnp3.opendnp3.TimeAndInterval) ->
   `pydnp3.opendnp3.IntervalUnits <#pydnp3.opendnp3.IntervalUnits>`_**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.TimeAndInterval) -> None

      2. __init__(self: pydnp3.opendnp3.TimeAndInterval, time:
         pydnp3.opendnp3.DNPTime, interval: int, units: int) -> None

      1. __init__(self: pydnp3.opendnp3.TimeAndInterval, time:
         pydnp3.opendnp3.DNPTime, interval: int, units:
         pydnp3.opendnp3.IntervalUnits) -> None

   ``property interval``

   ``property units``

**class pydnp3.opendnp3.TimeAndIntervalConfig**

   Bases: `pydnp3.opendnp3.StaticConfigTimeAndIntervalInfo
   <#pydnp3.opendnp3.StaticConfigTimeAndIntervalInfo>`_

   **__init__(self: pydnp3.opendnp3.TimeAndIntervalConfig) -> None**

**class pydnp3.opendnp3.TimeSyncMode**

   Bases: ``pybind11_builtins.pybind11_object``

   Indicates the validity of timestamp values for an entire object
   header.

   Members:

      NonLAN : Synchronize the outstation’s time using the non-LAN
      time sync procedure.

      LAN : Synchronize the outstation’s time using the LAN time sync
      procedure.

      None : Don’t perform a time-sync.

   **__init__(self: pydnp3.opendnp3.TimeSyncMode, arg0: int) -> None**

**class pydnp3.opendnp3.TimestampMode**

   Bases: ``pybind11_builtins.pybind11_object``

   Determines what the master station does when it sees the NEED_TIME
   iin bit.

   Members:

      SYNCHRONIZED : The timestamp is UTC synchronized at the remote
      device.

      UNSYNCHRONIZED : The device indicate the timestamp may be
      unsynchronized.

      INVALID : Timestamp is not valid, ignore the value and use a
      local timestamp.

   **__init__(self: pydnp3.opendnp3.TimestampMode, arg0: int) ->
   None**

**pydnp3.opendnp3.ToUnderlying(*args, **kwargs)**

   Overloaded function.

   1. ToUnderlying(flag: pydnp3.opendnp3.BinaryQuality) -> int

   2. ToUnderlying(flag: pydnp3.opendnp3.DoubleBitBinaryQuality) ->
      int

   3. ToUnderlying(flag: pydnp3.opendnp3.CounterQuality) -> int

   4. ToUnderlying(flag: pydnp3.opendnp3.FrozenCounterQuality) -> int

   5. ToUnderlying(flag: pydnp3.opendnp3.AnalogQuality) -> int

   6. ToUnderlying(flag: pydnp3.opendnp3.AnalogOutputStatusQuality) ->
      int

   7. ToUnderlying(flag: pydnp3.opendnp3.BinaryOutputStatusQuality) ->
      int

**class pydnp3.opendnp3.Transaction**

   Bases: ``pybind11_builtins.pybind11_object``

   Uses RAII to safely perform a transaction.

   **Apply(transactable: pydnp3.opendnp3.ITransactable, fun:
   Callable[[pydnp3.opendnp3.Transaction], None]) -> None**

   **End(pTransactable: pydnp3.opendnp3.ITransactable) -> None**

   **Start(pTransactable: pydnp3.opendnp3.ITransactable) -> None**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.opendnp3.Transaction, transactable:
         pydnp3.opendnp3.ITransactable) -> None

      2. __init__(self: pydnp3.opendnp3.Transaction, pTransactable:
         pydnp3.opendnp3.ITransactable) -> None

**class pydnp3.opendnp3.TypedMeasurementBool**

   Bases: `pydnp3.opendnp3.Measurement
   <#pydnp3.opendnp3.Measurement>`_

   Common subclass to analogs and counters.

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.TypedMeasurementDouble**

   Bases: `pydnp3.opendnp3.Measurement
   <#pydnp3.opendnp3.Measurement>`_

   Common subclass to analogs and counters.

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.TypedMeasurementDoubleBit**

   Bases: `pydnp3.opendnp3.Measurement
   <#pydnp3.opendnp3.Measurement>`_

   Common subclass to analogs and counters.

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.TypedMeasurementUint32**

   Bases: `pydnp3.opendnp3.Measurement
   <#pydnp3.opendnp3.Measurement>`_

   Common subclass to analogs and counters.

   **__init__(*args, **kwargs)**

**class pydnp3.opendnp3.UserOperation**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumerates possible remote operations on users.

   Members:

      OP_ADD

      OP_DELETE

      OP_CHANGE

      OP_UNDEFINED

   **__init__(self: pydnp3.opendnp3.UserOperation, arg0: int) ->
   None**

**pydnp3.opendnp3.UserOperationFromType(rawType: int) ->
`pydnp3.opendnp3.UserOperation <#pydnp3.opendnp3.UserOperation>`_**

**pydnp3.opendnp3.UserOperationToString(userOperation:
pydnp3.opendnp3.UserOperation) -> str**

**pydnp3.opendnp3.UserOperationToType(userOperation:
pydnp3.opendnp3.UserOperation) -> int**

**class pydnp3.opendnp3.UserRole**

   Bases: ``pybind11_builtins.pybind11_object``

   Enumerates pre-defined rules in secure authentication.

   Members:

      VIEWER

      OPERATOR

      ENGINEER

      INSTALLER

      SECADM

      SECAUD

      RBACMNT

      SINGLE_USER

      UNDEFINED

   **__init__(self: pydnp3.opendnp3.UserRole, arg0: int) -> None**

**pydnp3.opendnp3.UserRoleFromType(rawType: int) ->
`pydnp3.opendnp3.UserRole <#pydnp3.opendnp3.UserRole>`_**

**pydnp3.opendnp3.UserRoleToString(userRole: pydnp3.opendnp3.UserRole)
-> str**

**pydnp3.opendnp3.UserRoleToType(userRole: pydnp3.opendnp3.UserRole)
-> int**

**pydnp3.opendnp3.WithIndex(*args, **kwargs)**

   Overloaded function.

   1. WithIndex(arg0: opendnp3::Binary, arg1: int) ->
      pydnp3.opendnp3.IndexedBinary

   2. WithIndex(arg0: opendnp3::DoubleBitBinary, arg1: int) ->
      pydnp3.opendnp3.IndexedDoubleBitBinary

   3. WithIndex(arg0: opendnp3::Analog, arg1: int) ->
      pydnp3.opendnp3.IndexedAnalog

   4. WithIndex(arg0: opendnp3::Counter, arg1: int) ->
      pydnp3.opendnp3.IndexedCounter

   5. WithIndex(arg0: opendnp3::FrozenCounter, arg1: int) ->
      pydnp3.opendnp3.IndexedFrozenCounter

   6. WithIndex(arg0: opendnp3::BinaryOutputStatus, arg1: int) ->
      pydnp3.opendnp3.IndexedBinaryOutputStatus

   7. WithIndex(arg0: opendnp3::AnalogOutputStatus, arg1: int) ->
      pydnp3.opendnp3.IndexedAnalogOutputStatus

   8. WithIndex(arg0: opendnp3::OctetString, arg1: int) ->
      pydnp3.opendnp3.IndexedOctetString

   9. WithIndex(arg0: opendnp3::TimeAndInterval, arg1: int) ->
      pydnp3.opendnp3.IndexedTimeAndInterval

   10. WithIndex(arg0: pydnp3.opendnp3.BinaryCommandEvent, arg1: int)
       -> pydnp3.opendnp3.IndexedBinaryCommandEvent

   11. WithIndex(arg0: pydnp3.opendnp3.AnalogCommandEvent, arg1: int)
       -> pydnp3.opendnp3.IndexedAnalogCommandEvent

   12. WithIndex(arg0: opendnp3::SecurityStat, arg1: int) ->
       pydnp3.opendnp3.IndexedSecurityStat

   13. WithIndex(arg0: pydnp3.opendnp3.ControlRelayOutputBlock, arg1:
       int) -> pydnp3.opendnp3.IndexedControlRelayOutputBlock

   14. WithIndex(arg0: pydnp3.opendnp3.AnalogOutputInt16, arg1: int)
       -> pydnp3.opendnp3.IndexedAnalogOutputInt16

   15. WithIndex(arg0: pydnp3.opendnp3.AnalogOutputInt32, arg1: int)
       -> pydnp3.opendnp3.IndexedAnalogOutputInt32

   16. WithIndex(arg0: pydnp3.opendnp3.AnalogOutputFloat32, arg1: int)
       -> pydnp3.opendnp3.IndexedAnalogOutputFloat32

   17. WithIndex(arg0: pydnp3.opendnp3.AnalogOutputDouble64, arg1:
       int) -> pydnp3.opendnp3.IndexedAnalogOutputDouble64


pydnp3.opendnp3.measurements
****************************

**pydnp3.opendnp3.measurements.IsEvent(*args, **kwargs)**

   Overloaded function.

   1. IsEvent(arg0: int, arg1: int, arg2: int) -> bool

   2. IsEvent(newMeas: pydnp3.opendnp3.TypedMeasurementDouble,
      oldMeas: pydnp3.opendnp3.TypedMeasurementDouble, deadband:
      float) -> bool


pydnp3.opendnp3.flags
*********************

See source or Python *help()* in REPL for values of constants in this
module.


pydnp3.opendnp3.levels
**********************

See source or Python *help()* in REPL for values of constants in this
module.
