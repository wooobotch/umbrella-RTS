#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include <glm/glm.hpp>
#include <queue>

struct MovementComponent {
    glm::vec2 targetPosition;
    std::queue<glm::vec2> path; // Cola de puntos a seguir
    float speed;

    MovementComponent(float speed = 1.0f) : speed(speed), targetPosition(0.0f, 0.0f) {}
};

#endif
