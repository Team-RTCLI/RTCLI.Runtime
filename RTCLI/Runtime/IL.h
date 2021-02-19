#pragma once
#include "Traits.hpp"

namespace RTCLI
{
    namespace System
    {
        struct Object;
    }
}

// ILs
namespace RTCLI
{
    // just do nothing.
    RTCLI_IL_FUNC void nop() RTCLI_NOEXCEPT;

    RTCLI_IL_FUNC void unimplemented_il(const char* instruction) RTCLI_NOEXCEPT;

    RTCLI_IL_FUNC i32 Cgt_Un(System::Object& val1, System::Object& val2) RTCLI_NOEXCEPT;
    template<typename T>
    typename std::enable_if_t<is_unsigned_v<T>, i32> 
    RTCLI_IL_FUNC /*i32*/ Cgt_Un(const T val1, const T val2) RTCLI_NOEXCEPT;
    
    template<typename T>
    typename std::enable_if_t<is_numeric_v<T>, i32>
    RTCLI_IL_FUNC /*i32*/ Cgt(const T val1, const T val2) RTCLI_NOEXCEPT;

    template<typename T>
    typename std::enable_if_t<is_numeric_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Add(const T val1, const T val2) RTCLI_NOEXCEPT;

    template<typename T>
    typename std::enable_if_t<is_numeric_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Add_Ovf(const T val1, const T val2) RTCLI_NOEXCEPT;

    template<typename T>
    typename std::enable_if_t<is_unsigned_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Add_Ovf_Un(const T val1, const T val2) RTCLI_NOEXCEPT;

    template<typename T>
    typename std::enable_if_t<is_numeric_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Sub(const T val1, const T val2) RTCLI_NOEXCEPT;

    template<typename T>
    typename std::enable_if_t<is_numeric_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Sub_Ovf(const T val1, const T val2) RTCLI_NOEXCEPT;

    template<typename T>
    typename std::enable_if_t<is_unsigned_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Sub_Ovf_Un(const T val1, const T val2) RTCLI_NOEXCEPT;
}

#include "Internal/Nop.inl"
#include "Internal/Cgt.inl"
#include "Internal/Add.inl"
#include "Internal/Sub.inl"