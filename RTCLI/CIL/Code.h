#pragma once
#include <Base.hpp>
#include <assert.h>

#define CODES \
    X(Nop, 0) \
    X(Break, 1) \
    X(Ldarg_0, 2) \
    X(Ldarg_1, 3) \
    X(Ldarg_2, 4) \
    X(Ldarg_3, 5) \
    X(Ldloc_0, 6) \
    X(Ldloc_1, 7) \
    X(Ldloc_2, 8) \
    X(Ldloc_3, 9) \
    X(Stloc_0, 10) \
    X(Stloc_1, 11) \
    X(Stloc_2, 12) \
    X(Stloc_3, 13) \
    X(Ldarg_S, 14) \
    X(Ldarga_S, 15) \
    X(Starg_S, 16) \
    X(Ldloc_S, 17) \
    X(Ldloca_S, 18) \
    X(Stloc_S, 19) \
    X(Ldnull, 20) \
    X(Ldc_I4_M1, 21) \
    X(Ldc_I4_0, 22) \
    X(Ldc_I4_1, 23) \
    X(Ldc_I4_2, 24) \
    X(Ldc_I4_3, 25) \
    X(Ldc_I4_4, 26) \
    X(Ldc_I4_5, 27) \
    X(Ldc_I4_6, 28) \
    X(Ldc_I4_7, 29) \
    X(Ldc_I4_8, 30) \
    X(Ldc_I4_S, 31) \
    X(Ldc_I4, 32) \
    X(Ldc_I8, 33) \
    X(Ldc_R4, 34) \
    X(Ldc_R8, 35) \
    X(Dup, 36) \
    X(Pop, 37) \
    X(Jmp, 38) \
    X(Call, 39) \
    X(Calli, 40) \
    X(Ret, 41) \
    X(Br_S, 42) \
    X(Brfalse_S, 43) \
    X(Brtrue_S, 44) \
    X(Beq_S, 45) \
    X(Bge_S, 46) \
    X(Bgt_S, 47) \
    X(Ble_S, 48) \
    X(Blt_S, 49) \
    X(Bne_Un_S, 50) \
    X(Bge_Un_S, 51) \
    X(Bgt_Un_S, 52) \
    X(Ble_Un_S, 53) \
    X(Blt_Un_S, 54) \
    X(Br, 55) \
    X(Brfalse, 56) \
    X(Brtrue, 57) \
    X(Beq, 58) \
    X(Bge, 59) \
    X(Bgt, 60) \
    X(Ble, 61) \
    X(Blt, 62) \
    X(Bne_Un, 63) \
    X(Bge_Un, 64) \
    X(Bgt_Un, 65) \
    X(Ble_Un, 66) \
    X(Blt_Un, 67) \
    X(Switch, 68) \
    X(Ldind_I1, 69) \
    X(Ldind_U1, 70) \
    X(Ldind_I2, 71) \
    X(Ldind_U2, 72) \
    X(Ldind_I4, 73) \
    X(Ldind_U4, 74) \
    X(Ldind_I8, 75) \
    X(Ldind_I, 76) \
    X(Ldind_R4, 77) \
    X(Ldind_R8, 78) \
    X(Ldind_Ref, 79) \
    X(Stind_Ref, 80) \
    X(Stind_I1, 81) \
    X(Stind_I2, 82) \
    X(Stind_I4, 83) \
    X(Stind_I8, 84) \
    X(Stind_R4, 85) \
    X(Stind_R8, 86) \
    X(Add, 87) \
    X(Sub, 88) \
    X(Mul, 89) \
    X(Div, 90) \
    X(Div_Un, 91) \
    X(Rem, 92) \
    X(Rem_Un, 93) \
    X(And, 94) \
    X(Or, 95) \
    X(Xor, 96) \
    X(Shl, 97) \
    X(Shr, 98) \
    X(Shr_Un, 99) \
    X(Neg, 100) \
    X(Not, 101) \
    X(Conv_I1, 102) \
    X(Conv_I2, 103) \
    X(Conv_I4, 104) \
    X(Conv_I8, 105) \
    X(Conv_R4, 106) \
    X(Conv_R8, 107) \
    X(Conv_U4, 108) \
    X(Conv_U8, 109) \
    X(Callvirt, 110) \
    X(Cpobj, 111) \
    X(Ldobj, 112) \
    X(Ldstr, 113) \
    X(Newobj, 114) \
    X(Castclass, 115) \
    X(Isinst, 116) \
    X(Conv_R_Un, 117) \
    X(Unbox, 118) \
    X(Throw, 119) \
    X(Ldfld, 120)  \
    X(Ldflda, 121) \
    X(Stfld, 122) \
    X(Ldsfld, 123) \
    X(Ldsflda, 124) \
    X(Stsfld, 125) \
    X(Stobj, 126) \
    X(Conv_Ovf_I1_Un, 127) \
    X(Conv_Ovf_I2_Un, 128) \
    X(Conv_Ovf_I4_Un, 129) \
    X(Conv_Ovf_I8_Un, 130) \
    X(Conv_Ovf_U1_Un, 131) \
    X(Conv_Ovf_U2_Un, 132) \
    X(Conv_Ovf_U4_Un, 133) \
    X(Conv_Ovf_U8_Un, 134) \
    X(Conv_Ovf_I_Un, 135) \
    X(Conv_Ovf_U_Un, 136) \
    X(Box, 137) \
    X(Newarr, 138) \
    X(Ldlen, 139) \
    X(Ldelema, 140) \
    X(Ldelem_I1, 141) \
    X(Ldelem_U1, 142) \
    X(Ldelem_I2, 143) \
    X(Ldelem_U2, 144) \
    X(Ldelem_I4, 145) \
    X(Ldelem_U4, 146) \
    X(Ldelem_I8, 147) \
    X(Ldelem_I, 148) \
    X(Ldelem_R4, 149) \
    X(Ldelem_R8, 150) \
    X(Ldelem_Ref, 151) \
    X(Stelem_I, 152) \
    X(Stelem_I1, 153) \
    X(Stelem_I2, 154) \
    X(Stelem_I4, 155) \
    X(Stelem_I8, 156) \
    X(Stelem_R4, 157) \
    X(Stelem_R8, 158) \
    X(Stelem_Ref, 159) \
    X(Ldelem_Any, 160) \
    X(Stelem_Any, 161) \
    X(Unbox_Any, 162) \
    X(Conv_Ovf_I1, 163) \
    X(Conv_Ovf_U1, 164) \
    X(Conv_Ovf_I2, 165) \
    X(Conv_Ovf_U2, 166) \
    X(Conv_Ovf_I4, 167) \
    X(Conv_Ovf_U4, 168) \
    X(Conv_Ovf_I8, 169) \
    X(Conv_Ovf_U8, 170) \
    X(Refanyval, 171) \
    X(Ckfinite, 172) \
    X(Mkrefany, 173) \
    X(Ldtoken, 174) \
    X(Conv_U2, 175) \
    X(Conv_U1, 176) \
    X(Conv_I, 177) \
    X(Conv_Ovf_I, 178) \
    X(Conv_Ovf_U, 179) \
    X(Add_Ovf, 180) \
    X(Add_Ovf_Un, 181) \
    X(Mul_Ovf, 182) \
    X(Mul_Ovf_Un, 183) \
    X(Sub_Ovf, 184) \
    X(Sub_Ovf_Un, 185) \
    X(Endfinally, 186) \
    X(Leave, 187) \
    X(Leave_S, 188) \
    X(Stind_I, 189) \
    X(Conv_U, 190) \
    X(Arglist, 191) \
    X(Ceq, 192) \
    X(Cgt, 193) \
    X(Cgt_Un, 194) \
    X(Clt, 195) \
    X(Clt_Un, 196) \
    X(Ldftn, 197) \
    X(Ldvirtftn, 198) \
    X(Ldarg, 199) \
    X(Ldarga, 200) \
    X(Starg, 201) \
    X(Ldloc, 202) \
    X(Ldloca, 203) \
    X(Stloc, 204) \
    X(Localloc, 205) \
    X(Endfilter, 206) \
    X(Unaligned, 207) \
    X(Volatile, 208) \
    X(Tail, 209) \
    X(Initobj, 210) \
    X(Constrained, 211) \
    X(Cpblk, 212) \
    X(Initblk, 213) \
    X(No, 214) \
    X(Rethrow, 215) \
    X(Sizeof, 216) \
    X(Refanytype, 217) \
    X(Readonly, 218) 

