#include "pch.h"
#include "CppUnitTest.h"
#include "Vec2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestVec2
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
		TEST_METHOD(Property_Magnitude)
		{
			math::Vec2f vec(4.f, 3.f);
			Assert::AreEqual(5.f, vec.Magnitude(), 0.0001f);
		
		}
		TEST_METHOD(Property_Normalized)
		{
			math::Vec2f vec(5.f, 3.f);
			math::Vec2f n = vec.Normalized();
			float mag = n.Magnitude();
			Assert::AreEqual(1.f, mag, 0.0001f);
		}
		TEST_METHOD(Property_SqrMagnitude)
		{
			math::Vec2f vec(2.f, 4.f);
			Assert::AreEqual(20.f, vec.SqrMagnitude(), 0.0001f);
		}

		TEST_METHOD(Public_Method_Equals)
		{
			math::Vec2f vec1(1.f, 10.f);
			math::Vec2f vec2(1.f,10.f);
			Assert::IsTrue(vec1.Equals(vec2));

			math::Vec2f vec3(4.f, 10.f);
			math::Vec2f vec4(4.f, 10.2f);
			Assert::IsFalse(vec3.Equals(vec4));
		}
		TEST_METHOD(Public_Method_Normalize)
		{
			math::Vec2f vec(2.f, 4.f);
			vec.Normalize();

			Assert::IsTrue(std::fabs(vec.Magnitude() - 1) < 1e-5f);
			Assert::IsTrue(vec.x > 0 && vec.y > 0);

		}
		TEST_METHOD(Public_Method_Set)
		{
			math::Vec2f vec(0.f, 0.f);
			vec.Set(2.1f, 1.f);
			Assert::AreEqual(2.1f, vec.x);
			Assert::AreEqual(1.f, vec.y);

			math::Vec2f vec1(2.3f, 2.f);
			math::Vec2f vec2(4.7f, 5.f);
			vec2.Set(vec1.x, vec1.y);
			Assert::IsTrue(vec2.Equals(vec1));
		}
		TEST_METHOD(Public_Method_ToString)
		{
			math::Vec2f vec(2.f, 4.f);
			std::string s = vec.ToString();
			Assert::IsTrue(s.find("(") == 0);
			Assert::IsTrue(s.find(",") != std::string::npos);
			Assert::IsTrue(s.find(")") == s.length() - 1);
		}
		TEST_METHOD(Static_ClampMagnitude)
		{
			math::Vec2f vec(5.f, 3.f);
			math::Vec2f vecClamped = math::Vec2f::ClampMagnitude(vec, 2.f);

			// Norme de 2
			Assert::IsTrue(std::abs(vecClamped.Magnitude() - 2.f) < 1e-5f);

			// direction conservee
			Assert::IsTrue(std::abs(vec.x / vec.y - vecClamped.x / vecClamped.y) < 1e-5f);
		}
		TEST_METHOD(Static_MoveTowards)
		{
			math::Vec2f current(1.f, 1.f);
			math::Vec2f target(4.f, 4.f);

			math::Vec2f result = math::Vec2f::MoveTowards(current, target, 5.f);
			Assert::IsTrue(target == result);
		}
		TEST_METHOD(Static_Perpendicular)
		{
			math::Vec2f v(1.f, 0.f);
			math::Vec2 p = math::Vec2f::Perpendicular(v);
			Assert::IsTrue(std::abs(math::Vec2f::Dot(v, p)) < 1e-5f);

			Assert::IsTrue(std::abs(p.Magnitude() - v.Magnitude()) < 1e-5f);
	
		}
		TEST_METHOD(Static_Reflect)
		{
			math::Vec2f dir(1, -1);
			math::Vec2f normal(0, 1);

			math::Vec2f r = math::Vec2f::Reflect(dir, normal);

			Assert::IsTrue(std::abs(r.x - 1.f) < 1e-5f);
			Assert::IsTrue(std::abs(r.y - 1.f) < 1e-5f);
		
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
			float pi = 3.14159265f;

			math::Vec2f vec1(1.f, 0.f);
			math::Vec2f vec2(0, 1.0f);
			Assert::AreEqual(pi /2, math::Vec2f::Angle(vec1, vec2), 0.001f);
		}
		TEST_METHOD(Static_SignedAngle)
		{
			float pi = 3.14159265f;

			math::Vec2f vec1(1.f, 0.f);
			math::Vec2f vec2(0, -1.0f);
			Assert::AreEqual(-pi / 2, math::Vec2f::SignedAngle(vec1, vec2), 0.001f);
		}
		TEST_METHOD(Static_SignedAngle2)
		{
			float pi = 3.14159265f;

			math::Vec2f vec1(1.f, 0.f);
			math::Vec2f vec2(-1.0, 0.f);
			Assert::AreEqual(pi, math::Vec2f::SignedAngle(vec1, vec2), 0.001f);
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
