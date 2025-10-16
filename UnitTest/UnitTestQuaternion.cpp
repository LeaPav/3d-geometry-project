#include "pch.h"
#include "CppUnitTest.h"
#include "Quaternion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestQuaternion {
	TEST_CLASS(Quaternion) {
	public:

		TEST_METHOD(Constructor_Default){}
		TEST_METHOD(Constructor_Values){}
		TEST_METHOD(Operator_Addition){}
		TEST_METHOD(Operator_Equality) {}
		//TEST_METHOD(Method_Identity) {}
		//TEST_METHOD(Property_EulerAngles) {}
		//TEST_METHOD(Property_Normalized) {}
		TEST_METHOD(Operator_this) {}
		TEST_METHOD(Method_Equals){}
		TEST_METHOD(Method_Set){}
		TEST_METHOD(Method_SetFromToRotation){}
		TEST_METHOD(Method_SetLookRotation){}
		TEST_METHOD(Method_ToAngleAxis){}
		TEST_METHOD(Method_ToString){}
		TEST_METHOD(Static_Angle){}
		TEST_METHOD(Static_AngleAxis){}
		TEST_METHOD(Static_Dot){}
		TEST_METHOD(Static_Euler){}
		TEST_METHOD(Static_FromToRotation){}
		TEST_METHOD(Static_Inverse){}
		TEST_METHOD(Static_Lerp){}
		TEST_METHOD(Static_LerpUncampled){}
		TEST_METHOD(Static_Normalize){}
		TEST_METHOD(Static_RotateTowards){}
		TEST_METHOD(Static_Slerp){}
		TEST_METHOD(Static_SlerpUncampled){}
	};
}