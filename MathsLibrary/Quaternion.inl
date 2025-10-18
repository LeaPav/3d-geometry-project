#include "Quaternion.h"
#include "Vec3.h"


namespace math {

	template <typename T>
	constexpr Quaternion<T>::Quaternion() : x(0), y(0), z(0), w(0) {}

	template <typename T>
	constexpr Quaternion<T>::Quaternion(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

	//static properties

	template<typename T>
	inline Quaternion<T> Quaternion<T>::Identity()
	{
		return Quaternion<T>(0, 0, 0, 1);
	}

	//properties

	template<typename T>
	inline Vec3<T> Quaternion<T>::EulerAngles() 
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
	
		return Vec3<T>(roll, pitch, yaw);
	}


	template <typename T>
	inline Quaternion<T> Quaternion<T>::Normalized() const {
		 T magnitude = std::sqrt(x * x + y * y + z * z + w * w);

		 if (magnitude < T(0.00001)) { 
			 return Quaternion<T>(0, 0, 0, 0); 
		 }

		 return Quaternion<T>(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
	}

	template<typename T>
	inline T& Quaternion<T>::operator[](int index)
	{
		if (index == 0) return x;
		else if (index == 1) return y;
		else if (index == 2) return z;
		else if (index == 3) return w;
		else throw std::out_of_range("Quaternion index out of range");
	}

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

		T dot = Vec3<T>::Dot(a, b);

		if (dot > T(0.99999)) {
			*this = Quaternion<T>(0, 0, 0, 1);
			return;
		}

		if (dot < T(-0.99999)) {
			Vec3<T> orthogonal = (std::fabs(a.x) > 0.9f) ? Vec3<T>(0, 1, 0) : Vec3<T>(1, 0, 0);
			
			Vec3<T> axis = Vec3<T>::Cross(a, orthogonal).Normalized();

			*this = Quaternion<T>(axis.x, axis.y, axis.z, 0); 
			
			return;
		}

		Vec3<T> axis = Vec3<T>::Cross(a, b).Normalized();

		T angle = std::acos(dot);
		T angleDivision = angle * T(0.5);

		T sinDivision = std::sin(angleDivision);
		T cosDivision = std::cos(angleDivision);

		*this = Quaternion<T>(axis.x * sinDivision, axis.y * sinDivision, axis.z * sinDivision, cosDivision);
	}


