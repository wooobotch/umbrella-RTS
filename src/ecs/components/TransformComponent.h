#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "Component.h"
#include <glm/glm.hpp>

class TransformComponent : public Component {
public:
    glm::vec2 position;
    glm::vec2 scale;

    TransformComponent(float x, float y) : position(x, y), scale(1.0f, 1.0f) {}
};

#endif
