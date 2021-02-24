cmake_minimum_required (VERSION 3.3)

include_directories(.)

file(GLOB_RECURSE 
    header_list 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hxx
)
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
    ${CMAKE_SOURCE_DIR}/${RTCLI_IMPL_NAME}/*.cpp
    ${CMAKE_SOURCE_DIR}/${RTCLI_IMPL_NAME}/*.hpp
    ${CMAKE_SOURCE_DIR}/${RTCLI_IMPL_NAME}/*.inl
)

# Add Files.
set(SRC_FILES 
    ${source_list}
)
set(HEADER_FILES 
    ${header_list}
)
set(IMPL_SRC_FILES 
    ${impl_source_list}
)

if(LIB)
    add_library(${RTCLI_IMPL_NAME} STATIC ${SRC_FILES} ${IMPL_SRC_FILES})
else()
    add_library(${RTCLI_IMPL_NAME} SHARED ${SRC_FILES} ${IMPL_SRC_FILES})
endif()

target_include_directories(${RTCLI_IMPL_NAME}  
    PUBLIC 
    $<INSTALL_INTERFACE:include>
    PRIVATE ${HEADER_FILES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
source_group(IMPLEMENTATION FILES ${IMPL_SRC_FILES})

INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/RTCLI/
    DESTINATION include/RTCLI
    FILES_MATCHING PATTERN "*.h*"
)
INSTALL (
    DIRECTORY ${CMAKE_SOURCE_DIR}/RTCLI/
    DESTINATION include/RTCLI
    FILES_MATCHING PATTERN "*.inl"
)

set(CLANG_DISABLED_WARNINGS "-Wno-unknown-attributes")
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(${RTCLI_IMPL_NAME} 
        PRIVATE
        ${CLANG_DISABLED_WARNINGS}
    )
endif()