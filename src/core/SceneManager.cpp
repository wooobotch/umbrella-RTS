#include "SceneManager.h"

void SceneManager::pushScene(std::shared_ptr<Scene> newScene) {
    if (!sceneStack.empty()) {
        sceneStack.back()->pause(); // Pausar la escena anterior si es necesario
    }
    sceneStack.push_back(newScene);
    newScene->init();
}

void SceneManager::popScene() {
    if (!sceneStack.empty()) {
        sceneStack.back()->cleanup();
        sceneStack.pop_back();
        if (!sceneStack.empty()) {
            sceneStack.back()->resume(); // Reanudar la escena anterior si aplica
        }
    }
}

std::shared_ptr<Scene> SceneManager::getCurrentScene() {
    return sceneStack.empty() ? nullptr : sceneStack.back();
}

void SceneManager::update(float deltaTime) {
    if (!sceneStack.empty()) {
        sceneStack.back()->update(deltaTime);
    }
}

void SceneManager::render() {
    for (const auto& scene : sceneStack) {
        scene->render();
    }
}

void SceneManager::handleInput() {
    if (!sceneStack.empty()) {
        sceneStack.back()->handleInput();
    }
}
