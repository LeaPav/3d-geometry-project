#pragma once
template <typename T>
class Vec4 {
public:
    T x, T y, T z, T w;

    Vec4() : x(0), y(0), z(0), w(0) {}
    Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    // properties

    T EulerAngles(const Vec3 rhs){}
    T Normalized(const Vec4 rhs) const { double magnitude = std::sqrt(x * x + y * y + z * z + w * w); return { x / magnitude, y / magnitude, z / magnitude } }


    //public methods

    bool Equals(const Vec4& rhs) const { if (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w); return { rhs.true } }
    T Set(/*const Vec4& rhs,*/ float newX, float newY, float newZ, float newW) const { return { new rhs.x, new rhs.y, new rhs.z, new rhs.w } }
    
    T SetFromToRotation(Vec3 fromDirection, Vec3 toDirection){}
    T SetLookRotation(Vec3 view, Vec3 up){}
    T ToAngleAxis(){}
    std::string ToString(const Vec4& rhs) const { std::string format; return format }

    // static methods

    T Euler(){}
    T LookRotation(){}
    T Normalize(){}
    T RotateTowards(){}
    T Slerp(){}
    T SlerpUncampled(){}
};