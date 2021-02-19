#include "TestSystem.h"

int main()
{
    auto& obj = *RTCLI::new_object<RTCLI::RTCLITestCase::TestSystem>(12);
    auto& inner_obj = *RTCLI::new_object<RTCLI::RTCLITestCase::TestSystem::TestInnerClass>(1);

    obj.MethodWithArgsFieldAccess(12, inner_obj);

    return 0;
}