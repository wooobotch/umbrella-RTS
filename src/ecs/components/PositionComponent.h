#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include <glm/glm.hpp>

struct PositionComponent {
    glm::vec2 position;
    PositionComponent(float x, float y) : position(x, y) {}
};

#endif
