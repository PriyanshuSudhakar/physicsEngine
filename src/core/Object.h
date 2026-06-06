#pragma once

#include <glm/glm.hpp>
#include <iostream>

class Object
{
protected:
    float mass;
    glm::vec2 currPosition;
    glm::vec2 velocity = glm::vec2(0.0f, 0.0f);

    // Different forces acting on the object
    glm::vec2 gravitaiotnalForce = glm::vec2(0.0f, 0.0f);
    glm::vec2 collisionForce = glm::vec2(0.0f, 0.0f);
    glm::vec2 groundForce = glm::vec2(0.0f, 0.0f);
    glm::vec2 electromagneticForce = glm::vec2(0.0f, 0.0f);

    glm::vec2 force = glm::vec2(0.0f, 0.0f); // this is the sum of all the forces acting on the object

    glm::vec2 acceleration = {0.0f, 0.0f};  

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
    virtual void updateVelocityAuto() = 0; // should happen automatically using the current force acting on the object according to the delta t time of the universe (time treated as abosulute since there is an absolute frame of reference as the obeserver of the screen itself)
    virtual void updatePosition(glm::vec2 position) { this->currPosition = position; } // should happen automatically using the velocity of the given object according to the delta t time of the universe (time treated as abosulute since there is an absolute frame of reference as the obeserver of the screen itself)
    virtual void updateInWorldPosition(glm::vec2 position)
    {
        this->currPosition = position;
    }
    virtual void updatePositionAuto() = 0;
    virtual void updateGravitationalForce(glm::vec2 force) { this->gravitaiotnalForce = force; } 
    virtual void updateCollisionForce(glm::vec2 force) { this->collisionForce = force; }
    virtual void updateGroundForce(glm::vec2 force) { this->groundForce = force; }
    virtual void updateElectromagneticForce(glm::vec2 force) { this->electromagneticForce = force; }
    virtual void updateForce()
    {
        std::cout << "[INFO] Gravitational Force for object " << this->objectID << ": " << this->gravitaiotnalForce.x << " in x direction and " << this->gravitaiotnalForce.y << " in y direction." << std::endl;
        // std::cout << "[INFO] Collision Force: " << this->collisionForce.x << " in x direction and " << this->collisionForce.y << " in y direction." << std::endl;
        // std::cout << "[INFO] Ground Force: " << this->groundForce.x << " in x direction and " << this->groundForce.y << " in y direction." << std::endl;
        // std::cout << "[INFO] Electromagnetic Force: " << this->electromagneticForce.x << " in x direction and " << this->electromagneticForce.y << " in y direction." << std::endl;
        this->force = this->gravitaiotnalForce + this->collisionForce + this->groundForce + this->electromagneticForce; // this is the sum of all the forces acting on the object
    }
    virtual void tick() {
        // updateForce();
        updateVelocityAuto();
        updatePositionAuto();
    }
};