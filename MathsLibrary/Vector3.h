#pragma once
template <typename T>
class Vec3 {
public:
    T x, T y, T z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    // properties

    float Magnitude() const { return std::sqrt(x * x + y * y + z * z); }
    Vec3 Normalized() const {
        float magnitude = Magnitude(); if (magnitude < 0.00001f) { return Vec3(0.0f, 0.0f, 0.0f); } return Vec3(x / magnitude, y / magnitude, z / magnitude);
    }
    float SqrMagnitude() const { return x * x + y * y + z * z; }


    //public methods

    bool Equals(const Vec3& rhs) const { return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);}
    
    //T Equals(const Vec3& rhs) const { return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);}
    // --> version template

    void Set(const Vec3& rhs) { x = rhs.x; y = rhs.y; z = rhs.z }
    std::string ToString() const { return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std_to_string(z) + ")"; }

    //static methods

    static Vec3 ClampMagnitude(const Vec3& rhs, float maxLength) {

        float magnitude = rhs.Magnitude();
        if (magnitude <= maxLength) { return rhs; }
        else { return rhs.Normalized() * maxLength; }

        //limiter la longeur d'un vecteur sans changer sa direction

    }


    static Vec3 MoveTowards(const Vec3& current, const Vec3& target, float maxDistanceDelta) {

        Vec3 delta = target - current;
        float distance = delta.Magnitude();

        if (distance <= maxDistanceDelta || distance == 0.0f) { return target; }
        else {
            Vec3 direction = delta / distance;
            return current + direction * maxDistanceDelta;
        }

        //déplace une valeur or objet d'une position actuelle vers une position cible à une vitesse constante
    }

    Vec3 Normalize(const Vec3& rhs) const { float magnitude = rhs.Magnitude(); if (magnitude < 0.00001f) { return Vec3(0.0f, 0.0f, 0.0f); })return { x / magnitude, y / magnitude, z / magnitude } }

    static T OrthoNormalize(Vec3 normal, Vec3 tangent /*,Vec3 binormal*/ ) {}

    static float Reflect(const Vec3& inDirection, const Vec3& inNormal) {

        Vec3 n = inNormal.Normalized();
        float scal = Dot(inDirection, n);
        return inDirection - n * (2.0f * scal) ; // formule de réflexion
    }

    static Vec3 RotateTowards(Vec3 current, Vec3 target, float maxRadiansDelta, float maxMagnitudeDelta) {}

};