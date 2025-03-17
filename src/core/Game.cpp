#include "Game.h"
#include <GLFW/glfw3.h>
#include "../src/ecs/Entity.h"
#include "../src/ecs/components/PositionComponent.h"
#include "../src/ecs/components/SelectableComponent.h"
#include "../src/ecs/components/MovementComponent.h"
#include "../src/ecs/systems/SelectionSystem.h"
#include "../src/ecs/systems/RenderSystem.h"
#include "../src/ecs/systems/MovementSystem.h"
#include "../src/pathfinding/AStar.h"
#include "Utils.h"
#include <vector>

Game::Game() : window(nullptr), running(false), tileMap(nullptr), pathfinder(nullptr) {}

Game::~Game() {
    if (window) {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    delete tileMap;
    delete pathfinder;
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
    tileMap = new TileMap();  // Crear un nuevo mapa
    pathfinder = new AStar(tileMap);  // Inicializar pathfinding con el nuevo mapa
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

    startNewGame(); // Se inicia el juego generando un nuevo mapa
    running = true;

    float lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        processInput();
        update();
        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    running = false;
}
