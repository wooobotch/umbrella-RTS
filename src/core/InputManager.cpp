#include "InputManager.h"
#include "UnitManager.h"
#include "Utils.h"
#include <iostream>

GLFWwindow* InputManager::window = nullptr;

void InputManager::initialize(GLFWwindow* win) {
    window = win;
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
}

// Callback de eventos del mouse
void InputManager::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        // Convertir coordenadas de pantalla a mundo
        glm::vec2 worldPos = Utils::screenToWorld(window, xpos, ypos);

        // Intentar seleccionar una unidad
        UnitManager::selectUnitAt(worldPos);
    }
}
