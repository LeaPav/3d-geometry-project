#pragma once
#include <limits>
#include <cmath>

namespace math {

	template <typename T>
	class Vec3 {
	public:
		T x;
		T y;
		T z;

		constexpr Vec3();
		constexpr Vec3(T x, T y, T z);


		// operators

		constexpr Vec3 operator+(const Vec3& rhs) const;
		constexpr Vec3 operator-(const Vec3& rhs) const;
		constexpr Vec3 operator*(T scalar) const;
		constexpr Vec3 operator/(T scalar) const;
		constexpr bool operator==(const Vec3& vec) const;
		constexpr bool operator!=(const Vec3& vec) const;

		T& operator[](int index);

		// static properties

		static constexpr Vec3 down();
		static constexpr Vec3 back();
		static constexpr Vec3 forward();
		static constexpr Vec3 left();
		static constexpr Vec3 one();
		static constexpr Vec3 right();
		static constexpr Vec3 up();
		static constexpr Vec3 zero();

		static constexpr Vec3 negativeInfinity();
		static constexpr Vec3 positiveInfinity();

		// properties

		float Magnitude() const { return std::sqrt(x * x + y * y + z * z); }
		Vec3 Normalized() const {
			float magnitude = Magnitude(); if (magnitude < 0.00001f) { return Vec3(0.0f, 0.0f, 0.0f); } return Vec3(x / magnitude, y / magnitude, z / magnitude);
		}
		float SqrMagnitude() const { return x * x + y * y + z * z; }

		//public methods

		bool Equals(const Vec3& rhs) const { return (x == rhs.x) && (y == rhs.y) && (z == rhs.z); }

		void Set(const Vec3& rhs) { x = rhs.x; y = rhs.y; z = rhs.z; }
		;
		std::string ToString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std_to_string(z) + ")"; }

		// static methods

		static float Angle(const Vec3& from, const Vec3& to);

		static float SignedAngle(const Vec3& from, const Vec3& to, const Vec3& axis);

		static T Distance(const Vec3& a, const Vec3& b);

		static constexpr T Dot(const Vec3& a, const Vec3& b);

		static Vec3 Lerp(const Vec3& a, const Vec3& b, float t);

		static Vec3 LerpUnclamped(const Vec3& a, const Vec3& b, float t);

		static constexpr Vec3 Max(const Vec3& a, const Vec3& b);

		static constexpr Vec3 Min(const Vec3& a, const Vec3& b);

		static constexpr Vec3 Scale(const Vec3& a, const Vec3& b);

		static Vec3 Cross(const Vec3& a, const Vec3& b);

		static Vec3 Slerp(const Vec3& a, const Vec3& b, float t);

		static Vec3 SlerpUnclamped(const Vec3& a, const Vec3& b, float t);

		static Vec3 Project(const Vec3& vec, const Vec3& onNormal);

		static Vec3 ProjectOnPlane(const Vec3& vec, const Vec3& planeNormal);

		static Vec3 MoveTowards(const Vec3& current, const Vec3& target, float maxDistanceDelta);;

		static Vec3 RotateTowards(const Vec3& current, const Vec3& target, float maxRadiansDelta, float maxMagnitudeDelta);

		static Vec3 ClampMagnitude(const Vec3& rhs, float maxLength);

	    Vec3 Normalize(const Vec3& rhs) const; 

		static T OrthoNormalize(const Vec3& normal, const Vec3& tangent, const Vec3& binormal);
		// {

		//	Vec3 vector1 = Normalized();

		//}

		static float Reflect(const Vec3& inDirection, const Vec3& inNormal);

	};

	using Vec3f = Vec3<float>;
	using Vec3i = Vec3<int>;
	using Vec3d = Vec3<double>;
	

}
#include "Vec3.inl"