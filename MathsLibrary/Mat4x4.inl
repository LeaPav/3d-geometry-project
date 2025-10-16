#include "Mat4x4.h"

namespace math {

	template<typename T>
	constexpr Mat4x4<T>::Mat4x4()
	{ 
		for (int i = 0; i < 16; i++) {
			mat[i] = (i % 5 == 0) ? 1 : 0; 
		}
	}

	template<typename T>
	constexpr Mat4x4<T>::Mat4x4(std::array<T, 16> values) : mat(values) {}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Identity()
	{
		return Mat4x4();
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Zero()
	{
		Mat4x4 mat;
		for (auto& m : mat.mat) {
			m = 0;
		}
		return mat;
	}

	template<typename T>
	constexpr Mat4x4<T> Mat4x4<T>::operator*(const Mat4x4<T>& rhs) const
	{
		Mat4x4<T> result{};

		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				result.mat[row + col * 4] = 0;
				for (int k = 0; k < 4; k++) {
					result.mat[row + col * 4] += mat[row + k * 4] * rhs.mat[k + col * 4];
				}
			}
		}
		return result;
	}

	template<typename T>
	inline T& Mat4x4<T>::operator()(int row, int col)
	{
		return mat[col * 4 + row];
	}

	template<typename T>
	inline const T& Mat4x4<T>::operator()(int row, int col) const
	{
		return mat[col * 4 + row];
	}

	template<typename T>
	inline T Mat4x4<T>::Minor(int row, int col) const
	{
		T sub[9];
		int index = 0;

		for (int c = 0; c < 4; c++) {
			if (c == col) continue;
			for (int r = 0; r < 4; r++) {
				if (r == row) continue;
				sub[index++] = mat[c * 4 + r];
			}
		}
		return
			sub[0] * (sub[4] * sub[8] - sub[5] * sub[7])
			- sub[1] * (sub[3] * sub[8] - sub[5] * sub[6])
			+ sub[2] * (sub[3] * sub[7] - sub[4] * sub[6]);
	}

	template<typename T>
	inline T Mat4x4<T>::Cofactor(int row, int col) const
	{
		T minor = Minor(row, col);
		if ((row + col) % 2 != 0) {
			minor = -minor;
		}
		return minor;
	}

	template<typename T>
	constexpr T Mat4x4<T>::Determinant() const
	{
		T det = 0;
		for (int col = 0; col < 4; col++) {
			det += mat[col * 4 + 0] * Cofactor(0, col);
		}
		return det;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Inverse() const
	{
		T det = Determinant();
		if (det == static_cast<T>(0))
			throw std::runtime_error("matrix not invertible");

		Mat4x4<T> transposed;
		for (int col = 0; col < 4; col++) {
			for (int row = 0; row < 4; row++) {
				transposed(col, row) = Cofactor(row, col);
			}
		}

		for (int i = 0; i < 16; i++) {
			transposed.mat[i] /= det;
		}
		return transposed;
	}

	template<typename T>
	inline bool Mat4x4<T>::IsIdentity() const
	{
		for (int col = 0; col < 4; col++) {
			for (int row = 0; row < 4; row++) {
				if (mat[col * 4 + row] != ((row == col) ? 1 : 0))
					return false;
			}
		}
		return true;
	}

	template<typename T>
	inline Vec3<T> Mat4x4<T>::LossyScale() const
	{
		Vec3<T> scale;

		scale.x = std::sqrt(mat[0] * mat[0] + mat[1]*mat[1] + mat[2] * mat[2]);
		scale.y = std::sqrt(mat[4] * mat[4] + mat[5]*mat[5] + mat[6] * mat[6]);
		scale.z = std::sqrt(mat[8] * mat[8] + mat[9]*mat[9] + mat[10] * mat[10]);

		return scale;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Transpose() const
	{
		Mat4x4<T> result;
		for (int col = 0; col < 4; col++) {
			for (int row = 0; row < 4; row++) {
				result.mat[col * 4 + row] = mat[row * 4 + col];
			}
		}
		return result;
	}

	template<typename T>
	inline Quaternion<T> Mat4x4<T>::Rotation() const
	{
		T m00 = mat[0], m01 = mat[4], m02 = mat[8];
		T m10 = mat[1], m11 = mat[5], m12 = mat[9];
		T m20 = mat[2], m21 = mat[6], m22 = mat[10];

		T trace = m00 + m11 + m22;
		Quaternion<R> q;

		if (trace > 0) {
			T s = std::sqrt(trace + 1.0) * 2;
			q.w = 0.25 * s;
			q.x = (m21 - m12) / s;
			q.y = (m02 - m20) / s;
			q.z = (m10 - m01) / s;
		}
		else if ((m00 > m11) && (m00 > m22)) {
			T s = std::sqrt(1.0 + m00 - m11 - m22) * 2;
			q.w = (m21 - m12) / s;
			q.x = 0.25 * s;
			q.y = (m01 + m10) / s;
			q.z = (m02 + m20) / s;
		}
		else if (m11 > m22) {
			T s = std::sqrt(1.0 + m11 - m00 - m22) * 2;
			q.w = (m02 - m20) / s;
			q.x = (m01 + m10) / s;
			q.y = 0.25 * s;
			q.z = (m12 + m21) / s;
		}
		else
		{
			T s = std::sqrt(1.0 + m22 - m00 - m11) * 2; 
			q.w = (m10 - m01) / s;
			q.x = (m02 + m20) / s;
			q.y = (m12 + m21) / s;
			q.z = 0.25 * s;
		}
		return q;
	}

	template<typename T>
	inline Vec3<T> Mat4x4<T>::GetPosition() const
	{
		return Vec3<T>(mat[0 + 3 * 4], mat[1 + 3 * 4], mat[2 + 3 * 4]);
	}

	template<typename T>
	inline Vec3<T> Mat4x4<T>::GetColumn(int col) const
	{
		return Vec3<T>(mat[col*4 + 0], mat[col*4 +1], mat[col*4+2]);
	}

	template<typename T>
	inline Vec3<T> Mat4x4<T>::GetRow(int row) const
	{
		return Vec3<T>(mat[0*4 +row], mat[1*4 + row], mat[2*4 + row]);
	}

	template<typename T>
	inline Vec3<T> Mat4x4<T>::MultiplyPoint3x4(const Vec3<T>& point) const
	{
		T x = point.x;
		T y = point.y;
		T z = point.z;

		T xp = mat[0] * x + mat[4] * y + mat[8] * z + mat[12];
		T yp = mat[1] * x + mat[5] * y + mat[9] * z + mat[13];
		T zp = mat[2] * x + mat[6] * y + mat[10] * z + mat[14];

		return Vec3<T>(xp, yp, zp);
	}

	template<typename T>
	inline Vec3<T> Mat4x4<T>::MultiplyVector(const Vec3<T>& vector) const
	{
		T x = vector.x;
		T y = vector.y;
		T z = vector.z;

		T xp = mat[0] * x + mat[4] * y + mat[8] * z;
		T yp = mat[1] * x + mat[5] * y + mat[9] * z;
		T zp = mat[2] * x + mat[6] * y + mat[10] * z;

		return Vec3<T>(xp, yp, zp);
	}

	template<typename T>
	inline bool Mat4x4<T>::ValidTRS() const
	{
		return mat[3] == 0 && mat[7] == 0 && mat[11] == 0 && mat[15] == 1;
	}

	template<typename T>
	inline void Mat4x4<T>::SetColumn(int index, const Vec3<T>& column)
	{
		mat[index*4+0] = column.x;
		mat[index*4+1] = column.y;
		mat[index*4+2] = column.z;
	}

	template<typename T>
	inline void Mat4x4<T>::SetRow(int index, const Vec3<T>& row)
	{
		mat[0*4 + index] = row.x;
		mat[1 * 4 + index] = row.y;
		mat[2 * 4 + index] = row.z;
	}

	template<typename T>
	inline void Mat4x4<T>::SetTRS(const Vec3<T>& pos, const Quaternion<T>& q, const Vec3<T>& s)
	{
		*this = TRS(pos, q, s);
	}

	template<typename T>
	inline Vec3<T> Mat4x4<T>::MultiplyPoint(const Vec3<T>& point) const
	{
		T x = point.x;
		T y = point.y;
		T z = point.z;

		T xp = mat[0] * x + mat[4] * y + mat[8] * z + mat[12];
		T yp = mat[1] * x + mat[5] * y + mat[9] * z + mat[13];
		T zp = mat[2] * x + mat[6] * y + mat[10] * z + mat[14];
		T wp = mat[3] * x + mat[7] * y + mat[11] * z + mat[15];
		if (wp != 0 && wp != 1) {
			xp /= wp;
			yp /= wp;
			zp /= wp;
		}
		return Vec3<T>(xp, yp, zp);
	}

	template<typename T>
	inline std::string Mat4x4<T>::ToString() const
	{
		std::string s;
		for (int row = 0; row < 4; row++) {
			s += "| ";
			for (int col = 0; col < 4; col++) {
				s += std::to_string(mat[row + col * 4]);
				if (col < 3) s += "\t";
			}
			s += " |\n";
		}
		return s;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Frustum(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		Mat4x4<T> m = Mat4x4<T>::Zero();
		m(0, 0) = 2 * zNear / (right - left);
		m(1, 1) = 2 * zNear / (top - bottom);
		m(0, 2) = (right + left) / (right - left);
		m(1, 2) = (top + bottom) / (top - bottom);
		m(2, 2) = (zFar + zNear) / (zNear - zFar);
		m(2, 3) = 2 * zFar * zNear / (zNear - zFar);
		m(3, 2) = -1;

		return m;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Scale(const Vec3<T>& vector)
	{
		Mat4x4<T> m;
		m.mat[0 + 0 * 4] = vector.x;
		m.mat[1 + 1 * 4] = vector.y;
		m.mat[2 + 2 * 4] = vector.z;
		m.mat[3 + 3 * 4] = 1;
		return m;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Translate(const Vec3<T>& vector)
	{
		Mat4x4<T> m = Mat4x4<T>::Identity();

		m.mat[12] = vector.x;
		m.mat[13] = vector.y;
		m.mat[14] = vector.z;

		return m;
	}

	template<typename T>
	inline bool Mat4x4<T>::Inverse3DAffine(const Mat4x4<T>& input, Mat4x4<T>& result)
	{
		Mat4x4<T> r = Mat4x4<T>::Identity();
		r.mat[0] = input.mat[0]; r.mat[1] = input.mat[1]; r.mat[2] = input.mat[2];
		r.mat[4] = input.mat[4]; r.mat[5] = input.mat[5]; r.mat[6] = input.mat[6];
		r.mat[8] = input.mat[8]; r.mat[9] = input.mat[9]; r.mat[10] = input.mat[10];

		Vec3<T> A(input.mat[12], input.mat[13], input.mat[14]);

		T detR = r.Determinant();
		if (detR == static_cast<T>(0)) { result = input; return false; }

		Mat4x4 inverseR = r.Inverse();
		Vec3<T> newT = inverseR.MultiplyVector(A) * static_cast<T>(-1);

		result = Mat4x4<T>::Identity();
		result.mat[0] = inverseR.mat[0]; result.mat[1] = inverseR.mat[1]; result.mat[2] = inverseR.mat[2];
		result.mat[4] = inverseR.mat[4]; result.mat[5] = inverseR.mat[5]; result.mat[6] = inverseR.mat[6];
		result.mat[8] = inverseR.mat[8]; result.mat[9] = inverseR.mat[9]; result.mat[10] = inverseR.mat[10];
		result.mat[12] = newT.x;
		result.mat[13] = newT.y;
		result.mat[14] = newT.z;

		return true;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::LookAt(const Vec3<T>& from, const Vec3<T>& to, const Vec3<T>& up)
	{
		Vec3<T> f = (to - from).Normalized();
		Vec3<T> r = f.Cross(f, up).Normalized();
		Vec3<T> u = f.Cross(r, f);
		Mat4x4<T> result = Mat4x4<T>::Identity();

		result.mat[0] = r.x; result.mat[1] = r.y; result.mat[2] = r.z; result.mat[3] = 0; 
		result.mat[4] = u.x; result.mat[5] = u.y; result.mat[6] = u.z; result.mat[7] = 0;
		result.mat[8] = -f.x; result.mat[9] = -f.y; result.mat[10] = -f.z; result.mat[11] = 0;
		result.mat[12] = from.x; result.mat[13] = from.y; result.mat[14] = from.z; result.mat[15] = 1;

		return result;
 	}
	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Ortho(T left, T right, T bottom, T top, T zNear, T zFar)
	{
		Mat4x4 result = Mat4x4<T>::Identity();

		result.mat[0] = 2.f / (right - left);
		result.mat[5] = 2.f / (top - bottom);
		result.mat[10] = 2.f / (zNear - zFar);

		result.mat[12] = -(right + left) / (right - left);
		result.mat[13] = -(top + bottom) / (top - bottom);
		result.mat[14] = -(zFar + zNear) / (zFar - zNear);

		return result;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Perspective(T fov, T aspect, T zNear, T zFar)
	{
		T fovRad = fov * static_cast<T>(3.14159265f) / 180.f;
		T f = 1.f / std::tan(fovRad / 2.0f);

		Mat4x4<T> result = Mat4x4<T>::Zero();

		result.mat[0] = f / aspect;
		result.mat[5] = f;
		result.mat[10] = (zFar + zNear) / (zNear - zFar);
		result.mat[14] = (2 * zFar * zNear) / (zNear - zFar);
		result.mat[11] = -1;

		return result;

	}
	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Rotate(const Quaternion<T>& q)
	{
		Mat4x4<T> m;

		T xx = q.x * q.x;
		T yy = q.y * q.y;
		T zz = q.z * q.z;
		T xy = q.x * q.y;
		T xz = q.x * q.z;
		T yz = q.y * q.z;
		T wx = q.w * q.x;
		T wy = q.w * q.y;
		T wz = q.w * q.z;

		m.mat[0] = 1 - 2 * (yy + zz);
		m.mat[1] = 2 * (xy + wz);
		m.mat[2] = 2 * (xz - wy);
		m.mat[3] = 0;

		m.mat[4] = 2 * (xy - wz);
		m.mat[5] = 1 - 2 * (xx + zz);
		m.mat[6] = 2 * (yz + wx);
		m.mat[7] = 0;

		m.mat[8] = 2 * (xz + wy);
		m.mat[9] = 2 * (yz - wx);
		m.mat[10] = 1 - 2 * (xx + yy);
		m.mat[11] = 0;

		m.mat[12] = 0; m.mat[13] = 0; m.mat[14] = 0; m.mat[15] = 1;

		return m;

	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::TRS(const Vec3<T>& pos, const Quaternion<T>& q, const Vec3<T>& s)
	{
		Mat4x4<T> result;

		Mat4x4<T> rot = Rotate(q);

		rot.mat[0] *= s.x; rot.mat[1] *= s.x; rot.mat[2] *= s.x;
		rot.mat[4] *= s.y; rot.mat[5] *= s.y; rot.mat[6] *= s.y;
		rot.mat[8] *= s.z; rot.mat[9] *= rot.mat[10] *= s.z;

		rot.mat[12] = pos.x;
		rot.mat[13] = pos.y;
		rot.mat[14] = pos.z;

		return rot;
	}
	

}
