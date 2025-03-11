#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>
#include "../rendering/TileMap.h"
#include "../pathfinding/AStar.h"

class Game {
public:
    Game();
    ~Game();

    void run();
    void startNewGame(); // Llamar desde menú

private:
    GLFWwindow* window;
    bool running;
    TileMap* tileMap = nullptr; // a inicializar al "comenzar partida"
    AStar* pathfinder = nullptr; // idem arriba

    void processInput();
    void update();
    void render();
};

#endif // GAME_H

