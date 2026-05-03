#pragma once

#include "Object.h"
#include <vector>
#include <string>

class Collision {
private:
    bool isCollisionDetectionActive;
    std::vector<Object*> objects;
    std::string type;
    int numberOfObjects;
public:
    Collision();
    void toggleCollisionDetection();
    void collisionDetector();
    bool collisionDetectorStatus();
    void addNonGhostObjects(Object* object, std::string type);
};