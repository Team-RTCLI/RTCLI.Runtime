#pragma once
#include "RTCLI/Base.hpp"

namespace RTCLI::System
{
    enum EObjectFlagBits : u32
    {
        None = 0,
        Null,
        Count
    };

    struct RTCLI_API Object 
    {
        using Flags = u32;
        using RC = i32;

        void Constructor() RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE bool operator==(const Object& other) RTCLI_NOEXCEPT
        {
            return this == &other;
        }

        const struct Type* type = nullptr;
        RC rc = 0;
        Flags flags = EObjectFlagBits::None;
    };

    template<typename T, typename... Args>
    T* new_object(Args&&... args);

    RTCLI_API Object* new_object(const Type& objectType) RTCLI_NOEXCEPT;
}

namespace RTCLI
{
    static constexpr System::Object null = { nullptr, 0, System::EObjectFlagBits::Null };

    using System::new_object;
}

#include "RTCLI/Runtime/Internal/Object.inl"