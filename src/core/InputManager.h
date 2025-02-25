#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <GLFW/glfw3.h>

class InputManager {
public:
    static bool isKeyPressed(int key);
    static bool isMouseButtonPressed(int button);

private:
    void processInput(GLFWwindow* window);
};

#endif
