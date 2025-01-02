#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
    private:
        glm::vec3 normal;
        glm::vec3 point;
    public:
        Plane() noexcept;
        Plane(glm::vec3 normal, glm::vec3 point) noexcept;
        Plane(glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, glm::vec3 Km, float n, bool render, glm::vec3 normal, glm::vec3 point) noexcept;
        Plane(const Plane& plane) noexcept;
        Plane(Plane&& plane) noexcept;
        Plane operator=(const Plane& plane) noexcept;
        Plane operator=(Plane&& plane) noexcept;
        ~Plane();
        glm::vec3 getNormal(const glm::vec3& point) const override;
        glm::vec3 getPoint() const noexcept;
        bool setNormal(const glm::vec3& normal);
        bool setPoint(const glm::vec3& point);
};

#endif