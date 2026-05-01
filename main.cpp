#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>

#include "Libs/Window.h"
#include "Libs/Triangle.h"
#include "Libs/Circle.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char *WINDOW_NAME = "myWindow";

std::vector<float> vertices = {
    0.0f, 0.0f, 0.0f, 0.5f, 0.3f, 0.0f,
    0.0f, 0.5f, 0.0f, 1.0f, 0.25f, 0.0f,
    0.5f, 0.0f, 0.0f, 0.25f, 0.0f, 0.0f};

std::vector<unsigned int> indices = {
    0, 1, 2};

int main()
{
   Window myWindow = Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

   glewInit();

   glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

   Triangle *triangle1 = new Triangle(vertices, indices);
   triangle1->setVertexShaderPath("../Shaders/vertexShader1.vert");
   triangle1->setFragmentShaderPath("../Shaders/fragmentShader1.frag");
   triangle1->createShaderProgram();

   Circle* circle1 = new Circle(0.0f, 0.0f, 0.2f);
   Circle* circle2 = new Circle(0.5f, 0.5f, 0.2f);
   Circle* circle3 = new Circle(-0.5f, -0.5f, 0.2f);

   while (!glfwWindowShouldClose(myWindow.getWindow()))
   {
      // 1. Process Events
      glfwPollEvents();

      // 2. Clear (The background color)
      glClearColor(0.3f, 0.5f, 0.6f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      // 3. Draw
      // triangle1->useShaderProgram();
      // glBindVertexArray(triangle1->getVAO());
      // triangle1->drawTriangles();

      circle1->drawCircle();
      circle2->drawCircle();
      circle3->drawCircle();

      // 4. Swap Buffers (Show what we just drew)
      glfwSwapBuffers(myWindow.getWindow());
   }

   glfwTerminate();
   return 0;
}