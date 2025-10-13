#pragma once
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <SFML/Graphics.hpp>

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


        //properties

        float Magnitude() const { return std::sqrt(x * x + y * y); }
        Vec2 Normalized() const { float magnitude = Magnitude(); if (magnitude < 0.00001f) { return Vec2(0.0f, 0.0f); } return Vec2(x / magnitude, y / magnitude); }
        float SqrMagnitude() const { return x * x + y * y; }

        //public methods

        bool Equals(const Vec2& rhs) const { return (x == rhs.x) && (y == rhs.y); }
        Vec2 Normalize(const Vec2& rhs) const  { float magnitude = rhs.Magnitude(); if (magnitude < 0.00001f) { return Vec2(0.0f, 0.0f); } return Vec2(x / magnitude, y / magnitude); }
        void Set(const Vec2& rhs) { x = rhs.x; y = rhs.y; }
        std::string ToString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ")"; }

        // static methods

        static Vec2 ClampMagnitude(const Vec2& rhs, float maxLength);


        static Vec2 MoveTowards(const Vec2& current, const Vec2& target, float maxDistanceDelta);


        static Vec2 Perpendicular(const Vec2& rhs);

        static float Reflect(const Vec2& inDirection, const Vec2& inNormal);

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