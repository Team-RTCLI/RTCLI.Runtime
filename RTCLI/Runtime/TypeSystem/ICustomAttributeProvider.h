#pragma once
#include "RTCLI/Traits.hpp"
#include "RTCLI/Runtime/Array.h"

namespace RTCLI
{
    class Type;

namespace Reflection
{
    interface [[CLR]] ICustomAttributeProvider
    {
        virtual System::ElementArray<System::Object> GetCustomAttributes(bool inherit) = 0;
        virtual System::ElementArray<System::Object> GetCustomAttributes(
            TRef<Type> attributeType, bool inherit) = 0;
        virtual System::Boolean IsDefined(TRef<Type> attributeType, bool inherit) = 0; 
    };
}
}