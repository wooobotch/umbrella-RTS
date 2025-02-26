#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class InputManager {
public:
    static void initialize(GLFWwindow* window);
    static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

private:
    static GLFWwindow* window;
};

#endif
