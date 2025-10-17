#include "pch.h"
#include "CppUnitTest.h"
#include "Quaternion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace math;

namespace UnitTestQuaternion {
	TEST_CLASS(Quaternion) {
public:
	TEST_METHOD(Constructor_Default)
	{
		Quaternionf q;
		Assert::AreEqual(0.0f, q.x);
		Assert::AreEqual(0.0f, q.y);
		Assert::AreEqual(0.0f, q.z);
		Assert::AreEqual(0.0f, q.w);
	}

	TEST_METHOD(Constructor_Values)
	{
		Quaternionf q(4.0f, 1.0f, 2.0f, 3.0f);
		Assert::AreEqual(4.0f, q.x);
		Assert::AreEqual(1.0f, q.y);
		Assert::AreEqual(2.0f, q.z);
		Assert::AreEqual(3.0f, q.w);	
	}
	TEST_METHOD(Operator_this)
	{
		Quaternionf q(1, 2, 3, 4);
		Assert::AreEqual(1.0f, q[0]);
		Assert::AreEqual(2.0f, q[1]);
		Assert::AreEqual(3.0f, q[2]);
		Assert::AreEqual(4.0f, q[3]);
	}
	TEST_METHOD(Operator_Equality) {
		math::Quaternionf q1(1, 0, 0, 0);
		math::Quaternionf q2(1, 0, 0, 0);
		math::Quaternionf q3(0, 1, 0, 0);

		Assert::IsTrue(q1 == q2);
		Assert::IsFalse(q1 == q3);
	}
	TEST_METHOD(Static_Identity)
	{
		auto q = Quaternionf::Identity();
		Assert::AreEqual(0.0f, q.x);
		Assert::AreEqual(0.0f, q.y);
		Assert::AreEqual(0.0f, q.z);
		Assert::AreEqual(1.0f, q.w);
	}	
	TEST_METHOD(Property_EulerAngles)
	{
		auto q = Quaternionf::Euler(0.0f, 90.0f, 0.0f);

		auto euler = q.EulerAngles();

		Assert::AreEqual(0.0f, euler.x, 0.5f);
		Assert::AreEqual(90.0f, euler.y, 0.5f);
		Assert::AreEqual(0.0f, euler.z, 0.5f);
	}
	TEST_METHOD(Property_Normalized)
	{
		Quaternionf q(2, 0, 0, 0);
		auto norm = q.Normalized();

		Assert::AreEqual(1.0f, norm.x, 0.0001f);
		Assert::AreEqual(0.0f, norm.y, 0.0001f);
		Assert::AreEqual(0.0f, norm.z, 0.0001f);
		Assert::AreEqual(0.0f, norm.w, 0.0001f);
	}
	TEST_METHOD(Method_Equals)
	{
		Quaternionf q1(1, 2, 3, 4);
		Quaternionf q2(1, 2, 3, 4);
		Quaternionf q3(0, 0, 0, 1);
		Assert::IsTrue(q1.Equals(q2));
		Assert::IsFalse(q1.Equals(q3));
	}
	TEST_METHOD(Method_Set)
	{
		Quaternionf q1(1, 2, 3, 4);
		Quaternionf q2;
		q2.Set(q1);
		Assert::IsTrue(q1.Equals(q2));
	}	
	TEST_METHOD(Method_SetFromToRotation)
	{
		Quaternionf q;
		Vec3f from(1, 0, 0);
		Vec3f to(0, 1, 0);

		q.SetFromToRotation(from, to);
		Vec3f rotated = q * from;

		Assert::AreEqual(to.x, rotated.x, 0.01f);
		Assert::AreEqual(to.y, rotated.y, 0.01f);
		Assert::AreEqual(to.z, rotated.z, 0.01f);
	}
	TEST_METHOD(Method_SetLookRotation)
	{
		Quaternionf q;
		Vec3f forward(0, 0, 1);
		Vec3f up(0, 1, 0);

		q.SetLookRotation(forward, up);
		Vec3f rotated = q * Vec3f(0, 0, 1); 

		Assert::AreEqual(forward.x, rotated.x, 0.01f);
		Assert::AreEqual(forward.y, rotated.y, 0.01f);
		Assert::AreEqual(forward.z, rotated.z, 0.01f);
	}
	TEST_METHOD(Method_ToAngleAxis)
	{
		auto q = Quaternionf::AngleAxis(45.0f, Vec3f(0, 0, 1));
		float angle;
		Vec3f axis;
		q.ToAngleAxis(angle, axis);
		Assert::AreEqual(45.0f, angle, 0.01f);
		Assert::AreEqual(0.0f, axis.x, 0.01f);
		Assert::AreEqual(0.0f, axis.y, 0.01f);
		Assert::AreEqual(1.0f, axis.z, 0.01f);
	}
	TEST_METHOD(Method_ToString)
	{
		Quaternionf q(1, 2, 3, 4);
		auto str = q.ToString();
		Assert::IsTrue(str.find("1") != std::string::npos);
		Assert::IsTrue(str.find("2") != std::string::npos);
		Assert::IsTrue(str.find("3") != std::string::npos);
		Assert::IsTrue(str.find("4") != std::string::npos);
	}
	TEST_METHOD(Static_Angle)
	{
		auto q1 = Quaternionf::AngleAxis(0.0f, Vec3f(0, 1, 0));
		auto q2 = Quaternionf::AngleAxis(90.0f, Vec3f(0, 1, 0));
		float angle = Quaternionf::Angle(q1, q2);

		Assert::AreEqual(90.0f, angle, 0.5f);
	}	
	TEST_METHOD(Static_AngleAxis)
	{
		auto q = Quaternionf::AngleAxis(90.0f, Vec3f(0, 1, 0));
		float halfAngleRad = 3.14159265f / 4;
		Assert::AreEqual(std::cos(halfAngleRad), q.w, 0.0001f);
		Assert::AreEqual(0.0f, q.x, 0.0001f);
		Assert::AreEqual(std::sin(halfAngleRad), q.y, 0.0001f);
		Assert::AreEqual(0.0f, q.z, 0.0001f);
	}

	TEST_METHOD(Static_Dot)
	{
		Quaternionf q1(1, 0, 0, 0);
		Quaternionf q2(0, 1, 0, 0);
		auto dot = Quaternionf::Dot(q1, q2);
		Assert::AreEqual(0.0f, dot);
	}
	TEST_METHOD(Static_Euler)
	{
		auto q = Quaternionf::Euler(0.0f, 90.0f, 0.0f);
		float angle;
		Vec3f axis;
		q.ToAngleAxis(angle, axis);

		Assert::AreEqual(90.0f, angle, 0.5f);
		Assert::AreEqual(0.0f, axis.x, 0.01f);
		Assert::AreEqual(1.0f, axis.y, 0.01f);
		Assert::AreEqual(0.0f, axis.z, 0.01f);
	}
	TEST_METHOD(Static_FromToRotation)
	{
		Vec3f from(1, 0, 0);
		Vec3f to(0, 1, 0);
		auto q = Quaternionf::FromToRotation(from, to);

		Vec3f rotated = q * from;
		Assert::AreEqual(to.x, rotated.x, 0.01f);
		Assert::AreEqual(to.y, rotated.y, 0.01f);
		Assert::AreEqual(to.z, rotated.z, 0.01f);
	}
	TEST_METHOD(Static_Inverse) {
		math::Quaternionf q(0.7071f, 0.7071f, 0.0f, 0.0f); 
		auto inv = math::Quaternionf::Inverse(q);
		auto identity = q * inv;

		Assert::AreEqual(1.0f, identity.w, 0.0001f);
		Assert::AreEqual(0.0f, identity.x, 0.0001f);
		Assert::AreEqual(0.0f, identity.y, 0.0001f);
		Assert::AreEqual(0.0f, identity.z, 0.0001f);
	}
	TEST_METHOD(Static_LookRotation)
	{
		Vec3f forward(0, 0, 1);
		Vec3f up(0, 1, 0);
		auto q = Quaternionf::LookRotation(forward, up);

		Vec3f result = q * Vec3f(0, 0, 1);
		Assert::AreEqual(forward.x, result.x, 0.01f);
		Assert::AreEqual(forward.y, result.y, 0.01f);
		Assert::AreEqual(forward.z, result.z, 0.01f);
	}
	TEST_METHOD(Static_Lerp)
	{
		Quaternionf q1(1, 0, 0, 0);
		Quaternionf q2(0, 1, 0, 0);
		auto result = Quaternionf::Lerp(q1, q2, 0.5f);

		Assert::AreEqual(0.5f, result.w, 0.01f);
		Assert::AreEqual(0.5f, result.x, 0.01f);
	}
	TEST_METHOD(Static_LerpUncampled)
	{
		Quaternionf q1(1, 0, 0, 0);
		Quaternionf q2(0, 1, 0, 0);
		auto result = Quaternionf::LerpUncampled(q1, q2, 0.5f);

		Assert::AreEqual(0.5f, result.w, 0.01f);
		Assert::AreEqual(0.5f, result.x, 0.01f);
	}
	TEST_METHOD(Static_Normalize) {
		math::Quaternionf q(2, 0, 0, 0);
		auto norm = math::Quaternionf::Normalize(q);
		Assert::AreEqual(1.0f, norm.w, 0.0001f);
		Assert::AreEqual(0.0f, norm.x, 0.0001f);
		Assert::AreEqual(0.0f, norm.y, 0.0001f);
		Assert::AreEqual(0.0f, norm.z, 0.0001f);
	}
	TEST_METHOD(Static_RotateTowards)
	{
		auto from = Quaternionf::AngleAxis(0.0f, Vec3f(0, 1, 0));
		auto to = Quaternionf::AngleAxis(90.0f, Vec3f(0, 1, 0));
		auto result = Quaternionf::RotateTowards(from, to, 45.0f);

		float angle = Quaternionf::Angle(from, result);
		Assert::AreEqual(45.0f, angle, 0.01f);
	}
	TEST_METHOD(Static_Slerp) {
		math::Quaternionf q1(1, 0, 0, 0);
		math::Quaternionf q2(0, 1, 0, 0);
		auto result = math::Quaternionf::Slerp(q1, q2, 0.5f);

		float expected = std::sqrt(0.5f);
		Assert::AreEqual(expected, result.w, 0.0001f);
		Assert::AreEqual(expected, result.x, 0.0001f);
	}
	TEST_METHOD(Static_SlerpUncampled)
	{
		Quaternionf q1(1, 0, 0, 0);
		Quaternionf q2(0, 1, 0, 0);
		auto result = Quaternionf::SlerpUncampled(q1, q2, 0.5f);

		float expected = std::sqrt(0.5f);
		Assert::AreEqual(expected, result.w, 0.01f);
		Assert::AreEqual(expected, result.x, 0.01f);
	}
	};

}