#pragma once
#include "Object.h"
#include "Traits.hpp"
#include "Array.h"
#include <functional>

namespace RTCLI::System
{
	class Delegate : public Object //,public ICloneable, public Runtime::Serialization::ISerializable
	{
	protected:
		TRef<Object> object;
		System::IntPtr function;
		System::IntPtr trampoline;
		TRef<ElementArray<Delegate>> delegates;
	public:
		virtual Object& Clone();
		static Delegate& Combine(TRef<Delegate> a, TRef<Delegate> b);
		Object& DynamicInvoke(TRef<ElementArray<Object>> args);

		virtual ElementArray<Delegate>& GetInvocationList();
	};
	class MulticastDelegate : public Delegate
	{
	};

	template<class T>
	class Func;
	template<class... Ts, class Result>
	class Func<Result(Ts...)> : public MulticastDelegate
	{
		using TrampolineType = Result(*)(Object& obj, System::IntPtr function, Ts... args);
		
		template<class F>
		Func(Object & obj, F function)
		{
			//fast path if function type is known at compile time
			this->object = obj;
			this->function = (RTCLI::IntPtr)function;
			TrampolineType trampolinef;
			using U = object_type_t<F>;
			if constexpr (!std::is_same_v<U, void>)
			{
				trampolinef = +[](Object& obj, System::IntPtr function, Ts&&... args)
				{
					return reinterpret_cast<U&>(obj).*reinterpret_cast<F>(function)(std::forward<Ts>(args)...);
				};
			}
			else
			{
				trampolinef = +[](Object& obj, System::IntPtr function, Ts&&... args)
				{
					return reinterpret_cast<F>(function)(std::forward<Ts>(args)...);
				};
			}
			trampoline = (RTCLI::IntPtr)trampolinef;
		}
		Func(Object& obj, RTCLI::IntPtr function)
		{
			//slow path if function type is erased
			this->object = obj;
			this->function = function;
			//initialize by reflection
			/*
			* trampolinef = +[](Object& obj, System::IntPtr function, Ts&&... args)
			* {
			*	Reflection::Invoke(obj, function, std::forward<Ts>(args)...);
			* }
			*/
		}
		virtual Result Invoke(Ts&&... args)
		{
			if (delegates.isNull())
			{
				TrampolineType callerp = (TrampolineType)caller;
				return callerp(object, function, std::forward<Ts>(args)...);
			}
			else
			{
				//foreach delegate in delegates call Invoke
				//return last result of Invoke
				auto& dels = delegates.Get();
				int len = dels.numElements;
				for (int i = 0; i < len - 1; ++i)
				{
					TrampolineType trampolinef = (TrampolineType)ArrayGet(dels, i).trampoline;
					trampolinef(object, function, std::forward<Ts>(args)...)
				}
				TrampolineType trampolinef = (TrampolineType)ArrayGet(dels, len - 1).trampoline;
				return trampolinef(object, function, std::forward<Ts>(args)...);
			}
		}
	};

	template<class Result>
	using Func_1 = Func<Result()>;
	template<class T, class Result>
	using Func_2 = Func<Result(T)>;
	template<class T1, class T2, class Result>
	using Func_3 = Func<Result(T1, T2)>;
	template<class T1, class T2, class T3, class Result>
	using Func_4 = Func<Result(T1, T2, T3)>;
	template<class T1, class T2, class T3, class T4, class Result>
	using Func_5 = Func<Result(T1, T2, T3, T4)>;
	template<class T1, class T2, class T3, class T4, class T5, class Result>
	using Func_6 = Func<Result(T1, T2, T3, T4, T5)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class Result>
	using Func_7 = Func<Result(T1, T2, T3, T4, T5, T6)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class Result>
	using Func_8 = Func<Result(T1, T2, T3, T4, T5, T6, T7)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class Result>
	using Func_9 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class Result>
	using Func_10 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class Result>
	using Func_11 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class Result>
	using Func_12 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class Result>
	using Func_13 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class Result>
	using Func_14 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class Result>
	using Func_15 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class Result>
	using Func_16 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class Result>
	using Func_17 = Func<Result(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16>
	using Action_16 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15>
	using Action_15 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14>
	using Action_14 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13>
	using Action_13 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12>
	using Action_12 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11>
	using Action_11 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
	using Action_10 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
	using Action_9 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8, T9)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
	using Action_8 = Func<void(T1, T2, T3, T4, T5, T6, T7, T8)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6, class T7>
	using Action_7 = Func<void(T1, T2, T3, T4, T5, T6, T7)>;
	template<class T1, class T2, class T3, class T4, class T5, class T6>
	using Action_6 = Func<void(T1, T2, T3, T4, T5, T6)>;
	template<class T1, class T2, class T3, class T4, class T5>
	using Action_5 = Func<void(T1, T2, T3, T4, T5)>;
	template<class T1, class T2, class T3, class T4>
	using Action_4 = Func<void(T1, T2, T3, T4)>;
	template<class T1, class T2, class T3>
	using Action_3 = Func<void(T1, T2, T3)>;
	template<class T1, class T2>
	using Action_2 = Func<void(T1, T2)>;
	template<class T>
	using Action_1 = Func<void(T)>;
	using Action = Func<void()>;
}

namespace RTCLI
{
}