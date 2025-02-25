#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include "Component.h"
#include "InputManager.h"

class MovementComponent : public Component {
public:
    glm::vec2 velocity;

    void update() override {
        if (InputManager::isKeyPressed(GLFW_KEY_W)) velocity.y = 1.0f;
        if (InputManager::isKeyPressed(GLFW_KEY_S)) velocity.y = -1.0f;
        if (InputManager::isKeyPressed(GLFW_KEY_A)) velocity.x = -1.0f;
        if (InputManager::isKeyPressed(GLFW_KEY_D)) velocity.x = 1.0f;
    }
};

#endif
