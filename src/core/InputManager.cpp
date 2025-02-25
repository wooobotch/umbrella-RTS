#include "InputManager.h"
#include <iostream>

void InputManager::processInput(GLFWwindow* window) {
    // Cerrar la ventana si se presiona la tecla ESC
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }

    // Manejar otros inputs aquí
//    for (const auto& action : keyBindings) {
//        if (glfwGetKey(window, action.first) == GLFW_PRESS) {
//            action.second(); // Ejecutar la acción asociada a la tecla
//        }
//    }
}

//void InputManager::bindKey(int key, std::function<void()> action) {
//    keyBindings[key] = action;
//}

//void InputManager::unbindKey(int key) {
//    keyBindings.erase(key);
//}
