#pragma once
#include <limits>
#include <cmath>
#include "Vec3.h"

//template <typename T>
//class Vec3;

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

        static Quaternion Identity();

        // properties

        Quaternion EulerAngles();
        Quaternion Normalized() const; 

        //public methods

        bool Equals(const Quaternion& rhs) const;
        void Set(const Quaternion& rhs);
        void SetFromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection);
        void SetLookRotation(const Vec3<T>& view, const Vec3<T>& up);
        void ToAngleAxis(float angle, const Vec3<T>& axis);
        std::string ToString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + ")"; }


        // static methods

        static float Angle(const Quaternion& from, const Quaternion& to);
        static float AngleAxis(float angle, const Vec3<T>& axis);
        static constexpr T Dot(const Quaternion& a, const Quaternion& b);
        static T Euler(float x, float y , float z);
        static T FromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection);
        static T Inverse(const Quaternion& rotation);
        static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t);
        static Quaternion LerpUncampled(const Quaternion& a, const Quaternion& b, float t);
        static T LookRotation();
        static Quaternion Normalize(const Quaternion& rhs);
        static Quaternion RotateTowards();
        static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);
        static Quaternion SlerpUncampled(const Quaternion& a, const Quaternion& b, float t);

        //operators

    /*  static Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs) const;
        static bool operator==(const Quaternion& lhs, const Quaternion& rhs) const;*/

    };

    using Quaternionf = Quaternion<float>;
    using Quaternioni = Quaternion<int>;
    using Quaterniond = Quaternion<double>;

}

#include "Quaternion.inl"
