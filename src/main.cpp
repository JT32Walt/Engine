#include <glad.h>
#include <glfw3.h>

#include <iostream>

#include <window.h>
#include <game.h>
#include <resourceManger.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window windowController(2560, 1440);
    windowController.createWindow();
    GLFWwindow* gameWindow = windowController.getWindow();
    glfwSetKeyCallback(gameWindow, key_callback);
    glfwSetFramebufferSizeCallback(gameWindow, framebuffer_size_callback);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Game Test;

    Test.Init();
    
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(gameWindow))
    {
        float currenctFrame = glfwGetTime();
        deltaTime = currenctFrame - lastFrame;
        lastFrame = currenctFrame;
        glfwPollEvents();

        //Input Handling
        Test.ProcessInput(deltaTime);
        //Update Game state
        Test.Upadate(deltaTime);
        //Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        Test.Render();

        glfwSwapBuffers(gameWindow);
    }
    ResourceManager::Clear();
    glfwTerminate();
    return 0;
}


