#include "CoreStub.hpp"
#include <iostream>

void RTCLI::Stub::CoreStub::init()
{
    std::cout << "RTCLI Core Init!" << std::endl;
}

void RTCLI::Stub::CoreStub::close()
{
    std::cout << "RTCLI Core Close!" << std::endl;
}

void RTCLI::Stub::CoreStub::frame()
{
    std::cout << "RTCLI Core Frame!" << std::endl;
}