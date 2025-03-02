#include "AStar.h"
#include <cmath>

struct Node {
    glm::vec2 pos;
    float gCost, hCost;
    Node* parent;
    Node(glm::vec2 p, float g, float h, Node* par) : pos(p), gCost(g), hCost(h), parent(par) {}
    float fCost() const { return gCost + hCost; }
};

// Distancia Manhattan
float heuristic(glm::vec2 a, glm::vec2 b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

std::queue<glm::vec2> AStar::findPath(glm::vec2 start, glm::vec2 goal) {
    std::priority_queue<Node*, std::vector<Node*>,
        [](const Node* a, const Node* b) { return a->fCost() > b->fCost(); }> openSet;

    std::unordered_map<int, Node*> allNodes;
    Node* startNode = new Node(start, 0, heuristic(start, goal), nullptr);
    openSet.push(startNode);
    allNodes[start.x * 100 + start.y] = startNode;

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (current->pos == goal) {
            std::queue<glm::vec2> path;
            while (current) {
                path.push(current->pos);
                current = current->parent;
            }
            return path;
        }

        std::vector<glm::vec2> neighbors = {
            {current->pos.x + 1, current->pos.y},
            {current->pos.x - 1, current->pos.y},
            {current->pos.x, current->pos.y + 1},
            {current->pos.x, current->pos.y - 1}
        };

        for (const auto& neighbor : neighbors) {
            float gCost = current->gCost + 1;
            float hCost = heuristic(neighbor, goal);
            Node* neighborNode = new Node(neighbor, gCost, hCost, current);
            openSet.push(neighborNode);
            allNodes[neighbor.x * 100 + neighbor.y] = neighborNode;
        }
    }

    return {};
}
