#include "Vec3.h"

namespace math {
    template<typename T>
    inline Vec2<T>::Vec2() : x(0), y(0)  { }

    template<typename T>
    inline Vec2<T>::Vec2(T x, T y) : x(x), y(y) { }

    template<typename T>
    inline Vec2<T> Vec2<T>::operator+(const Vec2& rhs) const
    {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::operator-(const Vec2& rhs) const
    {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::operator*(T scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::operator/(T scalar) const
    {
        return Vec2(x / scalar, y / scalar);
    }

    template<typename T>
    inline bool Vec2<T>::operator==(const Vec2& vec) const
    {
        return (x == vec.x) && (y == vec.y);
    }

    template<typename T>
    inline bool Vec2<T>::operator!=(const Vec2& vec) const
    {
        return (x != vec.x) || (y != vec.y);
    }

    template<typename T>
    inline T& Vec2<T>::operator[](int index)
    {
         if (index == 0) return x; 
         else if (index == 1) return y;
         else throw std::out_of_range("Vec2 index out of range"); 
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::zero() {
        return Vec2(0, 0);
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::one()
    {
        return Vec2(1, 1);
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::up()
    {
        return Vec2(0, 1);
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::down()
    {
        return Vec2(0, -1);
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::right()
    {
        return Vec2(1, 0);
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::left()
    {
        return Vec2(-1, 0);
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::positiveInfinity()
    {
        return Vec2(std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity());
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::negativeInfinity()
    {
        return Vec2(-std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity());
    }

    template<typename T>
    inline float Vec2<T>::Angle(const Vec2& from, const Vec2& to)
    {
        float magnitudeFrom = std::sqrt(from.x * from.x + from.y * from.y);
        float magnitudeTo = std::sqrt(to.x * to.x + to.y * to.y);

        float dot = Dot(from, to);

        if (magnitudeFrom == 0 || magnitudeTo == 0) return 0.0f; // eviter la division par 0

        float cosTheta = dot / (magnitudeFrom * magnitudeTo);
        cosTheta = std::fmax(-1.f, std::fmin(1.f, cosTheta));

        return std::acos(cosTheta);
    }

    template<typename T>
    inline float Vec2<T>::SignedAngle(const Vec2& from, const Vec2& to)
    {

        float dot = Dot(from, to);
        float product = from.x * to.y - from.y * to.x; // pour connaitre le sens de la rotation (product > 0 -> anti horaire, product < 0 -> horaire)

        return std::atan2(product, dot);
    }

    template<typename T>
    inline T Vec2<T>::Distance(const Vec2& a, const Vec2& b)
    {
        T dx = a.x - b.x;
        T dy = a.y - b.y;
        return std::sqrt(dx * dx + dy * dy);
    }
    template<typename T>
    inline T Vec2<T>::Dot(const Vec2& a, const Vec2& b)
    {
        return a.x * b.x + a.y * b.y; // produit scalaire
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::Lerp(const Vec2& a, const Vec2& b, float t)
    {
        t = std::fmax(0.0f, std::fmin(1.0f, t));
        return Vec2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::LerpUnclamped(const Vec2& a, const Vec2& b, float t)
    {
        return Vec2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::Max(const Vec2& a, const Vec2& b)
    {
        return Vec2((a.x > b.x) ? a.x : b.x, (a.y > b.y) ? a.y : b.y);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::Min(const Vec2& a, const Vec2& b)
    {
        return Vec2((a.x < b.x) ? a.x : b.x, (a.y < b.y) ? a.y : b.y);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::Scale(const Vec2& a, const Vec2& b)
    {
        return Vec2(a.x * b.x, a.y * b.y);
    }


}
