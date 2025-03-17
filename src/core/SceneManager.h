#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>
#include <stack>
#include "Scene.h"

class SceneManager {
private:
    std::stack<std::unique_ptr<Scene>> scenes;
public:
    void changeScene(std::unique_ptr<Scene> newScene) {
        if (!scenes.empty()) {
            scenes.top()->cleanup();
            scenes.pop();
        }
        scenes.push(std::move(newScene));
        scenes.top()->init();
    }

    void pushScene(std::unique_ptr<Scene> newScene) {
        if (!scenes.empty()) {
            scenes.top()->cleanup();
        }
        scenes.push(std::move(newScene));
        scenes.top()->init();
    }

    void popScene() {
        if (!scenes.empty()) {
            scenes.top()->cleanup();
            scenes.pop();
        }
        if (!scenes.empty()) {
            scenes.top()->init();
        }
    }

    void handleInput() {
        if (!scenes.empty()) {
            scenes.top()->handleInput();
        }
    }

    void update() {
        if (!scenes.empty()) {
            scenes.top()->update();
        }
    }

    void render() {
        if (!scenes.empty()) {
            scenes.top()->render();
        }
    }
};

#endif
