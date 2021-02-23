#pragma once
#include "RTCLI/Traits.hpp"

namespace RTCLI::System
{
    //MSDN: https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable-1?view=net-5.0
    template<typename T>
    interface [[CLR]] IComparable_1
    {
        virtual Boolean CompareTo(P<T> other) = 0;
    };

    //MSDN: https://docs.microsoft.com/zh-cn/dotnet/api/system.icomparable?view=net-5.0
    using IComparable = IComparable_1<Object>;
}
