#pragma once
#include <type_traits>
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
        RTCLI_FORCEINLINE Object(nullptr_t null)
            :type(nullptr), rc(1), flags(EObjectFlagBits::Null)
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
        virtual TRef<class String> ToString() const RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE Boolean isNull() const RTCLI_NOEXCEPT
        {
            return flags & EObjectFlagBits::Null;
        }
    protected:
        TRef<Object> MemberwiseClone() const RTCLI_NOEXCEPT;
    };

    template<typename T>
    struct Managed
    {
        static_assert(
            std::is_base_of_v<System::Object, T>,
            "ManagedObject must be derived from System::Object!"
        );
        Managed(nullptr_t null) RTCLI_NOEXCEPT
            :object(const_cast<System::Object*>(&RTCLI::nullObject))
        {

        }
        Managed(const System::Object& object_) RTCLI_NOEXCEPT
        {
            if (object_.isNull()) {
                object = const_cast<System::Object*>(&RTCLI::nullObject);
            }
            else
            {
                object = const_cast<System::Object*>(&object_);
            }
        }
        Managed& operator=(const System::Object& object_) RTCLI_NOEXCEPT
        {
            if(this->object == &object_)
            {
                return *this;
            }
            if (object_.isNull()) {
                object = const_cast<System::Object*>(&RTCLI::nullObject);
            }
            else
            {
                object = const_cast<System::Object*>(&object_);
            }
        }
        T& Get() RTCLI_NOEXCEPT
        {
            return *static_cast<T*>(object);
        }

        System::Object* object = nullptr;
    };

    template<typename T, typename... Args>
    Managed<T> new_object(Args&&... args);

    RTCLI_API Managed<Object> new_object(const Type& objectType) RTCLI_NOEXCEPT;
}
}

namespace RTCLI
{
    static const nullptr_t null = nullptr; 
    static const System::Object nullObject 
        = System::Object{ nullptr, 0, System::EObjectFlagBits::Null };

    using System::Managed;
    using System::new_object;
}

#include "RTCLI/Runtime/Internal/Object.inl"