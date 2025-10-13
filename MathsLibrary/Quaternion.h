#pragma once
#include <limits>
#include <cmath>

namespace math{
    template <typename T>
    class Quaternion {
    public:
        T x;
        T y;
        T z; 
        T w;

        constexpr Quaternion() ;
        constexpr Quaternion(T x, T y, T z, T w);

        //static Properties

        static Quaternion identity();

        // properties

        Quaternion EulerAngles();
        Quaternion Normalized() const; 

        //public methods

        bool Equals(const Quaternion& rhs) const;
        void Set(const Quaternion& rhs);
        void SetFromToRotation(const Quaternion& fromDirection, const Quaternion& toDirection);
        static T SetLookRotation(const Quaternion& view, const Quaternion& up);
        static T ToAngleAxis(float angle, const Quaternion& axis);
        std::string ToString() const; /* { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")"; }*/


        // static methods

        static float Angle(const Quaternion& from, const Quaternion& to);
        static float AngleAxis();
        static constexpr T Dot(const Quaternion& a, const Quaternion& b);
        static T Euler();
        static T FromToRotation();
        static T Inverse();
        static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t);
        static Quaternion LerpUncampled(const Quaternion& a, const Quaternion& b, float t);
        static T LookRotation();
        //Vec4 Normalize(const Vec4& rhs) const;
        static Quaternion RotateTowards();
        static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);
        static Quaternion SlerpUncampled(const Quaternion& a, const Quaternion& b, float t);

        //operators

        constexpr Quaternion operator*(T scalar) const;
        constexpr bool operator==(const Quaternion& vec) const;

    };

    using Quaternionf = Quaternion<float>;
    using Quaternioni = Quaternion<int>;
    using Quaterniond = Quaternion<double>;

}

#include "Quaternion.inl"
#include "Vec3.inl"