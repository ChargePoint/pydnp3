
pydnp3.asiopal
**************

Bindings for asiopal namespace

**class pydnp3.asiopal.ChannelRetry**

   Bases: ``pybind11_builtins.pybind11_object``

   Class used to configure how channel failures are retried

   **Default() -> `pydnp3.asiopal.ChannelRetry
   <#pydnp3.asiopal.ChannelRetry>`_**

      Return the default configuration of exponential backoff from 1
      sec to 1 minute.

   **NextDelay(self: pydnp3.asiopal.ChannelRetry, arg0:
   pydnp3.openpal.TimeDuration) -> `pydnp3.openpal.TimeDuration
   <openpal.rst#pydnp3.openpal.TimeDuration>`_**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.asiopal.ChannelRetry, minOpenRetry:
         pydnp3.openpal.TimeDuration, maxOpenRetry:
         pydnp3.openpal.TimeDuration) -> None

         Construct a channel retry config class.

      :Parameters:
         *  **minOpenRetry** – minimum connection retry interval on
            failure

         *  **maxOpenRetry** – maximum connection retry interval on
            failure

         *  **strategy** – strategy to use

      1. __init__(self: pydnp3.asiopal.ChannelRetry, minOpenRetry:
         pydnp3.openpal.TimeDuration, maxOpenRetry:
         pydnp3.openpal.TimeDuration, strategy:
         pydnp3.asiopal.IOpenDelayStrategy) -> None

         Construct a channel retry config class.

      :Parameters:
         *  **minOpenRetry** – minimum connection retry interval on
            failure

         *  **maxOpenRetry** – maximum connection retry interval on
            failure

         *  **strategy** – strategy to use

      1. __init__(self: pydnp3.asiopal.ChannelRetry) -> None

      Default configuration of exponential backoff from 1 sec to 1
      minute.

   ``property maxOpenRetry``

      Maximum connection retry interval on failure.

   ``property minOpenRetry``

      Minimum connection retry interval on failure.

**pydnp3.asiopal.Configure(settings: pydnp3.asiopal.SerialSettings,
port: asio::basic_serial_port<asio::serial_port_service>, ec:
std::error_code) -> bool**

   Serial port configuration functions free to keep the classes
   simple.

**class pydnp3.asiopal.Executor**

   Bases: `pydnp3.openpal.IExecutor
   <openpal.rst#pydnp3.openpal.IExecutor>`_

   Implementation of openpal::IExecutor backed by asio::strand.
   Shutdown life-cycle guarantees are provided by using
   std::shared_ptr.

   **BlockUntil(self: pydnp3.asiopal.Executor, action: Callable[[],
   None]) -> None**

   **BlockUntilAndFlush(self: pydnp3.asiopal.Executor, action:
   Callable[[], None]) -> None**

   **Create(io: pydnp3.asiopal.IO) -> `pydnp3.asiopal.Executor
   <#pydnp3.asiopal.Executor>`_**

      :Returns:
         shared_ptr to openpal.Executor

   **Fork(self: pydnp3.asiopal.Executor) -> `pydnp3.asiopal.Executor
   <#pydnp3.asiopal.Executor>`_**

      Create a new Executor that shares the underling
      std::shared_ptr<IO>.

   **GetTime(self: pydnp3.asiopal.Executor) ->
   `pydnp3.openpal.MonotonicTimestamp
   <openpal.rst#pydnp3.openpal.MonotonicTimestamp>`_**

   **Post(self: pydnp3.asiopal.Executor, runnable: Callable[[], None])
   -> None**

   **ReturnFrom(*args, **kwargs)**

      Overloaded function.

      1. ReturnFrom(self: pydnp3.asiopal.Executor, action:
         Callable[[], bool]) -> bool

      2. ReturnFrom(self: pydnp3.asiopal.Executor, action:
         Callable[[], pydnp3.opendnp3.StackStatistics]) ->
         pydnp3.opendnp3.StackStatistics

      3. ReturnFrom(self: pydnp3.asiopal.Executor, action:
         Callable[[], pydnp3.opendnp3.LinkStatistics]) ->
         pydnp3.opendnp3.LinkStatistics

      4. ReturnFrom(self: pydnp3.asiopal.Executor, action:
         Callable[[], pydnp3.openpal.LogFilters]) ->
         pydnp3.openpal.LogFilters

   **Start(*args, **kwargs)**

      Overloaded function.

      1. Start(self: pydnp3.asiopal.Executor, duration:
         pydnp3.openpal.TimeDuration, runnable: Callable[[], None]) ->
         pydnp3.openpal.ITimer

      2. Start(self: pydnp3.asiopal.Executor, duration:
         pydnp3.openpal.MonotonicTimestamp, runnable: Callable[[],
         None]) -> pydnp3.openpal.ITimer

   **__init__(self: pydnp3.asiopal.Executor, io: pydnp3.asiopal.IO) ->
   None**

