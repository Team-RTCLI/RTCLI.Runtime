#pragma once
#include "RTCLI/Base.hpp"
#include <string_view>

namespace RTCLI::System
{
	struct Boolean
	{
		static constexpr std::wstring_view FalseString = RTCLI_NATIVE_STRING("False");
		static constexpr std::wstring_view TrueString = RTCLI_NATIVE_STRING("True");

		RTCLI_FORCEINLINE Boolean() RTCLI_NOEXCEPT {}

		RTCLI_FORCEINLINE Boolean(bool v) RTCLI_NOEXCEPT
			:value(v) {}

		RTCLI_FORCEINLINE operator bool() RTCLI_NOEXCEPT
		{
			return value;
		}

		bool value = false;
	};
}