namespace RTCLI::CIL
{
#define X(a, b) a=b,
    enum class Code : RTCLI::u32 { CODES };
#undef X

namespace Internal
{
    #define X(a, b) #a, 
        static const RTCLI::vector<RTCLI::string> CodeStrings = { CODES };
    #undef X

    #define X(a, b) {#a, RTCLI::CIL::Code::a}, 
        static const RTCLI::unordered_map<RTCLI::string, RTCLI::CIL::Code> CodeMap = { CODES };
    #undef X
}

    RTCLI_INLINE RTCLI::CIL::Code CodeFromString(const RTCLI::string& name) RTCLI_NOEXCEPT
    {
        if(Internal::CodeMap.find(name) == Internal::CodeMap.end())
        {
            assert(0 && "FATAL_ERROR: No CIL Code with this name!");
            return RTCLI::CIL::Code::Nop;
        }
        return Internal::CodeMap.find(name)->second;
    }

    RTCLI_INLINE RTCLI::string_view ToString(const RTCLI::CIL::Code code) RTCLI_NOEXCEPT
    {
        auto index = static_cast<u32>(code);
        if(index >= Internal::CodeStrings.size())
        {
            assert(0 && "FATAL_ERROR: UNKNOWN CIL Code!");
            return "NONE";
        }
        return Internal::CodeStrings[index];
    }
}
#undef CODES