#include <RTCLI/RTCLI.hpp>

namespace RTCLI::RTCLITestCase
{
	class TestSystem : public RTCLI::System::Object
	{
	public:
		class TestInnerClass : public RTCLI::System::Object
		{
		public:
			RTCLI::System::Void Constructor(RTCLI::System::Int32 id);
			RTCLI::System::Void CallTest(RTCLI::System::Int32 u);
			RTCLI::System::Void CallTestF(RTCLI::System::Single u);
			RTCLI::System::Int32 get_ID();
			RTCLI::System::Int32 _ID_k__BackingField;
		};
		RTCLI::System::Void Constructor(RTCLI::System::Int32 val);
		RTCLI::RTCLITestCase::TestSystem op_Addition(RTCLI::RTCLITestCase::TestSystem& b, RTCLI::RTCLITestCase::TestSystem& c);
		RTCLI::System::Void MethodWithArgsAccess(RTCLI::System::Int32 argInt, RTCLI::RTCLITestCase::TestSystem::TestInnerClass& argClass);
		RTCLI::System::Single get_prop();
		RTCLI::System::Void set_prop(RTCLI::System::Single value);
		RTCLI::System::Void MethodWithArgsOps(RTCLI::System::Int32 arg0, RTCLI::System::Int32 arg1);
		RTCLI::System::Void MethodWithArgsFieldAccess(RTCLI::System::Int32 argInt, RTCLI::RTCLITestCase::TestSystem::TestInnerClass& argClass);
		RTCLI::System::Single _prop_k__BackingField;
	};
}
