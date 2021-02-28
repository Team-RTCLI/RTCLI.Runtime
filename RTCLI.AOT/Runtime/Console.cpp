#define DLL_IMPLEMENTATION
#include "Runtime/Console/Write.h"
#include "Runtime/String.h"
#include <iostream>

using namespace RTCLI::System::Console;

RTCLI_API void RTCLI::System::Console::WriteLine(const Char* str) RTCLI_NOEXCEPT
{
	std::wcout << str << std::endl;
}

RTCLI_API void RTCLI::System::Console::Write(const Char* str) RTCLI_NOEXCEPT
{
	std::wcout << str;
}

RTCLI_API void RTCLI::System::Console::WriteLine(const System::String& str) RTCLI_NOEXCEPT
{
	std::wcout << str.chars << std::endl;
}

RTCLI_API void RTCLI::System::Console::Write(const System::String& str) RTCLI_NOEXCEPT
{
	std::wcout << str.chars;
}

RTCLI_API void RTCLI::System::Console::WriteLine(const System::Int32 int_) RTCLI_NOEXCEPT
{
	std::wcout << i32(int_) << std::endl;
}

RTCLI_API void RTCLI::System::Console::Write(const System::Int32 int_) RTCLI_NOEXCEPT
{
	std::wcout << i32(int_);
}

RTCLI_API void RTCLI::System::Console::WriteLine(const System::Single f) RTCLI_NOEXCEPT
{
	std::wcout << f32(f) << std::endl;
}

RTCLI_API void RTCLI::System::Console::Write(const System::Single f) RTCLI_NOEXCEPT
{
	std::wcout << f32(f);
}