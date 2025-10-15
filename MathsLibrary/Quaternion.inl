#include "Quaternion.h"
#include "Vec3.h"


namespace math {

	//static properties

	template <typename T>
	constexpr Quaternion<T>::Quaternion() : x(0), y(0), z(0), w(0) {}

	template <typename T>
	constexpr Quaternion<T>::Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

	//properties

	template<typename T>
	inline Quaternion<T> Quaternion<T>::EulerAngles() //impossible de mettre Vec3<T>
	{
		//rotation autour de X
		T sinr_cosp = 2 * (w * x + y * z);
		T cosr_cosp = 1 - 2 * (x * x + y * y);
		T roll = std::atan2(sinr_cosp, cosr_cosp);

		//rotation autour de Y
		T sinp = 2 * (w * y - z * x);
		T pitch;
		if (std::abs(sinp) >= 1) {
			pitch = (sinp < 0 ? -1 : 1) * 3.14159265f / 2;
		}
		else {
			pitch = std::asin(sinp);
		}

		//rotation autour de Z
		T siny_cosp = 2 * (w * z + x * y);
		T cosy_cosp = 1 - 2 * (y * y + z * z);
		T yaw = std::atan2(siny_cosp, cosy_cosp);

		T deg = 180.0 / 3.14159265f;
		T roll_deg = roll * deg;
		T pitch_deg = pitch * deg;
		T yaw_deg = yaw * deg;

		return Vec3<T>(roll_deg, pitch_deg, yaw_deg);
	}

	template <typename T>
	constexpr Quaternion<T> Quaternion<T>::Normalized() const {
		 float magnitude = std::sqrt(x * x + y * y + z * z + w * w); 

		 if (magnitude < 0.00001f) { 
			 return Quaternion(0.0f, 0.0f, 0.0f, 0.0f); 
		 }

		 return Quaternion(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
	}

	template<typename T>
	inline bool Quaternion<T>::Equals(const Quaternion& rhs) const
	{
		return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w);
	}

	template<typename T>
	inline void Quaternion<T>::Set(const Quaternion& rhs)
	{
		return  x = rhs.x, y = rhs.y, z = rhs.z, w = rhs.w;
	}


	template<typename T>
	inline void Quaternion<T>::SetFromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection)
	{
	
		Vec3<T> a = fromDirection.Normalized();
		Vec3<T> b = toDirection.Normalized();
	
		Vec3<T> cross = Vec3<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	
		T dot = a.x * b.x + a.y * b.y + a.z * b.z;
		
		
	
		if (a >= 1 && b >= 1) {
			return a.dot(b);
		}

	
	}



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
	inline float math::Quaternion<T>::Angle(const Quaternion& from, const Quaternion& to)
	{
		float magnitudeFrom = std::sqrt(from.x * from.x + from.y * from.y + from.z * from.z + from.w * from.w);
		float magnitudeTo = std::sqrt(to.x * to.x + to.y * to.y + to.z * to.z + to.w * to.w);

		float dot = Dot(from, to);

		if (magnitudeFrom == 0 || magnitudeTo == 0) return 0.0f;

		float cosTheta = dot / (magnitudeFrom * magnitudeTo);
		cosTheta = std::fmax(-1.f, std::fmin(1.f, cosTheta));

		return std::acos(cosTheta) * (180.0f / 3.14159265f );
	}

	//template <typename T>
	//AngleAxis

	template<typename T>
	constexpr T Quaternion<T>::Dot(const Quaternion& a, const Quaternion& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; // produit scalaire
	}

	template <typename T>
	T Euler()
	{
		return T();
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::Lerp(const Quaternion& a, const Quaternion& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));
		return Quaternion(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::LerpUncampled(const Quaternion& a, const Quaternion& b, float t)
	{
		return Quaternion(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
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
	inline Quaternion<T> Quaternion<T>::Slerp(const Quaternion& a, const Quaternion& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));

		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(a, b))); // faudra changer apres pour pouvoir mettre a.Normalized et b.Normalized
		T theta = std::acos(dot);
		return (a * (std::sin((1 - t) * theta) / std::sin(theta)) + b * (std::sin(t * theta) / std::sin(theta)));

	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::SlerpUncampled(const Quaternion& a, const Quaternion& b, float t)
	{
		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(a, b))); // faudra changer apres pour pouvoir mettre a.Normalized et b.Normalized
		T theta = std::acos(dot);
		return (a * (std::sin((1 - t) * theta) / std::sin(theta)) + b * (std::sin(t * theta) / std::sin(theta)));
	}


	//operators
	
	template<typename T>
	constexpr Quaternion<T> Quaternion<T>::operator*(T scalar) const
	{
		return Quaternion(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	template<typename T>
	constexpr bool Quaternion<T>::operator==(const Quaternion& vec) const
	{
		return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
	}
}