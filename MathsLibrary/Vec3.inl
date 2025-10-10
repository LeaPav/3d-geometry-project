
namespace math {
	template<typename T>
	inline Vec3<T>::Vec3() : x(0), y(0), z(0) {}

	template<typename T>
	inline math::Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

	template<typename T>
	inline Vec3<T> Vec3<T>::operator+(const Vec3& rhs) const
	{
		return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::operator-(const Vec3& rhs) const
	{
		return Vec3(x - rhs.x, y - rhs.y, z - rhs.z);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::operator*(T scalar) const
	{
		return Vec3(x * scalar, y * scalar, z * scalar);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::operator/(T scalar) const
	{
		return Vec3(x / scalar, y / scalar, z / scalar);
	}

	template<typename T>
	inline bool Vec3<T>::operator==(const Vec3& vec) const
	{
		return (x == vec.x) && (y == vec.y) && (z == vec.z);
	}

	template<typename T>
	inline bool Vec3<T>::operator!=(const Vec3& vec) const
	{
		return  (x != vec.x) || (y != vec.y) || (z != vec.z);
	}
	template<typename T>
	inline T& Vec3<T>::operator[](int index)
	{
		if (index == 0) return x;
		else if (index == 1) return y;
		else if (index == 2) return z;
		else throw std::out_of_range("Vec2 index out of range");
	}


	template<typename T>
	inline Vec3<T> Vec3<T>::back()
	{
		return Vec3(0, 0, -1);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::down()
	{
		return Vec3(0, -1, 0);
	}

	template<typename T>
	inline Vec3<T> Vec3<T>::forward()
	{
		return Vec3(0,0,1);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::left()
	{
		return Vec3(-1, 0, 0);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::one()
	{
		return Vec3(1, 1, 1);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::right()
	{
		return Vec3(1, 0, 0);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::up()
	{
		return Vec3(0, 1, 0);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::zero()
	{
		return Vec3(0, 0, 0);
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::negativeInfinity()
	{
		return Vec2(-std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity());
	}
	template<typename T>
	inline Vec3<T> Vec3<T>::positiveInfinity()
	{
		return Vec2(std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity());
	}
}