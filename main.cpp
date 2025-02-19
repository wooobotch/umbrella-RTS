#include <iostream>
#include "src/core/Logger.h"
#include "src/game/Game.h"

int main() {
    Logger::info("Starting...");
    std::cout << "Umbrella RTS" << std::endl;

    Game game;
    game.run();

    return 0;
}
