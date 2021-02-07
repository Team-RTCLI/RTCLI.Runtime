#pragma once
#include "RTCLI/Base.hpp"

namespace RTCLI::System
{
    struct RTCLI_API Object 
    {
        using Flags = u32;
        using RC = i32;

        const struct Type* type = nullptr;
        RC rc;
        Flags flags;
    };

    template<typename T>
    T* new_object();

    RTCLI_API Object* new_object(const Type& objectType);
}

#include "Internal/Object.inl"