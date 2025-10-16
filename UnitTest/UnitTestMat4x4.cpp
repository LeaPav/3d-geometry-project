#include "pch.h"
#include "CppUnitTest.h"
#include "Mat4x4.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMat4x4
{
	TEST_CLASS(Mat4x4)
	{
	public:

		TEST_METHOD(Constructor_Default)
		{
			math::Mat4x4f m; 

			for (int row = 0; row < 4; ++row)
			{
				for (int col = 0; col < 4; ++col)
				{
					float expected = (row == col) ? 1.0f : 0.0f;
					Assert::AreEqual(expected, m(row, col), 0.0001f);
				}
			}
			math::Mat4x4f m2;
			Assert::IsTrue(m.IsIdentity());
		}
		TEST_METHOD(Constructor_Array)
		{
			std::array<float, 16> arr = {
				1,2,3,4,
				5,6,7,8,
				9,10,11,12,
				13,14,15,16
			};
			math::Mat4x4f m(arr);
			for (int i = 0; i < 16; i++)
				Assert::AreEqual(arr[i], m.mat[i]);
		}
		TEST_METHOD(Zero)
		{
			auto id = math::Mat4x4f::Identity();
			auto zero = math::Mat4x4f::Zero();

			Assert::IsTrue(id.IsIdentity());

			for (int i = 0; i < 16; i++)
				Assert::AreEqual(0.0f, zero.mat[i]);
		}

		TEST_METHOD(Operator_RowCol)
		{
			math::Mat4x4f m;
			m(1, 2) = 42.0f;
			Assert::AreEqual(42.0f, m(1, 2));
		}

		TEST_METHOD(Multiplication_Identity)
		{
			math::Mat4x4f a = math::Mat4x4f::Identity();
			math::Mat4x4f b = math::Mat4x4f::Identity();
			math::Mat4x4f c = a * b;
			Assert::IsTrue(c.IsIdentity());
		}
		TEST_METHOD(Transpose)
		{
			math::Mat4x4f m({ 1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16 });
			auto t = m.Transpose();

			for (int row = 0; row < 4; ++row)
				for (int col = 0; col < 4; ++col)
					Assert::AreEqual(m(col, row), t(row, col), 0.0001f);
		}
		TEST_METHOD(Determinant_Inverse)
		{
			math::Mat4x4f m({ 1,0,0,0, 0,2,0,0, 0,0,3,0, 0,0,0,1 });
			float det = m.Determinant();
			Assert::AreEqual(6.0f, det, 0.0001f);

			auto inv = m.Inverse();
			auto I = m * inv;
			for (int row = 0; row < 4; ++row)
				for (int col = 0; col < 4; ++col)
					Assert::AreEqual((row == col) ? 1.0f : 0.0f, I(row, col), 0.001f);

			math::Mat4x4f m2 = math::Mat4x4f::Identity();
			float det2 = m2.Determinant();
			Assert::AreEqual(1.0f, det2);

			auto inv2 = m2.Inverse();
			Assert::IsTrue(inv2.IsIdentity());
		}

		TEST_METHOD(Minor_CoFactor) 
		{
			math::Mat4x4f m = math::Mat4x4f::Identity();
			float minor = m.Minor(0, 0);
			float cofactor = m.Cofactor(0, 0);

			Assert::AreEqual(1.0f, minor);
			Assert::AreEqual(1.0f, cofactor);
		}

		TEST_METHOD(GetPosition)
		{
			math::Mat4x4f m = math::Mat4x4f::Identity();
			m(0, 3) = 1.0f; m(1, 3) = 2.0f; m(2, 3) = 3.0f;
			auto pos = m.GetPosition();
			Assert::AreEqual(1.0f, pos.x);
			Assert::AreEqual(2.0f, pos.y);
			Assert::AreEqual(3.0f, pos.z);
		}
		TEST_METHOD(MultiplyPoint3x4_Vector) 
		{
			math::Mat4x4f m = math::Mat4x4f::Identity();
			math::Vec3f v{ 1,2,3 };
			auto res = m.MultiplyPoint3x4(v);
			Assert::AreEqual(v.x, res.x);
			Assert::AreEqual(v.y, res.y);
			Assert::AreEqual(v.z, res.z);
		}
		TEST_METHOD(LossyScale)
		{
			math::Mat4x4f m = math::Mat4x4f::Scale({ 2.0f,3.0f,4.0f });
			auto s = m.LossyScale();
			Assert::AreEqual(2.0f, s.x);
			Assert::AreEqual(3.0f, s.y);
			Assert::AreEqual(4.0f, s.z);
		}

		TEST_METHOD(Scale_Translate)
		{
			auto s = math::Mat4x4f::Scale({ 2.0f,2.0f,2.0f });
			auto t = math::Mat4x4f::Translate({ 1.0f,2.0f,3.0f });

			math::Vec3f p{ 1,1,1 };
			auto ps = s.MultiplyPoint3x4(p);
			Assert::AreEqual(2.0f, ps.x);
			Assert::AreEqual(2.0f, ps.y);
			Assert::AreEqual(2.0f, ps.z);

			auto pt = t.MultiplyPoint3x4(p);
			Assert::AreEqual(2.0f, pt.x);
			Assert::AreEqual(3.0f, pt.y);
			Assert::AreEqual(4.0f, pt.z);
		}
		TEST_METHOD(LookAt)
		{
			math::Vec3f from{ 0,0,0 };
			math::Vec3f to{ 0,0,-1 };
			math::Vec3f up{ 0,1,0 };

			auto mat = math::Mat4x4f::LookAt(from, to, up);
	
			Assert::AreEqual(0.0f, mat(0, 2));
			Assert::AreEqual(0.0f, mat(1, 2));
			Assert::AreEqual(1.0f, mat(2, 2)); 
		}
		TEST_METHOD(Perspective_Ortho_Frustum)
		{
			auto p = math::Mat4x4f::Perspective(45.0f, 1.0f, 0.1f, 100.0f);
			auto o = math::Mat4x4f::Ortho(-1, 1, -1, 1, 0.1f, 100.0f);
			auto f = math::Mat4x4f::Frustum(-1, 1, -1, 1, 0.1f, 100.0f);

			Assert::AreNotEqual(0.0f, p(0, 0));
			Assert::AreNotEqual(0.0f, o(0, 0));
			Assert::AreNotEqual(0.0f, f(0, 0));
		}
		TEST_METHOD(Inverse3DAffine)
		{
			math::Mat4x4f m = math::Mat4x4f::Translate({ 1,2,3 });
			math::Mat4x4f result;
			bool ok = math::Mat4x4f::Inverse3DAffine(m, result);
			Assert::IsTrue(ok);
			auto id = m * result;
			for (int i = 0; i < 16; i++)
			{
				if (i % 5 == 0)
					Assert::AreEqual(1.0f, id.mat[i], 0.0001f);
				else
					Assert::AreEqual(0.0f, id.mat[i], 0.0001f);
			}
		}
	};
}
