
pydnp3.asiodnp3
***************

Bindings for asiodnp3 namespace

**class pydnp3.asiodnp3.ConsoleLogger**

   Bases: `pydnp3.openpal.ILogHandler
   <openpal.rst#pydnp3.openpal.ILogHandler>`_

   LogHandler that prints all log messages to the console.

   **Create(printLocation: bool = False) ->
   `pydnp3.openpal.ILogHandler
   <openpal.rst#pydnp3.openpal.ILogHandler>`_**

      :Parameters:
         **printLocation** – defaults to False

      :Returns:
         shared_ptr to openpal.ILogHandler

   **Log(self: pydnp3.asiodnp3.ConsoleLogger, entry:
   pydnp3.openpal.LogEntry) -> None**

         Callback method for log messages.

      :Parameters:
         **entry** – the log message to handle

   **__init__(self: pydnp3.asiodnp3.ConsoleLogger, printLocation: bool
   = False) -> None**

      :Parameters:
         **printLocation** – defaults to False

**class pydnp3.asiodnp3.DNP3Manager**

   Bases: ``pybind11_builtins.pybind11_object``

   Root DNP3 object used to create channels and sessions.

   **AddSerial(self: pydnp3.asiodnp3.DNP3Manager, id: str, levels:
   int, retry: pydnp3.asiopal.ChannelRetry, settings:
   pydnp3.asiopal.SerialSettings, listener:
   pydnp3.asiodnp3.IChannelListener) -> `pydnp3.asiodnp3.IChannel
   <#pydnp3.asiodnp3.IChannel>`_**

         Add a persistent TCP serial channel.

      :Parameters:
         *  **id** – Alias that will be used for logging purposes with
            this channel

         *  **levels** – Bitfield that describes the logging level for
            this channel and associated sessions

         *  **retry** – Retry parameters for failed channels

         *  **settings** – settings object that fully parameterizes
            the serial port

         *  **listener** – optional callback interface (can be
            nullptr) for info about the running channel

      :Returns:
         shared_ptr to a channel interface

   **AddTCPClient(self: pydnp3.asiodnp3.DNP3Manager, id: str, levels:
   int, retry: pydnp3.asiopal.ChannelRetry, host: str, local: str,
   port: int, listener: pydnp3.asiodnp3.IChannelListener) ->
   `pydnp3.asiodnp3.IChannel <#pydnp3.asiodnp3.IChannel>`_**

         Add a persistent TCP client channel. Automatically attempts
         to reconnect.

      :Parameters:
         *  **id** – Alias that will be used for logging purposes with
            this channel

         *  **levels** – Bitfield that describes the logging level for
            this channel and associated sessions

         *  **retry** – Retry parameters for failed channels

         *  **host** – IP address of remote outstation (i.e. 127.0.0.1
            or www.google.com)

         *  **local** – adapter address on which to attempt the
            connection (use 0.0.0.0 for all adapters)

         *  **port** – Port of remote outstation is listening on

      :param listener optional callback interface (can be nullptr) for
      info about the running channel  :return: shared_ptr to a channel
      interface

   **AddTCPServer(self: pydnp3.asiodnp3.DNP3Manager, id: str, levels:
   int, retry: pydnp3.asiopal.ChannelRetry, endpoint: str, port: int,
   listener: pydnp3.asiodnp3.IChannelListener) ->
   `pydnp3.asiodnp3.IChannel <#pydnp3.asiodnp3.IChannel>`_**

         Add a persistent TCP server channel. Only accepts a single
         connection at a time.

      :Parameters:
         *  **id** – Alias that will be used for logging purposes with
            this channel

         *  **levels** – Bitfield that describes the logging level for
            this channel and associated sessions

         *  **retry** – Retry parameters for failed channels

         *  **endpoint** – Network adapter to listen on, i.e.
            127.0.0.1 or 0.0.0.0

         *  **port** – Port to listen on

         *  **listener** – optional callback interface (can be
            nullptr) for info about the running channel

      :Returns:
         shared_ptr to a channel interface

   **AddTLSClient(self: pydnp3.asiodnp3.DNP3Manager, id: str, levels:
   int, retry: pydnp3.asiopal.ChannelRetry, host: str, local: str,
   port: int, config: pydnp3.asiopal.TLSConfig, listener:
   pydnp3.asiodnp3.IChannelListener, ec: std::error_code) ->
   `pydnp3.asiodnp3.IChannel <#pydnp3.asiodnp3.IChannel>`_**

         Add a TLS client channel.

      :throw std::system_error Throws underlying ASIO exception of TLS
      configuration is invalid  :param id: Alias that will be used for
      logging purposes with this channel  :param levels: Bitfield that
      describes the logging level for this channel and associated
      sessions  :param retry: Retry parameters for failed channels
      :param host: IP address of remote outstation (i.e. 127.0.0.1 or
      www.google.com)  :param local: adapter address on which to
      attempt the connection (use 0.0.0.0 for all adapters)  :param
      port: Port of remote outstation is listening on  :param config:
      TLS configuration information  :param listener: optional
      callback interface (can be nullptr) for info about the running
      channel  :param ec: An error code. If set, a nullptr will be
      returned  :return: shared_ptr to a channel interface

   **AddTLSServer(self: pydnp3.asiodnp3.DNP3Manager, id: str, levels:
   int, retry: pydnp3.asiopal.ChannelRetry, endpoint: str, port: int,
   config: pydnp3.asiopal.TLSConfig, listener:
   pydnp3.asiodnp3.IChannelListener, ec: std::error_code) ->
   `pydnp3.asiodnp3.IChannel <#pydnp3.asiodnp3.IChannel>`_**

         Add a TLS server channel.

      :throw std::system_error Throws underlying ASIO exception of TLS
      configuration is invalid  :param id: Alias that will be used for
      logging purposes with this channel  :param levels: Bitfield that
      describes the logging level for this channel and associated
      sessions  :param retry: Retry parameters for failed channels
      :param endpoint: Network adapter to listen on, i.e. 127.0.0.1 or
      0.0.0.0  :param port: Port to listen on  :param config: TLS
      configuration information  :param listener: optional callback
      interface (can be nullptr) for info about the running channel
      :param ec: An error code. If set, a nullptr will be returned
      :return: shared_ptr to a channel interface

   **CreateListener(*args, **kwargs)**

      Overloaded function.

      1. CreateListener(self: pydnp3.asiodnp3.DNP3Manager, loggerid:
         str, loglevel: pydnp3.openpal.LogFilters, endpoint:
         pydnp3.asiopal.IPEndpoint, callbacks:
         pydnp3.asiodnp3.IListenCallbacks, ec: std::error_code) ->
         pydnp3.asiopal.IListener

         Create a TCP listener that will be used to accept incoming
         connections.

      :Returns:
         shared_ptr to a listener interface

      1. CreateListener(self: pydnp3.asiodnp3.DNP3Manager, loggerid:
         str, loglevel: pydnp3.openpal.LogFilters, endpoint:
         pydnp3.asiopal.IPEndpoint, config: pydnp3.asiopal.TLSConfig,
         callbacks: pydnp3.asiodnp3.IListenCallbacks, ec:
         std::error_code) -> pydnp3.asiopal.IListener

         Create a TLS listener that will be used to accept incoming
         connections.

      :Returns:
         shared_ptr to a listener interface

   **Shutdown(self: pydnp3.asiodnp3.DNP3Manager) -> None**

      Permanently shutdown the manager and all sub-objects that have
      been created. Stop the thread pool.

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.asiodnp3.DNP3Manager, concurrencyHint:
         int) -> None

      2. __init__(self: pydnp3.asiodnp3.DNP3Manager, concurrencyHint:
         int, handler: pydnp3.openpal.ILogHandler) -> None

      3. __init__(self: pydnp3.asiodnp3.DNP3Manager, concurrencyHint:
         int, handler: pydnp3.openpal.ILogHandler, onThreadStart:
         Callable[[], None]) -> None

      4. __init__(self: pydnp3.asiodnp3.DNP3Manager, concurrencyHint:
         int, handler: pydnp3.openpal.ILogHandler, onThreadStart:
         Callable[[], None], onThreadExit: Callable[[], None]) -> None

         Construct a manager:

      :Parameters:
         *  **concurrencyHint** – How many threads to allocate in the
            thread pool

         *  **handler** – Callback interface for log messages

      :param onThreadStart Action to run when a thread pool thread
      starts  :param onThreadExit Action to run just before a thread
      pool thread exits

