#pragma once
#include "RTCLI/Traits.hpp"

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

    template<typename T, typename U>
    RTCLI_IL_FUNC bool Ceq(T&& val1, U&& val2) RTCLI_NOEXCEPT
    {
        return val1 == val2;
    }

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

    template<typename T>
    RTCLI_IL_FUNC bool Cond(T&& val1) RTCLI_NOEXCEPT
    {
        return bool(val1);
    }


    template<class T>
    RTCLI_IL_FUNC T& Box(const typename T::ValueType& value);

    template<class T>
    RTCLI_IL_FUNC typename T::ValueType UnBox(const System::Object& object);

    template<class T>
    RTCLI_IL_FUNC T& Castclass(System::Object& object);

#define RTCLI_ADDRESSOF(val) (RTCLI::IntPtr)(iptr)std::addressof(val)

    template<class T>
    RTCLI_IL_FUNC void Pop(T&&) {}
}

#include "Internal/Nop.inl"
#include "Internal/Cgt.inl"
#include "Internal/Add.inl"
#include "Internal/Sub.inl"
#include "Internal/Box.inl"