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

        static constexpr Vec2 Zero();
        static constexpr Vec2 One();
        static constexpr Vec2 Up();
        static constexpr Vec2 Down();
        static constexpr Vec2 Right();
        static constexpr Vec2 Left();

        static constexpr  Vec2 PositiveInfinity();
        static constexpr Vec2 NegativeInfinity();


        //properties

        float Magnitude() const;
        Vec2 Normalized() const;
        float SqrMagnitude() const;

        //public methods

        bool Equals(const Vec2& rhs) const;
        Vec2 Normalize(const Vec2& rhs) const; 
        void Set(T newX, T newY); 
        std::string ToString() const;

        // static methods

        static Vec2 ClampMagnitude(const Vec2& rhs, float maxLength);

        static Vec2 MoveTowards(const Vec2& current, const Vec2& target, float maxDistanceDelta);

        static Vec2 Perpendicular(const Vec2& rhs);

        static Vec2 Reflect(const Vec2& inDirection, const Vec2& inNormal);

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