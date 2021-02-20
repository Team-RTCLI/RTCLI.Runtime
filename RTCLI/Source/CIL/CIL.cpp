#define DLL_IMPLEMENTATION

#include "RTCLI/CIL/OpCodes.h"
#include <vector>
#include <assert.h>
#include <string>
#include <unordered_map>

namespace Internal
{
    #define X(a, b) #a, 
        static const std::vector<std::string> CodeStrings = { CODES };
    #undef X

    #define X(a, b) {#a, RTCLI::CIL::Code::a}, 
        static const std::unordered_map<std::string, RTCLI::CIL::Code> CodeMap = { CODES };
    #undef X
}

namespace RTCLI::CIL
{
    RTCLI_DLLEXPORT RTCLI::CIL::Code CodeFromString(const char* name) RTCLI_NOEXCEPT
    {
        if(Internal::CodeMap.find(name) == Internal::CodeMap.end())
        {
            assert(0 && "FATAL_ERROR: No CIL Code with this name!");
            return RTCLI::CIL::Code::Nop;
        }
        return Internal::CodeMap.find(name)->second;
    }

    RTCLI_DLLEXPORT const char* ToString(const RTCLI::CIL::Code code) RTCLI_NOEXCEPT
    {
        auto index = static_cast<u32>(code);
        if(index >= Internal::CodeStrings.size())
        {
            assert(0 && "FATAL_ERROR: UNKNOWN CIL Code!");
            return "NONE";
        }
        return Internal::CodeStrings[index].c_str();
    }
}

#undef DLL_IMPLEMENTATION