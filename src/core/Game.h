#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <memory>
#include "../rendering/TileMap.h"
#include "../pathfinding/AStar.h"
#include "SceneManager.h"

class Game {
public:
    Game();
    ~Game();

    void run();
    void startNewGame(); // Llamar desde menú

private:
    GLFWwindow* window;
    bool running;
    std::unique_ptr<TileMap> tileMap;
    std::unique_ptr<AStar> pathfinder;
    SceneManager sceneManager;

    void processInput();
    void update(float deltaTime);
    void render();
};

#endif
