#include <iostream>

namespace RTCLI
{
	RTCLI_IL_FUNC void nop() RTCLI_NOEXCEPT
	{

	}

	RTCLI_IL_FUNC void unimplemented_il(const char* instruction) RTCLI_NOEXCEPT
	{
		std::cout << "unimplemented_il: " << instruction;
	}
}