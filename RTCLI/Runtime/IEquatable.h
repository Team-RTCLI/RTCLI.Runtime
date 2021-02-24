#pragma once
#include "RTCLI/Runtime/Nullable.h"
#include "RTCLI/Runtime/IFormatProvider.h"

namespace RTCLI::System
{
    //MSDN: https://docs.microsoft.com/zh-cn/dotnet/api/system.iequatable-1?view=net-5.0
    template<class T>
    interface [[CLR]] IEquatable_1
    {
        virtual bool Equals(TRef<T> other) = 0;
    };
}