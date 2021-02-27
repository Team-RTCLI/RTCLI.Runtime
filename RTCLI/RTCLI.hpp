//! The Native Interface of RTCLI.
//! You only need to include this file in order to use RTCLI.
#pragma once
#include "Runtime/Int.h"
#include "Runtime/Single.h"
#include "Runtime/Boolean.h"
#include "Runtime/Array.h"
#include "Runtime/Delegate.h"

#include "Runtime/IL.h"

#include "Runtime/String.h"

#include "Runtime/Console/Write.h"
#include "Runtime/IComparable.h"
#include "Runtime/IConvertible.h"
#include "Runtime/IEquatable.h"

#ifndef RTCLI_API
#define RTCLI_API RTCLI_DLLVISIBLE
#endif

namespace RTCLI
{
    using Int32 = System::Int32;
    using Int64 = System::Int64;
    using Object = System::Object;
    
    //! Initializes RTCLI.
    RTCLI_API void init();

    //! Closes RTCLI.
    RTCLI_API void close();

    //! Advances the state of RTCLI into next frame.
    RTCLI_API void frame();
}