**class pydnp3.asiodnp3.DefaultListenCallbacks**

   Bases: `pydnp3.asiodnp3.IListenCallbacks
   <#pydnp3.asiodnp3.IListenCallbacks>`_

   Callback interface invoked when a new connection is accepted.

   **AcceptCertificate(self: pydnp3.asiodnp3.DefaultListenCallbacks,
   sessionid: int, info: pydnp3.asiodnp3.X509Info) -> bool**

         Ask user code if the following preverified certificate should
         be accepted.  If true, the certificate should be accepted,
         false otherwise.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **info** – Information from the x509 certificate

   **AcceptConnection(self: pydnp3.asiodnp3.DefaultListenCallbacks,
   sessionid: int, ipaddress: str) -> bool**

         Ask user code if the following connection should be accepted.
         If true, the connection is accepted and a link frame parser
         is created to handle incoming frame data.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **ipaddress** – The IP address of the connecting host. Can
            optionally be used for connection filtering

   **GetFirstFrameTimeout(self:
   pydnp3.asiodnp3.DefaultListenCallbacks) ->
   `pydnp3.openpal.TimeDuration
   <openpal.rst#pydnp3.openpal.TimeDuration>`_**

      :Returns:
         the amount of time the session should wait for the first
         frame

   **OnCertificateError(self: pydnp3.asiodnp3.DefaultListenCallbacks,
   sessionid: int, info: pydnp3.asiodnp3.X509Info, error: int) ->
   None**

         Called when a certificate fails verification.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **info** – Information from the x509 certificate

         *  **error** – Error code with reason for failed verification

   **OnConnectionClose(self: pydnp3.asiodnp3.DefaultListenCallbacks,
   sessionid: int, session: pydnp3.asiodnp3.IMasterSession) -> None**

         Called when a socket closes.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **session** – Possibly NULL shared_ptr to the master
            session if it was created

   **OnFirstFrame(self: pydnp3.asiodnp3.DefaultListenCallbacks,
   sessionid: int, header: pydnp3.opendnp3.LinkHeaderFields, acceptor:
   pydnp3.asiodnp3.ISessionAcceptor) -> None**

         Called when the first link-layer frame is received for a
         session.

   **__init__(self: pydnp3.asiodnp3.DefaultListenCallbacks) -> None**

