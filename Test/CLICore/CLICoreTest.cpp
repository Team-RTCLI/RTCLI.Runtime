#include <iostream>
#include <RTCLI/RTCLI.hpp>

int main()
{
    RTCLI::init();

    if constexpr (!RTCLI::is_unsigned_v<RTCLI::u32>)
    {
        std::cerr << "RTCLI::is_unsigned error!" << std::endl;
    }

    if (RTCLI::Cgt_Un(0u, 1u) != 0 || RTCLI::Cgt_Un(1u, 0u) != 1)
    {
        std::cerr << "RTCLI::Cgt_Un error!" << std::endl;
    }

    if (RTCLI::Add(2u, 12u) != 14u)
    {
        std::cerr << "RTCLI::Add error!" << std::endl;
    }

    if (RTCLI::StaticCast<RTCLI::i32>(0u) != 0)
    {
        std::cerr << "RTCLI::StaticCast error!" << std::endl;
    }

    if (RTCLI::StaticCast<RTCLI::Int32>(0u) != 0)
    {
        std::cerr << "RTCLI::StaticCast error!" << std::endl;
    }

    RTCLI::frame();
    RTCLI::close();
    
    return 0;
}