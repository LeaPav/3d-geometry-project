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

        Vec2() ;
        Vec2(T x, T y) ;


        // operators

        Vec2 operator+(const Vec2& rhs) const; 
        Vec2 operator-(const Vec2& rhs) const; 
        Vec2 operator*(T scalar) const; 
        Vec2 operator/(T scalar) const;
        bool operator==(const Vec2& vec) const; 
        bool operator!=(const Vec2& vec) const;

        T& operator[](int index);

        // static properties

        static Vec2 zero(); 
        static Vec2 one();
        static Vec2 up();
        static Vec2 down();
        static Vec2 right();
        static Vec2 left();

        static Vec2 positiveInfinity(); 
        static Vec2 negativeInfinity();

        // static methods

        static float Angle(const Vec2& from, const Vec2& to); 

        static float SignedAngle(const Vec2& from, const Vec2& to);
    

        static T Distance(const Vec2& a, const Vec2& b); 

        static T Dot(const Vec2& a, const Vec2& b); 

        static Vec2 Lerp(const Vec2& a, const Vec2& b, float t);

        static Vec2 LerpUnclamped(const Vec2& a, const Vec2& b, float t);

        static Vec2 Max(const Vec2& a, const Vec2& b); 

        static Vec2 Min(const Vec2& a, const Vec2& b); 

        static Vec2 Scale(const Vec2& a, const Vec2& b);

    };


    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;

   

}

#include "Vec2.inl"