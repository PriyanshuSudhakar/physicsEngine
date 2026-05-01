#include <GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Reader.h"

class Shader {
private:
    unsigned int shaderProgram, vertexShader, fragmentShader;
public:
    Shader();
    Shader(std::string vertexShaderPath, std::string fragmentShaderPath);
    unsigned int getShaderProgram();
    void useShaderProgram();
};