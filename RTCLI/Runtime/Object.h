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
    struct nullref_t 
    {
        template <typename T>
        operator T&() const;
    };

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

        RTCLI_FORCEINLINE Object(const struct Type* t_ = nullptr,
            RC rc_ = 0, Flags flags_ = EObjectFlagBits::None);

        // null
        RTCLI_FORCEINLINE Object(const nullref_t null);
        RTCLI_FORCEINLINE Object& operator=(const nullref_t null) RTCLI_NOEXCEPT;

        void Constructor() RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE bool operator==(const Object& other) const RTCLI_NOEXCEPT;

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
        Managed() RTCLI_NOEXCEPT;
        Managed(nullref_t null) RTCLI_NOEXCEPT;
        Managed(const System::Object& object_) RTCLI_NOEXCEPT;
        Managed& operator=(const System::Object& object_) RTCLI_NOEXCEPT;
        T& Get() RTCLI_NOEXCEPT;
        const T& Get() const RTCLI_NOEXCEPT;
    protected:
        System::Object* object = nullptr;
    };

    template<typename T, typename... Args>
    T& new_object(Args&&... args);
    RTCLI_API Object& new_object(const Type& objectType) RTCLI_NOEXCEPT;

    static const System::nullref_t null;
    static const System::Object nullObject 
        = System::Object{ nullptr, 0, System::EObjectFlagBits::Null };
}
}

namespace RTCLI
{
    using System::null;
    using System::nullObject;

    using System::Managed;
    using System::new_object;
}

#include "RTCLI/Runtime/Internal/Object.inl"
#include "RTCLI/Runtime/Internal/Managed.inl"