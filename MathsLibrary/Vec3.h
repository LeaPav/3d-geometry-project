#pragma once
#include <limits>

namespace math {

	template <typename T>
	class Vec3 {
	public:
		T x;
		T y;
		T z;

		Vec3();
		Vec3(T x, T y, T z);


		// operators

		Vec3 operator+(const Vec3& rhs) const;
		Vec3 operator-(const Vec3& rhs) const;
		Vec3 operator*(T scalar) const;
		Vec3 operator/(T scalar) const;
		bool operator==(const Vec3& vec) const;
		bool operator!=(const Vec3& vec) const;

		T& operator[](int index);

		// static properties

		static Vec3 down();
		static Vec3 back();
		static Vec3 forward();
		static Vec3 left();
		static Vec3 one();
		static Vec3 right();
		static Vec3 up();
		static Vec3 zero();

		static Vec3 negativeInfinity();
		static Vec3 positiveInfinity();

		// static methods

		static float Angle(const Vec3& from, const Vec3& to);

		static float SignedAngle(const Vec3& from, const Vec3& to, const Vec3& axis);

		static T Distance(const Vec3& a, const Vec3& b);

		static T Dot(const Vec3& a, const Vec3& b);

		static Vec3 Lerp(const Vec3& a, const Vec3& b, float t);

		static Vec3 LerpUnclamped(const Vec3& a, const Vec3& b, float t);

		static Vec3 Max(const Vec3& a, const Vec3& b);

		static Vec3 Min(const Vec3& a, const Vec3& b);

		static Vec3 Scale(const Vec3& a, const Vec3 b);

		static Vec3 Cross(const Vec3& a, const Vec3& b);

		static Vec3 Slerp(const Vec3& a, const Vec3& b, float t);
	};

	using Vec3f = Vec3<float>;
	using Vec3i = Vec3<int>;
	using Vec3d = Vec3<double>;
	

}
#include "Vec3.inl"