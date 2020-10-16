//! In this file, you can define all compile settings that is used by the RTCLI.
//! RTCLI does not rely on a specific build system, all code-specific build settings goes here. You can however 
//! use the build system you prefer to define macros that affects the configurations listed here.
//! 
//! This is the ONLY source file in RTCLI library that you are expected to edit. If you edit other files, your 
//! change may be overwritten by a new version of RTCLI.
#pragma once


//------------------------ Begin of User Configuration Section ------------------------

// If you need to configure CPU architecture manually, define this macro.
// If this is not enabled, RTCLI detects the underlying CPU manually.
//#define RTCLI_MANUAL_CONFIG_CPU_ARCHITECTURE

// If you define RTCLI_MANUAL_CONFIG_CPU_ARCHITECTURE, you should manually choose one of the following CPU
// aichitecture:
//#define RTCLI_PLATFORM_X86_64
//#define RTCLI_PLATFORM_X86
//#define RTCLI_PLATFORM_ARM64
//#define RTCLI_PLATFORM_ARM32
//#define RTCLI_PLATFORM_POWERPC64
//#define RTCLI_PLATFORM_POWERPC32

// If you need to configure CPU traits manually, define this macro.
// If this is not enabled, RTCLI defines CPU traits manually by the CPU architecture selected above.
//#define RTCLI_MANUAL_CONFIG_CPU_TRAITS

// If you define RTCLI_MANUAL_CONFIG_CPU_TRAITS, you should manually choose the CPU traits you want below:
// Select one of:
//#define RTCLI_PLATFORM_32BIT
//#define RTCLI_PLATFORM_64BIT
// Select one of:
//#define RTCLI_PLATFORM_LITTLE_ENDIAN
//#define RTCLI_PLATFORM_BIG_ENDIAN
// Select any number of:
//#define RTCLI_PLATFORM_SSE
//#define RTCLI_PLATFORM_SSE2
//#define RTCLI_PLATFORM_AVX
//#define RTCLI_PLATFORM_AVX2

// If you need to configure C++ Compiler/Toolchain manually, define this macro.
// If this is not enabled, RTCLI detects the underlying C++ Compiler/Toolchain manually.
//#define RTCLI_MANUAL_CONFIG_COMPILER

// If you define RTCLI_MANUAL_CONFIG_COMPILER, you should manually choose the Compiler/Toolchain you want below:
//#define RTCLI_COMPILER_MSVC
//#define RTCLI_COMPILER_GCC
//#define RTCLI_COMPILER_CLANG

// If you need to configure C++ Compiler/Toolchain traits manually, define this macro.
// If this is not enabled, RTCLI configures the C++ Compiler/Toolchain traits automatically.
//#define RTCLI_MANUAL_CONFIG_COMPILER_TRAITS

// If you define RTCLI_MANUAL_CONFIG_COMPILER_TRAITS, you should manually define the following macros:
//#define RTCLI_COMPILER_VERSION /*YOUR_COMPILER_VERSION*/

// If you need to configure C++ Standard manually, define this macro.
//#define RTCLI_MANUAL_CONFIG_CPP_STANDARD

// If you define RTCLI_MANUAL_CONFIG_CPP_STANDARD, you should any of the following macros:
// Note that C++11 is required in order to compile RTCLI, so it is not listed here.
//#define RTCLI_COMPILER_CPP14
//#define RTCLI_COMPILER_CPP17
//#define RTCLI_COMPILER_CPP20

// If you want to build RTCLI as static library, defines this macro.
//#define RTCLI_BUILD_LIB

// If you want to disable the hot-reloading feature of RTCLI, define this macro.
// The hot-reloading feature is useful for application development, but should be disabled in releasing.
//#define RTCLI_DISABLE_HOT_RELOADING

// If you want to use your host's custom basic types for RTCLI, defines these types here.
// If not defined, RTCLI uses these types from stdint.
//#define RTCLI_CUSTOM_BASE_TYPES

// If you define RTCLI_CUSTOM_BASE_TYPES, fill the definition of base types here.
/*namespace RTCLI
{

    using u8 = USER_SPECIFIC_TYPE;
    using i8 = USER_SPECIFIC_TYPE;
    using u16 = USER_SPECIFIC_TYPE;
    using i16 = USER_SPECIFIC_TYPE;
    using u32 = USER_SPECIFIC_TYPE;
    using i32 = USER_SPECIFIC_TYPE;
    using u64 = USER_SPECIFIC_TYPE;
    using i64 = USER_SPECIFIC_TYPE;
    using f32 = USER_SPECIFIC_TYPE;
    using f64 = USER_SPECIFIC_TYPE;
    using usize = USER_SPECIFIC_TYPE;
    using isize = USER_SPECIFIC_TYPE;
    using c8 = USER_SPECIFIC_TYPE;
    using c16 = USER_SPECIFIC_TYPE;
    using c32 = USER_SPECIFIC_TYPE;
}*/

//------------------------- End of User Configuration Section -------------------------

#ifndef RTCLI_MANUAL_CONFIG_CPU_ARCHITECTURE
    #if defined(__x86_64__) || defined(_M_X64) || defined(_AMD64_) || defined(_M_AMD64)
        #define RTCLI_PLATFORM_X86_64
    #elif defined(__i386) || defined(_M_IX86) || defined(_X86_)
        #define RTCLI_PLATFORM_X86
    #elif defined(__aarch64__) || defined(__AARCH64) || defined(_M_ARM64)
        #define RTCLI_PLATFORM_ARM64
    #elif defined(__arm__) || defined(_M_ARM)
        #define RTCLI_PLATFORM_ARM32
    #elif defined(__POWERPC64__) || defined(__powerpc64__)
        #define RTCLI_PLATFORM_POWERPC64
    #elif defined(__POWERPC__) || defined(__powerpc__)
        #define RTCLI_PLATFORM_POWERPC32
    #else
        #error Unrecognized CPU was used.
    #endif
