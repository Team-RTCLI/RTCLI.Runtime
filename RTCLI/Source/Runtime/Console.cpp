#define DLL_IMPLEMENTATION
#include "Runtime/Console/Write.h"
#include "Runtime/String.h"
#include <iostream>

using namespace RTCLI::System::Console;

RTCLI_API void RTCLI::System::Console::WriteLine(const RTCLI::Char* str) RTCLI_NOEXCEPT
{
#ifdef _MSC_VER
	std::wcout << str << std::endl;
#else
	std::cout << str << std::endl;
#endif
}

RTCLI_API void RTCLI::System::Console::Write(const RTCLI::Char* str) RTCLI_NOEXCEPT
{
#ifdef _MSC_VER
	std::wcout << str;
#else
	std::cout << str;
#endif
}


RTCLI_API void RTCLI::System::Console::WriteLine(const RTCLI::System::String& str) RTCLI_NOEXCEPT
{
#ifdef _MSC_VER
	std::wcout << str.chars << std::endl;
#else
	std::cout << str.chars << std::endl;
#endif
}

RTCLI_API void RTCLI::System::Console::Write(const RTCLI::System::String& str) RTCLI_NOEXCEPT
{
#ifdef _MSC_VER
	std::wcout << str.chars;
#else
	std::cout << str.chars;
#endif
}