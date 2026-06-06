#include "Circle.h"

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

    this->mass = 1.0f;

    // Fill the vertices and indices
    int trianglesNeeded = ceil((2 * M_PI) / this->angle);

    // std::cout << trianglesNeeded << " traingles were drawn" << std::endl;
    std::vector<float> vertices = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    for (int i = 0; i <= trianglesNeeded; i++)
    {
        vertices.push_back(this->radii * glm::sin(i * this->angle));
        vertices.push_back(this->radii * glm::cos(i * this->angle));
        vertices.push_back(0.01f);

        vertices.push_back(glm::sin(i));
        vertices.push_back(glm::cos(i));
        vertices.push_back(glm::tan(i));
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
    std::string shaderPath = SHADER_PATH;
    this->triangles->setVertexShaderPath(shaderPath + "vertexShader1.vert");
    this->triangles->setFragmentShaderPath(shaderPath + "fragmentShader1.frag");

    this->triangles->createShaderProgram();
    this->objectID = this->triangles->getObjectID();

    // std::cout << "[INFO] circle object created with object ID: " << this->objectID << std::endl;

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(x, y, 0.0f));
    unsigned int transformLoc = glGetUniformLocation(this->objectID, "translate");
    glUseProgram(this->objectID);
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
}

void Circle::drawCircle()
{
    // std::cout << "[DEBUG] Drawing circle at: " << currPosition.x << ", " << currPosition.y << std::endl;
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
    // remove later start
    this->currPosition = position;
    updateInWorldPosition(position);
    // remove later end
}

// void Circle::updatePositionAuto()
// {
//     float timeSpeed = 0.001f;
//     this->currPosition.x += this->velocity.x * timeSpeed;
//     this->currPosition.y += this->velocity.y * timeSpeed;
//     updateInWorldPosition(this->currPosition);
// }

void Circle::updatePositionAuto()
{
    float timeSpeed = 0.001f;

    // position uses current velocity AND current acceleration
    this->currPosition.x += this->velocity.x * timeSpeed + 0.5f * this->acceleration.x * timeSpeed * timeSpeed;
    this->currPosition.y += this->velocity.y * timeSpeed + 0.5f * this->acceleration.y * timeSpeed * timeSpeed;

    updateInWorldPosition(this->currPosition);
}

void Circle::draw()
{
    drawCircle(); // just delegate to your existing function for now
}

void Circle::updateInWorldPosition(glm::vec2 currentPosition)
{
    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(currPosition.x, currPosition.y, 0.0f));
    unsigned int transformLoc = glGetUniformLocation(this->objectID, "translate");
    // std::cout << "[DEBUG] transformLoc for object " << object << ": " << transformLoc << std::endl;
    glUseProgram(this->objectID);
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
    // std::cout << "[DEBUG] OpenGL updated" << std::endl;
}

// void Circle::updateVelocityAuto()
// {
//     float timeSpeed = 0.001f;
//     // Test
//     this->velocity.x += (this->force.x / this->mass) * timeSpeed;
//     this->velocity.y += (this->force.y / this->mass) * timeSpeed;
// }

void Circle::updateVelocityAuto()
{
    float timeSpeed = 0.001f;

    glm::vec2 oldAccel = this->acceleration;
    this->acceleration = this->force / this->mass;

    // average old and new acceleration (Velocity Verlet)
    this->velocity.x += 0.5f * (oldAccel.x + this->acceleration.x) * timeSpeed;
    this->velocity.y += 0.5f * (oldAccel.y + this->acceleration.y) * timeSpeed;
}

void Circle::tick()
{
    updateForce();
    updatePositionAuto();
    updateVelocityAuto();
}
