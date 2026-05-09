cmake_minimum_required(VERSION 3.10)
project(OpenGLTest)

find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)

# 1. Create the target first
add_executable(
    app main.cpp
    src/core/Window.cpp
    src/core/Window.h
    src/helper/Reader.cpp
    src/helper/Reader.h
    src/mesh/2d/Triangle.cpp
    src/mesh/2d/Triangle.h
    src/core/Shader.cpp
    src/core/Shader.h
    src/mesh/2d/Circle.cpp
    src/mesh/2d/Circle.h
    src/physics/Gravity.cpp
    src/physics/Gravity.h
    src/physics/Clock.cpp
    src/physics/Clock.h
    src/core/Object.h
    src/physics/Collision.cpp
    src/physics/Collision.h
)

# 2. Now tell CMake where to find the headers for 'app'
target_include_directories(app PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/helper"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/mesh/2d"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/mesh/3d"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/physics"
)

target_compile_definitions(app PRIVATE 
    SHADER_PATH="${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/"
)

# 3. Link the libraries
target_link_libraries(app PRIVATE
    OpenGL::GL
    glfw
    GLEW::GLEW
    glm::glm
)
