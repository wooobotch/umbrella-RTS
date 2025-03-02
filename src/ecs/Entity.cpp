#include "Entity.h"
#include "components/Component.h"

void Entity::addComponent(std::shared_ptr<Component> component) {
    components.push_back(component);
}

void Entity::update() {
    for (auto& component : components) {
        component->update();
    }
}

void Entity::render() {
    for (auto& component : components) {
        component->render();
    }
}
