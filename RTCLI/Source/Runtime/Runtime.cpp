#define DLL_IMPLEMENTATION
#include "Runtime/Object.h"

namespace RTCLI::System
{
    RTCLI_API Object* new_object(const struct Type& objectType)
    {
        Object* object = new Object();
       
        return object;
    }
}