	template <typename T>
	inline void Quaternion<T>::SetLookRotation(const Vec3<T>& view, const Vec3<T>& up)
	{
		Vec3<T> viewV = view.Normalized();
		Vec3<T> upU = up.Normalized();

		Vec3<T> axisX = axisX.Cross(upU, view).Normalized();
		Vec3<T> axisY = axisY.Cross(viewV, axisX);

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
	inline T math::Quaternion<T>::Angle(const Quaternion& from, const Quaternion& to)
	{
		float magnitudeFrom = std::sqrt(from.x * from.x + from.y * from.y + from.z * from.z + from.w * from.w);
		float magnitudeTo = std::sqrt(to.x * to.x + to.y * to.y + to.z * to.z + to.w * to.w);

		float dot = Dot(from, to);

		if (magnitudeFrom == 0 || magnitudeTo == 0) return 0.0f;

		float cosTheta = dot / (magnitudeFrom * magnitudeTo);
		cosTheta = std::fmax(-1.f, std::fmin(1.f, cosTheta));

		return static_cast<T>(2.0 * std::acos(cosTheta) * (180.0f / 3.14159265f ));
	}

	template<typename T>
	inline Quaternion<T> Quaternion<T>::AngleAxis(const T& angle, const Vec3<T>& axis)
	{
		T angleRad = angle * T(3.14159265)/ T(180);
		T angleDiv = angleRad / T(2);

		T scaling = std::sin(angleDiv);
		T w = std::cos(angleDiv);

		Vec3<T> axisNormalize = axis.Normalized();

		return Quaternion<T>(
			axisNormalize.x * scaling,
			axisNormalize.y * scaling,
			axisNormalize.z * scaling,
			w
		);
	}

	template<typename T>
	constexpr T Quaternion<T>::Dot(const Quaternion& a, const Quaternion& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::Euler(T x, T y, T z)
	{
		T cosX = static_cast<T>(std::cos(x * 0.5));
		T sinX = static_cast<T>(std::sin(x * 0.5));
		T cosY = static_cast<T>(std::cos(y * 0.5));
		T sinY = static_cast<T>(std::sin(y * 0.5));
		T cosZ = static_cast<T>(std::cos(z * 0.5));
		T sinZ = static_cast<T>(std::sin(z * 0.5));

		return Quaternion<T>(
			sinX * cosY * cosZ - cosX * sinY * sinZ, 
			cosX * sinY * cosZ + sinX * cosY * sinZ, 
			cosX * cosY * sinZ - sinX * sinY * cosZ, 
			cosX * cosY * cosZ + sinX * sinY * sinZ  
		);
	}

	template<typename T>
	inline Quaternion<T> Quaternion<T>::FromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection)
	{
		Vec3<T> a = fromDirection.Normalized();
		Vec3<T> b = toDirection.Normalized();

		T dot = Vec3<T>::Dot(a, b);

		if (dot > T(0.9999)) {
			return Quaternion<T>::Identity();
		}

		Vec3<T> orthogonal = Vec3<T>(1, 0, 0).Cross(a, b);
		
		if (dot < T(-0.9999)) {
			Vec3<T> orthogonal = Vec3<T>(1, 0, 0).Cross(a, b);
			if (orthogonal.SqrMagnitude() < T(0.00001)) {
				orthogonal = Vec3<T>(0, 1, 0).Cross(a, b);
			}

			orthogonal = orthogonal.Normalized();
			return Quaternion<T>(orthogonal.x, orthogonal.y, orthogonal.z, T(0));
		}

		Vec3<T> axis = axis.Cross(a, b);

		T w = std::sqrt((1 + dot) * 2);
		T scaling = T(1) / w;

		return Quaternion<T>(axis.x * scaling, axis.y * scaling, axis.z * scaling, w * T(0.5)).Normalized();
	}

	template<typename T>
	inline Quaternion<T> Quaternion<T>::Inverse(const Quaternion& rotation)
	{
		T sqrMagnitude = rotation.x * rotation.x + rotation.y * rotation.y + rotation.z * rotation.z + rotation.w * rotation.w;

		if (sqrMagnitude < T(0.00001)) {
			return Quaternion<T>::Identity();
		}

		return Quaternion<T>( -rotation.x / sqrMagnitude, -rotation.y / sqrMagnitude, -rotation.z / sqrMagnitude, rotation.w / sqrMagnitude);
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::Lerp(const Quaternion& a, const Quaternion& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));
		Quaternion<T> qua(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);

		return qua.Normalized();
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::LerpUncampled(const Quaternion& a, const Quaternion& b, float t)
	{
		Quaternion<T> qua(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t, a.w + (b.w - a.w) * t);
		
		return qua.Normalized();
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::LookRotation(const Vec3<T>& forward, const Vec3<T>& upwards)
	{
		Vec3<T> forw = forward.Normalized();
		Vec3<T> up = upwards.Normalized();

		Vec3<T> axisX = axisX.Cross(up, forw).Normalized();
		Vec3<T> axisY = axisY.Cross(forw, axisX);

		T m00 = axisX.x, m01 = axisY.x, m02 = forw.x;
		T m10 = axisX.y, m11 = axisY.y, m12 = forw.y;
		T m20 = axisX.z, m21 = axisY.z, m22 = forw.z;

		T trace = m00 + m11 + m22;
		Quaternion<T> qua;

		if (trace > 0) {
			T scaling = std::sqrt(1 + trace) * 2;

			qua.w = scaling / 4;
			qua.x = (m21 - m12) / scaling;
			qua.y = (m02 - m20) / scaling;
			qua.z = (m10 - m01) / scaling;

		}
		else if (m00 > m11 && m00 > m22) {
			T scaling = std::sqrt(1 + m00 - m11 - m22) * 2;

			qua.x = scaling / 4;
			qua.w = (m21 - m12) / scaling;
			qua.y = (m10 + m01) / scaling;
			qua.z = (m20 + m02) / scaling;

		}
		else if (m11 > m00 && m11 > m22) {
			T scaling = std::sqrt(1 + m11 - m00 - m22) * 2;

			qua.y = scaling / 4;
			qua.w = (m02 - m20) / scaling;
			qua.x = (m10 + m01) / scaling;
			qua.z = (m21 - m12) / scaling;

		}
		else {
			T scaling = std::sqrt(1 + m22 - m11 - m00) * 2;

			qua.z = scaling / 4;
			qua.w = (m10 - m01) / scaling;
			qua.x = (m20 + m02) / scaling;
			qua.y = (m21 - m12) / scaling;
		}

		return qua.Normalized();
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::Normalize(const Quaternion& rhs)
	{
	    T magnitude = std::sqrt (rhs.x * rhs.x + rhs.y * rhs.y + rhs.z * rhs.z + rhs.w * rhs.w);
	    
	    if (magnitude < T(0.00001)) {
	        return Quaternion<T>(0, 0, 0, 0);
	    }

		return Quaternion<T>(rhs.x / magnitude, rhs.y / magnitude, rhs.z / magnitude, rhs.w / magnitude);
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::RotateTowards(const Quaternion& from, const Quaternion& to, const T maxDelta)
	{

		T angle = Angle(from, to);

		if (angle < T(0.00001)) {
			return to;
		}

		T t = std::min(T(1), std::abs(maxDelta) /angle);

		return Quaternion<T>::Slerp(from, to, t);
	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::Slerp(const Quaternion& a, const Quaternion& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));

		Quaternion<T> qauternionA = a.Normalized();
		Quaternion<T> quaternionB = b.Normalized();

		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(qauternionA, quaternionB ))); 
		T theta = std::acos(dot);
		return ((std::sin((1 - t) * theta) / std::sin(theta)) * qauternionA + (std::sin(t * theta) / std::sin(theta)) * quaternionB);

	}

	template <typename T>
	inline Quaternion<T> Quaternion<T>::SlerpUncampled(const Quaternion& a, const Quaternion& b, float t)
	{
		Quaternion<T> quaternionA = a.Normalized();
		Quaternion<T> quaternionB = b.Normalized();

		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(quaternionA, quaternionB)));
		T theta = std::acos(dot);
		return ((std::sin((1 - t) * theta) / std::sin(theta)) * quaternionA + (std::sin(t * theta) / std::sin(theta)) * quaternionB);
	}


	//operators

	template<typename T>
	constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		return Quaternion<T>(
			lhs.w *rhs.x + lhs.x * rhs.w + lhs.y * rhs.z - lhs.z * rhs.y,
			lhs.w * rhs.y - lhs.x * rhs.z + lhs.y * rhs.w + lhs.z * rhs.x,
			lhs.w * rhs.z + lhs.x * rhs.y - lhs.y * rhs.x + lhs.z * rhs.w,
			lhs.w * rhs.w - lhs.x * rhs.x - lhs.y * rhs.y - lhs.z * rhs.z
		);
	}
	template <typename T>
	constexpr Vec3<T> operator*(const Quaternion<T>& lhs, const Vec3<T>& rhs)
	{
		Quaternion<T> vectorQua(rhs.x, rhs.y, rhs.z, T(0));

		Quaternion<T> inverseQua = Quaternion<T>::Inverse(lhs);
		Quaternion<T> rotation = lhs * vectorQua * inverseQua;

		return Vec3<T>(rotation.x, rotation.y, rotation.z);
	}

	template <typename T>
	constexpr Quaternion<T> operator*(T lhs, const Quaternion<T>& rhs)
	{
		return Quaternion<T>( lhs * rhs.x, lhs * rhs.y, lhs*rhs.z, lhs* rhs.w); 
	}

	template<typename T>
	constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		return Quaternion<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
	}

	template<typename T>
	constexpr bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs)
	{
		T dot = lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
		return std::abs(std::abs(dot) - T(1)) < T(0.00001);
	}
}