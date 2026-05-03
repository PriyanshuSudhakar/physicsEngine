#pragma once

#include "Object.h"
#include <vector>
#include <string>

class Collision {
private:
    bool isCollisionDetectionActive;
    bool isWallCollisionActive;
    std::vector<Object*> objects;
    std::string type;
    int numberOfObjects;
    int wallWidth;
    int wallHeight;
public:
    Collision();
    void toggleCollisionDetection();
    void collisionDetector();
    void wallCollisionDetector();
    bool collisionDetectorStatus();
    void addNonGhostObjects(Object* object, std::string type);
    void setWallWidth(int width);
    void setWallHeight(int height);
};