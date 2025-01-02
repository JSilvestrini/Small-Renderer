#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
    private:
        glm::vec3 center;
        glm::vec3 radius;

    public:
        Sphere() noexcept;
        Sphere(glm::vec3 center, glm::vec3 radius) noexcept;
        Sphere(glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, glm::vec3 Km, float n, bool render, glm::vec3 center, glm::vec3 radius) noexcept;
        Sphere(const Sphere& Sphere) noexcept;
        Sphere(Sphere&& Sphere) noexcept;
        Sphere& operator=(const Sphere& Sphere) noexcept;
        Sphere& operator=(Sphere&& Sphere) noexcept;
        ~Sphere();
        glm::vec3 getCenter() const noexcept;
        glm::vec3 getNormal(const glm::vec3& point) const override;
        glm::vec3 getRadius() const noexcept;
        bool setCenter(const glm::vec3& center);
        bool setRadius(const glm::vec3& radius);
};

#endif