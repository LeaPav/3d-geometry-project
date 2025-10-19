#include "Vec3.h"

namespace math {
	template<typename T>
	constexpr Vec3<T>::Vec3() : x(0), y(0), z(0) {}

	template<typename T>
	constexpr math::Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::operator+(const Vec3& rhs) const
	{
		return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::operator-(const Vec3& rhs) const
	{
		return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::operator*(T scalar) const
	{
		return Vec3(x * scalar, y * scalar, z * scalar);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::operator/(T scalar) const
	{
		return Vec3(x / scalar, y / scalar, z / scalar);
	}

	template<typename T>
	constexpr bool Vec3<T>::operator==(const Vec3& vec) const
	{
		return (x == vec.x) && (y == vec.y) && (z == vec.z);
	}

	template<typename T>
	constexpr bool Vec3<T>::operator!=(const Vec3& vec) const
	{
		return  (x != vec.x) || (y != vec.y) || (z != vec.z);
	}
	template<typename T>
	inline T& Vec3<T>::operator[](int index)
	{
		if (index == 0) return x;
		else if (index == 1) return y;
		else if (index == 2) return z;
		else throw std::out_of_range("Vec3 index out of range");
	}


	template<typename T>
	constexpr Vec3<T> Vec3<T>::Back()
	{
		return Vec3(0, 0, -1);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::Down()
	{
		return Vec3(0, -1, 0);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::Forward()
	{
		return Vec3(0,0,1);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::Left()
	{
		return Vec3(-1, 0, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::One()
	{
		return Vec3(1, 1, 1);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::Right()
	{
		return Vec3(1, 0, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::Up()
	{
		return Vec3(0, 1, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::Zero()
	{
		return Vec3(0, 0, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::NegativeInfinity()
	{
		return Vec3(-std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity());
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::PositiveInfinity()
	{
		return Vec3(std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity());
	}

	//static methods

	template<typename T>
	inline float Vec3<T>::Magnitude() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Normalized() const
	{
		float magnitude = Magnitude(); 
		if (magnitude < static_cast<T>(0.00001)) {
			return Vec3(0, 0, 0); } 
		return Vec3(x / magnitude, y / magnitude, z / magnitude);
	}

	template<typename T>
	inline float Vec3<T>::SqrMagnitude() const
	{
		return x * x + y * y + z * z;
	}

	template<typename T>
	inline bool Vec3<T>::Equals(const Vec3& rhs) const
	{
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}

	template<typename T>
	inline void Vec3<T>::Set(T newX, T newY, T newZ)
	{
		x = newX;
		y = newY;
		z = newZ;
	}

	template<typename T>
	inline std::string Vec3<T>::ToString() const
	{
		 return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")"; 
	}

	template<typename T>
	inline float math::Vec3<T>::Angle(const Vec3& from, const Vec3& to)
	{
		float magnitudeFrom = std::sqrt(from.x * from.x + from.y * from.y + from.z * from.z);
		float magnitudeTo = std::sqrt(to.x * to.x + to.y * to.y + to.z * to.z);

		float dot = Dot(from, to);

		if (magnitudeFrom == 0 || magnitudeTo == 0) return 0.0f;

		float cosTheta = dot / (magnitudeFrom * magnitudeTo);
		cosTheta = std::fmax(-1.f, std::fmin(1.f, cosTheta));

		return std::acos(cosTheta);
	}

	template<typename T>
	inline float Vec3<T>::SignedAngle(const Vec3& from, const Vec3& to, const Vec3& axis)
	{
	
		Vec3 crossProduct = Cross(from, to);
		float sign = (Dot(axis, crossProduct) >= 0) ? 1.0f : -1.0f;
		float angle = Angle(from, to);

		return angle * sign;
	}

	template<typename T>
	inline T Vec3<T>::Distance(const Vec3& a, const Vec3& b)
	{
		T dx = a.x - b.x;
		T dy = a.y - b.y;
		T dz = a.z - b.z;
		return std::sqrt(dx * dx + dy * dy + dz * dz);
	}

	template<typename T>
	constexpr T Vec3<T>::Dot(const Vec3& a, const Vec3& b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z; // scalar product
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Lerp(const Vec3& a, const Vec3& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));
		return a + (b - a) * t;
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::LerpUnclamped(const Vec3& a, const Vec3& b, float t)
	{
		return a + (b - a) * t;
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::Max(const Vec3& a, const Vec3& b)
	{
		return Vec3(std::max(a.x, b.x), std::max(a.y, b.y), std::max(a.z, b.z));

	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::Min(const Vec3& a, const Vec3& b)
	{
		return Vec3(std::min(a.x, b.x), std::min(a.y, b.y), std::min(a.z, b.z));
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::Scale(const Vec3& a, const Vec3& b)
	{
		return Vec3(a.x * b.x, a.y * b.y, a.z * b.z);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::Cross(const Vec3& a, const Vec3& b)
	{
		return Vec3<T>(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
		);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::Slerp(const Vec3& a, const Vec3& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));

		Vec3<T> aNorm = a.Normalized();
		Vec3<T> bNorm = b.Normalized();
		 
		T dot = Dot(aNorm, bNorm);
		dot = std::fmax(T(-1), std::fmin(T(1.0f), dot));

		T theta = std::acos(dot);

		T mag = (1 - t) * a.Magnitude() + t * b.Magnitude();

		return (aNorm * (std::sin((1 - t) * theta) / std::sin(theta)) + bNorm * (std::sin(t * theta) / std::sin(theta))) * mag;
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::SlerpUnclamped(const Vec3& a, const Vec3& b, float t)
	{

		Vec3<T> aNorm = a.Normalized();
		Vec3<T> bNorm = b.Normalized();

		T dot = Dot(aNorm, bNorm);
		dot = std::fmax(T(-1), std::fmin(T(1.0f), dot));
		T theta = std::acos(dot);

		if (std::abs(theta) < 1e-5f) return LerpUnclamped(aNorm, bNorm, t).Normalized();

		T mag = (1 - t) * a.Magnitude() + t * b.Magnitude();
		return (aNorm * (std::sin((1 - t) * theta) / std::sin(theta)) + bNorm * (std::sin(t * theta) / std::sin(theta))) * mag;
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::Project(const Vec3& vec, const Vec3& onNormal)
	{
		T denom = Dot(onNormal, onNormal); // denominator
		if (denom == 0) return Vec3<T>();

		return onNormal * (Vec3<T>::Dot(vec, onNormal) / denom);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::ProjectOnPlane(const Vec3& vec, const Vec3& planeNormal)
	{
		T denom = Dot(planeNormal, planeNormal);
		if (denom == 0) return Vec3<T>();

		return vec - planeNormal * (Vec3<T>::Dot(vec, planeNormal) / denom);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::MoveTowards(const Vec3& current, const Vec3& target, float maxDistanceDelta)
	{
		Vec3 delta = target - current;
		float distance = delta.Magnitude();

		if (distance <= maxDistanceDelta || distance == 0.0f) { return target; }

		Vec3 direction = delta / distance;
		return current + direction * maxDistanceDelta;

		//moves a value or object from a current position to a target position at a constant speed
		
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::RotateTowards(const Vec3& current, const Vec3& target, float maxRadiansDelta, float maxMagnitudeDelta)
	{
	
		float currentMag = current.Magnitude();
		float targetMag = target.Magnitude();

		if (current == target) return target;

		if (currentMag < 0.f) {
			float newMag = std::min(targetMag, maxMagnitudeDelta);
			return target.Normalized() * newMag;
		}
		Vec3 currentDir = current / currentMag;
		Vec3 targetDir = target.Normalized();

		float angle = Angle(currentDir, targetDir);

		float t = (angle < 0.f) ? 1.f : std::fmin(1.f, maxRadiansDelta / angle);

		Vec3 newDir = Slerp(currentDir, targetDir, t).Normalized();
		float newMag = currentMag + std::fmax(-maxMagnitudeDelta, std::fmin(maxMagnitudeDelta, targetMag - currentMag));

		return newDir * newMag;

	}

	template<typename T>
	inline Vec3<T> Vec3<T>::ClampMagnitude(const Vec3& rhs, float maxLength)
	{
		float magnitude = rhs.Magnitude();
		if (magnitude <= maxLength) { return rhs; }
		else { return rhs.Normalized() * maxLength; }

		//limit the length of a vector without changing its direction
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Normalize(const Vec3<T>& rhs)
	{
		T magnitude = rhs.Magnitude();

		if (magnitude < static_cast<T>(0.00001))
			return Vec3<T>(0, 0, 0);

		return Vec3(rhs.x / magnitude, rhs.y / magnitude, rhs.z / magnitude);

	}

	template<typename T>
	inline void Vec3<T>::Normalize()
	{
		float magnitude = Magnitude();
		if (magnitude < static_cast<T>(0.00001)) {
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			return;
		}
		x /= magnitude;
		y /= magnitude;
		z /= magnitude;
	}

	template<typename T>
	inline void Vec3<T>::OrthoNormalize(Vec3& normal,Vec3& tangent)
	{
		normal = normal.Normalized();

		tangent = tangent - normal * Dot(normal, tangent);
		tangent = tangent.Normalized();

	}

	template<typename T>
	inline void Vec3<T>::OrthoNormalize(Vec3& normal, Vec3& tangent, Vec3& binormal)
	{
		normal = normal.Normalized();
		tangent = tangent - normal * Dot(normal, tangent);
		tangent = tangent.Normalized();

		binormal = binormal - normal * Dot(normal, binormal) - tangent * Dot(tangent, binormal);
		binormal = binormal.Normalized();
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Reflect(const Vec3& inDirection, const Vec3& inNormal)
	{
		Vec3 n = inNormal.Normalized();
		float scal = Dot(inDirection, n);
		return inDirection - n * (2.0f * scal); // reflection formula
	}

}