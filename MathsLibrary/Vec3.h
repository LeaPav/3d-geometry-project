#pragma once
#include <limits>
#include <cmath>
#include <iostream>

namespace math {

	template <typename T>
	class Vec3 {
	public:
		T x;
		T y;
		T z;

		// Default constructor. Initializes x, y, z to zero. 
		constexpr Vec3();
		// Initilaizes vector with given x, y, z values.
		constexpr Vec3(T x, T y, T z);


		// *************operators*************


		// Adds two vectors.
		constexpr Vec3 operator+(const Vec3& rhs) const;
		// Subtracts two vectors.
		constexpr Vec3 operator-(const Vec3& rhs) const;
		// Multiplies vector by a scalar.
		constexpr Vec3 operator*(T scalar) const;
		// Divides vector by a scalar.
		constexpr Vec3 operator/(T scalar) const;
		// Checks if two vectors are equals.
		constexpr bool operator==(const Vec3& vec) const;
		// Checks if two vectors are not equals.
		constexpr bool operator!=(const Vec3& vec) const;

		// Accesses x, y, z by index (0 = x, 1 = y, 2 = z).
		T& operator[](int index);


		// *************static properties*************


		//Returns a vector pointing down (0, -1, 0).
		static constexpr Vec3 Down();
		// Returns a vector pointing back (0, 0, -1).
		static constexpr Vec3 Back();
		// Returns a vector pointing forward (0, 0, 1).
		static constexpr Vec3 Forward();
		// Returns a vector pointing left (-1, 0, 0).
		static constexpr Vec3 Left();
		// Returns a vector with all components set to 1. 
		static constexpr Vec3 One();
		// Returns a vector pointing right (1, 0, 0).
		static constexpr Vec3 Right();
		// Returns a vector pointing up (0, 1, 0).
		static constexpr Vec3 Up();
		// Returns a vector with all components set to 0.
		static constexpr Vec3 Zero();

		// Returns a vector with all components set to negative infinity.
		static constexpr Vec3 NegativeInfinity();
		// Return a vector with all components set to positive infinity.
		static constexpr Vec3 PositiveInfinity();


		// *************properties*************


		// Returns the magnitude (length) of the vector. The legnth of the vector is square root of (x*x, y*y, z*z).
		float Magnitude() const;
		// Returns a normalized copy of the vector. It does not modify the current vector.
		Vec3 Normalized() const;
		// Returns the squared magnitude(avoids sqrt).
		float SqrMagnitude() const;


		// *************public methods*************


		// Check if another vector is equal to this one.
		bool Equals(const Vec3& rhs) const; 

		// Sets the x, y and z components.
		void Set(T newX, T newY, T newZ ); 

		// Returns a string representation of the vector.
		std::string ToString() const; 

		// Normalizes the vector in-place. Note that this method is modifying the current vector.
		void Normalize();


		// *************static methods*************


		// Returns the angle in radiant between two vectors. 
		static float Angle(const Vec3& from, const Vec3& to);

		// Returns the signed angle in radiant between two vectors. 
		static float SignedAngle(const Vec3& from, const Vec3& to, const Vec3& axis);

		// Returns the distance between two vectors.
		static T Distance(const Vec3& a, const Vec3& b);

		// Returns the dot product of two vectors.
		static constexpr T Dot(const Vec3& a, const Vec3& b);

		// Linearly interpolates between two vectors.
		static Vec3 Lerp(const Vec3& a, const Vec3& b, float t);

		// Linearly interpolates without clamping.
		static Vec3 LerpUnclamped(const Vec3& a, const Vec3& b, float t);

		// Returns the component-wise maximum of two vectors.
		static constexpr Vec3 Max(const Vec3& a, const Vec3& b);

		// Returns the component-wise mimimum of two vectors.
		static constexpr Vec3 Min(const Vec3& a, const Vec3& b);

		// Multiplies two vectors component-wise.
		static constexpr Vec3 Scale(const Vec3& a, const Vec3& b);

		// Returns the cross product of two vectors.
		static Vec3 Cross(const Vec3& a, const Vec3& b);

		// Spherical interpolation between two vectors.
		static Vec3 Slerp(const Vec3& a, const Vec3& b, float t);

		// Spherical interpolation without clamping.
		static Vec3 SlerpUnclamped(const Vec3& a, const Vec3& b, float t);

		// Projects a vector onto another. The resulting projection is the amount of vector that points in the same direction as onNormal.
		static Vec3 Project(const Vec3& vec, const Vec3& onNormal);

		// Projects a vector onto a plane.
		static Vec3 ProjectOnPlane(const Vec3& vec, const Vec3& planeNormal);

		// Move a vector towards a target by a maximum delta.
		static Vec3 MoveTowards(const Vec3& current, const Vec3& target, float maxDistanceDelta);;

		// Rotates a vector towards a targent with angular and magnitude constraints.
		static Vec3 RotateTowards(const Vec3& current, const Vec3& target, float maxRadiansDelta, float maxMagnitudeDelta);

		// Clamps the magnitude of a vector to a maximum length.
		static Vec3 ClampMagnitude(const Vec3& rhs, float maxLength);

		// Returns a normalized copy of a vector.
		static Vec3 Normalize(const Vec3& rhs);

		// OrthoNomarlizes two vectors.
		static void OrthoNormalize(Vec3& normal, Vec3& tangent);

		// OrthoNormalizes three vectors.
		static void OrthoNormalize(Vec3& normal, Vec3& tangent, Vec3& binormal);

		// Reflects a vector off a surface with a given normal.
		static Vec3 Reflect(const Vec3& inDirection, const Vec3& inNormal);

	};

	using Vec3f = Vec3<float>;
	using Vec3i = Vec3<int>;
	using Vec3d = Vec3<double>;
	

}
#include "Vec3.inl"