**class pydnp3.asiodnp3.DefaultMasterApplication**

   Bases: `pydnp3.opendnp3.IMasterApplication
   <opendnp3.rst#pydnp3.opendnp3.IMasterApplication>`_

   **AssignClassDuringStartup(self:
   pydnp3.asiodnp3.DefaultMasterApplication) -> bool**

   **ConfigureAssignClassRequest(self:
   pydnp3.asiodnp3.DefaultMasterApplication, fun:
   Callable[[pydnp3.opendnp3.Header], None]) -> None**

      Configure the request headers for assign class.  Only called if
      AssignClassDuringStartup returns true.  The user only needs to
      call the function for each header type to be written.

   **Create() -> `pydnp3.opendnp3.IMasterApplication
   <opendnp3.rst#pydnp3.opendnp3.IMasterApplication>`_**

      :Returns:
         shared_ptr to opendnp3.IMasterApplication

   **Now(self: pydnp3.asiodnp3.DefaultMasterApplication) ->
   `pydnp3.openpal.UTCTimestamp
   <openpal.rst#pydnp3.openpal.UTCTimestamp>`_**

      :Returns:
         a UTCTimestamp of the current time

   **OnReceiveIIN(self: pydnp3.asiodnp3.DefaultMasterApplication, iin:
   pydnp3.opendnp3.IINField) -> None**

      Called when a response or unsolicited response is receive from
      the outstation.

   **OnStateChange(self: pydnp3.asiodnp3.DefaultMasterApplication,
   value: pydnp3.opendnp3.LinkStatus) -> None**

      Called when a the reset/unreset status of the link layer
      changes.

   **OnTaskComplete(self: pydnp3.asiodnp3.DefaultMasterApplication,
   info: pydnp3.opendnp3.TaskInfo) -> None**

      Task completion notification.

   **OnTaskStart(self: pydnp3.asiodnp3.DefaultMasterApplication, type:
   pydnp3.opendnp3.MasterTaskType, id: pydnp3.opendnp3.TaskId) ->
   None**

      Task start notification.

   **__init__(self: pydnp3.asiodnp3.DefaultMasterApplication) ->
   None**

