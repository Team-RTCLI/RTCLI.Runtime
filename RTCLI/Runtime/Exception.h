#pragma once
#include "Object.h"

namespace RTCLI::System
{
    struct RTCLI_API Exception : public Object
    {

    };

    RTCLI_API void Throw(const Exception& exception) RTCLI_NOEXCEPT;

    struct OverflowException : public System::Exception
    {
        const char* val1 = nullptr;
        const char* val2 = nullptr;
        const char* type = nullptr;
        void Constructor(const char* val1, const char* val2, const char* type) RTCLI_NOEXCEPT
        {

        }
    };
}

namespace RTCLI
{
    using System::Throw;
}