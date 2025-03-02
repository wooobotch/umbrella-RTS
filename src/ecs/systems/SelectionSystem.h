#ifndef SELECTION_SYSTEM_H
#define SELECTION_SYSTEM_H

#include "../components/PositionComponent.h"
#include "../components/SelectableComponent.h"
#include "../Entity.h"
#include <vector>
#include <glm/glm.hpp>

class SelectionSystem {
public:
    static void selectEntityAt(const glm::vec2& worldPos, std::vector<Entity>& entities) {
        for (auto& entity : entities) {
            auto pos = entity.getComponent<PositionComponent>();
            auto selectable = entity.getComponent<SelectableComponent>();

            if (pos && selectable) {
                float dist = glm::length(worldPos - pos->position);
                selectable->selected = (dist <= 0.5f);
            }
        }
    }
};

#endif
