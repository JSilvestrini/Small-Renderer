#include "Shape.h"

Shape::Shape() noexcept : 
    Ka(glm::vec3()),
    Kd(glm::vec3()),
    Ks(glm::vec3()),
    Km(glm::vec3()),
    n(0),
    render(true) {}

Shape::Shape(glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, glm::vec3 Km, float n, bool render) noexcept : 
    Ka(Ka),
    Kd(Kd),
    Ks(Ks),
    Km(Km),
    n(n),
    render(render) {}

Shape::Shape(const Shape& shape) noexcept :
    Ka(shape.Ka),
    Kd(shape.Kd),
    Ks(shape.Ks),
    Km(shape.Km),
    n(shape.n),
    render(shape.render) {}

Shape::Shape(Shape&& shape) noexcept :
    Ka(std::move(shape.Ka)),
    Kd(std::move(shape.Kd)),
    Ks(std::move(shape.Ks)),
    Km(std::move(shape.Km)),
    n(std::move(shape.n)),
    render(std::move(shape.render)) {
        shape.Ka = glm::vec3();
        shape.Kd = glm::vec3();
        shape.Ks = glm::vec3();
        shape.Km = glm::vec3();
        shape.n = -1;
        shape.render = false;
    }

Shape& Shape::operator=(const Shape& shape) noexcept {
    if (this == &shape) {
        return *this;
    }

    this->Ka = shape.Ka;
    this->Kd = shape.Kd;
    this->Ks = shape.Ks;
    this->Km = shape.Km;
    this->n = shape.n;
    this->render = shape.render;

    return *this;
}

Shape& Shape::operator=(Shape&& shape) noexcept {
    if (this == &shape) {
        return *this;
    }

    this->Ka = std::move(shape.Ka);
    this->Kd = std::move(shape.Kd);
    this->Ks = std::move(shape.Ks);
    this->Km = std::move(shape.Km);
    this->n = std::move(shape.n);
    this->render = std::move(shape.render);

    shape.Ka = glm::vec3();
    shape.Kd = glm::vec3();
    shape.Ks = glm::vec3();
    shape.Km = glm::vec3();
    shape.n = -1;
    shape.render = false;

    return *this;
}

Shape::~Shape() {}

glm::vec3 Shape::getKa() const noexcept { return this->Ka; }
glm::vec3 Shape::getKd() const noexcept { return this->Kd; }
glm::vec3 Shape::getKs() const noexcept { return this->Ks; }
glm::vec3 Shape::getKm() const noexcept { return this->Km; }
float Shape::getN() const noexcept { return this->n; }
bool Shape::getRender() const noexcept { return this->render; }
glm::vec3 Shape::getNormal(const glm::vec3& point) const { return glm::vec3(); }

bool Shape::setKa(const glm::vec3& ka) {
    this->Ka = ka;
    return (this->Ka == ka);
}

bool Shape::setKd(const glm::vec3& kd) {
    this->Kd = kd;
    return (this->Kd == kd);
}

bool Shape::setKs(const glm::vec3& ks) {
    this->Ks = ks;
    return (this->Ks == ks);
}

bool Shape::setKm(const glm::vec3& km) {
    this->Km = km;
    return (this->Km == km);
}

bool Shape::setN(const float& n) {
    this->n = n;
    return (this->n == n);
}

bool Shape::setRender(const bool& render) {
    this->render = render;
    return (this->render == render);
}