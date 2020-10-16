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
	//! @param[in] addr The pointer returned by `allocate` or `reallocate` method. If this is `nullptr`, this function does nothing.
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
}

namespace RTCLI
{
	//! vm object
	struct object {};

	//! vm method
	struct method {};

	//! a frame with parameters / return address / local variables of method-call.
	struct record_frame {};

	//! frame_stack / call_stack
	//! a record_frame will be pushed at each method call.
	//! frame will be poped once the method-call ends.  
	struct frame_stack 
	{
		RTCLI_PIL_API virtual bool enque_frame(record_frame&) RTCLI_NOEXCEPT = 0;
	};

	struct cli_machine
	{
		
	};

	//! calls a VM method
	RTCLI_PIL_API object call(cli_machine& vm, object& caller, method& mtd, record_frame& frame) RTCLI_NOEXCEPT;

	RTCLI_PIL_API void nop(cli_machine& vm, frame_stack& stack) RTCLI_NOEXCEPT;

}

namespace RTCLI::DesignCase
{
	struct hello_world_stack_frame final : public RTCLI::record_frame
	{
		string str;
	};

	void hello_world_marshal(hello_world_stack_frame& sf)
	{
		return hello_world(sf.str);
	}

	void hello_world(string)
	{

	}

	// IL:
	// IL_XXXX: ldstr "hello_world!"
	// IL_XXXX: stloc.0
	// IL_XXXX: ldloc.0
	// IL_XXXX: call hello_world(float, string)
	// Interpreter =>
	// string param = vm.ld("hello_world");    // from vm.managed_memory
	// stack_frame& sf = ld(param);		// load param to stack_frame
	// call(vm, null, "hello_world", sf);	//
}