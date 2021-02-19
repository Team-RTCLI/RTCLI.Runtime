#pragma once
#include "RTCLI/Base.hpp"

namespace RTCLI::System
{
    template<typename InnerT>
    struct IntT
    {
        RTCLI_FORCEINLINE IntT() RTCLI_NOEXCEPT
        {

        }
        RTCLI_FORCEINLINE IntT(InnerT v) RTCLI_NOEXCEPT
            :value(v)
        {

        }
        RTCLI_FORCEINLINE bool operator==(const InnerT other) RTCLI_NOEXCEPT
        {
            return value == other;
        }
        RTCLI_FORCEINLINE bool operator!=(const InnerT other) RTCLI_NOEXCEPT
        {
            return value != other;
        }
        RTCLI_FORCEINLINE bool operator<(const InnerT other) RTCLI_NOEXCEPT
        {
            return value < other;
        }
        RTCLI_FORCEINLINE bool operator>(const InnerT other) RTCLI_NOEXCEPT
        {
            return value > other;
        }
        IntT& operator+=(const IntT& rhs) RTCLI_NOEXCEPT 
        {                           
            this->value += rhs.value;
            return *this;
        }
        RTCLI_FORCEINLINE friend IntT operator+(IntT lhs, const IntT other) RTCLI_NOEXCEPT
        {
            lhs += other;
            return lhs;
        }
        IntT& operator-=(const IntT& rhs) RTCLI_NOEXCEPT 
        {                           
            this->value -= rhs.value;
            return *this;
        }
        RTCLI_FORCEINLINE friend IntT operator-(IntT lhs, const IntT other) RTCLI_NOEXCEPT
        {
            lhs -= other;
            return lhs;
        }
        RTCLI_FORCEINLINE operator InnerT() RTCLI_NOEXCEPT
        {
            return value;
        }
    protected:
        InnerT value = 0;
    };
    using Int8 = IntT<i8>;
    using Int16 = IntT<i16>;
    using Int32 = IntT<i32>;
    using Int64 = IntT<i64>;


    using UInt8 = IntT<u8>;
    using UInt16 = IntT<u16>;
    using UInt32 = IntT<u32>;
    using UInt64 = IntT<u64>;
}

namespace RTCLI
{
    using Int8 = System::Int8;
    using Int16 = System::Int16;
    using Int32 = System::Int32;
    using Int64 = System::Int64;


    using UInt8 = System::UInt8;
    using UInt16 = System::UInt16;
    using UInt32 = System::UInt32;
    using UInt64 = System::UInt64;
}