#pragma once
#include <array>
#include <cmath>
#include <iostream>
#include "Vec3.h"
#include "Quaternion.h"


namespace math {

	template <typename T>
	class Mat4x4 {
	public:
		std::array<T, 16> mat; // matrix elements in column-major order.


		// *********************** Constructors ************************


		// Default constructor. Initializes to identity matrix.
		constexpr Mat4x4();

		// Initializes matrix with a flat array of 16 values.
		constexpr Mat4x4(std::array<T, 16> values);
		

		// *********************** Static Properties ***********************


		// Returns the identity matrix. 
		// 1.00000 0.00000 0.00000 0.00000
		// 0.00000 1.00000 0.00000 0.00000
		// 0.00000 0.00000 1.00000 0.00000
		// 0.00000 0.00000 0.00000 1.00000
		static constexpr Mat4x4 Identity();

		// Returns a matrix with all elements set to zero.
		// 0.00000 0.00000 0.00000 0.00000
		// 0.00000 0.00000 0.00000 0.00000
		// 0.00000 0.00000 0.00000 0.00000
		// 0.00000 0.00000 0.00000 0.00000
		static constexpr Mat4x4 Zero();


		// *********************** operators ***********************


		// Multiplies two matrices.
		constexpr Mat4x4 operator*(const Mat4x4<T>& rhs) const;

		// Access matrix elements at (row, col).
		T& operator()(int row, int col);

		// Access matrix elements at (row, col) as const.
		const T& operator()(int row, int col) const;


		// *********************** Properties ***********************


		//  Determinant of the submatrix obtained by removing row i and column j
		T Minor(int row, int col) const;

		// Minor with an added sign, depending on the position in the matrix.
		T Cofactor(int row, int col) const;

		// Computes the determinant of the matrix.
		constexpr T Determinant() const;

		// Returns the inverse of the matrix.
		Mat4x4 Inverse() const;

		// Check if the matrix is an identity matrix.
		bool IsIdentity() const;

		// Extracts the scale from the matrix.
		Vec3<T> LossyScale() const;

		// Returns the transposed matrix.
		Mat4x4 Transpose() const;

		// Extracts the rotation as a quaternion.
		Quaternion<T> Rotation() const;
	

		// *********************** Public Methods *********************** 


		// Returns the position vector from the matrix.
		Vec3<T> GetPosition() const;
		// Returns the column at the given index.
		Vec3<T> GetColumn(int col) const;
		// Returns the row at the given index.
		Vec3<T> GetRow(int row) const;
		
		// Sets the column at the given index.
		void SetColumn(int index, const Vec3<T>& column);
		// Sets the row at the given index.
		void SetRow(int index, const Vec3<T>& row);
		// Sets the matrix using position, rotation, and scale.
		void SetTRS(const Vec3<T>& pos, const Quaternion<T>& q, const Vec3<T>& s);

		// Transforms a point using the matrix.
		Vec3<T> MultiplyPoint(const Vec3<T>& point) const;
		// Transforms a point using only the top 3x4 part of the matrix.
		Vec3<T> MultiplyPoint3x4(const Vec3<T>& point) const;
		// Transforms a direction vector (ignores translation).
		Vec3<T> MultiplyVector(const Vec3<T>& vector) const;

		// Checks if the matrix represents a valid TRS transform.
		bool ValidTRS() const;

		// Returns a string representation of the matrix.
		std::string ToString() const;


		// *********************** Static Methods *********************** 


		// Creates a perspective frustum matrix.
		static Mat4x4 Frustum(T left, T right, T bottom, T top, T zNear, T zFar);

		// Creates a scale matrix.
		static constexpr Mat4x4 Scale(const Vec3<T>& vector);

		// Creates a translation matrix.
		static constexpr Mat4x4 Translate(const Vec3<T>& vector);

		// Computes the inverse of a 3D affine matrix.
		static bool Inverse3DAffine(const Mat4x4<T>& input, Mat4x4<T>& result);

		// Creates a lookAt matrix from position and target.
		static Mat4x4 LookAt(const Vec3<T>& from, const Vec3<T>& to, const Vec3<T>& up);

		// Create a orthographic projection matrix.
		static Mat4x4 Ortho(T left, T right, T bottom, T top, T zNear, T zFar);

		// Creates a perspective projection matrix.
		static Mat4x4 Perspective(T fov, T aspect, T zNear, T zFar);

		// Creates a rotation matrix from a quaternion.
		static Mat4x4 Rotate(const Quaternion<T>& q);

		// Creates a TRS matrix from position, rotation, and scale.
		static Mat4x4 TRS(const Vec3<T>& pos, const Quaternion<T>& q, const Vec3<T>& s);
	};

	using Mat4x4f = Mat4x4<float>;
	using Mat4x4d = Mat4x4<double>;
	using Mat4x4i = Mat4x4<int>;

}

#include "Mat4x4.inl"