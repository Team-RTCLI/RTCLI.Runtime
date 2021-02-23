#pragma once
#include "RTCLI/Runtime/Object.h"

namespace RTCLI
{
namespace System
{
namespace Reflection
{
    class [[CLR, Abstract]] MemberInfo : public System::Object
    {
    public:

    protected:
        MemberInfo();
        void Constructor() RTCLI_NOEXCEPT;
    };
}
}
}