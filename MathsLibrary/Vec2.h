#pragma once
#include <iostream>
#include <limits>
#include <cmath>

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
        bool operator!=(const Vec2& vec) const { return (x!= vec.x) || (y != vec.y); }
             

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

        static float Angle(const Vec2& from, const Vec2& to) {
            float magnitudeFrom = std::sqrt(from.x * from.x + from.y * from.y);
            float magnitudeTo = std::sqrt(to.x * to.x + to.y * to.y);

            float dot = Dot(from, to);

            if (magnitudeFrom == 0 || magnitudeTo == 0) return 0.0f;

            float cosTheta = dot / (magnitudeFrom * magnitudeTo);
            cosTheta = std::fmax(-1.f, std::fmin(1.f, cosTheta));

            return std::acos(cosTheta) * 180.0f / 3.14159265f;
        }

        static T Distance(const Vec2& a, const Vec2& b) {
            T dx = a.x - b.x;
            T dy = a.y - b.y;
            return std::sqrt(dx * dx + dy * dy);
        }

        static T Dot(const Vec2& a, const Vec2& b) {
            return a.x * b.x + a.y * b.y; // produit scalaire
        
        }

        static Vec2 Lerp(const Vec2& a, const Vec2& b, float t) { // t : facteur d'interpolation, entre 0-1
            t = std::fmax(0.0f, std::fmin(1.0f, t));
            return Vec2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t);
        }

        static Vec2 Max(const Vec2& a, const Vec2& b) {
            return Vec2((a.x > b.x) ? a.x : b.x, (a.y > b.y) ? a.y : b.y);
        }

        static Vec2 Min(const Vec2& a, const Vec2& b) {
            return Vec2((a.x < b.x) ? a.x : b.x, (a.y < b.y) ? a.y : b.y);
        }

        static Vec2 Scale(const Vec2& a, const Vec2& b) {
            return Vec2(a.x * b.x, a.y * b.y);
        }
    };


    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;

}