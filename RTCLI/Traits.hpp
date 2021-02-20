#pragma once
#include <type_traits>
#include "Runtime/Int.h"
#include "Runtime/Single.h"
#include "Runtime/Object.h"

namespace RTCLI
{
    template<typename T>
    struct is_unsigned
    {
        static constexpr bool value =
            std::is_same_v<T, u8> ||
            std::is_same_v<T, u16> ||
            std::is_same_v<T, u32> ||
            std::is_same_v<T, u64> ||
            std::is_same_v<T, usize> 
            ||
            std::is_same_v<T, UInt8> ||
            std::is_same_v<T, UInt16> ||
            std::is_same_v<T, UInt32> ||
            std::is_same_v<T, UInt64>
            ;
    };
    template<typename T>
    static constexpr bool is_unsigned_v = is_unsigned<T>::value;

    template<typename T>
    struct is_signed
    {
        static constexpr bool value =
            std::is_same_v<T, i8> ||
            std::is_same_v<T, i16> ||
            std::is_same_v<T, i32> ||
            std::is_same_v<T, f32> ||
            std::is_same_v<T, i64> ||
            std::is_same_v<T, f64> ||
            std::is_same_v<T, isize>
            ||
            std::is_same_v<T, Int8> ||
            std::is_same_v<T, Int16> ||
            std::is_same_v<T, Int32> ||
            std::is_same_v<T, Int64> ||
            std::is_same_v<T, Single> ||
            std::is_same_v<T, Double>
            ;
    };
    template<typename T>
    static constexpr bool is_signed_v = is_signed<T>::value;

    template<typename T>
    struct is_numeric
    {
        static constexpr bool value = is_unsigned_v<T> || is_signed_v<T>;
    };
    template<typename T>
    static constexpr bool is_numeric_v = is_numeric<T>::value;
}