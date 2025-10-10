#include "pch.h"
#include "CppUnitTest.h"
#include "Vec2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathsTests
{
	TEST_CLASS(Vec2)
	{
	public:
		
		TEST_METHOD(Constructor_Default)
		{
			math::Vec2f vec;
			Assert::AreEqual(0.0f, vec.x);
			Assert::AreEqual(0.0f, vec.y);
		}
		TEST_METHOD(Constructor_Values)
		{
			math::Vec2f vec(2.0f, 1.0f);
			Assert::AreEqual(2.0f, vec.x);
			Assert::AreEqual(1.0f, vec.y);
		}
		TEST_METHOD(Operator_Addition)
		{
			math::Vec2f vec1(2.0f, 1.0f);
			math::Vec2f vec2(4.0f, 3.0f);
			math::Vec2f result = vec1 + vec2;
			Assert::AreEqual(6.f, result.x);
			Assert::AreEqual(4.0f, result.y);
		}
		TEST_METHOD(Operator_Subtraction)
		{
			math::Vec2f vec1(2.0f, 1.0f);
			math::Vec2f vec2(4.0f, 3.0f);
			math::Vec2f result = vec1 - vec2;
			Assert::AreEqual(-2.f, result.x);
			Assert::AreEqual(-2.f, result.y);
		}
		TEST_METHOD(Operator_ScalarMultiply)
		{
			math::Vec2f vec(5.0f, 6.0f);
			math::Vec2f result = vec * 2;
			Assert::AreEqual(10.f, result.x);
			Assert::AreEqual(12.f, result.y);
		}
		TEST_METHOD(Operator_ScalarDivide)
		{
			math::Vec2f vec(4.0f, 2.0f);
			math::Vec2f result = vec / 2;
			Assert::AreEqual(2.f, result.x);
			Assert::AreEqual(1.f, result.y);
		}
		TEST_METHOD(Operator_Equality)
		{
			math::Vec2f vec1(2.0f, 3.0f);
			math::Vec2f vec2(2.0f, 3.0f);
			Assert::IsTrue(vec1 == vec2);
		}
		TEST_METHOD(Operator_Inequality)
		{
			math::Vec2f vec1(2.0f, 1.0f);
			math::Vec2f vec2(1.0f, 3.0f);
			Assert::IsTrue(vec1 != vec2);
		}
		TEST_METHOD(Operator_this)
		{
			math::Vec2f vec1(2.0f, 1.0f);
			Assert::AreEqual(vec1.x, vec1[0]);
			Assert::AreEqual(vec1.y, vec1[1]);
		}
		TEST_METHOD(Static_Distance)
		{
			math::Vec2f vec1(0.f, 0.f);
			math::Vec2f vec2(3.0f, 4.0f);
			Assert::AreEqual(5.0f, math::Vec2f::Distance(vec1, vec2), 0.001f);
		}
		TEST_METHOD(Static_Dot)
		{
			math::Vec2f vec1(1.f, 3.f);
			math::Vec2f vec2(3.0f, 4.0f);
			Assert::AreEqual(15.0f, math::Vec2f::Dot(vec1, vec2));
		}
		TEST_METHOD(Static_Angle)
		{
			math::Vec2f vec1(1.f, 0.f);
			math::Vec2f vec2(0, 1.0f);
			Assert::AreEqual(1.5708f, math::Vec2f::Angle(vec1, vec2), 0.001f);
		}
		TEST_METHOD(Static_SignedAngle)
		{
			math::Vec2f vec1(1.f, 0.f);
			math::Vec2f vec2(0, -1.0f);
			Assert::AreEqual(-1.57079632679f, math::Vec2f::SignedAngle(vec1, vec2), 0.001f);
		}
		TEST_METHOD(Static_Lerp)
		{
			math::Vec2f vec1(0.f, 0.f);
			math::Vec2f vec2(10, 10.0f);
			math::Vec2f result = math::Vec2f::Lerp(vec1, vec2, 0.5f);
			Assert::AreEqual(5.f, result.x);
			Assert::AreEqual(5.f, result.y);
		}
		TEST_METHOD(Static_LerpUnclamped)
		{
			math::Vec2f vec1(0.f, 0.f);
			math::Vec2f vec2(10, 10.0f);
			math::Vec2f result = math::Vec2f::LerpUnclamped(vec1, vec2, 1.5f);
			Assert::AreEqual(15.f, result.x);
			Assert::AreEqual(15.f, result.y);
		}
		TEST_METHOD(Static_Max)
		{
			math::Vec2f vec1(1.f, 3.f);
			math::Vec2f vec2(2.f, 5.0f);
			math::Vec2f result = math::Vec2f::Max(vec1, vec2);
			Assert::AreEqual(2.f, result.x);
			Assert::AreEqual(5.f, result.y);
		}
		TEST_METHOD(Static_Min)
		{
			math::Vec2f vec1(1.f, 4.f);
			math::Vec2f vec2(6.f, 9.0f);
			math::Vec2f result = math::Vec2f::Min(vec1, vec2);
			Assert::AreEqual(1.f, result.x);
			Assert::AreEqual(4.f, result.y);
		}
		TEST_METHOD(Static_Scale)
		{
			math::Vec2f vec1(2.f, 4.f);
			math::Vec2f vec2(4.f, 5.0f);
			math::Vec2f result = math::Vec2f::Scale(vec1, vec2);
			Assert::AreEqual(8.f, result.x);
			Assert::AreEqual(20.f, result.y);
		}
	};
}
