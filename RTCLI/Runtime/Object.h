#pragma once
#include "RTCLI/Runtime/Boolean.h"
#include "RTCLI/Runtime/Int.h"

namespace RTCLI
{
    template<typename T>
	struct TRef;
namespace System
{
    enum EObjectFlagBits : u32
    {
        None = 0,
        Null,
        Count
    };

    struct RTCLI_API Object 
    {
        using Flags = u32;
        using RC = i32;
        const struct Type* type = nullptr;
        RC rc = 0;
        Flags flags = EObjectFlagBits::None;

        RTCLI_FORCEINLINE Object(
            const struct Type* t_ = nullptr, RC rc_ = 0, Flags flags_ = EObjectFlagBits::None)
            :type(t_), rc(rc_), flags(flags_)
        {}

        void Constructor() RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE bool operator==(const Object& other) const RTCLI_NOEXCEPT
        {
            if(this == &other)
            {
                return true;
            }
            if(flags & EObjectFlagBits::Null)
            {
                return (other.flags & EObjectFlagBits::Null);
            }
            return false;
        }

        static Boolean Equals(TRef<System::Object> objA, TRef<System::Object> objB) RTCLI_NOEXCEPT;
        static Boolean ReferenceEquals(TRef<System::Object> objA, TRef<System::Object> objB) RTCLI_NOEXCEPT;
        virtual Boolean Equals(TRef<System::Object> obj) const RTCLI_NOEXCEPT;
        virtual Int32 GetHashCode() const RTCLI_NOEXCEPT;
        TRef<Type> GetType() const RTCLI_NOEXCEPT;
        virtual TRef<struct String> ToString() const RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE Boolean isNull() const RTCLI_NOEXCEPT
        {
            return flags & EObjectFlagBits::Null;
        }
    protected:
        TRef<Object> MemberwiseClone() const RTCLI_NOEXCEPT;
    };

    template<typename T, typename... Args>
    T* new_object(Args&&... args);

    RTCLI_API Object* new_object(const Type& objectType) RTCLI_NOEXCEPT;
}
}

namespace RTCLI
{
    static const System::Object null 
        = System::Object{ nullptr, 0, System::EObjectFlagBits::Null };

    using System::new_object;
}

#include "RTCLI/Runtime/Internal/Object.inl"