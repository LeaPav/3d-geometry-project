#include "pch.h"
#include "CppUnitTest.h"
#include "Vec3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestVec3
{
	TEST_CLASS(Vec3)
	{
	public:

		float pi = 3.14159265f;
		TEST_METHOD(Constructor_Default)
		{
			math::Vec3f vec;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
			Assert::AreEqual(0.0f, vec.z);
		}
		TEST_METHOD(Constructor_Values)
		{
			math::Vec3f vec(2.f, 1.f, 3.f);
			Assert::AreEqual(2.f, vec.x);
			Assert::AreEqual(1.f, vec.y);
			Assert::AreEqual(3.f, vec.z);
		}
		TEST_METHOD(Operator_Addition)
		{
			math::Vec3f vec1(2.f, 1.f, 3.f);
			math::Vec3f vec2(4.f, 2.f, 1.f);

			math::Vec3f result = vec1 + vec2;

			Assert::AreEqual(6.f, result.x);
			Assert::AreEqual(3.f, result.y);
			Assert::AreEqual(4.f, result.z);
		}
		TEST_METHOD(Operator_Subtraction)
		{
			math::Vec3f vec1(6.f, 4.f, 2.f);
			math::Vec3f vec2(3.f, 1.f, 3.f);

			math::Vec3f result = vec1 - vec2;

			Assert::AreEqual(3.f, result.x);
			Assert::AreEqual(3.f, result.y);
			Assert::AreEqual(-1.f, result.z);
		}
		TEST_METHOD(Operator_ScalarMultiply)
		{
			math::Vec3f vec(6.f, 4.f, 2.f);

			math::Vec3f result = vec * 3;

			Assert::AreEqual(18.f, result.x);
			Assert::AreEqual(12.f, result.y);
			Assert::AreEqual(6.f, result.z);
		}
		TEST_METHOD(Operator_ScalarDivide)
		{
			math::Vec3f vec(10.f, 8.f, 9.f);

			math::Vec3f result = vec / 2;

			Assert::AreEqual(5.f, result.x);
			Assert::AreEqual(4.f, result.y);
			Assert::AreEqual(4.5f, result.z);
		}
		TEST_METHOD(Operator_Equality)
		{
			math::Vec3f vec1(7.f, 14.f, 2.f);
			math::Vec3f vec2(7.f, 14.f, 2.f);

			Assert::IsTrue(vec1 == vec2);
		}
		TEST_METHOD(Operator_Inequality)
		{
			math::Vec3f vec1(5.f, 14.f, 2.f);
			math::Vec3f vec2(7.f, 5.f, 12.f);

			Assert::IsTrue(vec1 != vec2);
		}
		TEST_METHOD(Operator_this)
		{
			math::Vec3f vec(5.f, 14.f, 2.f);

			Assert::AreEqual(vec.x, vec[0]);
			Assert::AreEqual(vec.y, vec[1]);
			Assert::AreEqual(vec.z, vec[2]);
		}
		TEST_METHOD(Static_Distance)
		{
			math::Vec3d vec1(2.f, 5.f, 7.f);
			math::Vec3d vec2(5.f, 4.f, 2.f);

			Assert::AreEqual(std::sqrt(35), math::Vec3d::Distance(vec1, vec2));
		}
		TEST_METHOD(Static_Dot)
		{
			math::Vec3f vec1(4.f, 8.f, 6.f);
			math::Vec3f vec2(7.f, 5.f, 3.f);

			Assert::AreEqual(86.f, math::Vec3f::Dot(vec1, vec2));
		}
		TEST_METHOD(Static_Angle)
		{

			math::Vec3f vec1(1, 0, 0);
			math::Vec3f vec2(0, 1, 0);
			Assert::AreEqual(pi / 2, math::Vec3f::Angle(vec1, vec2), 0.001f);
		}
		TEST_METHOD(Static_SignedAngle)
		{

			math::Vec3f vec1(1, 0, 0);
			math::Vec3f vec2(0, 1, 0);
			math::Vec3f axis(0, 0, -1);
			Assert::AreEqual(-pi / 2, math::Vec3f::SignedAngle(vec1, vec2, axis), 0.001f);
		}
		TEST_METHOD(Static_Lerp)
		{
			math::Vec3f vec1(0.f, 0.f, 0.f);
			math::Vec3f vec2(5, 10.0f, 6.f);
			math::Vec3f result = math::Vec3f::Lerp(vec1, vec2, 0.5f);
			Assert::AreEqual(2.5f, result.x);
			Assert::AreEqual(5.f, result.y);
			Assert::AreEqual(3.f, result.z);

		}
		TEST_METHOD(Static_LerpUnclamped)
		{
			math::Vec3f vec1(0.f, 0.f, 0.f);
			math::Vec3f vec2(5, 10.0f, 6.f);
			math::Vec3f result = math::Vec3f::LerpUnclamped(vec1, vec2, 2);
			Assert::AreEqual(10.f, result.x);
			Assert::AreEqual(20.f, result.y);
			Assert::AreEqual(12.f, result.z);
		}
		TEST_METHOD(Static_Max)
		{
			math::Vec3f vec1(3.f, 7.f, 15.2f);
			math::Vec3f vec2(2.f, 5.0f, 4.5f);
			math::Vec3f result = math::Vec3f::Max(vec1, vec2);
			Assert::AreEqual(3.f, result.x);
			Assert::AreEqual(7.f, result.y);
			Assert::AreEqual(15.2f, result.z);
		}
		TEST_METHOD(Static_Min)
		{
			math::Vec3f vec1(3.f, 7.f, 15.2f);
			math::Vec3f vec2(2.f, 5.0f, 4.5f);
			math::Vec3f result = math::Vec3f::Min(vec1, vec2);
			Assert::AreEqual(2.f, result.x);
			Assert::AreEqual(5.f, result.y);
			Assert::AreEqual(4.5f, result.z);
		}
		TEST_METHOD(Static_Scale)
		{
			math::Vec3f vec1(8.f, 6.f, 14.f);
			math::Vec3f vec2(7.f, 6.0f, 2.f);
			math::Vec3f result = math::Vec3f::Scale(vec1, vec2);
			Assert::AreEqual(56.f, result.x);
			Assert::AreEqual(36.f, result.y);
			Assert::AreEqual(28.f, result.z);
		}
		TEST_METHOD(Static_Cross)
		{
			math::Vec3f vec1(2.f, 6.f, 8.f);
			math::Vec3f vec2(3.f, 5.f, 1.f);
			math::Vec3f result = math::Vec3f::Cross(vec1, vec2);
			Assert::AreEqual(-34.f, result.x);
			Assert::AreEqual(22.f, result.y);
			Assert::AreEqual(-8.f, result.z);
		}
	};
}
