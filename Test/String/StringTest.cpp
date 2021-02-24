#include "RTCLI/RTCLI.hpp"

int main(void)
{
    using namespace RTCLI;
    //******** TEST NATIVE STRING ********//
    System::String string = null;
    if(!string.isNull())  
    {
        std::cerr << "string should be null!" << std::endl;
    }

    Managed<System::String> managed = 
        new_object<System::String>(RTCLI_NATIVE_STRING("Managed String Created!"));
    System::Console::WriteLine(managed);

    std::cout << "Test Finished!" << std::endl;
    return 0;
}