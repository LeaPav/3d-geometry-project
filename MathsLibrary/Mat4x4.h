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

		// operators

		constexpr Mat4x4 operator*(const Mat4x4<T>& rhs) const;

		T& operator()(int row, int col);

		const T& operator()(int row, int col) const;
		// Properties

		//  determinant of the submatrix obtained by removing row i and column j
		T Minor(int row, int col) const;

		//minor with an added sign, depending on the position in the matrix.
		T Cofactor(int row, int col) const;

		constexpr T Determinant() const;

		Mat4x4 Inverse() const;

		bool IsIdentity() const;

		Vec3<T> LossyScale() const;

		Mat4x4 Transpose() const;

		// Quaternion rotation() const;
	

		// Public Methods

		Vec3<T> GetPosition() const;
		Vec3<T> GetColumn(int col) const;
		Vec3<T> GetRow(int row) const;
		
		void SetColumn(int index, const Vec3<T>& column);
		void SetRow(int index, const Vec3<T>& row);
		// void SetTRS(Vec3 pos, Quaternion q, Vec3 s);

		Vec3<T> MultiplyPoint(const Vec3<T>& point) const;
		Vec3<T> MultiplyPoint3x4(const Vec3<T>& point) const;
		Vec3<T> MultiplyVector(const Vec3<T>& vector) const;

		//bool ValidTRS() const;

		std::string ToString() const;

		// Static Methods

		static Mat4x4 Frustum(T left, T right, T bottom, T top, T zNear, T zFar);

		static Mat4x4 Scale(const Vec3<T>& vector);

		static Mat4x4 Translate(const Vec3<T>& vector);

		static bool Inverse3DAffine(const Mat4x4<T>& input, Mat4x4<T>& result);

		static Mat4x4 LookAt(const Vec3<T>& from, const Vec3<T>& to, const Vec3<T>& up);

		static Mat4x4 Ortho(T left, T right, T bottom, T top, T zNear, T zFar);

		static Mat4x4 Perspective(T fov, T aspect, T zNear, T zFar);

		//static Mat4x4 Rotate(Quaternion q);

		// static Mat4x4 TRS(Vec3 pos, Quaternion q, Vec3 s);
	};
	


}

#include "Mat4x4.inl"