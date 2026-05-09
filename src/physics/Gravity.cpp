#include "Gravity.h"
#include <thread>
#include <chrono>

Gravity::Gravity()
{
    this->numberOfObjects = 0;
}

void Gravity::toggleGravity()
{
    this->isActive = !this->isActive;
}

bool Gravity::getGravityStatus()
{
    return this->isActive;
}

void Gravity::addObject(Circle *circle)
{
    numberOfObjects++;
    this->objects.push_back(circle);
    glm::vec2 tempForce;
    tempForce.x = 0.0f;
    tempForce.y = 0.0f;
    this->forces.push_back(tempForce);
}

void Gravity::gravity()
{
    for (int currObject = 0; currObject < this->numberOfObjects; currObject++)
    {
        // glm::vec2 force;
        // force.x = this->forces[currObject].x;
        // force.y = this->forces[currObject].y;
        this->forces[currObject].x = 0.0f;
        this->forces[currObject].y = 0.0f;

        for (int object = 0; object < this->numberOfObjects; object++)
        {
            if (object == currObject)
            {
                continue;
            }

            // std::cout << "[DEBUG] start" << std::endl;

            // Calculate Total Force on currObject
            float currObject_x = this->objects[currObject]->getPosition().x;
            float currObject_y = this->objects[currObject]->getPosition().y;
            float currObject_mass = this->objects[currObject]->getMass();
            float object_x = this->objects[object]->getPosition().x;
            float object_y = this->objects[object]->getPosition().y;
            float object_mass = this->objects[object]->getMass();

            // std::cout << "[DEBUG] numberOfObjects: " << this->numberOfObjects << std::endl;
            // std::cout << "[DEBUG] objects.size(): " << this->objects.size() << std::endl;
            // std::cout << "[DEBUG] currObject: " << currObject << ", object: " << object << std::endl;
            // std::cout << "[DEBUG] pointer currObject: " << this->objects[currObject] << std::endl;
            // std::cout << "[DEBUG] pointer object: " << this->objects[object] << std::endl;

            // std::cout << "[DEBUG] end" << std::endl;

            float dist_x = currObject_x - object_x;
            int dir_x = (currObject_x < object_x) ? 1 : -1;
            float dist_y = currObject_y - object_y;
            int dir_y = (currObject_y < object_y) ? 1 : -1;

            // std::cout << "[INFO]: Horizontal distance between the objects are: " << dist_x << std::endl;
            // std::cout << "[INFO]: Vertical distance between the objects are: " << dist_y << std::endl;

            // std::cout << "[INFO]: Mass of object1: " << currObject_mass << std::endl;
            // std::cout << "[INFO]: Mass of object2: " << object_mass << std::endl;

            // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            
            // make it zero if collision detection is turned on
            float epsilon = 0.5f; // tune this value

            // Force is towards object
            float currForce_x = dir_x * ((currObject_mass * object_mass) / (dist_x * dist_x + epsilon));
            float currForce_y = dir_y * ((currObject_mass * object_mass) / (dist_y * dist_y + epsilon));

            // std::cout << "[INFO]: Horizontal force between the objects are: " << currForce_x << std::endl;
            // std::cout << "[INFO]: Vertical forces between the objects are: " << currForce_y << std::endl;

            this->forces[currObject].x += currForce_x;
            this->forces[currObject].y += currForce_y;

            // std::cout << "[INFO]: calculated force between the objects are: " << this->forces[currObject].x << std::endl;
            // std::cout << "[INFO]: calculated force between the objects are: " << this->forces[currObject].y << std::endl;
        }

        // update the current force
        // std::cout << "[DEBUG:] currObject is " << currObject << std::endl;
        // this->forces[currObject] = force;
    }

    // std::cout << "[DEBUG:] Log before update velocity" << std::endl;
    updateVelocity();
}

void Gravity::updateVelocity()
{
    // std::cout << "[DEBUG:] Clock Crash test" << std::endl;
    float timeSpeed = 0.001f;
    Clock time = Clock(timeSpeed);
    // std::cout << "[DEBUG:] Clock Did not crash" << std::endl;

    for (int object = 0; object < this->numberOfObjects; object++)
    {
        // std::cout << "[DEBUG] Updating object: " << object << std::endl;

        float acceleration_x = this->forces[object].x / this->objects[object]->getMass();
        float acceleration_y = this->forces[object].y / this->objects[object]->getMass();
        // std::cout << "[DEBUG] Acceleration: " << acceleration_x << ", " << acceleration_y << std::endl;

        glm::vec2 currVelocity = this->objects[object]->getVelocity();
        currVelocity.x += acceleration_x * time.getTimeSpeed();
        currVelocity.y += acceleration_y * time.getTimeSpeed();
        this->objects[object]->updateVelocity(currVelocity);
        // std::cout << "[DEBUG] Velocity updated" << std::endl;

        glm::vec2 currPosition = this->objects[object]->getPosition();
        currPosition.x += currVelocity.x * time.getTimeSpeed();
        currPosition.y += currVelocity.y * time.getTimeSpeed();
        this->objects[object]->updatePosition(currPosition);
        // std::cout << "[DEBUG] Position updated" << std::endl;
        // std::cout << "[DEBUG] Matrix built" << std::endl;
    }
}

void Gravity::groundGravity() {
    float timeSpeed = 0.0001f;
    Clock time = Clock(timeSpeed);
    // std::cout<<"[Info] Number of objects: "<<this->numberOfObjects<<std::endl;
    for(int object=0;object<this->numberOfObjects;object++) {
        // just add force in the downward direction
        this->forces[object].y = 0.0f; 
        this->forces[object].y = -this->earthMass * this->g;
        glm::vec2 currentVelocity = this->objects[object]->getVelocity();
        currentVelocity.y += (this->forces[object].y / this->objects[object]->getMass()) * time.getTimeSpeed(); 
        this->objects[object]->updateVelocity(currentVelocity);
        glm::vec2 currentPosition = this->objects[object]->getCurrentCoordinates();
        currentPosition.y += (currentVelocity.y * time.getTimeSpeed());
        // std::cout<<"[Info Velocity]: Current velocity of the object is: "<<currentVelocity.x<<"in x direction and "<<currentVelocity.y<<"in the y direction."<<std::endl;
        // this->objects[object]->updatePosition(currentPosition);
        // this->objects[object]->updateInWorldPosition(currentPosition);
    }
    
}