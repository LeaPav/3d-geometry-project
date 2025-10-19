#pragma once
#include <iostream>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <SFML/Graphics.hpp>

namespace math{
    template<typename T>
    class Vec2 {
    public:
        T x; // Horizontal component
        T y; // Vertical component

        // Default constructor. Initializes x and y to zero.
        constexpr Vec2() ;
        // Initializes vector with given x and y values.
        constexpr Vec2(T x, T y) ;
        // Converts from an SMFL Vector2f.
        constexpr Vec2(const sf::Vector2f& v);
        
        
        // *************operators*************


        // Add two vectors.
        constexpr Vec2 operator+(const Vec2& rhs) const;
        // Substracts two vectors.
        constexpr Vec2 operator-(const Vec2& rhs) const;
        // Multiplies vector by a scalar.
        constexpr Vec2 operator*(T scalar) const;
        // Divides vector by a scalar.
        constexpr Vec2 operator/(T scalar) const;
        // Checks if two vector are equal.
        constexpr bool operator==(const Vec2& vec) const;
        // Checks if two vector are not equal.
        constexpr bool operator!=(const Vec2& vec) const;
        // Adds another vector to this one.
        constexpr Vec2& operator+=(const Vec2& vec);
        // Substracts another vector from this one.
        constexpr Vec2& operator-=(const Vec2& vec);
        // Converts to SFML Vector2f.
        operator sf::Vector2f() const;
        // Accesses x or y by index ( 0 = 1, 1 = y).
        T& operator[](int index);


        // *************static properties*************


        // Returns a vector with both components set to 0.
        static constexpr Vec2 Zero();
        // returns a vector with both components set to 1.
        static constexpr Vec2 One();
        // Returns a vector pointing up (0,1).
        static constexpr Vec2 Up();
        // Returns a vector pointing down (0, -1).
        static constexpr Vec2 Down();
        // Returns a vector pointing right (1, 0).
        static constexpr Vec2 Right();
        // Returns a vector point left (-1, 0).
        static constexpr Vec2 Left();

        // Returns a vector with both components set to positive infinity.
        static constexpr  Vec2 PositiveInfinity();
        // Returns a vector with both components set to negative infinity.
        static constexpr Vec2 NegativeInfinity();


        // *************properties*************


        // Returns the magnitude (length) of the vector. The length of the vector is square of (x*x+y*y).
        float Magnitude() const;
        // Returns a normalized copy of the vector. It does not modify the current vector.
        Vec2 Normalized() const;
        // Returns the squared magnitude (avoids sqrt).
        float SqrMagnitude() const;


        // *************public methods*************


        // Check if another vector is equal to this one.
        bool Equals(const Vec2& rhs) const;
        // Normalize the vector in-place. Note that this method is modifying the current vector.
        void Normalize(); 
        // Set the x and y components.
        void Set(T newX, T newY); 
        // Returns a string representation of the vector.
        std::string ToString() const;


        // *************static methods*************


        // Clamps the magnitude of a vector to a maximum length.
        static Vec2 ClampMagnitude(const Vec2& rhs, float maxLength);

        // Move a vector towards a target by a maximum delta.
        static Vec2 MoveTowards(const Vec2& current, const Vec2& target, float maxDistanceDelta);

        // Returns the vector perpendicular to a vector.
        static Vec2 Perpendicular(const Vec2& rhs);

        // Reflects a vector off a surface with a given normal.
        static Vec2 Reflect(const Vec2& inDirection, const Vec2& inNormal);

        // Returns the angle in radiant between two vectors. 
        static float Angle(const Vec2& from, const Vec2& to); 

        // Returns the signed angle in radiant between two vectors.
        static float SignedAngle(const Vec2& from, const Vec2& to);
    
        // Returns the distance between two vectors.
        static T Distance(const Vec2& a, const Vec2& b); 

        // Returns the dot product of two vectors.
        static constexpr T Dot(const Vec2& a, const Vec2& b);

        // Linearly interpolates between two vectors.
        static Vec2 Lerp(const Vec2& a, const Vec2& b, float t);

        // Linearly interpolates without clamping.
        static Vec2 LerpUnclamped(const Vec2& a, const Vec2& b, float t);

        // Returns the component-wise maximum of two vectors.
        static constexpr Vec2 Max(const Vec2& a, const Vec2& b);

        // Returns the component-wise minimum of two vectors.
        static constexpr Vec2 Min(const Vec2& a, const Vec2& b);

        // Multiplies two vectors component-wise.
        static constexpr Vec2 Scale(const Vec2& a, const Vec2& b);

    };


    using Vec2f = Vec2<float>;
    using Vec2i = Vec2<int>;
    using Vec2d = Vec2<double>;

   

}

#include "Vec2.inl"