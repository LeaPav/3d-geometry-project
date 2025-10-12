#pragma once
template <typename T>
class Vec4 {
public:
    T x, T y, T z, T w;

    Vec4() : x(0), y(0), z(0), w(0) {}
    Vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    // properties

    T EulerAngles(const Vec3& rhs){}
    Vec4 Normalized() const { float magnitude = std::sqrt(x * x + y * y + z * z + w * w); if (magnitude < 0.00001f) { return Vec4(0.0f, 0.0f, 0.0f, 0.0f); } return Vec4(x / magnitude, y / magnitude, z / magnitude), w / magnitude; }


    //public methods

    bool Equals(const Vec4& rhs) const { return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w); }
    void Set(const Vec4& rhs) { return  x = rhs.x, y = rhs.y, z = rhs.z, w = rhs.w; }
    
    T SetFromToRotation(const Vec3& fromDirection, const Vec3& toDirection){}
    T SetLookRotation(const Vec3& view, Vec3 up){}
    T ToAngleAxis(){}
    std::string ToString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")"; }

    // static methods

    T Euler(){}
    T LookRotation(){}

    Vec4 Normalize(const Vec4& rhs) const {
        float magnitude = std::sqrt(x * x + y * y + z * z + w * w);
        
        if (magnitude < 0.00001f) {
            return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
        }

        return Vec4(x/ magnitude, y/ magnitude, z/ magnitude, w/ magnitude);
    }

    T RotateTowards(){}
    T Slerp(){}
    T SlerpUncampled(){}
};