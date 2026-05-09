#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "../mesh/2d/Circle.h"
#include "Clock.h"

class Gravity {
private:
    const double G = 6.67408e-11;
    const double g = 9.8;
    const double earthMass = 10;
    std::vector<Circle*> objects;
    bool isActive;
    int numberOfObjects;
    std::vector<glm::vec2> forces;
public:
    Gravity();
    void addObject(Circle* circle);
    void toggleGravity();
    bool getGravityStatus();
    void gravity();
    void groundGravity();
    void updateVelocity();
};