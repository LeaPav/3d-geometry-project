#pragma once
#include <limits>
#include <cmath>

namespace math{
    template <typename T>
    class Vec4 {
    public:
        T x;
        T y;
        T z; 
        T w;

        constexpr Vec4() ;
        constexpr Vec4(T x, T y, T z, T w);

        //static Properties

        static Vec4 identity();

        // properties

        T EulerAngles(const Vec3& rhs) {}
        Vec4 Normalized() const; { float magnitude = std::sqrt(x * x + y * y + z * z + w * w); if (magnitude < 0.00001f) { return Vec4(0.0f, 0.0f, 0.0f, 0.0f); } return Vec4(x / magnitude, y / magnitude, z / magnitude, w / magnitude); }

        //public methods

        bool Equals(const Vec4& rhs) const;
        void Set(const Vec4& rhs); { return  x = rhs.x, y = rhs.y, z = rhs.z, w = rhs.w; }

        static T SetFromToRotation(const Vec3& fromDirection, const Vec3& toDirection);
        static T SetLookRotation(const Vec3& view, Vec3 up);
        static T ToAngleAxis(float angle, const Vec3& axis);
        std::string ToString() const; /* { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")"; }*/


        // static methods

        static float Angle(const Vec4& from, const Vec4& to);
        static float AngleAxis();
        static constexpr T Dot(const Vec4& a, const Vec4& b);
        static T Euler();
        static T FromToRotation();
        static T Inverse();
        static Vec4 Lerp(const Vec4& a, const Vec4& b, float t);
        static Vec4 LerpUncampled(const Vec4& a, const Vec4& b, float t);
        static T LookRotation();
        //Vec4 Normalize(const Vec4& rhs) const;
        static Vec4 RotateTowards();
        static Vec4 Slerp(const Vec4& a, const Vec4& b, float t);
        static Vec4 SlerpUncampled(const Vec4& a, const Vec4& b, float t);

        //operators

        constexpr Vec4 operator*(T scalar) const;
        constexpr bool operator==(const Vec4& vec) const;

    };

    using Vec4f = Vec4<float>;
    using Vec4i = Vec4<int>;
    using Vec4d = Vec4<double>;

}

#include "Quaternion.inl"