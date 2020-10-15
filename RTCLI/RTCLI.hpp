//! The Native Interface of RTCLI.
//! You only need to include this file in order to use RTCLI.
#pragma once
#include "Base.hpp"

#ifndef RTCLI_API
#define RTCLI_API
#endif

namespace RTCLI
{
    //! Initiailizes RTCLI.
    RTCLI_API void init();

    //! Closes RTCLI.
    RTCLI_API void close();

    //! Advances the state of RTCLI into next frame.
    RTCLI_API void frame();

    
}