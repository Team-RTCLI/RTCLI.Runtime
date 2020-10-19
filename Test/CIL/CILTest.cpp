#include <iostream>
#include <RTCLI/CIL/OpCodes.h>

int main()
{
    std::cout << "CILTest" << std::endl;
    std::cout << RTCLI::CIL::ToString(
        RTCLI::CIL::CodeFromString("Nop")
    );
    return 0;
}