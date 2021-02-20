#define DLL_IMPLEMENTATION
#include "Runtime/Exception.h"
#include "Runtime/String.h"

namespace RTCLI::System
{
    // *******************  Object  *************************//
    RTCLI_API void Object::Constructor() RTCLI_NOEXCEPT
    {

    }

    RTCLI_API Object* new_object(const struct Type& objectType) RTCLI_NOEXCEPT
    {
        Object* object = new Object();
       
        return object;
    }

    // *******************  Exception  *************************//
    RTCLI_API void Throw(const Exception& exception) RTCLI_NOEXCEPT
    {

    }

    // *******************  String  *************************//
    RTCLI_API String& String::Intern(const String& str) RTCLI_NOEXCEPT
    {
        return (String&)RTCLI::null;
    }

    RTCLI_API String& String::IsInterned(const String& str) RTCLI_NOEXCEPT
    {
        return (String&)RTCLI::null;
    }
}