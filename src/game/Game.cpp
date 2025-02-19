#include "Game.h"
#include "../core/Logger.h"
#define GLFW_KEY_ESCAPE 256

Game::Game() : running(true) {
    if (!glfwInit()) {
        Logger::error("No se pudo inicializar GLFW.");
        running = false;
        return;
    }

    window = glfwCreateWindow(800, 600, "Umbrella RTS", NULL, NULL);
    if (!window) {
        Logger::error("No se pudo crear la ventana.");
        glfwTerminate();
        running = false;
        return;
    }
    Logger::info("Ventana creada correctamente.");
}

Game::~Game() {
    glfwDestroyWindow(window);
    glfwTerminate();
    Logger::info("Juego terminado.");
}

void Game::processInput() {
    if (glfwWindowShouldClose(window)) {
        running = false;
    }

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        running = false;
    }
}

void Game::run() {
    while (running) {
        processInput();
        update();
        render();
    }
}

void Game::update() {
    // General game logic
}

void Game::render() {
    // Basic rendering
}
