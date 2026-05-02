cmake_minimum_required(VERSION 3.10)
project(OpenGLTest)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

# 1. Create the target first
add_executable(
    app main.cpp
    Window.cpp
    Libs/Window.h
    Reader.cpp
    Libs/Reader.h
    Triangle.cpp
    Libs/Triangle.h
    Shader.cpp
    Libs/Shader.h
    Circle.cpp 
    Libs/Circle.h
    Gravity.cpp
    Libs/Gravity.h
    Clock.cpp 
    Libs/Clock.h
)

# 2. Now tell CMake where to find the headers for 'app'
target_include_directories(app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Libs")

# 3. Link the libraries
target_link_libraries(app PRIVATE
    OpenGL::GL
    glfw
    GLEW::GLEW
    glm::glm
)
