cmake_minimum_required (VERSION 2.8)

project (pydnp3)
set(PYDNP3_MAJOR_VERSION 0)
set(PYDNP3_MINOR_VERSION 1)
set(PYDNP3_MICRO_VERSION 1)
set(PYDNP3_VERSION ${PYDNP3_MAJOR_VERSION}.${PYDNP3_MINOR_VERSION}.${PYDNP3_MICRO_VERSION})

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release
RelWithDebInfo MinSizeRel."
      FORCE)
endif()

message("CMake build is: ${CMAKE_BUILD_TYPE}")


#include(${PROJECT_SOURCE_DIR}/settings.cmake)


# other options off-by-default that you can enable
option(WERROR "Set all warnings to errors" OFF)
option(STATICLIBS "Builds static versions of all installed libraries" OFF)
option(COVERAGE "Builds the libraries with coverage info for gcov (gcc only)" OFF)
option(PROFILE "Builds the libraries with profiling support (gcc only)" OFF)

set(CMAKE_REQUIRED_FLAGS ${CMAKE_CXX_FLAGS})

set(STATICLIBS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility=hidden")

add_subdirectory(deps/pybind11)
add_subdirectory(deps/dnp3)

# include paths for all the local libraries
include_directories(deps/dnp3/cpp/libs/include)
include_directories(deps/dnp3/cpp/libs/src)

# asio
include_directories(deps/dnp3/deps/asio/asio/include)
add_definitions(-DASIO_STANDALONE)

pybind11_add_module(pydnp3 MODULE src/pydnp3.cpp src/pydnp3asiodnp3.cpp src/pydnp3asiopal.cpp src/pydnp3opendnp3.cpp src/pydnp3openpal.cpp)
target_link_libraries(pydnp3 PRIVATE asiopal asiodnp3 openpal opendnp3)



