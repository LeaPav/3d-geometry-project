#pragma once
#include <iostream>

namespace math {
    template<typename T>
    class Vec2 {
    public:
        T x, T y;

        Vec2() : x(0), y(0) {}
        Vec2(T x, T y) : x(x), y(y) {}

        //properties

        T Magnitude() const { return  std::sqrt(x * x + y * y)  }

        Vec2 Normalized() const { double magnitude = std::sqrt(x * x + y * y); return x / magnitude, y / magnitude  }
        //Vec2 Normalized() const { double magnitude = Magnitude(); if (magnitude < 0) return 0 }
        //Vec2 Normalized() const { if (Magnitude() < 0) return 0 }
        
        T SqrMagnitude() const { return  x * x + y * y  }

        //public methods

        bool Equals(const Vec2& rhs) const { if (x == rhs.x) && (y == rhs.y); return  rhs.true  }
        T Normalize(const Vec2& rhs) const { double normalize = std::sqrt(x * x + y * y); if (normalise == 1)  return normalise  }
        T Set(const Vec2& rhs) const { return new rhs.x, new rhs.y  }
        std::string ToString(const Vec2& rhs) const { std::string format; return format }

        //static methods

        static Vec2 ClampMagnitude(const Vec2& rhs, float maxLength) {
           
            float magnitude = rhs.Magnitude()
            if (magnitude <= maxLength) { return rhs }
            else{ return rhs.Normalized() * maxLength }

            //limiter la longeur d'un vecteur sans changer sa direction

        }


        static Vec2 MoveTowards(const Vec2& current, const Vec2& target, float maxDistanceDelta) {
        
            Vec2 delta = target - current;
            float distance = Distance(current, target);

            Vec2 direction = delta / distance

            if (distance <= maxDistanceDelta || distance == 0.0f) { return target; } else {return current + direction * maxDistanceDelta}

            //déplace une valeur or objet d'une position actuelle vers une position cible à une vitesse constante
        }


        static Vec2 Perpendicular(const Vec2& rhs) { return Vec2 (-rhs.y, rhs.x) } // formule de perpendicularité

        static float Reflect(const Vec2& inDirection, const Vec2& inNormal) {
            
            Vec2 n = Normalized(inNormal);
            float scal = Dot(inDirection, n);
            return inDirection - 2 * n * scal; // formule de réflexion
        }

        static T Dot(const Vec2& a, const Vec2& b) {
            return a.x * b.x + a.y * b.y; // produit scalaire

        }
        static float Angle(const Vec2& from, const Vec2& to) {
            float magnitudeFrom = std::sqrt(from.x * from.x + from.y * from.y);
            float magnitudeTo = std::sqrt(to.x * to.x + to.y * to.y);

            float dot = from.x * to.x + from.y * to.y;

            if (magnitudeFrom == 0 || magnitudeTo == 0) return 0.0f;

            float cosTheta = dot / (magnitudeFrom * magnitudeTo);
            cosTheta = std::fmax(-1.f, std::fmin(1.f, cosTheta));

            return std::acos(cosTheta) * 180.0f / 3.14159265f;
        }

        static T Distance(const Vec2& a, const Vec2& b) {
            T dx = a.x - b.x;
            T dy = a.y - b.y;
            return std::sqrt(dx * dx + dy * dy); //distance
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