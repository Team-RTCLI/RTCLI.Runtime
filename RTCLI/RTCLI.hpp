//! The Native Interface of RTCLI.
//! You only need to include this file in order to use RTCLI.
#pragma once
#include "Runtime/Object.h"

#ifndef RTCLI_API
#define RTCLI_API RTCLI_DLLVISIBLE
#endif

namespace RTCLI
{
    using Object = Runtime::Object;
    
    //! Initializes RTCLI.
    RTCLI_API void init();

    //! Closes RTCLI.
    RTCLI_API void close();

    //! Advances the state of RTCLI into next frame.
    RTCLI_API void frame();
}