#pragma once
#include "RTCLI/Base.hpp"
#include "RTCLI/Runtime/Object.h"

namespace RTCLI
{
namespace System
{
    struct Type;

    // Actualy this is an interface.
    // MSDN: https://docs.microsoft.com/zh-cn/dotnet/api/system.ValueType?view=net-5.0
    struct [[CLR, Abstract]] ValueType : Object
    {
        virtual Type& GetType() RTCLI_NOEXCEPT = 0;

    };

    template<class T>
    void initialize_object(T& address);
}
}


namespace RTCLI
{
    using System::initialize_object;
}