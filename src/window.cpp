#include <window.h>

/*
    SETS UP THE BASIC WINDOW FOR RENDERING
    RETURNS THE WINDOW POINTER TO THE MAIN FUNCTION
    RETUNRS NULL IF ERR
*/
void window::createWindow() {
    GLFWwindow* win = glfwCreateWindow(resX, resY, "Placeholder Text", glfwGetPrimaryMonitor(), NULL);
    if (win == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        runningWindow = nullptr;
    }
    glfwMakeContextCurrent(win);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        runningWindow = nullptr;
    }

    glViewport(0, 0, resX, resY);

    

    runningWindow = win;
}

GLFWwindow* window::getWindow() {
    return runningWindow;
}

void window::closeWindow() {
    glfwSetWindowShouldClose(runningWindow, true);
}