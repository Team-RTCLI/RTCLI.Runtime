#pragma once
#include "RTCLI/Runtime/Nullable.h"
#include "RTCLI/Runtime/IFormatProvider.h"

namespace RTCLI::System
{
    //MSDN: https://docs.microsoft.com/zh-cn/dotnet/api/system.iconvertible?view=net-5.0
    interface [[CLR]] IConvertible
    {
        virtual TypeCode GetTypeCode() = 0;

    };
}