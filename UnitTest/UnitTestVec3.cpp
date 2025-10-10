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
		
	};
}
