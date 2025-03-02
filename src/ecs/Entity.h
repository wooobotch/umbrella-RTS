#ifndef ENTITY_H
#define ENTITY_H

#include <unordered_map>
#include <typeindex>
#include <memory>

class Entity {
private:
    std::unordered_map<std::type_index, std::shared_ptr<void>> components;

public:
    template <typename T>
    void addComponent(T component) {
        components[std::type_index(typeid(T))] = std::make_shared<T>(component);
    }

    template <typename T>
    T* getComponent() {
        auto it = components.find(std::type_index(typeid(T)));
        return (it != components.end()) ? static_cast<T*>(it->second.get()) : nullptr;
    }
};

#endif
