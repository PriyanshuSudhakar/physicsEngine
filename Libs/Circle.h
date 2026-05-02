#pragma once

#define _USE_MATH_DEFINES
#include "Triangle.h"
#include <glm/glm.hpp>
#include <cmath>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Circle {
private:
    float mass;

    float centre_x, centre_y;
    float radii;

    float* vertices;
    unsigned int* indices;

    float angle = 0.1f;

    Triangle* triangles;
    unsigned int objectID;

    glm::vec2 currPosition;
    glm::vec2 velocity;
public:
    Circle(float x, float y, float radii, float theta);
    void drawCircle();
    void setMass(float mass);
    float getMass();
    unsigned int getObjectID();
    glm::vec2 getCurrentCoordinates();
    glm::vec2 getVelocity();
    void updateVelocity(glm::vec2 velocity);
    glm::vec2 getPosition();
    void updatePosition(glm::vec2 position);
};