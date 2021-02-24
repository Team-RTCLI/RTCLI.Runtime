#pragma once
#include "RTCLI/Traits.hpp"

namespace RTCLI::System
{
    //MSDN: https://docs.microsoft.com/en-us/dotnet/api/system.icloneable?view=net-5.0
    interface [[CLR]] ICloneable_1
    {
        virtual System::Object Clone() const = 0;
    };
}
