#pragma once
#include "RTCLI/Base.hpp"

namespace RTCLI::System
{
    struct RTCLI_API VTable 
    {
        
    };
    
    struct RTCLI_API Type 
    {
        VTable table;
        uuid id;
    };
}