**class pydnp3.asiodnp3.Error**

   Bases: ``pybind11_builtins.pybind11_object``

   Members:

   SHUTTING_DOWN

   NO_TLS_SUPPORT

   NO_SERIAL_SUPPORT

   **__init__(self: pydnp3.asiodnp3.Error, arg0: int) -> None**

**class pydnp3.asiodnp3.IChannel**

   Bases: `pydnp3.asiopal.IResource
   <asiopal.rst#pydnp3.asiopal.IResource>`_

   Represents a communication channel upon which masters and
   outstations can be bound.

   **AddMaster(self: pydnp3.asiodnp3.IChannel, id: str, SOEHandler:
   pydnp3.opendnp3.ISOEHandler, application:
   pydnp3.opendnp3.IMasterApplication, config:
   pydnp3.asiodnp3.MasterStackConfig) -> `pydnp3.asiodnp3.IMaster
   <#pydnp3.asiodnp3.IMaster>`_**

         Add a master to the channel.

      :Parameters:
         *  **id** – An ID that gets used for logging.

         *  **SOEHandler** – Callback object for all received
            measurements

         *  **application** – The master application bound to the
            master session

         *  **config** – Configuration object that controls how the
            master behaves

      :Returns:
         shared_ptr to the running master

   **AddOutstation(self: pydnp3.asiodnp3.IChannel, id: str,
   commandHandler: pydnp3.opendnp3.ICommandHandler, application:
   pydnp3.opendnp3.IOutstationApplication, config:
   pydnp3.asiodnp3.OutstationStackConfig) ->
   `pydnp3.asiodnp3.IOutstation <#pydnp3.asiodnp3.IOutstation>`_**

         Add an outstation to the channel.

      :Parameters:
         *  **id** – An ID that gets used for logging

         *  **commandHandler** – Callback object for handling command
            requests

         *  **application** – Callback object for user code

         *  **config** – Configuration object that controls how the
            outstation behaves

      :Returns:
         shared_ptr to the running outstation

   **GetLogFilters(self: pydnp3.asiodnp3.IChannel) ->
   `pydnp3.openpal.LogFilters
   <openpal.rst#pydnp3.openpal.LogFilters>`_**

      :Returns:
         the current logger settings for this channel

   **GetStatistics(self: pydnp3.asiodnp3.IChannel) ->
   `pydnp3.opendnp3.LinkStatistics
   <opendnp3.rst#pydnp3.opendnp3.LinkStatistics>`_**

      Synchronously read the channel statistics.

   **SetLogFilters(self: pydnp3.asiodnp3.IChannel, filters:
   pydnp3.openpal.LogFilters) -> None**

      :Parameters:
         **filters** – adjust the filters to this value

   **__init__(self: pydnp3.asiodnp3.IChannel) -> None**

**class pydnp3.asiodnp3.IChannelListener**

   Bases: ``pybind11_builtins.pybind11_object``

   Callback interface for receiving information about a running
   channel.

   **OnStateChange(self: pydnp3.asiodnp3.IChannelListener, state:
   pydnp3.opendnp3.ChannelState) -> None**

      Receive callbacks for state transitions on the channels
      executor.

   **__init__(self: pydnp3.asiodnp3.IChannelListener) -> None**

