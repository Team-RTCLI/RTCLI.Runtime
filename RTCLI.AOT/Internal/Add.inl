#include "RTCLI/Runtime/Exception.h"
#include "RTCLI/Traits.hpp"

namespace RTCLI
{
    template<typename T>
    typename std::enable_if_t<is_numeric_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Add(const T val1, const T val2) RTCLI_NOEXCEPT
    {
        return val1 + val2;
    }

    template<typename T>
    typename std::enable_if_t<is_numeric_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Add_Ovf(const T val1, const T val2) RTCLI_NOEXCEPT
    {
        std::cerr << "Add_Ovf Unimplemented!" << std::endl;
        if (false)
        {
            const OverflowException& e 
                = new_object<OverflowException>(nullptr, nullptr, nullptr).Get();
            RTCLI::Throw(e);
        }
        return val1 + val2;
    }

    template<typename T>
    typename std::enable_if_t<is_unsigned_v<T>, T>
    RTCLI_IL_FUNC /*T*/ Add_Ovf_Un(const T val1, const T val2) RTCLI_NOEXCEPT
    {
        std::cerr << "Add_Ovf_Un Unimplemented!" << std::endl;
        if (false)
        {
            const OverflowException& e = 
                new_object<OverflowException>(nullptr, nullptr, nullptr).Get();
            RTCLI::Throw(e);
        }
        return val1 + val2;
    }

}