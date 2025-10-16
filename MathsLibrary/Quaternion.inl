#include "Quaternion.h"
#include "Vec3.h"


namespace math {

	template <typename T>
	constexpr Quaternion<T>::Quaternion() : x(0), y(0), z(0), w(0) {}

	template <typename T>
	constexpr Quaternion<T>::Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

	//static properties

	template<typename T>
	inline static Quaternion<T> Quaternion<T>::Identity()
	{
		return Quaternion<T>(0, 0, 0, 1);
	}

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
	
		//T deg = 180.0 / 3.14159265f;
		//T roll_deg = roll * deg;
		//T pitch_deg = pitch * deg;
		//T yaw_deg = yaw * deg;
	
		return Vec3<T>(roll, pitch, yaw);
	}


	template <typename T>
	constexpr Quaternion<T> Quaternion<T>::Normalized() const {
		 T magnitude = std::sqrt(x * x + y * y + z * z + w * w); 

		 if (magnitude < T(0.00001)) { 
			 return Quaternion<T>(0, 0, 0, 0); 
		 }

		 return Quaternion<T>(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
	}

	//this[int]

	//public methods

	template<typename T>
	inline bool Quaternion<T>::Equals(const Quaternion& rhs) const
	{
		return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w);
	}

	template<typename T>
	inline void Quaternion<T>::Set(const Quaternion<T>& rhs)
	{
		x = rhs.x; y = rhs.y; z = rhs.z; w = rhs.w;
	}

	template<typename T>
	inline void Quaternion<T>::SetFromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection)
	{
	
		Vec3<T> a = fromDirection.Normalized();
		Vec3<T> b = toDirection.Normalized();
	
		Vec3<T> cross = Vec3<T>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	
		T dot = a.x * b.x + a.y * b.y + a.z * b.z;
		
		if (dot > 1 - T(0.00001)) {
			return;
		}

		Vec3<T> orthogonal = Vec3<T>(1, 0, 0);

		if (dot < -1 + T(0.00001)) {
			if (std::fabs(a.x) > 0.9f) {
				orthogonal = Vec3<T>(0, 1, 0);
			}

			Vec3<T> perpendicular = a.Cross(orthogonal).Normalized();
			*this = Quaternion<T>(perpendicular.x, perpendicular.y, perpendicular.z, 0);
			
			return;
		}

		Vec3<T> axis = cross;

		T w = std::sqrt((1 + dot) * 2);
		T scaling = 1 / w;

		*this = Quaternion<T>(axis.x * scaling, axis.y * scaling, axis.z * scaling, w * 0.5f);

	}

	template <typename T>
	inline void Quaternion<T>::SetLookRotation(const Vec3<T>& view, const Vec3<T>& up)
	{
		Vec3<T> view = view.Normalized();
		Vec3<T> up = up.Normalized();

		Vec3<T> axisX = up.Cross(view).Normalized();
		Vec3<T> axisY = view.Cross(axisX);

		T m00 = axisX.x, m01 = axisY.x, m02 = view.x;
		T m10 = axisX.y, m11 = axisY.y, m12 = view.y;
		T m20 = axisX.z, m21 = axisY.z, m22 = view.z;

		T trace = m00 + m11 + m22;
		
		if (trace > 0) {
			T scaling = std::sqrt(1 + trace) * 2;

			if (std::abs(scaling) < T(0.00001)) {
				*this = Quaternion<T>::Identity();
				return;
			}

			w = scaling / 4;
			x = (m21 - m12) / scaling;
			y = (m02 - m20) / scaling;
			z = (m10 - m01) / scaling;

		}else if (m00 > m11 && m00 > m22){
			T scaling = std::sqrt(1 + m00 - m11 - m22) * 2;

			if (std::abs(scaling) < T(0.00001)) {
				*this = Quaternion<T>::Identity();
				return;
			}

			x = scaling / 4;
			w = (m21 - m12) / scaling;
			y = (m10 + m01) / scaling;
			z = (m20 + m02) / scaling;

		}else if (m11 > m00 && m11 > m22){
			T scaling = std::sqrt(1 + m11 - m00 - m22) * 2;

			if (std::abs(scaling) < T(0.00001)) {
				*this = Quaternion<T>::Identity();
				return;
			}

			y = scaling / 4;
			w = (m02 - m20) / scaling;
			x = (m10 + m01) / scaling;
			z = (m21 - m12) / scaling;

		}else{
			T scaling = std::sqrt(1 + m22 - m11 - m00) * 2;

			if (std::abs(scaling) < T(0.00001)) {
				*this = Quaternion<T>::Identity();
				return;
			}

			z = scaling / 4;
			w = (m10 - m01) / scaling;
			x = (m20 + m02) / scaling;
			y = (m21 - m12) / scaling;
		}
	}

	template<typename T>
	inline void Quaternion<T>::ToAngleAxis(T& angle, Vec3<T>& axis)
	{
		angle = 2 * std::acos(w);

		T sinDivision = std::sqrt(1 - w * w);

		if (sinDivision > T(0.00001)) {
			axis = Vec3<T>(x, y, z) / sinDivision;
			axis = axis.Normalized();

		}else{
			axis = Vec3<T>(1, 0, 0);
		}
	}

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

	template<typename T>
	inline float Quaternion<T>::AngleAxis(float angle, const Vec3<T>& axis)
	{

		return 0.0f;
	}

	template<typename T>
	constexpr T Quaternion<T>::Dot(const Quaternion& a, const Quaternion& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; // produit scalaire
	}

	template <typename T>
	inline T Euler(float x, float y, float z)
	{
		return T();
	}

	template<typename T>
	inline T Quaternion<T>::FromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection)
	{
		return T();
	}

	template<typename T>
	inline T Quaternion<T>::Inverse(const Quaternion& rotation)
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

	template <typename T>
	inline Quaternion<T> Quaternion<T>::Normalize(const Quaternion& rhs)
	{
	    T magnitude = std::sqrt(x * x + y * y + z * z + w * w);
	    
	    if (magnitude < T(0.00001)) {
	        return Quaternion<T>(0, 0, 0, 0);
	    }

	   return Quaternion<T>(x/ magnitude, y/ magnitude, z/ magnitude, w/ magnitude);
	}

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

	//template<typename T>
	//constexpr Quaternion<T> Quaternion<T>::operator*(const Quaternion& lhs, const Quaternion& rhs) const
	//{
	//	return Quaternion(x * scalar, y * scalar, z * scalar, w * scalar);
	//}
	//
	//template<typename T>
	//constexpr bool Quaternion<T>::operator==(const Quaternion& lhs, const Quaternion& rhs) const
	//{
	//	return (x == vec.x) && (y == vec.y) && (z == vec.z) && (w == vec.w);
	//}
}