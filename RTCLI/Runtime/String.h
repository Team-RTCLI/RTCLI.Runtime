#pragma once
#include "Object.h"

namespace RTCLI::System
{
	class RTCLI_API String : public Object
	{
	public:
        static String& Intern(const String& str) RTCLI_NOEXCEPT;
		static String& IsInterned(const String& str) RTCLI_NOEXCEPT;

		RTCLI_FORCEINLINE String(const Char* str)
			:length(RTCLI_STRING_LENGTH(str)), chars(const_cast<Char*>(str))
		{

		}

        ///< Length of string *excluding* the trailing null (which is included in 'chars').
		i32 length = 0; 
        Char* chars = nullptr;
	};
}