#pragma once
#include <iostream>

namespace math {
    template<typename T>
    class Vec2 {
    public:
        T x, T y;

        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}

        //properties

        T Magnitude() const { return { std::sqrt(x * x + y * y) } }
        Vec2 Normalized() const { double magnitude = std::sqrt(x * x + y * y); return { x / magnitude, y / magnitude } }
        //Vec2 Normalized() const { double magnitude = Magnitude(); if (magnitude < 0) return 0 }
        //Vec2 Normalized() const { if (Magnitude() < 0) return 0 }
        T SqrMagnitude() const { return { x * x + y * y } }

        /*Vec2 x(const Vec2& rhs) const { return {rhs.x} }
        Vec2 y(const Vec2 rhs) const {return {rhs.y} }*/

        //public methods

        bool Equals(const Vec2& rhs) const { if (x == rhs.x) && (y == rhs.y); return { rhs.true } }
        T Normalize(const Vec2& rhs) const { double normalize = std::sqrt(x * x + y * y); if (normalise == 1) { return normalise } }
        T Set(const Vec2& rhs) const { return { new rhs.x, new rhs.y } }
        std::string ToString(const Vec2& rhs) const { std::string format; return format }
    };

    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;

}