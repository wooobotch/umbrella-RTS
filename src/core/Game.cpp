#include "Game.h"
#include <GLFW/glfw3.h>
#include <SDL2/SDL.h>
#include "../ecs/Entity.h"
#include "../ecs/components/PositionComponent.h"
#include "../ecs/components/SelectableComponent.h"
#include "../ecs/components/MovementComponent.h"
#include "../ecs/systems/SelectionSystem.h"
#include "../ecs/systems/RenderSystem.h"
#include "../ecs/systems/MovementSystem.h"
#include "../pathfinding/AStar.h"
#include "Utils.h"
#include "../scenes/SplashScene.h"
#include <vector>
#include <iostream>

Game::Game() : window(nullptr), running(true) {
    sceneManager.pushScene(std::make_shared<SplashScene>());
}

Game::~Game() {
    if (window) {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
}

void Game::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        glm::vec2 worldPos = Utils::screenToWorld(window, xpos, ypos);

        for (auto& entity : entities) {
            auto selectable = entity.getComponent<SelectableComponent>();
            auto move = entity.getComponent<MovementComponent>();
            auto pos = entity.getComponent<PositionComponent>();

            if (selectable && selectable->selected && move && pos) {
                move->path = pathfinder->findPath(pos->position, worldPos, UnitType::INFANTRY);
            }
        }
    }
}

void Game::initEntities() {
    Entity e1;
    e1.addComponent(PositionComponent(-0.5f, 0.5f));
    e1.addComponent(SelectableComponent());
    e1.addComponent(MovementComponent(1.5f)); // Velocidad 1.5 unidades/s
    entities.push_back(e1);
}

void Game::startNewGame() {
    tileMap = std::make_unique<TileMap>();
    pathfinder = std::make_unique<AStar>(tileMap.get());  // Pasamos el puntero sin perder propiedad
    initEntities();
}

void Game::run() {
    if (!glfwInit()) return;

    window = glfwCreateWindow(800, 600, "Umbrella RTS", nullptr, nullptr);
    if (!window) return;

    glfwMakeContextCurrent(window);

    glfwSetMouseButtonCallback(window, [](GLFWwindow* w, int b, int a, int m) {
        Game* game = static_cast<Game*>(glfwGetWindowUserPointer(w));
        if (game) game->mouseButtonCallback(w, b, a, m);
    });

    glfwSetWindowUserPointer(window, this);

    sceneManager.pushScene(std::make_shared<SplashScene>());

    running = true;
    float lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        processInput();
        update(deltaTime);
        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    running = false;
}

void Game::processInput() {
    sceneManager.handleInput();
}

void Game::update(float deltaTime) {
    sceneManager.update(deltaTime);
}

void Game::render() {
    glClear(GL_COLOR_BUFFER_BIT);
    sceneManager.render();
}
