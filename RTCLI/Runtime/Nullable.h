#pragma once
#include "RTCLI/Traits.hpp"

namespace RTCLI
{
    class Type;
namespace System
{
    struct Object;

    template<typename T>
    struct [[CLR]] Nullable_1
    {
        Nullable_1()
            :contain(nullptr)
        {

        };
        Boolean getHasValue() RTCLI_NOEXCEPT;
        T getValue() RTCLI_NOEXCEPT;
    protected:
        T* contain = nullptr;
    };
    

    class [[CLR, Static]] Nullable
    {
    public:
        template<typename T>
        static Boolean Compare(Nullable_1<T>, Nullable_1<T>);

        template<typename T>
        static Boolean Equals(Nullable_1<T>, Nullable_1<T>);

        static const Type& GetUnderlyingType(RefT<Type> nullableType);
    };
}
}

namespace RTCLI
{
namespace System
{
    template<typename T>
    RTCLI_FORCEINLINE Boolean Nullable_1<T>::getHasValue() RTCLI_NOEXCEPT
    {
        return contain != nullptr;
    }

    template<typename T>
    RTCLI_FORCEINLINE T Nullable_1<T>::getValue() RTCLI_NOEXCEPT
    {
        return *T;
    }
}
}