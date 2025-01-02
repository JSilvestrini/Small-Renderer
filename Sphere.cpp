#include "Sphere.h"

Sphere::Sphere() noexcept : Shape(), center(glm::vec3()), radius(glm::vec3()) {}

Sphere::Sphere(glm::vec3 center, glm::vec3 radius) noexcept : Shape(), center(center), radius(radius) {}

Sphere::Sphere(glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, glm::vec3 Km, float n, bool render, glm::vec3 center, glm::vec3 radius) noexcept : 
    Shape(Ka, Kd, Ks, Km, n, render),
    center(center),
    radius(radius) {}

Sphere::Sphere(const Sphere& sphere) noexcept : Shape(sphere), center(sphere.center), radius(sphere.radius) {}

Sphere::Sphere(Sphere&& sphere) noexcept : Shape(sphere), center(std::move(sphere.center)), radius(std::move(sphere.radius)) {
    sphere.center = glm::vec3();
    sphere.radius = glm::vec3();
}

Sphere& Sphere::operator=(const Sphere& sphere) noexcept {
    if (this == &sphere) {
        return *this;
    }

    Shape::operator=(sphere);

    this->center = sphere.center;
    this->radius = sphere.radius;

    return *this;
}

Sphere& Sphere::operator=(Sphere&& sphere) noexcept {
    if (this == &sphere) {
        return *this;
    }

    Shape::operator=(sphere);

    this->center = std::move(sphere.center);
    this->radius = std::move(sphere.radius);

    sphere.center = glm::vec3();
    sphere.radius = glm::vec3();

    return *this;
}

Sphere::~Sphere() {}

// getters
glm::vec3 Sphere::getCenter() const noexcept { return this->center; }
glm::vec3 Sphere::getRadius() const noexcept { return this->radius; }

glm::vec3 Sphere::getNormal(const glm::vec3& point) const {
    return glm::normalize((point - this->center));
}

// setters
bool Sphere::setCenter(const glm::vec3& center) {
    this->center = center;
    return (this->center == center);
}

bool Sphere::setRadius(const glm::vec3& radius) {
    this->radius = radius;
    return (this->radius == radius);
}