**class pydnp3.asiodnp3.IListenCallbacks**

   Bases: ``pybind11_builtins.pybind11_object``

   Callback interface invoked when a new connection is accepted.

   **AcceptCertificate(self: pydnp3.asiodnp3.IListenCallbacks,
   sessionid: int, info: pydnp3.asiodnp3.X509Info) -> bool**

         Ask user code if the following preverified certificate should
         be accepted.  If true, the certificate should be accepted,
         false otherwise.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **info** – Information from the x509 certificate

   **AcceptConnection(self: pydnp3.asiodnp3.IListenCallbacks,
   sessionid: int, ipaddress: str) -> bool**

         Ask user code if the following connection should be accepted.
         If true, the connection is accepted and a link frame parser
         is created to handle incoming frame data.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **ipaddress** – The IP address of the connecting host. Can
            optionally be used for connection filtering

   **GetFirstFrameTimeout(self: pydnp3.asiodnp3.IListenCallbacks) ->
   `pydnp3.openpal.TimeDuration
   <openpal.rst#pydnp3.openpal.TimeDuration>`_**

      :Returns:
         the amount of time the session should wait for the first
         frame.

   **OnCertificateError(self: pydnp3.asiodnp3.IListenCallbacks,
   sessionid: int, info: pydnp3.asiodnp3.X509Info, error: int) ->
   None**

         Called when a certificate fails verification.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **info** – Information from the x509 certificate

         *  **error** – Error code with reason for failed verification

   **OnConnectionClose(self: pydnp3.asiodnp3.IListenCallbacks,
   sessionid: int, session: pydnp3.asiodnp3.IMasterSession) -> None**

         Called when a socket closes.

      :Parameters:
         *  **sessionid** (*unsigned long*) – Incrementing id used to
            uniquely identify the session

         *  **session** – Possibly NULL shared_ptr to the master
            session if it was created

   **OnFirstFrame(self: pydnp3.asiodnp3.IListenCallbacks, sessionid:
   int, header: pydnp3.opendnp3.LinkHeaderFields, acceptor:
   pydnp3.asiodnp3.ISessionAcceptor) -> None**

         Called when the first link-layer frame is received for a
         session.

   **__init__(self: pydnp3.asiodnp3.IListenCallbacks) -> None**

**class pydnp3.asiodnp3.IMaster**

   Bases: `pydnp3.asiodnp3.IMasterOperations
   <#pydnp3.asiodnp3.IMasterOperations>`_, `pydnp3.asiodnp3.IStack
   <#pydnp3.asiodnp3.IStack>`_

   Interface that represents a running master session.

   **__init__(self: pydnp3.asiodnp3.IMaster) -> None**

