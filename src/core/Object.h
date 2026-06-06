#pragma once

#include <glm/glm.hpp>

class Object
{
protected:
    float mass;
    glm::vec2 currPosition;
    glm::vec2 velocity;

    // Different forces acting on the object
    glm::vec2 gravitaiotnalForce;
    glm::vec2 collisionForce;
    glm::vec2 groundForce;
    glm::vec2 electromagneticForce;

    glm::vec2 force; // this is the sum of all the forces acting on the object

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
    virtual glm::vec2 getForce() { return this->force; }

    virtual void updateVelocity(glm::vec2 velocity) { this->velocity = velocity; }
    virtual void updatePosition(glm::vec2 position) { this->currPosition = position; }
    virtual void updateInWorldPosition(glm::vec2 position)
    {
        this->currPosition = position;
    }
    virtual void updateGravitationalForce(glm::vec2 force) { this->gravitaiotnalForce = force; } // this needs to be the sum of all the forces acting on the object
    virtual void updateCollisionForce(glm::vec2 force) { this->collisionForce = force; }
    virtual void updateGroundForce(glm::vec2 force) { this->groundForce = force; }
    virtual void updateElectromagneticForce(glm::vec2 force) { this->electromagneticForce = force; }
    virtual void updateForce(glm::vec2 force)
    {
        this->force = this->gravitaiotnalForce + this->collisionForce + this->groundForce + this->electromagneticForce;
    }
};