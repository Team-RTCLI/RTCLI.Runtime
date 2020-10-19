#include <iostream>
#include <RTCLI/RTCLI.hpp>

int main()
{
    std::cout << "CLICore Test" << std::endl;

    RTCLI::init();
    RTCLI::frame();
    RTCLI::close();

    return 0;
}