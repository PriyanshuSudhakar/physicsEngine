#include "Libs/Triangle.h"

Triangle::Triangle(std::vector<float>& vertices, std::vector<unsigned int>& indices) {
    // 2. Allocate heap memory
    this->vertices = new float[vertices.size()];
    this->indices = new unsigned int[indices.size()];

    this->triangleCount = indices.size();

    std::copy(vertices.begin(), vertices.end(), this->vertices);
    std::copy(indices.begin(), indices.end(), this->indices);

    glGenVertexArrays(1, &this->VAO); 
    glBindVertexArray(this->VAO); 
    glGenBuffers(1, &this->VBO);

    // 2. copy our vertices array in a buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), this->vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &this->EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), this->indices, GL_STATIC_DRAW);

    // tells how to interpret the buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);   // location, size (that is vec3), type of data, do we want data normalised, stride (space between consecutive vertex attribute), offset
    glEnableVertexAttribArray(0);  // Enable the vertex Attribute 
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Triangle::createShaderProgram() {
    this->shaderProgram = new Shader(this->vertexShaderPath, this->fragmentShaderPath);
}

void Triangle::useShaderProgram() {
    this->shaderProgram->useShaderProgram();
}

void Triangle::setVertexShaderPath(std::string vertexShaderPath) {
    this->vertexShaderPath = vertexShaderPath;
}

void Triangle::setFragmentShaderPath(std::string fragmentShaderPath) {
    this->fragmentShaderPath = fragmentShaderPath;
}

unsigned int Triangle::getVAO() {
    return this->VAO;
}

unsigned int Triangle::getEBO() {
    return this->EBO;
}

unsigned int Triangle::getVBO() {
    return this->VBO;
} 

void Triangle::drawTriangles() {
    
    glDrawElements(GL_TRIANGLES, this->triangleCount * 3, GL_UNSIGNED_INT, 0);
}