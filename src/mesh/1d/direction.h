#pragma once

#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <glm/glm.hpp>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../core/Object.h"

class Direction {
private:
    float length;
    float angle; // in radians
    Triangle* arrowHead;
public:
    Direction(float len, float ang);
    ~Direction();
    glm::vec2 getVector() const;
    void setLength(float len);
    void setAngle(float ang);
    float getLength() const;
    float getAngle() const;
};