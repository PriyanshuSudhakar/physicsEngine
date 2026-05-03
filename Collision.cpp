#include "Libs/Collision.h"

Collision::Collision() {
    this->isCollisionDetectionActive = true;
    this->numberOfObjects = 0;
}

void Collision::toggleCollisionDetection() {
    this->isCollisionDetectionActive = !this->isCollisionDetectionActive;
}

void Collision::collisionDetector() {
    for(int object1=0;object1<this->numberOfObjects;object1++) {
        for(int object2=object1+1;object2<this->numberOfObjects;object2++) {
            if(object1 == object2) {
                continue;
            }

            // get the current position of the objects
            float object1_pos_x = this->objects[object1]->getCurrentCoordinates().x;
            float object1_pos_y = this->objects[object1]->getCurrentCoordinates().y;

            float object2_pos_x = this->objects[object2]->getCurrentCoordinates().x;
            float object2_pos_y = this->objects[object2]->getCurrentCoordinates().y;

            // did they collide
            float dist = sqrt((object1_pos_x-object2_pos_x) * (object1_pos_x-object2_pos_x) + (object1_pos_y-object2_pos_y) * (object1_pos_y-object2_pos_y));
            if(dist > this->objects[object1]->getBoundingRadius() + this->objects[object2]->getBoundingRadius()) {
                continue;
            }

            // get the current velocities of the objects
            // float object1_vel_x = this->objects[object1]->getVelocity().x;
            // float object1_vel_y = this->objects[object1]->getVelocity().y;
            glm::vec2 vel_object_1 = this->objects[object1]->getVelocity();

            // float object2_vel_x = this->objects[object2]->getVelocity().x;
            // float object2_vel_y = this->objects[object2]->getVelocity().y;
            glm::vec2 vel_object_2 = this->objects[object2]->getVelocity();

            glm::vec2 normal = glm::normalize(this->objects[object1]->getCurrentCoordinates() - this->objects[object2]->getCurrentCoordinates());

            float vel_object_1_n = glm::dot(vel_object_1, normal);
            float vel_object_2_n = glm::dot(vel_object_2, normal);

            float m1 = this->objects[object1]->getMass();
            float m2 = this->objects[object2]->getMass();

            // update the velocities
            // conservation of momentum + energy
            float vel_object_1_n_new = (vel_object_1_n * (m1 - m2) + 2 * m2 * vel_object_2_n) / (m1 + m2);
            float vel_object_2_n_new = (vel_object_2_n * (m2 - m1) + 2 * m1 * vel_object_1_n) / (m1 + m2);

            // float overlap = this->objects[object1]->getBoundingRadius() + this->objects[object2]->getBoundingRadius() - dist;

            vel_object_1 += (vel_object_1_n_new - vel_object_1_n) * normal;
            vel_object_2 += (vel_object_2_n_new - vel_object_2_n) * normal;

            this->objects[object1]->updateVelocity(vel_object_1);
            this->objects[object2]->updateVelocity(vel_object_2);
        }
    }
}

bool Collision::collisionDetectorStatus() {
    return this->isCollisionDetectionActive;
}

void Collision::addNonGhostObjects(Object* object, std::string type) {
    this->numberOfObjects++;
    this->objects.push_back(object);
    this->type = type;
}