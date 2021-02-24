#pragma once
#include <limits>
#include "RTCLI/Base.hpp"
#include "RTCLI/Runtime/Int.h"

namespace RTCLI::System
{
    struct RTCLI_API Single 
    {
        typedef std::numeric_limits<f32> SingleInfo;
        RTCLI_FORCEINLINE Single() RTCLI_NOEXCEPT
        {

        }
        RTCLI_FORCEINLINE Single(f32 v) RTCLI_NOEXCEPT
            :value(v)
        {

        }

        static constexpr f32 Epsilon = SingleInfo::epsilon();
	    static constexpr f32 MaxValue = SingleInfo::max();
	    static constexpr f32 MinValue = SingleInfo::min();
        static constexpr f32 NaN = SingleInfo::quiet_NaN();
        static constexpr f32 NegativeInfinity = -1.f * SingleInfo::infinity();
        static constexpr f32 PositiveInfinity = SingleInfo::infinity();
        
        RTCLI_FORCEINLINE operator f32() const RTCLI_NOEXCEPT
        {
            return value;
        }
        //Int32 CompareTo(const struct Object& value);
        //Int32 CompareTo(f32 value);
        //Int32 CompareTo(Single value);

        //bool Equals(const struct Object& obj);
        //bool Equals(f32 obj);
        //bool Equals(Single obj);

        //Int32 GetHashCode();
        //TypeCode GetTypeCode();

        //static bool IsInfinity (f32 f);
        //static bool IsNaN (f32 f);
        //static bool IsNegativeInfinity (f32 f);
        //static bool IsPositiveInfinity (f32 f);
    protected:
        f32 value = 0.f;
    };

    struct RTCLI_API Double
    {
        f64 value = 0;
    };
}

namespace RTCLI
{
    using System::Single;
    using System::Double;
}