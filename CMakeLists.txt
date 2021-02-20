cmake_minimum_required (VERSION 3.3)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(RTCLI_IMPL_NAME "RTCLIDefault")

project(${RTCLI_IMPL_NAME} VERSION 0.0.1)

# Build Options.
option(LIB "Build RTCLI as Static Library." ON)

# Detect Platforms.
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(PLATFORM_64BIT 1)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(PLATFORM_32BIT 1)
else()
    message(FATAL_ERROR "Unknown Architecture is specified.")
endif()

# Define Global Constants.
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BUILD_DIR ${CMAKE_BINARY_DIR})

if(PLATFORM_64BIT)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug64)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR}/RelWithDebugInfo64)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release64)
elseif(PLATFORM_32BIT)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Debug)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_BINARY_DIR}/RelWithDebugInfo)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Release)
else()
    message(FATAL_ERROR "Unknown Architecture is specified.")
endif()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;RelWithDebInfo" CACHE STRING "" FORCE)

# Define Macros.
if(LIB)
    add_definitions("-DRTCLI_BUILD_LIB")
    message(STATUS "Build as lib.")
endif()

if(NOT "cxx_std_11" IN_LIST CMAKE_CXX_COMPILE_FEATURES)
    message(FATAL_ERROR "C++11 Support is required to compile RTCLI")
endif()

include_directories(.)

add_subdirectory(RTCLI)
add_subdirectory(Test)

install(TARGETS ${RTCLI_IMPL_NAME}
    EXPORT ${RTCLI_IMPL_NAME}Targets 
    LIBRARY DESTINATION lib  # 动态库安装路径
    ARCHIVE DESTINATION lib  # 静态库安装路径
    RUNTIME DESTINATION bin  # 可执行文件安装路径
    PUBLIC_HEADER DESTINATION include  # 头文件安装路径
)

# 写入库的版本信息
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${RTCLI_IMPL_NAME}ConfigVersion.cmake
    VERSION ${PACKAGE_VERSION}
    COMPATIBILITY AnyNewerVersion  # 表示该函数库向下兼容
)
install(EXPORT ${RTCLI_IMPL_NAME}Targets
    FILE ${RTCLI_IMPL_NAME}Targets.cmake
    NAMESPACE RTCLI::
    DESTINATION lib/cmake/${RTCLI_IMPL_NAME}
)

configure_file(${RTCLI_IMPL_NAME}/${RTCLI_IMPL_NAME}Config.cmake.in ${RTCLI_IMPL_NAME}Config.cmake @ONLY)
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/${RTCLI_IMPL_NAME}Config.cmake"
          "${CMAKE_CURRENT_BINARY_DIR}/${RTCLI_IMPL_NAME}ConfigVersion.cmake"
    DESTINATION lib/cmake/${RTCLI_IMPL_NAME}
)

