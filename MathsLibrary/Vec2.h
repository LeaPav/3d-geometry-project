#pragma once

namespace math{
    template<typename T>
    class Vec2 {
    public:
        T x, T y;

        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}


        // operators

        Vec2 operator+(const Vec2& rhs) { return (x + rhs.x, y + rhs.y) }
        Vec2 operator-(const Vec2& rhs) { return (x - rhs.x, y - rhs.y ) }
        

    };


    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;

}