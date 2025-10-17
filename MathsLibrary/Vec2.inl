#include "Vec2.h"

namespace math {
    template<typename T>
    constexpr Vec2<T>::Vec2() : x(0), y(0)  { }

    template<typename T>
    constexpr Vec2<T>::Vec2(T x, T y) : x(x), y(y) { }

    template<typename T>
    inline constexpr Vec2<T>::Vec2(const sf::Vector2f& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) { }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::operator+(const Vec2& rhs) const
    {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::operator-(const Vec2& rhs) const
    {
        return Vec2(x - rhs.x, y - rhs.y);
    }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::operator*(T scalar) const
    {
        return Vec2(x * scalar, y * scalar);
    }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::operator/(T scalar) const
    {
        return Vec2(x / scalar, y / scalar);
    }

    template<typename T>
    constexpr bool Vec2<T>::operator==(const Vec2& vec) const
    {
        return (x == vec.x) && (y == vec.y);
    }

    template<typename T>
    constexpr bool Vec2<T>::operator!=(const Vec2& vec) const
    {
        return (x != vec.x) || (y != vec.y);
    }

    template<typename T>
    inline constexpr Vec2<T>& Vec2<T>::operator+=(const Vec2& vec)
    {
        x+= vec.x;
        y+= vec.y;
        return *this;
    }

    template<typename T>
    inline constexpr Vec2<T>& Vec2<T>::operator-=(const Vec2& vec)
    {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    template<typename T>
    inline Vec2<T>::operator sf::Vector2f() const
    {
        return sf::Vector2f(static_cast<float>(x), static_cast<float>(y));
    }

    template<typename T>
    inline T& Vec2<T>::operator[](int index)
    {
         if (index == 0) return x; 
         else if (index == 1) return y;
         else throw std::out_of_range("Vec2 index out of range"); 
    }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::Zero() {
        return Vec2(0, 0);
    }
    template<typename T>
    constexpr Vec2<T> Vec2<T>::One()
    {
        return Vec2(1, 1);
    }
    template<typename T>
    constexpr Vec2<T> Vec2<T>::Up()
    {
        return Vec2(0, 1);
    }
    template<typename T>
    constexpr Vec2<T> Vec2<T>::Down()
    {
        return Vec2(0, -1);
    }
    template<typename T>
    constexpr Vec2<T> Vec2<T>::Right()
    { 
        return Vec2(1, 0);
    }
    template<typename T>
    constexpr Vec2<T> Vec2<T>::Left()
    {
        return Vec2(-1, 0);
    }
    template<typename T>
    constexpr Vec2<T> Vec2<T>::PositiveInfinity()
    {
        return Vec2(std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity());
    }
    template<typename T>
    constexpr Vec2<T> Vec2<T>::NegativeInfinity()
    {
        return Vec2(-std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity());
    }

    template<typename T>
    inline float Vec2<T>::Magnitude() const
    {
        return std::sqrt(x * x + y * y);
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::Normalized() const
    {
        float magnitude = Magnitude(); 
        if (magnitude < 0.00001f) {
            return Vec2(0.0f, 0.0f); } 
        return Vec2(x / magnitude, y / magnitude);
    }

    template<typename T>
    inline float Vec2<T>::SqrMagnitude() const
    {
        return x * x + y * y;
    }
    
    template<typename T>
    inline bool Vec2<T>::Equals(const Vec2& rhs) const
    {
        return (x == rhs.x) && (y == rhs.y);
    }

    template<typename T>
    inline void Vec2<T>::Normalize() 
    {
        float magnitude = Magnitude(); 
        if (magnitude < static_cast<T>(0.00001)) { 
            x = 0.0f;
            y = 0.0f;
            return;
        } 
        x /= magnitude;
        y /= magnitude;
    }

    template<typename T>
    inline void Vec2<T>::Set(T newX, T newY)
    {
        x = newX;
        y = newY;
    }

    template<typename T>
    inline std::string Vec2<T>::ToString() const
    {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }


    template<typename T>
    inline Vec2<T> Vec2<T>::ClampMagnitude(const Vec2& rhs, float maxLength) 
    {
        float magnitude = rhs.Magnitude();
        if (magnitude <= maxLength) { return rhs; }
        else { return rhs.Normalized() * maxLength; }

        //limiter la longeur d'un vecteur sans changer sa direction
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::MoveTowards(const Vec2& current, const Vec2& target, float maxDistanceDelta)
    {
        Vec2 delta = target - current;
        float distance = Distance(current, target);

        if (distance <= maxDistanceDelta || distance == 0.0f) { return target; }

        Vec2 direction = delta / distance;
        return current + direction * maxDistanceDelta;

        //déplace une valeur or objet d'une position actuelle vers une position cible à une vitesse constante
    }
    template<typename T>
    inline Vec2<T> Vec2<T>::Perpendicular(const Vec2& rhs)
    {
        return Vec2(-rhs.y, rhs.x); 
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::Reflect(const Vec2& inDirection, const Vec2& inNormal)
    {
        Vec2 n = inNormal.Normalized();
        float scal = Dot(inDirection, n);
        return inDirection - n * (2.0f * scal); // formule de réflexion
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
    constexpr T Vec2<T>::Dot(const Vec2& a, const Vec2& b)
    {
        return a.x * b.x + a.y * b.y; // produit scalaire
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::Lerp(const Vec2& a, const Vec2& b, float t)
    {
        t = std::fmax(0.0f, std::fmin(1.0f, t));
        return a + (b - a) * t;
    }

    template<typename T>
    inline Vec2<T> Vec2<T>::LerpUnclamped(const Vec2& a, const Vec2& b, float t)
    {
        return a + (b - a) * t;
    }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::Max(const Vec2& a, const Vec2& b)
    {
        return Vec2(std::max(a.x, b.x), std::max(a.y, b.y));
    }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::Min(const Vec2& a, const Vec2& b)
    {
        return Vec2(std::min(a.x, b.x), std::min(a.y, b.y));
    }

    template<typename T>
    constexpr Vec2<T> Vec2<T>::Scale(const Vec2& a, const Vec2& b)
    {
        return Vec2(a.x * b.x, a.y * b.y);
    }


}
