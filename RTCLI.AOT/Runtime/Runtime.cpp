#define DLL_IMPLEMENTATION
#include <iostream>
#include "Runtime/Exception.h"
#include "Runtime/String.h"
#include "RTCLI/Traits.hpp"
#include "Runtime/TypeSystem/Type.h"
#include <cwctype>

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

    RTCLI_API Object& new_object(const struct Type& objectType) RTCLI_NOEXCEPT
    {
        std::cerr << "new_object(const struct Type&) unimplemented!" << std::endl;
        return RTCLI::null;
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
        
        return RTCLI::null;
    }

    RTCLI_API String& String::ToLower(void) const RTCLI_NOEXCEPT
    {
        String& lower = new_object<System::String>(this->chars, this->length);
        
        return lower;
    }
    
    RTCLI_API String& String::ToUpper(void) const RTCLI_NOEXCEPT
    {
        String& upper = new_object<System::String>(this->chars, this->length);

        return RTCLI::null;
    }

    RTCLI_API String& String::IsInterned(const String& str) RTCLI_NOEXCEPT
    {
        std::cerr << "String::IsInterned unimplemented!" << std::endl;

        return RTCLI::null;
    }

    RTCLI_API System::Int32 String::get_Length() const RTCLI_NOEXCEPT
    {
        return length;
    }
}
