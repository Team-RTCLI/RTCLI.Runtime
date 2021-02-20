#pragma once
#include "RTCLI/Base.hpp"

namespace RTCLI
{
namespace System
{
	struct String;
namespace Console
{
	RTCLI_API void WriteLine(const RTCLI::Char* str) RTCLI_NOEXCEPT;
	RTCLI_API void Write(const RTCLI::Char* str) RTCLI_NOEXCEPT;

	RTCLI_API void WriteLine(const RTCLI::System::String& str) RTCLI_NOEXCEPT;
	RTCLI_API void Write(const RTCLI::System::String& str) RTCLI_NOEXCEPT;
}
}
}