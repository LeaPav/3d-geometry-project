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

		TEST_METHOD(Instance_Magnitude)
		{
			math::Vec3f vec(5.f, 14.f, 2.f);

			Assert::AreEqual(15.f, vec.Magnitude(), 0.0001f);
	
		}
		TEST_METHOD(Instance_SqrMagnitude)
		{
			math::Vec3f vec(4.f, 3.f, 6.f);

			Assert::AreEqual(61.f, vec.SqrMagnitude(), 0.0001f);

		}
		TEST_METHOD(Instance_Normalized_Mag1)
		{
			math::Vec3f vec(3.f, 0.f, 4.f);
			math::Vec3f n = vec.Normalized();
			float mag = n.Magnitude();
			Assert::AreEqual(1.f, mag, 0.0001f);

		}
		TEST_METHOD(Instance_Normalized_Direction)
		{
			math::Vec3f vec(20.f, -10.f, 15.f);
			math::Vec3f n = vec.Normalized();

			math::Vec3f cross = math::Vec3f::Cross(vec, n);
			float crossMag = cross.Magnitude();

			Assert::IsTrue(crossMag < 1e-5f);

		}

		TEST_METHOD(Method_Equals)
		{
			math::Vec3f vec1(3.1f, 2.4f, 5.f);
			math::Vec3f vec2(3.1f, 2.4f, 5.f);
			Assert::IsTrue(vec1.Equals(vec2));

			math::Vec3f vec3(1.f, 12.3f, 7.f);
			math::Vec3f vec4(1.f, 12.5f, 7.f);
			Assert::IsFalse(vec3.Equals(vec4));

		}

		TEST_METHOD(Method_Set)
		{

			math::Vec3f v(3.f, 7.6f, 15.3f);
			v.Set(7.f, 2.1f, 6.f);
			Assert::AreEqual(v.x, 7.f);
			Assert::AreEqual(v.y, 2.1f);
			Assert::AreEqual(v.z, 6.f);

			math::Vec3f vec1(5.6f, 8.f, 6.1f);
			math::Vec3f vec2(12.f, 15.4f, 7.4f);
			vec1.Set(vec2.x, vec2.y, vec2.z);

			Assert::IsTrue(vec1.Equals(vec2));
		
		}

		TEST_METHOD(Method_ToString)
		{
			math::Vec3f vec(2.f, 4.f, 5.f);
			std::string s = vec.ToString();
			
			Assert::IsTrue(s.find("(") == 0);
			Assert::IsTrue(s.find(",") != std::string::npos);
			Assert::IsTrue(s.find(",", s.find(",") + 1) != std::string::npos);
			Assert::IsTrue(s.find(")") == s.length() - 1);

		}

		TEST_METHOD(Method_Normalize)
		{
			math::Vec3f vec(2.f, 4.f, 5.f);
			vec.Normalize();
			Assert::IsTrue(std::fabs(vec.Magnitude() - 1) < 1e-5f);
			Assert::IsTrue(vec.x > 0 && vec.y > 0 && vec.z > 0);

		}

		TEST_METHOD(Static_ClampMagnitude)
		{
			math::Vec3f vec(5.f, 3.f, 2.f);
			math::Vec3f vecClamped = math::Vec3f::ClampMagnitude(vec, 2.f);

			// Norme de 2
			Assert::IsTrue(std::abs(vecClamped.Magnitude() - 2.f) < 1e-5f);

			math::Vec3f dir1 = vec.Normalized();
			math::Vec3f dirClamped1 = vecClamped.Normalized();

			Assert::IsTrue(std::fabs(dir1.x - dirClamped1.x) < 1e-5f);
			Assert::IsTrue(std::fabs(dir1.y - dirClamped1.y) < 1e-5f);
			Assert::IsTrue(std::fabs(dir1.z - dirClamped1.z) < 1e-5f);

			// vec plus petit que la limite
			math::Vec3f vec2(0.5f, 0.5f, 0.5f);
			math::Vec3f clamped2 = math::Vec3f::ClampMagnitude(vec2, 2.f);

			Assert::IsTrue(std::fabs(clamped2.x - vec2.x) < 1e-6f);
			Assert::IsTrue(std::fabs(clamped2.y - vec2.y) < 1e-6f);
			Assert::IsTrue(std::fabs(clamped2.z - vec2.z) < 1e-6f);

			// vecteur nul
			math::Vec3f vec3(0.f, 0.f, 0.f);
			math::Vec3f clamped3 = math::Vec3f::ClampMagnitude(vec3, 2.f);

			Assert::AreEqual(0.f, clamped3.x, 1e-6f);
			Assert::AreEqual(0.f, clamped3.y, 1e-6f);
			Assert::AreEqual(0.f, clamped3.z, 1e-6f);
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

		TEST_METHOD(Static_MoveTowards)
		{
			math::Vec3f current(0.f, 0.f, 0.f);
			math::Vec3f target(1.f, 1.f, 1.f);

			math::Vec3f result = math::Vec3f::MoveTowards(current, target, 5.f);
			Assert::IsTrue(target == result);
		}
		TEST_METHOD(Static_OrthoNormalize)
		{
			math::Vec3f v(1.f, -1.f, 0.f);
			math::Vec3f v2(1.f, 1.f, 0.f);
			
			math::Vec3f::OrthoNormalize(v, v2);

			Assert::IsTrue(std::fabs(v.Magnitude() - 1.f) < 1e-5f);
			Assert::IsTrue(std::fabs(v2.Magnitude() - 1.f) < 1e-5f);

			Assert::IsTrue(std::fabs(math::Vec3f::Dot(v, v2)) < 1e-5f);
		}

		TEST_METHOD(Static_Project)
		{
			math::Vec3f vec(1.f, 2.f, 3.f);
			math::Vec3f onNormal(0.f, 1.f, 0.f);

			math::Vec3f result = math::Vec3f::Project(vec, onNormal);
			math::Vec3f expected(0.f, 2.f, 0.f);

			Assert::IsTrue(result == expected);
		}
		TEST_METHOD(Static_ProjectOnPlane)
		{
			math::Vec3f vec(1.f, 2.f, 3.f);
			math::Vec3f planeNormal(0.f, 1.f, 0.f);

			math::Vec3f result = math::Vec3f::ProjectOnPlane(vec, planeNormal);
			math::Vec3f expected(1.f, 0.f, 3.f);

			Assert::IsTrue(result == expected);
		}
		TEST_METHOD(Static_Reflect)
		{
			math::Vec3f v(1.f, -1.f, 0.f);
			math::Vec3f normal(0.f, 1.f, 0.f);

			math::Vec3f result = math::Vec3f::Reflect(v, normal);
			math::Vec3f expected(1.f, 1.f, 0.f);

			Assert::IsTrue(result == expected);
		}

		TEST_METHOD(Static_RotateTowards)
		{
			math::Vec3f v1{ 1.f, 0.f, 0.f };
			math::Vec3f v2{ 0.f, 2.f, 0.f };
			math::Vec3f result{ math::Vec3f::RotateTowards(v1, v2, 0.7853981f, 0.f) };

			Assert::AreEqual(0.7071067f, result.x, 0.00001f);
			Assert::AreEqual(0.7071067f, result.y, 0.00001f);
			Assert::AreEqual(0.f, result.z);
			Assert::AreEqual(v1.Magnitude(), result.Magnitude(), 0.00001f);
		}
		TEST_METHOD(Static_Slerp_Ortho)
		{
			math::Vec3f vec1(1, 0, 0);
			math::Vec3f vec2(0, 1, 0);
			math::Vec3f result = math::Vec3f::Slerp(vec1, vec2, 0.5f);

			Assert::AreEqual(0.7071f, result.x, 0.001f);
			Assert::AreEqual(0.7071f, result.y, 0.001f);
			Assert::AreEqual(0.0f, result.z, 0.001f);
		}
		TEST_METHOD(Static_Slerp_2) 
		{
			math::Vec3f vec1(1, 0, 0);
			math::Vec3f vec2(-1, 0, 0);
			math::Vec3f result = math::Vec3f::Slerp(vec1, vec2, 0.0f);
			Assert::AreEqual(vec1.Normalized().x, result.x, 0.001f);
			Assert::AreEqual(vec1.Normalized().y, result.y, 0.001f);
			Assert::AreEqual(vec1.Normalized().z, result.z, 0.001f);

			math::Vec3f result1 = math::Vec3f::Slerp(vec1, vec2, 1.0f);
			Assert::AreEqual(vec2.Normalized().x, result1.x, 0.001f);
			Assert::AreEqual(vec2.Normalized().y, result1.y, 0.001f);
			Assert::AreEqual(vec2.Normalized().z, result1.z, 0.001f);
		}
		TEST_METHOD(Static_SlerpUnclamped)
		{
			math::Vec3f vec1(1, 0, 0);
			math::Vec3f vec2(0, 1, 0);
			math::Vec3f result = math::Vec3f::Slerp(vec1, vec2, 1.5f);
			Assert::IsTrue(result.y > 0.7071f);
		}
		TEST_METHOD(Static_SlerpUnclamped2)
		{
			math::Vec3f vec1(1, 0, 0);
			math::Vec3f vec2(0, 1, 0);
			math::Vec3f result = math::Vec3f::Slerp(vec1, vec2, -0.5f);
			Assert::IsTrue(result.x > 0.7071f);
		}
	};
}
