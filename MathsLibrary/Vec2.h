#pragma once
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>

namespace math{
    template<typename T>
    class Vec2 {
    public:
        T x; 
        T y;

        constexpr Vec2() ;
        constexpr Vec2(T x, T y) ;


        // operators

        constexpr Vec2 operator+(const Vec2& rhs) const; 
        constexpr Vec2 operator-(const Vec2& rhs) const;
        constexpr Vec2 operator*(T scalar) const;
        constexpr Vec2 operator/(T scalar) const;
        constexpr bool operator==(const Vec2& vec) const;
        constexpr bool operator!=(const Vec2& vec) const;
        operator sf::Vector2f() const;

        T& operator[](int index);

        // static properties

        static constexpr Vec2 zero();
        static constexpr Vec2 one();
        static constexpr Vec2 up();
        static constexpr Vec2 down();
        static constexpr Vec2 right();
        static constexpr Vec2 left();

        static constexpr  Vec2 positiveInfinity();
        static constexpr Vec2 negativeInfinity();

        // static methods

        static float Angle(const Vec2& from, const Vec2& to); 

        static float SignedAngle(const Vec2& from, const Vec2& to);
    

        static T Distance(const Vec2& a, const Vec2& b); 

        static constexpr T Dot(const Vec2& a, const Vec2& b);

        static Vec2 Lerp(const Vec2& a, const Vec2& b, float t);

        static Vec2 LerpUnclamped(const Vec2& a, const Vec2& b, float t);

        static constexpr Vec2 Max(const Vec2& a, const Vec2& b);

        static constexpr Vec2 Min(const Vec2& a, const Vec2& b);

        static constexpr Vec2 Scale(const Vec2& a, const Vec2& b);

    };


    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;

   

}

#include "Vec2.inl"