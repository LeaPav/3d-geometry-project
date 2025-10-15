#pragma once
#include <array>
#include <cmath>
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
	};
	
}

#include "Mat4x4.inl"