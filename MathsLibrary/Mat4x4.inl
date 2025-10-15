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


}
