#pragma once
#include "Internal/StackBehaviour.h"
#include "Internal/Code.h"
#include "RTCLI/Base.hpp"

namespace RTCLI::CIL
{
    enum class OpCodeType : RTCLI::u32 
    {
        Annotation = 0,
        Macro = 1,
        Nternal = 2,
        Objmodel = 3,
        Prefix = 4,
        Primitive = 5
    };

    enum class FlowControl : RTCLI::u32 
    {
        Branch = 0,
        Break = 1,
        Call = 2,
        Cond_Branch = 3,
        Meta = 4,
        Next = 5,
        Phi = 6,
        Return = 7,
        Throw = 8
    };

    struct OpCode
    {
        OpCode() = default;
        ~OpCode() = default;

        RTCLI_FORCEINLINE const char* Name(void) const RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE RTCLI::usize Size(void) const RTCLI_NOEXCEPT;

        RTCLI_FORCEINLINE Code Code(void) const RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE RTCLI::i16 Value(void) const RTCLI_NOEXCEPT;

        RTCLI_FORCEINLINE RTCLI::u8 Op1(void) const RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE RTCLI::u8 Op2(void) const RTCLI_NOEXCEPT;

        RTCLI_FORCEINLINE StackBehaviour StackBehaviourPop(void) const RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE StackBehaviour StackBehaviourPush(void) const RTCLI_NOEXCEPT;

        RTCLI_FORCEINLINE OpCodeType OpCodeType(void) const RTCLI_NOEXCEPT;
        RTCLI_FORCEINLINE FlowControl FlowControl(void) const RTCLI_NOEXCEPT;

        bool operator==(const OpCode& rhs) RTCLI_NOEXCEPT;
    };
}