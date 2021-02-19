#include <RTCLI/RTCLI.hpp>
#include "TestSystem.h"

#pragma warning(push)
#pragma warning(disable: 4102)

//RTCLI::RTCLITestCase::TestSystem::TestInnerClass::Constructor
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_TestInnerClass_Constructor__Stack
{
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::TestInnerClass::Constructor(RTCLI::System::Int32 id)
{
	RTCLI_RTCLITestCase_TestSystem_TestInnerClass_Constructor__Stack stack;
	stack.Init<false>();
	// IL_0000: ldarg.0
IL_0000: auto& s0 = *this;
	// IL_0001: call System.Void System.Object::.ctor()
IL_0001: ((RTCLI::System::Object&)s0).RTCLI::System::Object::Constructor();
	// IL_0006: nop
IL_0006: RTCLI::nop();
	// IL_0007: nop
IL_0007: RTCLI::nop();
	// IL_0008: ldarg.0
IL_0008: auto& s1 = *this;
	// IL_0009: ldarg.1
IL_0009: auto& s2 = id;
	// IL_000a: stfld System.Int32 RTCLITestCase.TestSystem/TestInnerClass::<ID>k__BackingField
IL_000a: s1._ID_k__BackingField = s2;
	// IL_000f: ret
IL_000f: return;
}

//RTCLI::RTCLITestCase::TestSystem::TestInnerClass::CallTest
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_TestInnerClass_CallTest__Stack
{
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::TestInnerClass::CallTest(RTCLI::System::Int32 u)
{
	RTCLI_RTCLITestCase_TestSystem_TestInnerClass_CallTest__Stack stack;
	stack.Init<false>();
	// IL_0000: nop
IL_0000: RTCLI::nop();
	// IL_0001: ldstr "Call Test"
IL_0001: const char* s0 = "Call Test";
	// IL_0006: call System.Void System.Console::WriteLine(System.String)
IL_0006: RTCLI::System::Console::WriteLine(s0);
	// IL_000b: nop
IL_000b: RTCLI::nop();
	// IL_000c: br.s IL_000e
IL_000c: goto IL_000e;
	// IL_000e: ret
IL_000e: return;
}

//RTCLI::RTCLITestCase::TestSystem::TestInnerClass::CallTestF
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_TestInnerClass_CallTestF__Stack
{
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::TestInnerClass::CallTestF(RTCLI::System::Single u)
{
	RTCLI_RTCLITestCase_TestSystem_TestInnerClass_CallTestF__Stack stack;
	stack.Init<false>();
	// IL_0000: nop
IL_0000: RTCLI::nop();
	// IL_0001: ldstr "Call Test F"
IL_0001: const char* s0 = "Call Test F";
	// IL_0006: call System.Void System.Console::WriteLine(System.String)
IL_0006: RTCLI::System::Console::WriteLine(s0);
	// IL_000b: nop
IL_000b: RTCLI::nop();
	// IL_000c: br.s IL_000e
IL_000c: goto IL_000e;
	// IL_000e: ret
IL_000e: return;
}

//RTCLI::RTCLITestCase::TestSystem::TestInnerClass::get_ID
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_TestInnerClass_get_ID__Stack
{
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Int32 RTCLI::RTCLITestCase::TestSystem::TestInnerClass::get_ID()
{
	RTCLI_RTCLITestCase_TestSystem_TestInnerClass_get_ID__Stack stack;
	stack.Init<false>();
	// IL_0000: ldarg.0
IL_0000: auto& s0 = *this;
	// IL_0001: ldfld System.Int32 RTCLITestCase.TestSystem/TestInnerClass::<ID>k__BackingField
IL_0001: auto& s1 = s0._ID_k__BackingField;
	// IL_0006: ret
IL_0006: return s1;
}

//RTCLI::RTCLITestCase::TestSystem::Constructor
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_Constructor__Stack
{
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::Constructor(RTCLI::System::Int32 val)
{
	RTCLI_RTCLITestCase_TestSystem_Constructor__Stack stack;
	stack.Init<false>();
	// IL_0000: ldarg.0
IL_0000: auto& s0 = *this;
	// IL_0001: call System.Void System.Object::.ctor()
IL_0001: ((RTCLI::System::Object&)s0).RTCLI::System::Object::Constructor();
	// IL_0006: nop
IL_0006: RTCLI::nop();
	// IL_0007: nop
IL_0007: RTCLI::nop();
	// IL_0008: ret
IL_0008: return;
}

//RTCLI::RTCLITestCase::TestSystem::op_Addition
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_op_Addition__Stack
{
	RTCLI::RTCLITestCase::TestSystem& v0 = (RTCLI::RTCLITestCase::TestSystem&)RTCLI::null;
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::RTCLITestCase::TestSystem RTCLI::RTCLITestCase::TestSystem::op_Addition(RTCLI::RTCLITestCase::TestSystem& b, RTCLI::RTCLITestCase::TestSystem& c)
{
	RTCLI_RTCLITestCase_TestSystem_op_Addition__Stack stack;
	stack.Init<true>();
	// IL_0000: nop
IL_0000: RTCLI::nop();
	// IL_0001: ldarg.0
IL_0001: auto& s0 = *this;
	// IL_0002: stloc.0
IL_0002: stack.v0 = s0;
	// IL_0003: br.s IL_0005
IL_0003: goto IL_0005;
	// IL_0005: ldloc.0
IL_0005: auto& s1 = stack.v0;
	// IL_0006: ret
IL_0006: return s1;
}

//RTCLI::RTCLITestCase::TestSystem::MethodWithArgsAccess
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_MethodWithArgsAccess__Stack
{
	RTCLI::RTCLITestCase::TestSystem::TestInnerClass& v0 = (RTCLI::RTCLITestCase::TestSystem::TestInnerClass&)RTCLI::null;
	RTCLI::System::Int32 v1 = RTCLI::System::Int32();
	RTCLI::RTCLITestCase::TestSystem::TestInnerClass& v2 = (RTCLI::RTCLITestCase::TestSystem::TestInnerClass&)RTCLI::null;
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::MethodWithArgsAccess(RTCLI::System::Int32 argInt, RTCLI::RTCLITestCase::TestSystem::TestInnerClass& argClass)
{
	RTCLI_RTCLITestCase_TestSystem_MethodWithArgsAccess__Stack stack;
	stack.Init<true>();
	// IL_0000: nop
IL_0000: RTCLI::nop();
	// IL_0001: ldarg.1
IL_0001: auto& s0 = argInt;
	// IL_0002: stloc.1
IL_0002: stack.v1 = s0;
	// IL_0003: ldarg.2
IL_0003: auto& s1 = argClass;
	// IL_0004: stloc.2
IL_0004: stack.v2 = s1;
	// IL_0005: ret
IL_0005: return;
}

//RTCLI::RTCLITestCase::TestSystem::get_prop
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_get_prop__Stack
{
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Single RTCLI::RTCLITestCase::TestSystem::get_prop()
{
	RTCLI_RTCLITestCase_TestSystem_get_prop__Stack stack;
	stack.Init<false>();
	// IL_0000: ldarg.0
IL_0000: auto& s0 = *this;
	// IL_0001: ldfld System.Single RTCLITestCase.TestSystem::<prop>k__BackingField
IL_0001: auto& s1 = s0._prop_k__BackingField;
	// IL_0006: ret
IL_0006: return s1;
}

//RTCLI::RTCLITestCase::TestSystem::set_prop
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_set_prop__Stack
{
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::set_prop(RTCLI::System::Single value)
{
	RTCLI_RTCLITestCase_TestSystem_set_prop__Stack stack;
	stack.Init<false>();
	// IL_0000: ldarg.0
IL_0000: auto& s0 = *this;
	// IL_0001: ldarg.1
IL_0001: auto& s1 = value;
	// IL_0002: stfld System.Single RTCLITestCase.TestSystem::<prop>k__BackingField
IL_0002: s0._prop_k__BackingField = s1;
	// IL_0007: ret
IL_0007: return;
}

//RTCLI::RTCLITestCase::TestSystem::MethodWithArgsOps
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_MethodWithArgsOps__Stack
{
	RTCLI::System::Int32 v0 = RTCLI::System::Int32();
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::MethodWithArgsOps(RTCLI::System::Int32 arg0, RTCLI::System::Int32 arg1)
{
	RTCLI_RTCLITestCase_TestSystem_MethodWithArgsOps__Stack stack;
	stack.Init<true>();
	// IL_0000: nop
IL_0000: RTCLI::nop();
	// IL_0001: ldarg.1
IL_0001: auto& s0 = arg0;
	// IL_0002: ldarg.2
IL_0002: auto& s1 = arg1;
	// IL_0003: add
IL_0003: auto s2 = RTCLI::Add(s0, s1);
	// IL_0004: stloc.0
IL_0004: stack.v0 = s2;
	// IL_0005: ldloc.0
IL_0005: auto& s3 = stack.v0;
	// IL_0006: ldarg.1
IL_0006: auto& s4 = arg0;
	// IL_0007: sub
IL_0007: auto s5 = RTCLI::Sub(s3, s4);
	// IL_0008: stloc.0
IL_0008: stack.v0 = s5;
	// IL_0009: ret
IL_0009: return;
}

//RTCLI::RTCLITestCase::TestSystem::MethodWithArgsFieldAccess
//[2-1] Here Begins Stack Declaration
struct RTCLI_RTCLITestCase_TestSystem_MethodWithArgsFieldAccess__Stack
{
	RTCLI::System::Int32 v0 = RTCLI::System::Int32();
	RTCLI::System::Int32 v1 = RTCLI::System::Int32();
	RTCLI::System::Int32 v2 = RTCLI::System::Int32();
	template<bool InitLocals> static void Init() {};//Active with MethodBody.InitLocals Property.
};

//[2-2] Here Begins Method Body
RTCLI::System::Void RTCLI::RTCLITestCase::TestSystem::MethodWithArgsFieldAccess(RTCLI::System::Int32 argInt, RTCLI::RTCLITestCase::TestSystem::TestInnerClass& argClass)
{
	RTCLI_RTCLITestCase_TestSystem_MethodWithArgsFieldAccess__Stack stack;
	stack.Init<true>();
	// IL_0000: nop
IL_0000: RTCLI::nop();
	// IL_0001: ldc.i4 11111111
IL_0001: RTCLI::System::Int32 s0 = RTCLI::StaticCast<RTCLI::System::Int32>(11111111);
	// IL_0006: stloc.0
IL_0006: stack.v0 = s0;
	// IL_0007: ldc.i4 11111111
IL_0007: RTCLI::System::Int32 s1 = RTCLI::StaticCast<RTCLI::System::Int32>(11111111);
	// IL_000c: stloc.1
IL_000c: stack.v1 = s1;
	// IL_000d: ldloc.0
IL_000d: auto& s2 = stack.v0;
	// IL_000e: ldloc.1
IL_000e: auto& s3 = stack.v1;
	// IL_000f: add
IL_000f: auto s4 = RTCLI::Add(s2, s3);
	// IL_0010: stloc.2
IL_0010: stack.v2 = s4;
	// IL_0011: ldarg.2
IL_0011: auto& s5 = argClass;
	// IL_0012: ldc.i4.s 9
IL_0012: RTCLI::System::Int32 s6 = RTCLI::StaticCast<RTCLI::System::Int32>(9);
	// IL_0014: callvirt System.Void RTCLITestCase.TestSystem/TestInnerClass::CallTest(System.Int32)
IL_0014: ((RTCLI::RTCLITestCase::TestSystem::TestInnerClass&)s5).CallTest(s6);
	// IL_0019: nop
IL_0019: RTCLI::nop();
	// IL_001a: ldarg.2
IL_001a: auto& s7 = argClass;
	// IL_001b: ldc.r4 9
IL_001b: RTCLI::System::Single s8 = RTCLI::StaticCast<RTCLI::System::Single>(9);
	// IL_0020: callvirt System.Void RTCLITestCase.TestSystem/TestInnerClass::CallTestF(System.Single)
IL_0020: ((RTCLI::RTCLITestCase::TestSystem::TestInnerClass&)s7).CallTestF(s8);
	// IL_0025: nop
IL_0025: RTCLI::nop();
	// IL_0026: ret
IL_0026: return;
}


#pragma warning(pop)