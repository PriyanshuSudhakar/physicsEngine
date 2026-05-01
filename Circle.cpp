#include "Libs/Circle.h"

Circle::Circle(float x, float y, float radii) {
    this->centre_x = x;
    this->centre_y = y;
    this->radii = radii;

    // Fill the vertices and indices
    int trianglesNeeded = ceil((2*M_PI) / this->angle);

    std::vector<float> vertices = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    for(int i=0;i<=trianglesNeeded;i++) {
        vertices.push_back(this->radii*glm::sin(i * this->angle));
        vertices.push_back(this->radii*glm::cos(i * this->angle));
        vertices.push_back(0.0f);

        vertices.push_back(glm::sin(i * this->angle));
        vertices.push_back(glm::cos(i * this->angle));
        vertices.push_back(0.0f);
    }

    std::vector<unsigned int> indices;
    int first = 1, second = 2;
    while(first <= trianglesNeeded) {
        indices.push_back(0);
        indices.push_back(first++);
        indices.push_back(second++);
    }

    this->triangles = new Triangle(vertices, indices);
    triangles->setVertexShaderPath("../Shaders/vertexShader1.vert");
    triangles->setFragmentShaderPath("../Shaders/fragmentShader1.frag");

    triangles->createShaderProgram();
}

void Circle::drawCircle() {
    glBindVertexArray(triangles->getVAO());
    triangles->useShaderProgram();
    triangles->drawTriangles();
}