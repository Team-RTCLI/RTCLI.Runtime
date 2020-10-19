cmake_minimum_required (VERSION 3.3)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

set(RTCLI_IMPL_DIR "RTCLIStub")

project(RTCLI)

include_directories(.)

add_subdirectory(RTCLI)
add_subdirectory(Test)