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

GLFWwindow* window;
std::vector<Entity> entities;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        glm::vec2 worldPos = Utils::screenToWorld(window, xpos, ypos);

        for (auto& entity : entities) {
            auto selectable = entity.getComponent<SelectableComponent>();
            auto move = entity.getComponent<MovementComponent>();
            auto pos = entity.getComponent<PositionComponent>();

            if (selectable && selectable->selected && move && pos) {
                move->path = AStar::findPath(pos->position, worldPos);
            }
        }
    }
}

void initEntities() {
    Entity e1;
    e1.addComponent(PositionComponent(-0.5f, 0.5f));
    e1.addComponent(SelectableComponent());
    e1.addComponent(MovementComponent(1.5f)); // Velocidad 1.5 unidades/s
    entities.push_back(e1);
}

int main() {
    if (!glfwInit()) return -1;
    window = glfwCreateWindow(800, 600, "Mata Burros", nullptr, nullptr);
    if (!window) return -1;
    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    initEntities();
    float lastTime = glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        MovementSystem::update(entities, deltaTime);
        RenderSystem::render(entities);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
