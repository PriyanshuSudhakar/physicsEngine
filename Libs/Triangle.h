#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "Shader.h"

class Triangle {
private:
    float* vertices;
    unsigned int* indices;
    int triangleCount;

    std::string vertexShaderPath, fragmentShaderPath;

    unsigned int VAO, VBO, EBO;
    Shader* shaderProgram;
public:
    Triangle(std::vector<float>& vertices, std::vector<unsigned int>& indices);
    void setVertexShaderPath(std::string vertexShaderPath);
    void setFragmentShaderPath(std::string fragmentShaderPath);
    void createShaderProgram();
    void useShaderProgram();
    unsigned int getVAO();
    unsigned int getVBO();
    unsigned int getEBO();
};