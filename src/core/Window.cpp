#include "Window.h"

Window::Window(int w, int h, const char* name) {
    this->width = w;
    this->height = h;

    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW\n";
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 16); // 4x Anti-aliasing


    // creating a window
    this->window = glfwCreateWindow(w, h, name, nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return;
    }

    // making the context current and initializing GLEW
    glfwMakeContextCurrent(window);
}

int Window::getHeight() {
    return this->height;
}

int Window::getWidth() {
    return this->width;
}

GLFWwindow* Window::getWindow() {
    return this->window;
}