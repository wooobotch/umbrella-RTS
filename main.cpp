#include <iostream>
#include "src/core/Logger.h"
#include "src/core/Game.h"

int main() {
    Logger::info("Starting...");
    std::cout << "Umbrella RTS" << std::endl;

    Game game;
    game.run();

    return 0;
}
