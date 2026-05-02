#include "Libs/Circle.h"

Circle::Circle(float x, float y, float radii, float theta)
{
    this->centre_x = x;
    this->centre_y = y;
    this->radii = radii;
    this->angle = theta;

    this->currPosition.x = x;
    this->currPosition.y = y;

    this->velocity.x = 0.0f;
    this->velocity.y = 0.0f;

    this->mass = 5.0f;

    // Fill the vertices and indices
    int trianglesNeeded = ceil((2 * M_PI) / this->angle);

    std::cout << trianglesNeeded << " traingles were drawn" << std::endl;
    std::vector<float> vertices = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    for (int i = 0; i <= trianglesNeeded; i++)
    {
        vertices.push_back(this->radii * glm::sin(i * this->angle));
        vertices.push_back(this->radii * glm::cos(i * this->angle));
        vertices.push_back(0.01f);

        vertices.push_back(glm::sin(i * this->angle));
        vertices.push_back(glm::cos(i * this->angle));
        vertices.push_back(0.01f);
    }

    std::vector<unsigned int> indices;
    int first = 1, second = 2;
    while (first <= trianglesNeeded)
    {
        indices.push_back(0);
        indices.push_back(first++);
        indices.push_back(second++);
    }

    this->triangles = new Triangle(vertices, indices);
    this->triangles->setVertexShaderPath("../Shaders/vertexShader1.vert");
    this->triangles->setFragmentShaderPath("../Shaders/fragmentShader1.frag");

    this->triangles->createShaderProgram();
    this->objectID = this->triangles->getObjectID();

    std::cout << "[INFO] circle object created with object ID: " << this->objectID << std::endl;

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(x, y, 0.0f));
    unsigned int transformLoc = glGetUniformLocation(this->objectID, "translate");
    glUseProgram(this->objectID);
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Circle::drawCircle()
{
    std::cout << "[DEBUG] Drawing circle at: " << currPosition.x << ", " << currPosition.y << std::endl;
    glBindVertexArray(triangles->getVAO());
    triangles->useShaderProgram();
    triangles->drawTriangles();
}

void Circle::setMass(float mass)
{
    this->mass = mass;
}

unsigned int Circle::getObjectID()
{
    return this->objectID;
}

glm::vec2 Circle::getCurrentCoordinates()
{
    return this->currPosition;
}

float Circle::getMass()
{
    return this->mass;
}

glm::vec2 Circle::getVelocity()
{
    return this->velocity;
}

void Circle::updateVelocity(glm::vec2 velocity)
{
    this->velocity = velocity;
}

glm::vec2 Circle::getPosition()
{
    return this->currPosition;
}

void Circle::updatePosition(glm::vec2 position)
{
    this->currPosition = position;
}