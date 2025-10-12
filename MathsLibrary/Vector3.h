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

    //static methods

    static Vec3 ClampMagnitude(const Vec3& rhs, float maxLength) {

        float magnitude = rhs.Magnitude()
            if (magnitude <= maxLength) { return rhs }
            else { return rhs.Normalized() * maxLength }

        //limiter la longeur d'un vecteur sans changer sa direction

    }

    static Cross(Vec3 lhs, Vec3 rhs) {}

    static Vec3 MoveTowards(const Vec3& current, const Vec3& target, float maxDistanceDelta) {

        Vec3 delta = target - current;
        float distance = Distance(current, target);

        Vec3 direction = delta / distance

            if (distance <= maxDistanceDelta || distance == 0.0f) { return target; }
            else { return current + direction * maxDistanceDelta }

        //déplace une valeur or objet d'une position actuelle vers une position cible à une vitesse constante
    }


    T Normalize(const Vec3& rhs) const { double magnitude = std::sqrt(x * x + y * y + z * z); return magnitude = 1 }
    static T OrthoNormalize(Vec3 normal, Vec3 tangent /*,Vec3 binormal*/ ) {}

    static Project(Vec3 vector, Vec3 onNormal) {}
    static Vec3 ProjectOnPlane(Vec3 vector, Vec3 planeNormal) {}

    static float Reflect(const Vec3& inDirection, const Vec3& inNormal) {

        Vec3 n = Normalized(inNormal);
        float scal = Dot(inDirection, n);
        return inDirection - 2 * n * scal; // formule de réflexion
    }

    static Vec3 RotateTowards(Vec3 current, Vec3 target, float maxRadiansDelta, float maxMagnitudeDelta) {}

    static Vec3 Slerp(Vec3 a, Vec3 b, float t) {}

    static Vec3 SlerpUncamped(Vec3 a, Vec3 b, float t) {}

};