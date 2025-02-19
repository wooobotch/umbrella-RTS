#include "Game.h"
#include "../core/Logger.h"

Game::Game() : running(true) {
    Logger::info("Juego iniciado.");
}

Game::~Game() {
    Logger::info("Juego terminado.");
}

void Game::run() {
    while (running) {
        processInput();
        update();
        render();
    }
}

void Game::processInput() {
    // Input events
}

void Game::update() {
    // General game logic
}

void Game::render() {
    // Basic rendering
}