**class pydnp3.asiopal.ExponentialBackoffStrategy**

   Bases: `pydnp3.asiopal.IOpenDelayStrategy
   <#pydnp3.asiopal.IOpenDelayStrategy>`_

   Implements IOpenDelayStrategy using exponential-backoff.

   **GetNextDelay(self: pydnp3.asiopal.ExponentialBackoffStrategy,
   current: pydnp3.openpal.TimeDuration, max:
   pydnp3.openpal.TimeDuration) -> `pydnp3.openpal.TimeDuration
   <openpal.rst#pydnp3.openpal.TimeDuration>`_**

   **Instance() -> `pydnp3.asiopal.IOpenDelayStrategy
   <#pydnp3.asiopal.IOpenDelayStrategy>`_**

   **__init__(*args, **kwargs)**

**class pydnp3.asiopal.IListener**

   Bases: `pydnp3.asiopal.IResource <#pydnp3.asiopal.IResource>`_

   Represents a running TCP or TLS listener that can be shutdown so
   that no new connections are accepted.

   **__init__(self: pydnp3.asiopal.IListener) -> None**

**class pydnp3.asiopal.IO**

   Bases: ``pybind11_builtins.pybind11_object``

   Container class for an asio::io_service.

   **__init__(self: pydnp3.asiopal.IO) -> None**

**class pydnp3.asiopal.IOpenDelayStrategy**

   Bases: ``pybind11_builtins.pybind11_object``

   A strategy interface for controlling how connection are retried

   **GetNextDelay(self: pydnp3.asiopal.IOpenDelayStrategy, current:
   pydnp3.openpal.TimeDuration, max: pydnp3.openpal.TimeDuration) ->
   `pydnp3.openpal.TimeDuration
   <openpal.rst#pydnp3.openpal.TimeDuration>`_**

   **__init__(self: pydnp3.asiopal.IOpenDelayStrategy) -> None**

**class pydnp3.asiopal.IResource**

   Bases: ``pybind11_builtins.pybind11_object``

   Anything that can be shutdown.

   **Shutdown(self: pydnp3.asiopal.IResource) -> None**

   **__init__(self: pydnp3.asiopal.IResource) -> None**

**class pydnp3.asiopal.SerialSettings**

   Bases: ``pybind11_builtins.pybind11_object``

   Settings structure for the serial port.

   **__init__(self: pydnp3.asiopal.SerialSettings) -> None**

      Defaults to the familiar 9600 8/N/1, no flow control.

   ``property asyncOpenDelay``

      Some physical layers need time to settle so that the first tx
      isn’t lost.

   ``property baud``

      Baud rate of the port, i.e. 9600 or 57600.

   ``property dataBits``

      Data bits, usually 8.

   ``property deviceName``

      name of the port, i.e. COM1 or /dev/tty0.

   ``property flowType``

      Flow control setting, usually FLOW_NONE.

   ``property parity``

      Parity setting for the port, usually PAR_NONE.

   ``property stopBits``

      Stop bits, usually set to 1.

**class pydnp3.asiopal.SocketHelpers**

   Bases: ``pybind11_builtins.pybind11_object``

   Bind a socket object to a local endpoint given an address. If the
   address is empty, 0.0.0.0 is used.

   **BindToLocalAddress(arg0: str, arg1:
   asio::ip::basic_endpoint<asio::ip::tcp>, arg2:
   asio::basic_stream_socket<asio::ip::tcp,
   asio::stream_socket_service<asio::ip::tcp> >, arg3:
   std::error_code) -> None**

   **__init__(*args, **kwargs)**

**class pydnp3.asiopal.TCPServer**

   Bases: `pydnp3.asiopal.IListener <#pydnp3.asiopal.IListener>`_

   Binds and listens on an IPv4 TCP port.  Meant to be used
   exclusively as a shared_ptr.

   **Shutdown(self: pydnp3.asiopal.TCPServer) -> None**

      Implement IListener.

   **__init__(self: pydnp3.asiopal.TCPServer, logger:
   pydnp3.openpal.Logger, executor: pydnp3.asiopal.Executor, endpoint:
   pydnp3.asiopal.IPEndpoint, ec: std::error_code) -> None**

