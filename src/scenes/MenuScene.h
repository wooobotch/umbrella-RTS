#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "../core/Scene.h"
#include <iostream>

class MenuScene : public Scene {
public:
    void init() override {
        std::cout << "Menu Scene Initialized" << std::endl;
    }
    void handleInput() override {
        std::cout << "Handling Menu Input" << std::endl;
    }
    void update() override {
        std::cout << "Updating Menu Scene" << std::endl;
    }
    void render() override {
        std::cout << "Rendering Menu Scene" << std::endl;
    }
    void cleanup() override {
        std::cout << "Cleaning up Menu Scene" << std::endl;
    }
};

#endif
