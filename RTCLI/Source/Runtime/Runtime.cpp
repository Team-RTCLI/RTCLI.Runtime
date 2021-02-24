#define DLL_IMPLEMENTATION
#include <iostream>
#include "Runtime/Exception.h"
#include "Runtime/String.h"
#include "RTCLI/Traits.hpp"
#include "Runtime/TypeSystem/Type.h"

namespace RTCLI::System
{
    // *******************  Object  *************************//
    RTCLI_API void Object::Constructor() RTCLI_NOEXCEPT
    {

    }

    Boolean Object::Equals(
        TRef<Object> objA, TRef<Object> objB) RTCLI_NOEXCEPT
    {
        return objA.Get().Equals(objB.Get());
    }

    Boolean Object::ReferenceEquals(
        TRef<Object> objA, TRef<Object> objB) RTCLI_NOEXCEPT
    {
        return &objA.Get() == &objB.Get();
    }

    RTCLI_API Boolean Object::Equals(TRef<Object> obj) const RTCLI_NOEXCEPT
    {
        return *this == obj.Get();
    }

    RTCLI_API Int32 Object::GetHashCode() const RTCLI_NOEXCEPT
    {
        std::cerr << "Object::GetHashCode unimplemented!" << std::endl;
        return 0;
    }

    RTCLI_API TRef<Type> Object::GetType() const RTCLI_NOEXCEPT
    {
        TRef<Type> null_ = RTCLI::null;
        std::cerr << "Object::GetType unimplemented!" << std::endl;
        return null_;
    }

    TRef<String> Object::ToString() const RTCLI_NOEXCEPT
    {
        String str = RTCLI_NATIVE_STRING("Object::ToString unimplemented!");
        std::cerr << "Object::ToString unimplemented!" << std::endl;
        return str;
    }

    RTCLI_API Managed<Object> new_object(const struct Type& objectType) RTCLI_NOEXCEPT
    {
        Managed<Object> res = RTCLI::null;
        std::cerr << "new_object unimplemented!" << std::endl;
        return res;
    }

    // *******************  Exception  *************************//
    RTCLI_API void Throw(const Exception& exception) RTCLI_NOEXCEPT
    {
        std::cerr << "Throw unimplemented!" << std::endl;
    }

    // *******************  String  *************************//
    RTCLI_API String& String::Intern(const String& str) RTCLI_NOEXCEPT
    {
        std::cerr << "String::Intern unimplemented!" << std::endl;
        
        return (String&)RTCLI::null;
    }

    RTCLI_API String& String::IsInterned(const String& str) RTCLI_NOEXCEPT
    {
        std::cerr << "String::IsInterned unimplemented!" << std::endl;

        return (String&)RTCLI::null;
    }
}