**class pydnp3.asiodnp3.IMasterOperations**

   Bases: `pydnp3.opendnp3.ICommandProcessor
   <opendnp3.rst#pydnp3.opendnp3.ICommandProcessor>`_

   All the operations that the user can perform on a running master.

   **AddAllObjectsScan(self: pydnp3.asiodnp3.IMasterOperations, gvId:
   pydnp3.opendnp3.GroupVariationID, period:
   pydnp3.openpal.TimeDuration, config: pydnp3.opendnp3.TaskConfig =
   <pydnp3.opendnp3.TaskConfig object at 0x7f756d2230b0>) ->
   `pydnp3.asiodnp3.IMasterScan <#pydnp3.asiodnp3.IMasterScan>`_**

         Add a scan that requests all objects using qualifier code
         0x06.

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

      :Returns:
         shared_ptr to asiodnp3.IMasterScan - a proxy class used to
         manipulate the scan

   **AddClassScan(self: pydnp3.asiodnp3.IMasterOperations, field:
   pydnp3.opendnp3.ClassField, period: pydnp3.openpal.TimeDuration,
   config: pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig
   object at 0x7f756d223170>) -> `pydnp3.asiodnp3.IMasterScan
   <#pydnp3.asiodnp3.IMasterScan>`_**

         Add a class-based scan to the master.

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

      :Returns:
         shared_ptr to asiodnp3.IMasterScan - a proxy class used to
         manipulate the scan

   **AddRangeScan(self: pydnp3.asiodnp3.IMasterOperations, gvId:
   pydnp3.opendnp3.GroupVariationID, start: int, stop: int, period:
   pydnp3.openpal.TimeDuration, config: pydnp3.opendnp3.TaskConfig =
   <pydnp3.opendnp3.TaskConfig object at 0x7f756d223230>) ->
   `pydnp3.asiodnp3.IMasterScan <#pydnp3.asiodnp3.IMasterScan>`_**

         Add a start/stop (range) scan to the master.

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

      :Returns:
         shared_ptr to asiodnp3.IMasterScan - a proxy class used to
         manipulate the scan.

   **AddScan(self: pydnp3.asiodnp3.IMasterOperations, period:
   pydnp3.openpal.TimeDuration, headers: List[pydnp3.opendnp3.Header],
   config: pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig
   object at 0x7f756dc648f0>) -> `pydnp3.asiodnp3.IMasterScan
   <#pydnp3.asiodnp3.IMasterScan>`_**

         Add a recurring user-defined scan from a vector of headers.

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

      :Returns:
         shared_ptr to asiodnp3.IMasterScan - a proxy class used to
         manipulate the scan

   **PerformFunction(self: pydnp3.asiodnp3.IMasterOperations, name:
   str, func: pydnp3.opendnp3.FunctionCode, headers:
   List[pydnp3.opendnp3.Header], config: pydnp3.opendnp3.TaskConfig =
   <pydnp3.opendnp3.TaskConfig object at 0x7f756d2232b0>) -> None**

         Perform any operation that requires just a function code

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

   **Restart(self: pydnp3.asiodnp3.IMasterOperations, op:
   pydnp3.opendnp3.RestartType, callback:
   Callable[[pydnp3.opendnp3.RestartOperationResult], None], config:
   pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig object at
   0x7f756dc66730>) -> None**

         Perform a cold or warm restart and get back the
         time-to-complete value

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

   **Scan(self: pydnp3.asiodnp3.IMasterOperations, headers:
   List[pydnp3.opendnp3.Header], config: pydnp3.opendnp3.TaskConfig =
   <pydnp3.opendnp3.TaskConfig object at 0x7f756d2232f0>) -> None**

         Initiate a single user defined scan via a vector of headers.

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

   **ScanAllObjects(self: pydnp3.asiodnp3.IMasterOperations, gvId:
   pydnp3.opendnp3.GroupVariationID, config:
   pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig object at
   0x7f756d223330>) -> None**

         Initiate a single scan that requests all objects (0x06
         qualifier code) for a certain group and variation.

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

   **ScanClasses(self: pydnp3.asiodnp3.IMasterOperations, field:
   pydnp3.opendnp3.ClassField, config: pydnp3.opendnp3.TaskConfig =
   <pydnp3.opendnp3.TaskConfig object at 0x7f756d2233f0>) -> None**

         Initiate a single class-based scan.

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

   **ScanRange(self: pydnp3.asiodnp3.IMasterOperations, gvId:
   pydnp3.opendnp3.GroupVariationID, start: int, stop: int, config:
   pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig object at
   0x7f756d223470>) -> None**

         Initiate a single start/stop (range) scan

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

   **SetLogFilters(self: pydnp3.asiodnp3.IMasterOperations, filters:
   pydnp3.openpal.LogFilters) -> None**

      :Parameters:
         **filters** – Adjust the filters to this value

   **Write(self: pydnp3.asiodnp3.IMasterOperations, value:
   pydnp3.opendnp3.TimeAndInterval, index: int, config:
   pydnp3.opendnp3.TaskConfig = <pydnp3.opendnp3.TaskConfig object at
   0x7f756d223570>) -> None**

         Write a time and interval object to a specific index

      :Parameters:
         **config** – defaults to opendnp3.TaskConfig.Default()

   **__init__(self: pydnp3.asiodnp3.IMasterOperations) -> None**

