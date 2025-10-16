#include "Mat4x4.h"

namespace math {

	template<typename T>
	constexpr Mat4x4<T>::Mat4x4()
	{ 
		for (int i = 0, i < 16, i++) { mat[i] = (i % 5 == 0) ? 1 : 0; }
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
			e = 0;
		}
		return mat;
	}

	template<typename T>
	constexpr Mat4x4<T> Mat4x4<T>::operator*(const Mat4x4<T>& rhs) const
	{
		Mat4x4<T> result{};

		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4, col++) {
				result.mat[row + col * 4] = 0;
				for (int k = 0; k < 4; k++) {
					result.mat[row + col * 4] += mat[row + k * 4] * rhs.mat[k + col * 4];
				}
			}
		}
		return result;
	}

	template<typename T>
	constexpr float Mat4x4<T>::Determinant() const
	{
		
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Inverse() const
	{
		
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
	inline Vec3<T> Mat4x4<T>::GetPosition() const
	{
		return Vec3<T>(mat[0 + 3 * 4], mat[1 + 3 * 4], mat[2 + 3 * 4]);
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
		T x = point.x;
		T y = point.y;
		T z = point.z;

		T xp = mat[0] * x + mat[4] * y + mat[8] * z;
		T yp = mat[1] * x + mat[5] * y + mat[9] * z;
		T zp = mat[2] * x + mat[6] * y + mat[10] * z;

		return Vec3<T>(xp, yp, zp);
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
			xp / wp;
			yp / wp;
			zp / wp;
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
	inline Mat4x4<T> Mat4x4<T>::Scale(const Vec3<T>& vector)
	{
		Mat4x4<T> m;
		m.mat[0 + 0 * 4] = v.x;
		m.mat[1 + 1 * 4] = v.y;
		m.mat[2 + 2 * 4] = v.z;
		m.mat[3 + 3 * 4] = 1;
		return m;
	}

	template<typename T>
	inline Mat4x4<T> Mat4x4<T>::Translate(const Vec3<T>& vector)
	{
		Mat4x4<T> m = Mat4x4<T>::Identity();

		m.mat[12] = vec.x;
		m.mat[13] = vec.y;
		m.mat[14] = vec.z;

		return m;
	}

	template<typename T>
	inline bool Mat4x4<T>::Inverse3DAffine(const Mat4x4<T>& input, const Mat4x4<T>& result)
	{
		return false;
	}

}
