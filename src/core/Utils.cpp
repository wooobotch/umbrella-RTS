#include "Utils.h"

glm::vec2 Utils::screenToWorld(GLFWwindow* window, double xpos, double ypos) {
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    float x = (xpos / width) * 2.0f - 1.0f;
    float y = 1.0f - (ypos / height) * 2.0f;

    return glm::vec2(x, y);
}
