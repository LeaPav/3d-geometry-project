
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
	constexpr Vec3<T> Vec3<T>::back()
	{
		return Vec3(0, 0, -1);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::down()
	{
		return Vec3(0, -1, 0);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::forward()
	{
		return Vec3(0,0,1);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::left()
	{
		return Vec3(-1, 0, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::one()
	{
		return Vec3(1, 1, 1);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::right()
	{
		return Vec3(1, 0, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::up()
	{
		return Vec3(0, 1, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::zero()
	{
		return Vec3(0, 0, 0);
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::negativeInfinity()
	{
		return Vec3(-std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity());
	}
	template<typename T>
	constexpr Vec3<T> Vec3<T>::positiveInfinity()
	{
		return Vec3(std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity());
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
		return a.x * b.x + a.y * b.y + a.z * b.z; // produit scalaire
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Lerp(const Vec3& a, const Vec3& b, float t)
	{
		t = std::fmax(0.0f, std::fmin(1.0f, t));
		return Vec3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::LerpUnclamped(const Vec3& a, const Vec3& b, float t)
	{
		return Vec3(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t, a.z + (b.z - a.z) * t);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::Max(const Vec3& a, const Vec3& b)
	{
		return Vec3((a.x > b.x) ? a.x : b.x, (a.y > b.y) ? a.y : b.y, (a.z > b.z) ? a.z : b.z);
	}

	template<typename T>
	constexpr Vec3<T> Vec3<T>::Min(const Vec3& a, const Vec3& b)
	{
		return Vec3((a.x < b.x) ? a.x : b.x, (a.y < b.y) ? a.y : b.y, (a.z < b.z) ? a.z : b.z);
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

		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(a, b))); // faudra changer apres pour pouvoir mettre a.Normalized et b.Normalized
		T theta = std::acos(dot);
		return (a * (std::sin((1 - t) * theta) / std::sin(theta)) + b * (std::sin(t * theta) / std::sin(theta)));
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::SlerpUnclamped(const Vec3& a, const Vec3& b, float t)
	{
		T dot = std::fmax(T(-1), std::fmin(T(1.0f), Dot(a,b))); // faudra changer apres pour pouvoir mettre a.Normalized et b.Normalized
		T theta = std::acos(dot);
		return (a * (std::sin((1 - t) * theta) / std::sin(theta)) + b * (std::sin(t * theta) / std::sin(theta)));
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::Project(const Vec3& vec, const Vec3& onNormal)
	{
		T denom = Dot(onNormal, onNormal); // denominateur, dans la formule c'est la norme au carré de b
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

		//déplace une valeur or objet d'une position actuelle vers une position cible à une vitesse constante;
		
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::RotateTowards(const Vec3& current, const Vec3& target, float maxRadiansDelta, float maxMagnitudeDelta)
	{
		
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::ClampMagnitude(const Vec3& rhs, float maxLength)
	{
		float magnitude = rhs.Magnitude();
		if (magnitude <= maxLength) { return rhs; }
		else { return rhs.Normalized() * maxLength; }

		//	//limiter la longeur d'un vecteur sans changer sa direction
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::Normalize(const Vec3& rhs)
	{
		float magnitude = rhs.Magnitude(); 
		if (magnitude < 0.00001f) { 
			return Vec3(0.0f, 0.0f, 0.0f); 
		} 
		return Vec3(x / magnitude, y / magnitude, z / magnitude); 
	}

	//template<typename T>
	//inline Vec3<T> Vec3<T>::OrthoNormalize(const Vec3& rhs)
	//{
	//	float magnitude = rhs.Magnitude();
	//	if (magnitude <= maxLength) { return rhs; }
	//	else { return rhs.Normalized() * maxLength; }

	//	//	//limiter la longeur d'un vecteur sans changer sa direction
	//}
	//

	template<typename T>
	inline float Vec3<T>::Reflect(const Vec3& inDirection, const Vec3& inNormal)
	{
		Vec3 n = inNormal.Normalized();
		float scal = Dot(inDirection, n);
		return inDirection - n * (2.0f * scal); // formule de réflexion
	}

}