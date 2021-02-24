#include "RTCLI/RTCLI.hpp"

int main(void)
{
    using namespace RTCLI;

    //******** TEST EMPTY INITIALIZE ********//
    System::Object object = null;
    if(!object.isNull())  
    {
        std::cerr << "object should be null!" << std::endl;
    }
    
    //******** TEST EMPTY MANAGED INITIALIZE ********//
    Managed<System::Object> managed = null;
    if(!managed.Get().isNull())  
    {
        std::cerr << "managed should be null!" << std::endl;
    }
    
    //******** TEST TREF INITIALIZE ********//
    TRef<System::Object> ref = null;
    if(!ref.Get().isNull())  
    {
        std::cerr << "ref should be null!" << std::endl;
    }

    std::cout << "Test Finished!" << std::endl;
    return 0;
}