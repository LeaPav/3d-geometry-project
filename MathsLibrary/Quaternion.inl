#include "Quaternion.h"

namespace math {

	//static properties


	//properties

	template <typename T>
	constexpr Vec4<T>::Vec4() : x(0), y(0), z(0), w(0) {}

	template <typename T>
	constexpr Vec4<T>::Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

	//public methods

	//template <typename T>
	//bool Equals(const Vec4& rhs) const
	//{
	//	 return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w);
	//}

	//template <typename T>
	//void Set(const Vec4& rhs)
	//{
	//}

	//template <typename T>
	//T SetFromToRotation(const Vec3& fromDirection, const Vec3& toDirection)
	//{
	//	return T();
	//}

	//template <typename T>
	//T SetLookRotation(const Vec3& view, Vec3 up)
	//{
	//	return T();
	//}

	//template <typename T>
	//T ToAngleAxis()
	//{
	//	return T();
	//}


	//static methods

	template <typename T>
	inline float math::Vec4<T>::Angle(const Vec4& from, const Vec4& to)
	{
		float magnitudeFrom = std::sqrt(from.x * from.x + from.y * from.y + from.z * from.z + from.w * from.w);
		float magnitudeTo = std::sqrt(to.x * to.x + to.y * to.y + to.z * to.z + to.w * to.w);

		float dot = Dot(from, to);

		if (magnitudeFrom == 0 || magnitudeTo == 0) return 0.0f;

		float cosTheta = dot / (magnitudeFrom * magnitudeTo);
		cosTheta = std::fmax(-1.f, std::fmin(1.f, cosTheta));

		return std::acos(cosTheta);
	}

	template <typename T>
	//AngleAxis

	template<typename T>
	constexpr T Vec4<T>::Dot(const Vec4& a, const Vec4& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; // produit scalaire
	}

	template <typename T>
	T Euler()
	{
		return T();
	}

	template <typename T>
	inline Vec4<T> Vec4<T>::Lerp(const Vec4& a, const Vec4& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));
		return Vec4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
	}

	template <typename T>
	inline Vec4<T> Vec4<T>::LerpUncampled(const Vec4& a, const Vec4& b, float t)
	{
		return Vec4(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
	}

	template <typename T>
	T LookRotation()
	{
		return T();
	}

	/*template <typename T>
	Vec4 Normalize(const Vec4& rhs) const
	{
	    float magnitude = std::sqrt(x * x + y * y + z * z + w * w);
	    
	    if (magnitude < 0.00001f) {
	        return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
	    }

	   return Vec4(x/ magnitude, y/ magnitude, z/ magnitude, w/ magnitude);
	}*/

	template <typename T>
	T RotateTowards()
	{
		return T();
	}

	template <typename T>
	inline Vec4<T> Vec4<T>::Slerp(const Vec4& a, const Vec4& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));

		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(a, b))); // faudra changer apres pour pouvoir mettre a.Normalized et b.Normalized
		T theta = std::acos(dot);
		return (a * (std::sin((1 - t) * theta) / std::sin(theta)) + b * (std::sin(t * theta) / std::sin(theta)));

	}

	template <typename T>
	inline Vec4<T> Vec4<T>::SlerpUncampled(const Vec4& a, const Vec4& b, float t)
	{
		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(a, b))); // faudra changer apres pour pouvoir mettre a.Normalized et b.Normalized
		T theta = std::acos(dot);
		return (a * (std::sin((1 - t) * theta) / std::sin(theta)) + b * (std::sin(t * theta) / std::sin(theta)));
	}


	//operators
	
	template<typename T>
	constexpr Vec4<T> Vec4<T>::operator*(T scalar) const
	{
		return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	template<typename T>
	constexpr bool Vec4<T>::operator==(const Vec4& vec) const
	{
		return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
	}
}