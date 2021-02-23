#pragma once
#include "RTCLI/Runtime/Nullable.h"
#include "RTCLI/Runtime/TypeSystem/Type.h"

namespace RTCLI::System
{
    //MSDN: https://docs.microsoft.com/zh-cn/dotnet/api/system.iformatprovider?view=net-5.0
    interface [[CLR]] IFormatProvider
    {
        virtual Nullable GetFormat(Nullable_1<Type> formatType) = 0;
    };
}