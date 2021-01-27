#pragma once

namespace RTCLI
{
    namespace Stub
    {
        class CoreStub
        {
        public:
            static void init();
            static void close();
            static void frame();
        };
    }
}