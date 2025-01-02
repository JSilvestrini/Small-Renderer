#ifndef SHAPE_H
#define SHAPE_H

#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <algorithm>

class Shape {
    private:
        glm::vec3 Ka;
        glm::vec3 Kd;
        glm::vec3 Ks;
        glm::vec3 Km;
        float n;
        bool render;
    public:
        Shape() noexcept;
        Shape(glm::vec3 Ka, glm::vec3 Kd, glm::vec3 Ks, glm::vec3 Km, float n, bool render) noexcept;
        Shape(const Shape& shape) noexcept;
        Shape(Shape&& shape) noexcept;
        Shape& operator=(const Shape& shape) noexcept;
        Shape& operator=(Shape&& shape) noexcept;
        ~Shape();
        glm::vec3 getKa() const noexcept;
        glm::vec3 getKd() const noexcept;
        glm::vec3 getKs() const noexcept;
        glm::vec3 getKm() const noexcept;
        float getN() const noexcept;
        bool getRender() const noexcept;
        virtual glm::vec3 getNormal(const glm::vec3& point) const;
        bool setKa(const glm::vec3& ka);
        bool setKd(const glm::vec3& kd);
        bool setKs(const glm::vec3& ks);
        bool setKm(const glm::vec3& km);
        bool setN(const float& n);
        bool setRender(const bool& render);
};

#endif