#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <vector>

#include "Libs/Window.h"
#include "Libs/Triangle.h"
#include "Libs/Circle.h"
#include "Libs/Gravity.h"
#include "Libs/Collision.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const char *WINDOW_NAME = "myWindow";

std::vector<float> vertices = {
    0.0f, 0.0f, 0.0f, 0.5f, 0.3f, 0.0f,
    0.0f, 0.5f, 0.0f, 1.0f, 0.25f, 0.0f,
    0.5f, 0.0f, 0.0f, 0.25f, 0.0f, 0.0f};

std::vector<unsigned int> indices = {
    0, 1, 2};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    Window myWindow = Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    glewInit();

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_MULTISAMPLE);

    Triangle *triangle1 = new Triangle(vertices, indices);
    triangle1->setVertexShaderPath("../Shaders/vertexShader1.vert");
    triangle1->setFragmentShaderPath("../Shaders/fragmentShader1.frag");
    triangle1->createShaderProgram();

    // Original 8 Circles
    Circle *circle1 = new Circle(0.25f, 0.0f, 0.01f, 0.1f);
    Circle *circle2 = new Circle(0.5f, 0.5f, 0.01f, 0.1f);
    Circle *circle3 = new Circle(0.5f, 0.0f, 0.01f, 0.1f);
    Circle *circle4 = new Circle(0.0f, 0.5f, 0.01f, 0.1f);
    Circle *circle5 = new Circle(0.0f, 0.0f, 0.01f, 0.1f);
    Circle *circle6 = new Circle(0.5f, 0.9f, 0.01f, 0.1f);
    Circle *circle7 = new Circle(0.5f, 0.3f, 0.01f, 0.1f);
    Circle *circle8 = new Circle(0.9f, 0.5f, 0.01f, 0.1f);

    // 10 Additional Circles
    Circle *circle9 = new Circle(-0.5f, 0.8f, 0.03f, 0.1f);
    Circle *circle10 = new Circle(-0.2f, 0.6f, 0.03f, 0.1f);
    Circle *circle11 = new Circle(-0.8f, 0.4f, 0.03f, 0.1f);
    Circle *circle12 = new Circle(-0.4f, 0.2f, 0.03f, 0.1f);
    Circle *circle13 = new Circle(-0.7f, -0.2f, 0.03f, 0.1f);
    Circle *circle14 = new Circle(-0.1f, -0.5f, 0.03f, 0.1f);
    Circle *circle15 = new Circle(0.3f, -0.8f, 0.03f, 0.1f);
    Circle *circle16 = new Circle(0.7f, -0.3f, 0.03f, 0.1f);
    Circle *circle17 = new Circle(-0.9f, 0.9f, 0.03f, 0.1f);
    Circle *circle18 = new Circle(0.1f, 0.8f, 0.03f, 0.1f);

    Gravity gravity;
    gravity.addObject(circle1); gravity.addObject(circle2); gravity.addObject(circle3);
    gravity.addObject(circle4); gravity.addObject(circle5); gravity.addObject(circle6);
    gravity.addObject(circle7); gravity.addObject(circle8); gravity.addObject(circle9);
    gravity.addObject(circle10); gravity.addObject(circle11); gravity.addObject(circle12);
    gravity.addObject(circle13); gravity.addObject(circle14); gravity.addObject(circle15);
    gravity.addObject(circle16); gravity.addObject(circle17); gravity.addObject(circle18);

    Collision collision;
    collision.setWallHeight(1);
    collision.setWallWidth(1);

    collision.addNonGhostObjects(circle1, "circle");
    collision.addNonGhostObjects(circle2, "circle");
    collision.addNonGhostObjects(circle3, "circle");
    collision.addNonGhostObjects(circle4, "circle");
    collision.addNonGhostObjects(circle5, "circle");
    collision.addNonGhostObjects(circle6, "circle");
    collision.addNonGhostObjects(circle7, "circle");
    collision.addNonGhostObjects(circle8, "circle");
    collision.addNonGhostObjects(circle9, "circle");
    collision.addNonGhostObjects(circle10, "circle");
    collision.addNonGhostObjects(circle11, "circle");
    collision.addNonGhostObjects(circle12, "circle");
    collision.addNonGhostObjects(circle13, "circle");
    collision.addNonGhostObjects(circle14, "circle");
    collision.addNonGhostObjects(circle15, "circle");
    collision.addNonGhostObjects(circle16, "circle");
    collision.addNonGhostObjects(circle17, "circle");
    collision.addNonGhostObjects(circle18, "circle");

    while (!glfwWindowShouldClose(myWindow.getWindow()))
    {
        glfwPollEvents();

        glClearColor(0.3f, 0.5f, 0.6f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Drawing all circles
        circle1->drawCircle(); circle2->drawCircle(); circle3->drawCircle();
        circle4->drawCircle(); circle5->drawCircle(); circle6->drawCircle();
        circle7->drawCircle(); circle8->drawCircle(); circle9->drawCircle();
        circle10->drawCircle(); circle11->drawCircle(); circle12->drawCircle();
        circle13->drawCircle(); circle14->drawCircle(); circle15->drawCircle();
        circle16->drawCircle(); circle17->drawCircle(); circle18->drawCircle();

        gravity.gravity();
        gravity.groundGravity();

        collision.collisionDetector();
        collision.wallCollisionDetector();

        glfwSwapBuffers(myWindow.getWindow());
    }

    // Optional: Clean up memory (Standard practice)
    delete triangle1; delete circle1; delete circle2; delete circle3;
    delete circle4; delete circle5; delete circle6; delete circle7;
    delete circle8; delete circle9; delete circle10; delete circle11;
    delete circle12; delete circle13; delete circle14; delete circle15;
    delete circle16; delete circle17; delete circle18;

    glfwTerminate();
    return 0;
}