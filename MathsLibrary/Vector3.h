#pragma once
template <typename T>
class Vec3 {
public:
    T x, T y, T z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    // properties

    T Magnitude() const { return { std::sqrt(x * x + y * y + z * z) } }
    Vec3 Normalized() const { double magnitude = std::sqrt(x * x + y * y + z * z); return { x / magnitude, y / magnitude, z / magnitude } }
    T SqrMagnitude() const { return { x * x + y * y + z * z } }


    //public methods

    bool Equals(const Vec3& rhs) const { if (x == rhs.x) && (y == rhs.y) && (z == rhs.z); return { rhs.true } }
    T Set(const Vec3& rhs) const { return { new rhs.x, new rhs.y, new rhs.z } }
    std::string ToString(const Vec3& rhs) const { std::string format; return format }


};