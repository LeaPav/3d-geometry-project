#pragma once
#include <iostream>
#include <limits>
namespace math{
    template<typename T>
    class Vec2 {
    public:
        T x; 
        T y;

        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}


        // operators

        Vec2 operator+(const Vec2& rhs) const { return Vec2(x + rhs.x, y + rhs.y); }
        Vec2 operator-(const Vec2& rhs) const { return Vec2(x - rhs.x, y - rhs.y); }
        Vec2 operator*(T scalar) const { return Vec2(x * scalar, y * scalar); }
        Vec2 operator/(T scalar) const { return Vec2(x / scalar, y / scalar); }
        bool operator==(const Vec2& vec) const { return (x == vec.x) && (y == vec.y); }
        bool operator!=(const Vec2& vec) const { return (x!= vec.x) && (y != vec.y); }
             

        // static properties

        static Vec2 zero() { return Vec2(0, 0); }
        static Vec2 one() { return Vec2(1, 1); }
        static Vec2 up() { return Vec2(0, 1); }
        static Vec2 down() { return Vec2(0, -1); }
        static Vec2 right() { return Vec2(1, 0); }
        static Vec2 left() { return Vec2(-1, 0); }

        static Vec2 positiveInfinity() { return Vec2(std::numeric_limits<T>::infinity(), std::numeric_limits<T>::infinity()); }
        static Vec2 negativeInfinity() { return Vec2(-std::numeric_limits<T>::infinity(), -std::numeric_limits<T>::infinity()); }

        // static methods



    };


    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;

}