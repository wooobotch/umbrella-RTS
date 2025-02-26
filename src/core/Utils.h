#ifndef UTILS_H
#define UTILS_H

#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Utils {
public:
    static glm::vec2 screenToWorld(GLFWwindow* window, double xpos, double ypos);
};

#endif