**class pydnp3.asiodnp3.IMasterScan**

   Bases: ``pybind11_builtins.pybind11_object``

   Interface for interacting with a permanently bound scan.

   **Demand(self: pydnp3.asiodnp3.IMasterScan) -> None**

      Request that the scan be performed as soon as possible.

   **__init__(self: pydnp3.asiodnp3.IMasterScan) -> None**

**class pydnp3.asiodnp3.IMasterSession**

   Bases: `pydnp3.asiodnp3.IMasterOperations
   <#pydnp3.asiodnp3.IMasterOperations>`_

   Interface that represents an emphemeral master session.

   **BeginShutdown(self: pydnp3.asiodnp3.IMasterSession) -> None**

   **GetStackStatistics(self: pydnp3.asiodnp3.IMasterSession) ->
   `pydnp3.opendnp3.StackStatistics
   <opendnp3.rst#pydnp3.opendnp3.StackStatistics>`_**

   **__init__(self: pydnp3.asiodnp3.IMasterSession) -> None**

**class pydnp3.asiodnp3.IOutstation**

   Bases: `pydnp3.asiodnp3.IStack <#pydnp3.asiodnp3.IStack>`_

   Interface representing a running outstation.

   **Apply(self: pydnp3.asiodnp3.IOutstation, updates:
   pydnp3.asiodnp3.Updates) -> None**

      Apply a set of measurement updates to the outstation.

   **SetLogFilters(self: pydnp3.asiodnp3.IOutstation, filters:
   pydnp3.openpal.LogFilters) -> None**

      :Parameters:
         **filters** – Adjust the filters to this value

   **SetRestartIIN(self: pydnp3.asiodnp3.IOutstation) -> None**

      Sets the restart IIN bit.  Normally applications should not
      touch this bit, but it is provided for simulating restarts.

   **__init__(self: pydnp3.asiodnp3.IOutstation) -> None**

**class pydnp3.asiodnp3.ISessionAcceptor**

   Bases: ``pybind11_builtins.pybind11_object``

   Callback interface invoked when a new connection is accepted

   **AcceptSession(self: pydnp3.asiodnp3.ISessionAcceptor, sessionid:
   str, SOEHandler: pydnp3.opendnp3.ISOEHandler, application:
   pydnp3.opendnp3.IMasterApplication, config:
   pydnp3.asiodnp3.MasterStackConfig) ->
   `pydnp3.asiodnp3.IMasterSession
   <#pydnp3.asiodnp3.IMasterSession>`_**

      :Returns:
         shared_ptr to asiodnp3.IMasterSession

   **__init__(self: pydnp3.asiodnp3.ISessionAcceptor) -> None**

**class pydnp3.asiodnp3.IStack**

   Bases: `pydnp3.asiopal.IResource
   <asiopal.rst#pydnp3.asiopal.IResource>`_

   Base class for masters or outstations.

   **Disable(self: pydnp3.asiodnp3.IStack) -> bool**

      Synchronously disable communications.

   **Enable(self: pydnp3.asiodnp3.IStack) -> bool**

      Synchronously enable communications.

   **GetStackStatistics(self: pydnp3.asiodnp3.IStack) ->
   `pydnp3.opendnp3.StackStatistics
   <opendnp3.rst#pydnp3.opendnp3.StackStatistics>`_**

      :Returns:
         stack statistics counters.

   **__init__(self: pydnp3.asiodnp3.IStack) -> None**

**class pydnp3.asiodnp3.MasterStackConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   A composite configuration struct that contains all the config
   information for a dnp3 master stack.

   **__init__(self: pydnp3.asiodnp3.MasterStackConfig) -> None**

   ``property link``

      Link layer config.

   ``property master``

      Master config.

