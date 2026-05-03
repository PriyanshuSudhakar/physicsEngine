#pragma once

#include <glm/glm.hpp>

class Object
{
protected:
    float mass;
    glm::vec2 currPosition;
    glm::vec2 velocity;
    unsigned int objectID;

public:
    virtual ~Object() {}

    virtual void draw() = 0;
    virtual float getBoundingRadius() = 0;

    virtual void setMass(float mass) { this->mass = mass; }
    virtual float getMass() { return this->mass; }

    virtual unsigned int getObjectID() { return this->objectID; }

    virtual glm::vec2 getCurrentCoordinates() { return this->currPosition; }
    virtual glm::vec2 getVelocity() { return this->velocity; }
    virtual glm::vec2 getPosition() { return this->currPosition; }

    virtual void updateVelocity(glm::vec2 velocity) { this->velocity = velocity; }
    virtual void updatePosition(glm::vec2 position) { this->currPosition = position; }
    virtual void updateInWorldPosition(glm::vec2 position)
    {
        this->currPosition = position;
    }
};