#endif

#ifndef RTCLI_MANUAL_CONFIG_CPU_TRAITS
    #if defined(__AVX__)
        #define RTCLI_PLATFORM_AVX
    #endif
    #if defined(__AVX2__)
        #define RTCLI_PLATFORM_AVX2
    #endif

    #if defined(RTCLI_PLATFORM_X86)
        #define RTCLI_PLATFORM_32BIT
        #define RTCLI_PLATFORM_LITTLE_ENDIAN
        #define RTCLI_PLATFORM_SSE
        #define RTCLI_PLATFORM_SSE2
    #endif

    #if defined(RTCLI_PLATFORM_X86_64)
        #define RTCLI_PLATFORM_64BIT
        #define RTCLI_PLATFORM_LITTLE_ENDIAN
        #define RTCLI_PLATFORM_SSE
        #define RTCLI_PLATFORM_SSE2
    #endif

    #if defined(RTCLI_PLATFORM_ARM32)
        #define RTCLI_PLATFORM_32BIT
        #define RTCLI_PLATFORM_LITTLE_ENDIAN
    #endif

    #if defined(RTCLI_PLATFORM_ARM64)
        #define RTCLI_PLATFORM_64BIT
        #define RTCLI_PLATFORM_LITTLE_ENDIAN
        #define RTCLI_PLATFORM_SSE
        #define RTCLI_PLATFORM_SSE2
    #endif

    #if defined(RTCLI_PLATFORM_POWERPC32)
        #define RTCLI_PLATFORM_32BIT
        #define RTCLI_PLATFORM_BIG_ENDIAN
    #endif

    #if defined(RTCLI_PLATFORM_POWERPC64)
        #define RTCLI_PLATFORM_64BIT
        #define RTCLI_PLATFORM_BIG_ENDIAN
    #endif
#endif

#ifndef RTCLI_MANUAL_CONFIG_COMPILER
    #if defined(__clang__)
        #define RTCLI_COMPILER_CLANG
    #elif defined(__GNUC__)
        #define RTCLI_COMPILER_GCC
    #elif defined(_MSC_VER)
        #define RTCLI_COMPILER_MSVC
    #else
        #error Unrecognized compiler was used.
    #endif
#endif

#ifndef RTCLI_MANUAL_CONFIG_COMPILER_TRAITS
    #if defined(RTCLI_COMPILER_MSVC)
        #define RTCLI_COMPILER_VERSION _MSC_VER
    #elif defined(RTCLI_COMPILER_CLANG)
        #define RTCLI_COMPILER_VERSION (__clang_major__ * 100 + __clang_minor__)
    #elif defined(RTCLI_COMPILER_GCC)
        #define RTCLI_COMPILER_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
    #endif
#endif

#ifndef RTCLI_MANUAL_CONFIG_CPP_STANDARD
    #if (defined(RTCLI_COMPILER_CLANG) || defined(RTCLI_COMPILER_GCC))
		#if __cplusplus >= 201703L
			#define RTCLI_COMPILER_CPP17
		#endif
		#if __cplusplus >= 201402L
			#define  RTCLI_COMPILER_CPP14
		#endif
    #elif defined(RTCLI_COMPILER_MSVC)
        #if (RTCLI_COMPILER_VERSION >= 1920)    // VS 2019
            #define RTCLI_COMPILER_CPP17
        #endif
		#if (RTCLI_COMPILER_VERSION >= 1910)    // VS 2017
			#define RTCLI_COMPILER_CPP14
		#endif
    #else
        #error "Failed to delect C++ standard version."
    #endif
#endif // RTCLI_MANUAL_CONFIG_CPP_STANDARD_VERSION

// Compiler Defines
#if defined(RTCLI_COMPILER_MSVC)
    #define RTCLI_DLL_EXPORT __declspec(dllexport)
#else
    #define RTCLI_DLL_EXPORT __attribute__ ((visibility("default")))
#endif

#if defined(RTCLI_COMPILER_MSVC)
    #define RTCLI_FORCEINLINE forceinline
#else
    #define RTCLI_FORCEINLINE inline
#endif
#define RTCLI_INLINE inline
// By Default we use cpp-standard above 2011XXL
#define RTCLI_NOEXCEPT noexcept

#ifdef RTCLI_COMPILER_MSVC
#define RTCLI_FUNCTION __FUNCTION__
#endif

// define RTCLI_BUILD_LIB in module's project config or API's source file, not in public domain.
#if defined(RTCLI_BUILD_LIB)
	#define RTCLI_EXPORT 
#else
	#define RTCLI_EXPORT RTCLI_DLL_EXPORT
#endif

#ifndef RTCLI_CUSTOM_BASE_TYPES
#include <cstdint>
#include <cstddef>
namespace RTCLI
{
    using u8 = std::uint8_t;
    using i8 = std::int8_t;
    using u16 = std::uint64_t;
    using i16 = std::int16_t;
    using u32 = std::uint32_t;
    using i32 = std::int32_t;
    using u64 = std::uint64_t;
    using i64 = std::int64_t;
    using f32 = float;
    using f64 = double;
    using usize = std::size_t;
    using isize = std::ptrdiff_t;
#ifdef RTCLI_COMPILER_CPP20
    using c8 = char8_t;
#else
	using c8 = char;
	static_assert(sizeof(c8) == 1, "Incorrect c8 type size.");
#endif
    using c16 = char16_t;
    using c32 = char32_t;
}
#endif