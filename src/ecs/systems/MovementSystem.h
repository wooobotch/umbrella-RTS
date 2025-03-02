#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include "../components/PositionComponent.h"
#include "../components/MovementComponent.h"
#include "../Entity.h"
#include <vector>

class MovementSystem {
public:
    static void update(std::vector<Entity>& entities, float deltaTime) {
        for (auto& entity : entities) {
            auto pos = entity.getComponent<PositionComponent>();
            auto move = entity.getComponent<MovementComponent>();

            if (pos && move && !move->path.empty()) {
                glm::vec2 nextStep = move->path.front();
                glm::vec2 direction = glm::normalize(nextStep - pos->position);
                float stepSize = move->speed * deltaTime;

                if (glm::length(nextStep - pos->position) <= stepSize) {
                    pos->position = nextStep;
                    move->path.pop();
                } else {
                    pos->position += direction * stepSize;
                }
            }
        }
    }
};

#endif
