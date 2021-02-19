#define DLL_IMPLEMENTATION
#include "Runtime/Object.h"
#include "Runtime/Exception.h"

namespace RTCLI::System
{
    RTCLI_API void Object::Constructor() RTCLI_NOEXCEPT
    {

    }

    RTCLI_API Object* new_object(const struct Type& objectType) RTCLI_NOEXCEPT
    {
        Object* object = new Object();
       
        return object;
    }

    RTCLI_API void Throw(const Exception& exception) RTCLI_NOEXCEPT
    {

    }
}