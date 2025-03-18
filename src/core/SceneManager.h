#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "Scene.h"
#include <vector>
#include <memory>

class SceneManager {
public:
    void pushScene(std::shared_ptr<Scene> newScene);  // Agregar nueva escena encima
    void popScene();  // Poppea la escena superior
    std::shared_ptr<Scene> getCurrentScene();
    void update(float deltaTime);
    void render();
    void handleInput();

private:
    std::vector<std::shared_ptr<Scene>> sceneStack;
};

#endif
