#include "Libs/Shader.h"


// namespace fs = std::filesystem;
Shader::Shader() {
    return;
}
Shader::Shader(std::string vertexShaderPath, std::string fragmentShaderPath) {
    // if(!fs::exists(vertexShaderPath)) {
    //     std::cout<<"[Error]: Vertex shader is missing!!"<<std::endl;
    // } else std::cout<<"Vertex Shader File Found"<<std::endl;

    // if(!fs::exists(fragmentShaderPath)) {
    //     std::cout<<"[Error]: Fragment shader is missing!!"<<std::endl;
    // } else std::cout<<"Fragment Shader file found"<<std::endl;

    Reader reader = Reader();
    const char* vertexShaderCode = reader.readFile(vertexShaderPath).c_str();
    const char* fragmentShaderCode = reader.readFile(fragmentShaderPath).c_str();

    
    this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vertexShader, 1, &vertexShaderCode, NULL);
    glCompileShader(this->vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(this->vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fragmentShader, 1, &fragmentShaderCode, NULL);
    glCompileShader(this->fragmentShader);

    glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(this->fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, this->vertexShader);
    glAttachShader(this->shaderProgram, this->fragmentShader);
    glLinkProgram(this->shaderProgram);
    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(this->shaderProgram, 512, NULL, infoLog);
        std::cout<<"[Error]: Shader Linking failed"<<std::endl;
    }
}

void Shader::useShaderProgram() {
    glUseProgram(this->shaderProgram);
    glDeleteShader(this->vertexShader);
    glDeleteShader(this->fragmentShader);
}