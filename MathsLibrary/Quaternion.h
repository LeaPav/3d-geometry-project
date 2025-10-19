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

        //Components of the quaternion: x, y, z are the imaginary parts, and w is the real part.
        T x;
        T y;
        T z; 
        T w;
        
        //Default constructor. Initializes a zero quaternion.
        constexpr Quaternion();

        //Initializes the quaternion with specified components.
        constexpr Quaternion(T x, T y, T z, T w);

        //                                              STATIC PROPERTIES

        //Returns the identity quaternion (0, 0, 0, 1), representing no rotation.
        static Quaternion Identity();

        //                                                  PROPERTIES

        //Converts th quaternion to Euler angles (rotation around X, Y, Z axis).
        Vec3<T> EulerAngles();

        //Returns a normalized version of the quaternion (unit length).
        Quaternion Normalized() const;

        //Accesses components by index : 0 --> x, 1 --> y, 2 --> z, 3 --> w.
        T& operator[](int index);

        //                                                 PUBLIC METHODS

        //Checks if two quaternions are equal.
        bool Equals(const Quaternion& rhs) const;

        //Copies values from another quaternion.
        void Set(const Quaternion& rhs);

        //Sets the quaternion to rotate from one direction to another.
        void SetFromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection);

        //Sets the quaternion to look in a specific direction with an up vector.
        void SetLookRotation(const Vec3<T>& view, const Vec3<T>& up);

        //Converts the quaternion to an angle-axis representation.
        void ToAngleAxis(T& angle, Vec3<T>& axis);

        //Returns a string representation of the quaternion.
        std::string ToString() const { return "(" + std::to_string(w) + ", " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")"; }


        //                                                 STATIC METHODS

        //Computes the angle between two quaternions.
        static T Angle(const Quaternion& from, const Quaternion& to);

        //Creates a quaternion from an angle and axis.
        static Quaternion AngleAxis(const T& angle, const Vec3<T>& axis);

        //Computes the dot product of two quaternions.
        static constexpr T Dot(const Quaternion& a, const Quaternion& b);

        //Creates a quaternion from Euler angles.
        static Quaternion Euler(T x, T y , T z);

        //Creates a quaternion representing rotation from one direction to another.
        static Quaternion FromToRotation(const Vec3<T>& fromDirection, const Vec3<T>& toDirection);

        //Returns the inverse of a quaternion (opposite rotation).
        static Quaternion Inverse(const Quaternion& rotation);

        //Linearly interpolates between two quaternions.
        static Quaternion Lerp(const Quaternion& a, const Quaternion& b, float t);

        //Unclamped version of linear interpolation.
        static Quaternion LerpUncampled(const Quaternion& a, const Quaternion& b, float t);

        //Creates a quaternion that looks in a given direction direction with an up vector.
        static Quaternion LookRotation(const Vec3<T>& forward, const Vec3<T>& upwards);

        //Returns a normalized version of the given quaternion.
        static Quaternion Normalize(const Quaternion& rhs);

        //Rotates from one quaternion to another by a maximum angle.
        static Quaternion RotateTowards(const Quaternion& from, const Quaternion& to, const T maxDelta);

        //Spherical linear interpolation between two quaternions.
        static Quaternion Slerp(const Quaternion& a, const Quaternion& b, float t);

        //Unclamped version of spherical interpolation.
        static Quaternion SlerpUncampled(const Quaternion& a, const Quaternion& b, float t);

    };

    //                                                         OPERATORS

    //Multiplies two quaternions (combines rotations).
    template <typename T>
    constexpr Quaternion<T> operator*(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    //Applies quaternion rotation to a vector.
    template <typename T>
    constexpr Vec3<T> operator*(const Quaternion<T>& lhs, const Vec3<T>& rhs);

    //Multiplies a quaternion by a scalar.
    template <typename T>
    constexpr Quaternion<T> operator*(T lhs, const Quaternion<T>& rhs);

    //Adds two quaternions component-wise.
    template<typename T>
    constexpr Quaternion<T> operator+(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    //Checks if two quaternions are equal.
    template <typename T>
    constexpr bool operator==(const Quaternion<T>& lhs, const Quaternion<T>& rhs);

    //Convenient aliases for common numeric types.
    using Quaternionf = Quaternion<float>;
    using Quaternioni = Quaternion<int>;
    using Quaterniond = Quaternion<double>;

}

#include "Quaternion.inl"