**class pydnp3.asiopal.TLSConfig**

   Bases: ``pybind11_builtins.pybind11_object``

   TLS configuration information.

   **__init__(self: pydnp3.asiopal.TLSConfig, peerCertFilePath: str,
   localCertFilePath: str, privateKeyFilePath: str, maxVerifyDepth:
   int = 0, allowTLSv10: bool = False, allowTLSv11: bool = False,
   allowTLSv12: bool = False, cipherList: str = '') -> None**

         Construct a TLS configuration.

      :Parameters:
         *  **peerCertFilePath** – Certificate file used to verify the
            peer or server. Can be CA file or a self-signed cert
            provided by other party.

         *  **localCertFilePath** – File that contains the certificate
            (or certificate chain) that will be presented to the
            remote side of the connection

         *  **privateKeyFilePath** – File that contains the private
            key corresponding to the local certificate

         *  **maxVerifyDepth** – The maximum certificate chain
            verification depth (0 == self-signed only)

         *  **allowTLSv10** – Allow TLS version 1.0 (default false)

         *  **allowTLSv11** – Allow TLS version 1.1 (default false)

         *  **allowTLSv12** – Allow TLS version 1.2 (default true)

         *  **cipherList** – The openssl cipher-list, defaults to
            empty string which does not modify the default cipher list

      localCertFilePath and privateKeyFilePath can optionally be the
      same file, i.e. a PEM that contains both pieces of data.

   ``property allowTLSv10``

      Allow TLS version 1.0 (default false).

   ``property allowTLSv11``

      Allow TLS version 1.1 (default false).

   ``property allowTLSv12``

      Allow TLS version 1.2 (default true).

   ``property cipherList``

      Openssl format cipher list

   ``property localCertFilePath``

      File that contains the certificate (or certificate chain) that
      will be presented to the remote side of the connection.

   ``property maxVerifyDepth``

      Max verification depth (defaults to 0 - peer certificate only).

   ``property peerCertFilePath``

      Certificate file used to verify the peer or server. Can be CA
      file or a self-signed cert provided by other party.

   ``property privateKeyFilePath``

      File that contains the private key corresponding to the local
      certificate.

**class pydnp3.asiopal.ThreadPool**

   Bases: ``pybind11_builtins.pybind11_object``

   A thread pool that calls asio::io_service::run.

   **CreateExecutor(self: pydnp3.asiopal.ThreadPool) ->
   `pydnp3.asiopal.Executor <#pydnp3.asiopal.Executor>`_**

   **Shutdown(self: pydnp3.asiopal.ThreadPool) -> None**

   **__init__(*args, **kwargs)**

      Overloaded function.

      1. __init__(self: pydnp3.asiopal.ThreadPool, logger:
         pydnp3.openpal.Logger, io: pydnp3.asiopal.IO, concurrency:
         int) -> None

      2. __init__(self: pydnp3.asiopal.ThreadPool, logger:
         pydnp3.openpal.Logger, io: pydnp3.asiopal.IO, concurrency:
         int, onThreadStart: Callable[[], None]) -> None

      3. __init__(self: pydnp3.asiopal.ThreadPool, logger:
         pydnp3.openpal.Logger, io: pydnp3.asiopal.IO, concurrency:
         int, onThreadStart: Callable[[], None], onThreadExit:
         Callable[[], None]) -> None

**class pydnp3.asiopal.Timer**

   Bases: ``pybind11_builtins.pybind11_object``

   Implementation of openpal::ITimer backed by
   asio::basic_waitable_timer<steady_clock>.

   **Cancel(self: pydnp3.asiopal.Timer) -> None**

   **ExpireAt(self: pydnp3.asiopal.Timer) ->
   `pydnp3.openpal.MonotonicTimestamp
   <openpal.rst#pydnp3.openpal.MonotonicTimestamp>`_**

   **__init__(self: pydnp3.asiopal.Timer, service: asio::io_service)
   -> None**

**class pydnp3.asiopal.UTCTimeSource**

   Bases: `pydnp3.openpal.IUTCTimeSource
   <openpal.rst#pydnp3.openpal.IUTCTimeSource>`_

   Interface that defines a method to get UTC timestamps

   **Instance() -> `pydnp3.openpal.IUTCTimeSource
   <openpal.rst#pydnp3.openpal.IUTCTimeSource>`_**

   **Now(self: pydnp3.asiopal.UTCTimeSource) ->
   `pydnp3.openpal.UTCTimestamp
   <openpal.rst#pydnp3.openpal.UTCTimestamp>`_**

   **__init__(*args, **kwargs)**

**class pydnp3.asiopal.steady_clock_t**

   Bases: ``pybind11_builtins.pybind11_object``

   Custom steady clock implementation to handle the situation where
   the Windows steady clock implementation is not monotonic.  Normal
   steady clock implementation is used on other platforms.

   **__init__(self: pydnp3.asiopal.steady_clock_t) -> None**

   **now() -> datetime.timedelta**