**class pydnp3.asiodnp3.MasterTCPServer**

   Bases: `pydnp3.asiopal.TCPServer
   <asiopal.rst#pydnp3.asiopal.TCPServer>`_

   Binds and listens on an IPv4 TCP port. Meant to be used exclusively
   as a shared_ptr.

   **Create(self: pydnp3.openpal.Logger, arg0:
   pydnp3.asiopal.Executor, arg1: pydnp3.asiopal.IPEndpoint, arg2:
   pydnp3.asiodnp3.IListenCallbacks, arg3:
   pydnp3.asiopal.ResourceManager, arg4: std::error_code) ->
   `pydnp3.asiodnp3.MasterTCPServer
   <#pydnp3.asiodnp3.MasterTCPServer>`_**

   **__init__(self: pydnp3.asiodnp3.MasterTCPServer, logger:
   pydnp3.openpal.Logger, executor: pydnp3.asiopal.Executor, endpoint:
   pydnp3.asiopal.IPEndpoint, callbacks:
   pydnp3.asiodnp3.IListenCallbacks, manager:
   pydnp3.asiopal.ResourceManager, ec: std::error_code) -> None**

**class pydnp3.asiodnp3.OutstationStackConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   A composite configuration struct that contains all the config
   information for a dnp3 outstation stack.

   **__init__(self: pydnp3.asiodnp3.OutstationStackConfig, dbSizes:
   pydnp3.opendnp3.DatabaseSizes) -> None**

   ``property dbConfig``

      Configuration of the database.

   ``property link``

      Link layer config.

   ``property outstation``

      Outstation config.

**class pydnp3.asiodnp3.PrintingChannelListener**

   Bases: `pydnp3.asiodnp3.IChannelListener
   <#pydnp3.asiodnp3.IChannelListener>`_

   Callback interface for receiving information about a running
   channel.

   **Create() -> `pydnp3.asiodnp3.IChannelListener
   <#pydnp3.asiodnp3.IChannelListener>`_**

      :Returns:
         shared_ptr to asiodnp3.IChannelListener

   **OnStateChange(self: pydnp3.asiodnp3.PrintingChannelListener,
   arg0: pydnp3.opendnp3.ChannelState) -> None**

   **__init__(self: pydnp3.asiodnp3.PrintingChannelListener) -> None**

**class pydnp3.asiodnp3.PrintingSOEHandler**

   Bases: `pydnp3.opendnp3.ISOEHandler
   <opendnp3.rst#pydnp3.opendnp3.ISOEHandler>`_

   ISOEHandler singleton that prints to the console.

   **Create() -> `pydnp3.opendnp3.ISOEHandler
   <opendnp3.rst#pydnp3.opendnp3.ISOEHandler>`_**

      :Returns:
         shared_ptr to opendnp3.ISOEHandler

   **Process(*args, **kwargs)**

      Overloaded function.

      1. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedBinary) -> None

      2. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedDoubleBitBinary) -> None

      3. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedAnalog) -> None

      4. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedCounter) -> None

      5. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedFrozenCounter) -> None

      6. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedBinaryOutputStatus) -> None

      7. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedAnalogOutputStatus) -> None

      8. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedOctetString) -> None

      9. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
         pydnp3.opendnp3.HeaderInfo, values:
         pydnp3.opendnp3.ICollectionIndexedTimeAndInterval) -> None

      10. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionIndexedBinaryCommandEvent) ->
          None

      11. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionIndexedAnalogCommandEvent) ->
          None

      12. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionIndexedSecurityStat) -> None

      13. Process(self: pydnp3.asiodnp3.PrintingSOEHandler, info:
          pydnp3.opendnp3.HeaderInfo, values:
          pydnp3.opendnp3.ICollectionDNPTime) -> None

   **__init__(self: pydnp3.asiodnp3.PrintingSOEHandler) -> None**

**class pydnp3.asiodnp3.X509Info**

   Bases: ``pybind11_builtins.pybind11_object``

   Select information from a preverified x509 certificate that user
   can can inspect an optionally reject.

   **__init__(self: pydnp3.asiodnp3.X509Info, depth: int,
   sha1thumbprint: pydnp3.openpal.RSlice, subjectName: str) -> None**

   ``property depth``

      The depth of the certificate in the chain.

   ``property sha1thumbprint``

      The sha1 thumbprint.

   ``property subjectName``

      The extracted subject name.

**pydnp3.asiodnp3.make_error_code(err: pydnp3.asiodnp3.Error) ->
std::error_code**
