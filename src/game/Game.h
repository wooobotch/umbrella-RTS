#ifndef GAME_H
#define GAME_H

#include <GLFW/glfw3.h>

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    GLFWwindow* window;
    bool running;
    void processInput();
    void update();
    void render();
};

#endif // GAME_H
