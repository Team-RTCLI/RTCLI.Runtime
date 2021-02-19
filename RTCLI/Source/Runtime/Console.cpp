#define DLL_IMPLEMENTATION
#include "Runtime/Console/WriteLine.h"
#include <iostream>

using namespace RTCLI::System::Console;

RTCLI_API void RTCLI::System::Console::WriteLine(const char* str) RTCLI_NOEXCEPT
{
	std::cout << str << std::endl;
}