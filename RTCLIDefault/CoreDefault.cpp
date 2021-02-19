#include "CoreDefault.hpp"
#include <iostream>

void RTCLI::Default::CoreDefault::init()
{
    std::cout << "RTCLI Core Init!" << std::endl;
}

void RTCLI::Default::CoreDefault::close()
{
    std::cout << "RTCLI Core Close!" << std::endl;
}

void RTCLI::Default::CoreDefault::frame()
{
    std::cout << "RTCLI Core Frame!" << std::endl;
}