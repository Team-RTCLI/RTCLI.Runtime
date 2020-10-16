cmake_minimum_required (VERSION 3.3)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)

project(RTCLI)

include_directories(
    .
    ./RTCLI
)

add_subdirectory(RTCLI)
add_subdirectory(Test)