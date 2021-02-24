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

    std::cout << "Test Finished!" << std::endl;
    return 0;
}