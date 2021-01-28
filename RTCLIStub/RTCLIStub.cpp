#define DLL_IMPLEMENTATION
#include <RTCLI.hpp>
#include <PIL.hpp>
#include <iostream>
#include <memory>
#include "CoreStub.hpp"

using namespace RTCLI::Stub;

namespace RTCLI
{
    RTCLI_DLL_EXPORT void init()
    {
        return CoreStub::init();
    }

    RTCLI_DLL_EXPORT void close()
    {
        return CoreStub::close();
    }

    RTCLI_DLL_EXPORT void frame()
    {
        return CoreStub::frame();
    }
}

namespace RTCLI
{
    void* memalloc(usize size, usize alignment)
    {
        return ::aligned_alloc(size, alignment);
    }

    void memfree(void* ptr, usize alignment)
    {
        return ::free(ptr);
    }

    void* memrealloc(void* ptr, usize size, usize alignment)
    {
        return ::realloc(ptr, size);
    }

    usize memsize(void* ptr, usize alignment)
    {
        return 0;
    }

    void output_debug_message(const c8* messgae)
    {
        std::cout << static_cast<const char*>(messgae) << std::endl;
    }
    
}

namespace RTCLI
{
    result_t open_file(const c8* path, EFileOpenMode mode, File** file)
    {
        return RTCLI::s_already_done;
    }

    void close_file(File* file)
    {
        return;
    }

    result_t seek_file(File* file, EFileSeekMode mode, i64 offset)
    {
        return RTCLI::s_already_done;
    }

    u64 tell_file(File* file)
    {
        return 0;
    }

    result_t read_file(File* file, void* buffer, usize sz, usize* size_read)
    {
        return RTCLI::s_already_done;
    }

    result_t write_file(File* file, const void* buffer, usize sz, usize* size_written)
    {
        return RTCLI::s_already_done;
    }
}