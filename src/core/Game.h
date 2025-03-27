#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include <memory>
#include "../rendering/TileMap.h"
#include "../ecs/Entity.h"
#include "../pathfinding/AStar.h"
#include "SceneManager.h"
#include "InputManager.h"

class Game {
public:
    Game();
    ~Game();

    void run();
    void initEntities();
    void startNewGame(); // Llamar desde menú

private:
    GLFWwindow* window;
    int mapWidth = 800;
    int mapHeight = 800;
    bool running;
    std::vector<Entity> entities;
    std::unique_ptr<TileMap> tileMap;
    std::unique_ptr<AStar> pathfinder;
    SceneManager sceneManager;

    void processInput();
    void update(float deltaTime);
    void render();
};

#endif
