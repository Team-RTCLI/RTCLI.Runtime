#pragma once
#include "Config.hpp"

namespace RTCLI
{
	//! The result code type.
	using result_t = i32;

	// The error codes used by RTCLI.

	//! General success.
	constexpr result_t s_ok = 0;
	//! The operation is already done and it does not need to be done a second time.
	constexpr result_t s_already_done = 1;
	//! The specified element already exists so there is no need to add another time.
	constexpr result_t s_item_already_exists = 3;

	//! General failure.
	constexpr result_t e_failure = -1;
	//! The specified item does not exist.
	constexpr result_t e_not_found = -2;
	//! The specified item already exists.
	constexpr result_t e_already_exists = -3;
	//! Invalid arguments are specified.
	constexpr result_t e_bad_arguments = -4;
	//! The operation is invoked in improper time.
	constexpr result_t e_bad_calling_time = -5;
	//! Memory allocation failed.
	constexpr result_t e_bad_memory_alloc = -6;
	//! This operation is not supported, it is most possibly not implemented on the current build/platform.
	constexpr result_t e_not_supported = -7;
	//! A call to the underlying operating system is failed and the reason cannot be represented by any other
	//! result code.
	constexpr result_t e_bad_system_call = -8;
	//! The access to the file or resource is denied.
	constexpr result_t e_access_denied = -9;
	//! The specified path is not a directory, or one component of the path prefix of the specified path is not a directory.
	constexpr result_t e_not_directory = -10;
	//! The time limit is reached before the operation finishes.
	constexpr result_t e_timeout = -11;
	//! The provided data or string is too long.
	constexpr result_t e_data_too_long = -12;
	//! The memory buffer provided by the user is not large enough to contain all returned data.
	constexpr result_t e_insufficient_buffer = -13;
	//! The service provider is too busy to finish the request call.
	constexpr result_t e_busy = -14;
	//! The number or container overflows.
	constexpr result_t e_out_of_range = -15;
	//! Syntax error detected when parsing the string.
	constexpr result_t e_syntax_error = -16;
	//! The operation is canceled by user.
	constexpr result_t e_user_canceled = -17;

	inline constexpr bool succeeded(result_t res)
	{
		return res >= 0;
	}

	inline constexpr bool failed(result_t res)
	{
		return res < 0;
	}

	struct RTCLI_API uuid
    {
		union
		{
			char bytes[12];
		};
    };
	static_assert(sizeof(uuid) == sizeof(char) * 12, "uuid size error!");
}