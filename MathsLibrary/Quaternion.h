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

        Vec3<T> EulerAngles();
        Quaternion Normalized() const; 
        T& operator[](int index);


        //public methods

        bool Equals(const Quaternion& rhs) const;
        void Set(const Quaternion& rhs);
        void SetFromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection);
        void SetLookRotation(const Vec3<T>& view, const Vec3<T>& up);
        void ToAngleAxis(T& angle, Vec3<T>& axis);
        std::string ToString() const { return "(" + std::to_string(w) + ", " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")"; }


        // static methods

        static T Angle(const Quaternion& from, const Quaternion& to);
        static Quaternion AngleAxis(const T& angle, const Vec3<T>& axis);
        static constexpr T Dot(const Quaternion& a, const Quaternion& b);
        static Quaternion Euler(T x, T y , T z);
        static Quaternion FromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection);
        static Quaternion Inverse(const Quaternion& rotation);
        static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t);
        static Quaternion LerpUncampled(const Quaternion& a, const Quaternion& b, float t);
        static Quaternion LookRotation(const Vec3<T>& forward, const Vec3<T>& upwards);
        static Quaternion Normalize(const Quaternion& rhs);
        static Quaternion RotateTowards(const Quaternion& from, const Quaternion& to, const T maxDelta);
        static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);
        static Quaternion SlerpUncampled(const Quaternion& a, const Quaternion& b, float t);

    };

    //operator

    template <typename T>
    constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template <typename T>
    constexpr Vec3<T> operator*(const Quaternion<T>& lhs, const Vec3<T>& rhs);

    template <typename T>
    constexpr Quaternion<T> operator*(T lhs, const Quaternion<T>& rhs);

    template<typename T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    template <typename T>
    constexpr bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    using Quaternionf = Quaternion<float>;
    using Quaternioni = Quaternion<int>;
    using Quaterniond = Quaternion<double>;

}

#include "Quaternion.inl"
