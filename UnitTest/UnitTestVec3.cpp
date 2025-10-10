#include "pch.h"
#include "CppUnitTest.h"
#include "Vec2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestVec3
{
	TEST_CLASS(Vec3)
	{
	public:

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
	};
}
