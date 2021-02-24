#pragma once
#include <type_traits>
#include "Runtime/Int.h"
#include "Runtime/Single.h"
#include "Runtime/Boolean.h"
#include "Runtime/Object.h"
#include "Runtime/ValueType.h"

namespace RTCLI
{
    template<typename T>
    struct is_unsigned : std::disjunction<
        std::is_same<T, u8>,
        std::is_same<T, u16>,
        std::is_same<T, u32>,
        std::is_same<T, u64>,
        std::is_same<T, usize>,
        std::is_same<T, UInt8>,
        std::is_same<T, UInt16>,
        std::is_same<T, UInt32>,
        std::is_same<T, UInt64>> {};
    template<typename T>
    static constexpr bool is_unsigned_v = is_unsigned<T>::value;

    template<typename T>
    struct is_signed : std::disjunction<
        std::is_same<T, i8>,
        std::is_same<T, i16>,
        std::is_same<T, i32>,
        std::is_same<T, f32>,
        std::is_same<T, i64>,
        std::is_same<T, f64>,
        std::is_same<T, isize>,
        std::is_same<T, Int8>,
        std::is_same<T, Int16>,
        std::is_same<T, Int32>,
        std::is_same<T, Int64>,
        std::is_same<T, Single>,
        std::is_same<T, Double>> {};
    template<typename T>
    static constexpr bool is_signed_v = is_signed<T>::value;

    template<typename T>
    struct is_numeric : std::disjunction<is_unsigned<T>, is_signed<T>> {};
    template<typename T>
    static constexpr bool is_numeric_v = is_numeric<T>::value;

	template<typename T>
	struct TRef
	{
        RTCLI_FORCEINLINE TRef(System::nullref_t null){}
		RTCLI_FORCEINLINE TRef(T& reference)
			:object(&reference)
		{
            
		}
        TRef& operator=(T& object_) RTCLI_NOEXCEPT
        {
            object = &object_;
            return *this; 
        }
        TRef& operator=(System::nullref_t null) RTCLI_NOEXCEPT
        {
            object = nullptr;
            return *this;
        }
		RTCLI_FORCEINLINE T& Get() RTCLI_NOEXCEPT
		{
			return *object;
		}
		RTCLI_FORCEINLINE const T& Get() const RTCLI_NOEXCEPT
		{
			return *object;
		}
        RTCLI_FORCEINLINE System::Boolean isNull() const RTCLI_NOEXCEPT
        {
            if(!object)
                return true;
            if constexpr (std::is_base_of_v<System::Object, T>)
                return object->isNull();
            else
                return false;
        }
		T* object = nullptr;
	}; 
	using ObjectRef = TRef<System::Object>;

    template<typename T>
    class TValue
    {
        RTCLI_FORCEINLINE TValue(const T& value)
            :value(value)
        {

        }
        TValue& operator=(const T& value) RTCLI_NOEXCEPT
        {
            this->value = value;
            return *this;
        }
        RTCLI_FORCEINLINE T& Get() RTCLI_NOEXCEPT
        {
            return value;
        }
        RTCLI_FORCEINLINE const T& Get() const RTCLI_NOEXCEPT
        {
            return value;
        }
        T value;
    };

    template<typename T>
    using TVar = std::conditional_t<std::is_base_of_v<System::Object, T>, TRef<T>, TValue<T>>;

    template<typename T>
    using TField = std::conditional_t<std::is_base_of_v<System::Object, T>, Managed<T>, TValue<T>>;

    template<typename T>
    using TRet = std::conditional_t<std::is_base_of_v<System::Object, T>, T&, T>;
}

