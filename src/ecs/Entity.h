#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <memory>

class Component;

class Entity {
public:
    void addComponent(std::shared_ptr<Component> component);
    void update();
    void render();

private:
    std::vector<std::shared_ptr<Component>> components;
};

#endif // ENTITY_H
