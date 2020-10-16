#pragma once
#include <Base.hpp>

namespace RTCLI::CIL
{
    enum class StackBehaviour : RTCLI::u32
    {
        Pop0 = 0,
        Pop1 = 1,
        Pop1_pop1 = 2,
        Popi = 3,
        Popi_pop1 = 4,
        Popi_popi = 5,
        Popi_popi8 = 6,
        Popi_popi_popi = 7,
        Popi_popr4 = 8,
        Popi_popr8 = 9,
        Popref = 10,
        Popref_pop1 = 11,
        Popref_popi = 12,
        Popref_popi_popi = 13,
        Popref_popi_popi8 = 14,
        Popref_popi_popr4 = 15,
        Popref_popi_popr8 = 16,
        Popref_popi_popref = 17,
        PopAll = 18,
        Push0 = 19,
        Push1 = 20,
        Push1_push1 = 21,
        Pushi = 22,
        Pushi8 = 23,
        Pushr4 = 24,
        Pushr8 = 25,
        Pushref = 26,
        Varpop = 27,
        Varpush = 28
    };
}