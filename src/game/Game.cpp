#include "Game.h"
#include "../core/Logger.h"
#include "../core/Timer.h"
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

void Game::render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void Game::run() {
    const float targetFrameTime = 1.0f / 60.0f;
    Timer::start();

    while (running) {
        float deltaTime = Timer::getDeltaTime();

        processInput();
        update();

        render();
        while(Timer::getDeltaTime() < targetFrameTime){
            ;
        }
    }
}

void Game::update() {
    ;// General game logic
}

