#ifndef WINDOW_H
#define WINDOW_H

#include <utility>
#include <glad.h>
#include <glfw3.h>
#include <iostream>

using namespace std;

class window
{
private:
    int resX;
    int resY;
    GLFWwindow* runningWindow;

public:
    window(int _resX, int _resY) {
        resX = _resX;
        resY = _resY;
    }

    void createWindow();
    GLFWwindow* getWindow();
    void closeWindow();

};

#endif  