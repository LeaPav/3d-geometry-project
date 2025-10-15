#pragma once
#include <array>
#include <cmath>
#include <iostream>
#include "Vec3.h"


namespace math {

	template <typename T>
	class Mat4x4 {
	public:
		std::array<T, 16> mat;


		// *********************** Constructors ************************

		
		constexpr Mat4x4();

		constexpr Mat4x4(std::array<T, 16> values);
		
		// Static Properties

		// Returns the identity matrix. 
		// 1.00000 0.00000 0.00000 0.00000
		// 0.00000 1.00000 0.00000 0.00000
		// 0.00000 0.00000 1.00000 0.00000
		// 0.00000 0.00000 0.00000 1.00000
		static Mat4x4 Identity();

		// Returns a matrix with all elements set to zero.
		// 0.00000 0.00000 0.00000 0.00000
		// 0.00000 0.00000 0.00000 0.00000
		// 0.00000 0.00000 0.00000 0.00000
		// 0.00000 0.00000 0.00000 0.00000
		static Mat4x4 Zero();

		// operator

		constexpr Mat4x4 operator*(const Mat4x4<T>& rhs) const;

		// Properties

		float Determinant() const;

		Mat4x4 Inverse() const;

		bool IsIdentity() const;

		// Public Methods

		Vec3<T> GetPosition() const;
		Vec3<T> MultiplyPoint(const Vec3<T>& point) const;
		Vec3<T> MultiplyPoint3x4(const Vec3<T>& point) const;
		Vec3<T> MultiplyVector(const Vec3<T>& vector) const;

		std::string ToString() const;

		// Static Methods

		static Mat4x4 Frustum(float left, float right, float bottom, float top, float zNear, float zFar);

		static Mat4x4 Scale(const Vec3<T>& vector);

		static Mat4x4 Translate(const Vec3<T>& vector);
	};
	
}

#include "Mat4x4.inl"