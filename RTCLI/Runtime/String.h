#pragma once
#include "Object.h"

namespace RTCLI::System
{
	class RTCLI_API String : public Object
	{
	public:
        static String& Intern(const String& str) RTCLI_NOEXCEPT;
		static String& IsInterned(const String& str) RTCLI_NOEXCEPT;

		RTCLI_FORCEINLINE String(const NativeChar* str)
		{
			chars = RTCLI_STRING_FROM_NATIVE(str);
			length = RTCLI_STRING_LENGTH(chars);
		}
		RTCLI_FORCEINLINE String(NativeChar* str, i32 strlen)
		{
			chars = RTCLI_STRING_FROM_NATIVE(str);
			length = strlen;
		}

		System::Int32 get_Length() const RTCLI_NOEXCEPT;
		System::String& ToLower(void) const RTCLI_NOEXCEPT;
		System::String& ToUpper(void) const RTCLI_NOEXCEPT;

        ///< Length of string *excluding* the trailing null (which is included in 'chars').
		i32 length = 0; 
        Char* chars = nullptr;
	};
}