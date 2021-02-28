#pragma once
#include "RTCLI/Base.hpp"
#include "RTCLI/Runtime/Int.h"
#include "RTCLI/Runtime/Single.h"

namespace RTCLI
{
namespace System
{
	class String;
namespace Console
{
	RTCLI_API void WriteLine(const System::Int32 int_) RTCLI_NOEXCEPT;
	RTCLI_API void Write(const System::Int32 int_) RTCLI_NOEXCEPT;

	RTCLI_API void WriteLine(const System::Single single_) RTCLI_NOEXCEPT;
	RTCLI_API void Write(const System::Single single_) RTCLI_NOEXCEPT;

	RTCLI_API void WriteLine(const Char* str) RTCLI_NOEXCEPT;
	RTCLI_API void Write(const Char* str) RTCLI_NOEXCEPT;

	RTCLI_API void WriteLine(const System::String& str) RTCLI_NOEXCEPT;
	RTCLI_API void Write(const System::String& str) RTCLI_NOEXCEPT;
}
}
}