#pragma once

#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "../../core/Shader.h"

class Triangle {
private:
    float mass;

    float* vertices;
    unsigned int* indices;
    int triangleCount;

    std::string vertexShaderPath, fragmentShaderPath;

    unsigned int VAO, VBO, EBO;
    Shader* shaderProgram;

    unsigned int objectID;
public:
    Triangle(std::vector<float>& vertices, std::vector<unsigned int>& indices);
    void setVertexShaderPath(std::string vertexShaderPath);
    void setFragmentShaderPath(std::string fragmentShaderPath);
    void createShaderProgram();
    void useShaderProgram();
    unsigned int getVAO();
    unsigned int getVBO();
    unsigned int getEBO();
    void drawTriangles();
    void setMass(float mass);
    unsigned int getObjectID();
};