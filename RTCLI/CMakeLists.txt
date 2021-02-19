cmake_minimum_required (VERSION 3.3)

include_directories(.)

file(GLOB_RECURSE 
    source_list 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hxx
    ${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/*.inl
)
file(GLOB_RECURSE 
    impl_source_list 
    ${CMAKE_SOURCE_DIR}/${RTCLI_IMPL_DIR}/*.cpp
    ${CMAKE_SOURCE_DIR}/${RTCLI_IMPL_DIR}/*.hpp
    ${CMAKE_SOURCE_DIR}/${RTCLI_IMPL_DIR}/*.inl
)

# Add Files.
set(SRC_FILES 
    ${source_list}
)
set(IMPL_SRC_FILES 
    ${impl_source_list}
)

if(LIB)
    add_library(RTCLI STATIC ${SRC_FILES} ${IMPL_SRC_FILES})
else()
    add_library(RTCLI SHARED ${SRC_FILES} ${IMPL_SRC_FILES})
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
source_group(IMPLEMENTATION FILES ${IMPL_SRC_FILES})