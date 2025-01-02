#include "Plane.h"

Plane::Plane() noexcept : Shape(), normal(glm::vec3(0.0f, 1.0f, 0.0f)), point(0.0f, 0.0f, 0.0f) {}

Plane::Plane(glm::vec3 normal, glm::vec3 point) noexcept : Shape(), normal(normal), point(normal) {}

Plane::Plane(glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, glm::vec3 Km, float n, bool render, glm::vec3 normal, glm::vec3 point) noexcept :
    Shape(Ka, Kd, Ks, Km, n, render),
    normal(normal),
    point(point) {}

Plane::Plane(const Plane& plane) noexcept : Shape(plane), normal(plane.normal), point(plane.point) {}

Plane::Plane(Plane&& plane) noexcept : Shape(plane), normal(std::move(plane.normal)), point(std::move(plane.point)) {
    plane.normal = glm::vec3();
    plane.point = glm::vec3();
}

Plane Plane::operator=(const Plane& plane) noexcept {
    if (this == &plane) {
        return *this;
    }

    Shape::operator=(plane);

    this->normal = plane.normal;
    this->point = plane.point;

    return *this;
}

Plane Plane::operator=(Plane&& plane) noexcept {
    if (this == &plane) {
        return *this;
    }

    Shape::operator=(plane);

    this->normal = std::move(plane.normal);
    this->point = std::move(plane.point);

    plane.normal = glm::vec3();
    plane.point = glm::vec3();

    return *this;
}

Plane::~Plane() {}

// getters
glm::vec3 Plane::getNormal(const glm::vec3& point) const { return this->normal; }
glm::vec3 Plane::getPoint() const noexcept { return this->point; }

// setters
bool Plane::setNormal(const glm::vec3& normal) {
    this->normal = normal;
    return (this->normal == normal);
}

bool Plane::setPoint(const glm::vec3& point) {
    this->point = point;
    return (this->point == point);
}