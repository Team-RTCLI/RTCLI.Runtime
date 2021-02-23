#include <iostream>
#include <RTCLI/RTCLI.hpp>
#include "RTCLI/Runtime/IComparable.h"
#include "RTCLI/Runtime/ValueType.h"

class Com : RTCLI::System::Object, RTCLI::System::IComparable_1<Com>
{
public:
    RTCLI::System::Boolean CompareTo(RTCLI::TRef<Com> other) override
    {
        return this->val == other.Get().val;
    }
    int val = 0;
};

struct Fuck
{
    RTCLI::System::Boolean CompareTo(Fuck other) 
    {
        return this->val == other.val;
    }
    int val = 1;
};

struct Fuck_v : RTCLI::System::ValueType, RTCLI::System::IComparable_1<Fuck_v>
{
    Fuck ent;
    RTCLI::System::Boolean CompareTo(RTCLI::TRef<Fuck_v> other) override
    {
        return ent.CompareTo(other.Get().ent);
    }
};


int main()
{
    RTCLI::init();

    if constexpr (!RTCLI::is_unsigned_v<RTCLI::u32>)
    {
        std::cerr << "RTCLI::is_unsigned error!" << std::endl;
    }

    if (RTCLI::Cgt_Un(0u, 1u) != 0 || RTCLI::Cgt_Un(1u, 0u) != 1)
    {
        std::cerr << "RTCLI::Cgt_Un error!" << std::endl;
    }

    if (RTCLI::Add(2u, 12u) != 14u)
    {
        std::cerr << "RTCLI::Add error!" << std::endl;
    }

    if (RTCLI::StaticCast<RTCLI::i32>(0u) != 0)
    {
        std::cerr << "RTCLI::StaticCast error!" << std::endl;
    }

    if (RTCLI::StaticCast<RTCLI::Int32>(0u) != 0)
    {
        std::cerr << "RTCLI::StaticCast error!" << std::endl;
    }

    Com a; a.val = 1;
    Com b; b.val = 2;
    if(a.CompareTo(b))
    {
        std::cerr << "CompareTo Error!" << std::endl;
    }
    Fuck f1; f1.val = 1;
    Fuck f2; f2.val = 2;

    RTCLI::frame();
    RTCLI::close();
    
    return 0;
}