#pragma once
#include "RTCLI/Base.hpp"
#include "RTCLI/Int.h"

namespace RTCLI::System
{
    struct RTCLI_API Single 
    {
        static constexpr f32 Epsilon = 1.401298E-45f;
	    static constexpr f32 MaxValue = 3.40282347E+38f;
	    static constexpr f32 MinValue = -3.40282347E+38f;
        static constexpr f32 NaN = 0.f / 0.f;
        static constexpr f32 NegativeInfinity = -1.f / 0.f;
        static constexpr f32 PositiveInfinity = 1.f / 0.f;

        Int CompareTo(const struct Object& value);
        Int CompareTo(f32 value);
        Int CompareTo(Single value);

        bool Equals(const struct Object& obj);
        bool Equals(f32 obj);
        bool Equals(Single obj);

        Int GetHashCode();
        TypeCode GetTypeCode();

        static bool IsInfinity (f32 f);
        static bool IsNaN (f32 f);
        static bool IsNegativeInfinity (f32 f);
        static bool IsPositiveInfinity (f32 f);
    protected:
        f32 value = 0.f;
    };
}