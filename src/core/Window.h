#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class Window {
private:
    int width, height;
    GLFWwindow* window;
public:
    Window(int w, int h, const char* name);
    int getHeight();
    int getWidth();
    GLFWwindow* getWindow();
};