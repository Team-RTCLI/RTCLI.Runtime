#pragma once
#include "Base.hpp"

#ifndef RTCLI_PIL_API
#define RTCLI_PIL_API
#endif

// The Platform Independent Layer.
// The host program/game engine should implement all functions listed here to port RTCLI
// into your program / game engine.
namespace RTCLI
{
    //! Allocates memory blocks.
	//! @param[in] size The number of bytes you want to allocate. If this is 0, no memory will be allocated and the return value will be `nullptr`.
	//! @param[in] alignment Optional. The required alignment of the address of the allocated memory block. 
	//! 
	//! If this is 0 (default), then the memory is allocated with no additional alignment requirement. In such case, the memory is aligned to 
	//! times of 8 in 32-bit platform, and times of 16 in 64-bit platform. 
	//! 
	//! If this is not 0, then the memory is allocated with the specified alignment requirement satisfied. The alignment value must be powers
	//! of 2 (32, 64, 128, 256, etc).
	//! 
	//! Note that you shall use the same alignment value for the same memory block in `allocate`, `free`, `reallocate` and `size` function.
	//! 
	//! @return Returns a pointer to the first available memory address allocated, or `nullptr` if failed to allocate one from this allocator.
	RTCLI_PIL_API void* memalloc(usize size, usize alignment = 0);

	//! Frees memory blocks allocated by `memalloc` or `memrealloc`.
	//! @param[in] ptr The pointer returned by `allocate` or `reallocate` method. If this is `nullptr`, this function does nothing.
	//! @param[in] alignment Optional. The alignment requirement specified when allocating the memory block. Default is 0.
	RTCLI_PIL_API void memfree(void* ptr, usize alignment = 0);

	//! Reallocates memory blocks allocated from `memalloc`. This function allocates a new memory block with the specified size and alignment
	//! requirement, copies the data from the old memory block to the new one, and frees the old memory block with the specified alignment.
	//! 
	//! @param[in] ptr The pointer to the former allocated memory allocated by `memalloc` or `memrealloc`. This will be freed if new memory 
	//! is successfully allocated. If this parameter is `nullptr`, this method behaves the same as `memalloc`.
	//! @param[in] size The new number of bytes to allocate.
	//! @param[in] alignment Optional. The alignment requirement for the old memory block. See docs for `memalloc` for details.
	//! Default is 0. 
	//! 
	//! The new and old memory block must use the same alignment requirement, which is decided when the old memory block is allocated.
	//! @return Returns a pointer to the reallocated memory block. If the allocation is failed, returns `nullptr` and
	//! the old memory block (if have) is not changed.
	RTCLI_PIL_API void* memrealloc(void* ptr, usize size, usize alignment = 0);

	//! Gets the allocated size of the memory block allocated from this allocator. The returned size is the size that is available to the user for
	//! accessing. Note that the allocated size may be bigger than the size required to specify alignment and padding requirements.
	//! @param[in] ptr The pointer returned by `memalloc` or `memrealloc` method. 
	//! @param[in] alignment Optional. The alignment requirement specified for the memory block during allocation. See docs for `memalloc` 
	//! for details. Default is 0. 
	//! @return Returns the size of bytes of the memory block. If `ptr` is `nullptr`, the returned value is 0.
	RTCLI_PIL_API usize memsize(void* ptr, usize alignment = 0);

	//! Outputs debug messages, warnings and errors to the host program. This will only be called by RTCLI when the debug layer is enabled.
	//! @param[in] messgae The message to output. The message buffer is valid until this call returns.
	RTCLI_PIL_API void output_debug_message(const c8* messgae);

	//! File structure.
	//! The definition of this structure is provided by the host.
	struct File;

	enum class EFileOpenMode : u32
	{
		//! Opens one file for reading only. If the file does not exist, the call fails with `e_not_found`
		read_existing = 0,
		//! Opens one file for writing only. If the file already exists, its content will be discarded and the file is opened as a new created file.
		write_new = 1,
		//! Opens one file for reading and writing. If the file does not exist, it will be created; if the file already exists, it will be opened and its 
		//! content will be preserved
		//! for reading.
		read_write = 2
	};

	enum class EFileSeekMode : u32
	{
		begin = 0,
		current = 1,
		end = 2
	};

	//! Opens one file stream from the host's file system. The file pointer should be set to the first byte of the file when returned.
	//! @param[in] path The path of the file to open.
	//! @param[in] mode The desired file opening mode.
	//! @param[out] file The memory to receive the file structure pointer. If this call fails, `nullptr` should be stored.
	//! This argument will never be `nullptr`.
	//! @return Returns one of the following result codes:
	//! * s_ok
	//! * e_bad_arguments
	//! * e_access_denied
	//! * e_file_not_exist
	//! * e_bad_system_call for all errors that cannot be identified.
	RTCLI_PIL_API result_t open_file(const c8* path, EFileOpenMode mode, File** file);

	//! Closes the file stream opened by `open_file`.
	//! @param[in] file The file stream structure.
	RTCLI_PIL_API void close_file(File* file);

	//! Sets the file pointer of the file stream.
	//! @param[in] file The file stream structure.
	//! @param[in] mode The file seek mode.
	//! @param[in] offset The file seek offset relative to the reference point specified in `mode`.
	//! @return Returns one of the following result codes:
	//! * s_ok
	//! * e_out_of_range If `offset` is out of supported range.
	//! * e_access_denied
	//! * e_bad_system_call for all errors that cannot be identified.
	RTCLI_PIL_API result_t seek_file(File* file, EFileSeekMode mode, i64 offset);

	//! Tells the current position of the file pointer of the file stream.
	//! @param[in] file The file stream structure.
	//! @return Returns the position of the file pointer represented in number of bytes relative to the beginning of the file.
	RTCLI_PIL_API u64 tell_file(File* file);

	//! Reads binary data from file. The file pointer should advance `*size_read` bytes after this call.
	//! @param[in] file The file stream structure.
	//! @param[in] buffer The buffer used to receive the read data. The buffer should be at least `sz` bytes.
	//! @param[in] sz The size of the data to read in bytes.
	//! @param[out] size_read If this is not `nullptr`, the actual read size will be stored to this parameter.
	//! @return Returns one of the following result codes:
	//! * s_ok
	//! * e_not_supported If the file stream is not opened in a readable mode.
	//! * e_bad_system_call for all errors that cannot be identified.
	RTCLI_PIL_API result_t read_file(File* file, void* buffer, usize sz, usize* size_read);

	//! Writes binary data to file. The file pointer should advance `*size_write` bytes after this call.
	//! @param[in] file The file stream structure.
	//! @param[in] buffer The buffer used to provide the data to be write. The buffer should be at least `sz` bytes.
	//! @param[in] sz The size of the data to write in bytes.
	//! @param[out] size_written If this is not `nullptr`, the actual written size will be stored to this parameter.
	//! @return Returns one of the following result codes:
	//! * s_ok
	//! * e_data_too_long
	//! * e_bad_system_call for all errors that cannot be identified.
	RTCLI_PIL_API result_t write_file(File* file, const void* buffer, usize sz, usize* size_written);


}