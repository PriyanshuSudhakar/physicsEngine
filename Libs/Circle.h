#pragma once

#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <glm/glm.hpp>
#include <cmath>

class Circle {
private:
    float centre_x, centre_y;
    float radii;

    float* vertices;
    unsigned int* indices;

    float angle = 0.1f;

    Triangle* triangles;
public:
    Circle(float x, float y, float radii);
    void drawCircle();
};