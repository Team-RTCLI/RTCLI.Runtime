#include <iostream>
#include "Traits.hpp"

namespace RTCLI
{
	RTCLI_IL_FUNC i32 Cgt_Un(System::Object& val1, System::Object& val2) RTCLI_NOEXCEPT
	{
		if (val1.flags == System::EObjectFlagBits::Null)
		{
			if (val2.flags == System::EObjectFlagBits::Null)
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}
		else if (val2.flags == System::EObjectFlagBits::Null)
		{
			if (val1.flags == System::EObjectFlagBits::Null)
			{
				return 2;
			}
			else
			{
				return 1;
			}
		}
		return 3;
	}

	template<typename T>
	typename std::enable_if_t<is_unsigned_v<T>, i32>
	RTCLI_IL_FUNC /*i32*/ Cgt_Un(const T val1, const T val2) RTCLI_NOEXCEPT
	{
		return (val1 > val2) ? 1 : 0;
	}

	template<typename T>
	typename std::enable_if_t<is_numeric_v<T>, i32>
	RTCLI_IL_FUNC /*i32*/ Cgt(const T val1, const T val2) RTCLI_NOEXCEPT
	{
		return (val1 > val2) ? 1 : 0;
	}
}