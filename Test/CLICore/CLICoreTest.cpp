#include <iostream>
#include <RTCLI/RTCLI.hpp>

int main()
{
    RTCLI::init();
    RTCLI::frame();
    RTCLI::close();

    return 0;
}