#include "AStar.h"
#include "Node.h"
#include <cmath>
#include <unordered_map>
#include <set>
#include <vector>

// Distancia Manhattan
inline float heuristic(glm::ivec2 a, glm::ivec2 b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

// Para mapear coordenadas a una clave única en `unordered_map`
inline int hash(glm::ivec2 pos) {
    return pos.x * 10000 + pos.y;
}

AStar::AStar(TileMap* tileMap) : tileMap(tileMap) {}

bool AStar::isWalkable(glm::ivec2 pos, UnitType unitType) {
    if (!tileMap) return false;
    return tileMap->isWalkable(pos, unitType);
}

float AStar::getMovementCost(glm::ivec2 pos, UnitType unitType) {
    if (!tileMap) return -1.0f;  // Ojo, costo no válido si no hay tileMap
    return tileMap->getMovementCost(pos, unitType);
}

// Encuentra un camino con A* Bidireccional
std::queue<glm::vec2> AStar::findPath(glm::vec2 start, glm::vec2 goal, UnitType unitType) {
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> openSetStart, openSetGoal;
    std::unordered_map<int, Node*> allNodesStart, allNodesGoal;
    std::unordered_map<int, float> gScoreStart, gScoreGoal;

    glm::ivec2 startPos = glm::round(start), goalPos = glm::round(goal);
    Node* startNode = new Node(startPos, 0, heuristic(startPos, goalPos), nullptr);
    Node* goalNode = new Node(goalPos, 0, heuristic(goalPos, startPos), nullptr);

    openSetStart.push(startNode);
    openSetGoal.push(goalNode);
    allNodesStart[hash(startPos)] = startNode;
    allNodesGoal[hash(goalPos)] = goalNode;
    gScoreStart[hash(startPos)] = 0;
    gScoreGoal[hash(goalPos)] = 0;

    while (!openSetStart.empty() && !openSetGoal.empty()) {
        if (processStep(openSetStart, allNodesStart, allNodesGoal, gScoreStart, unitType))
            return reconstructPath(allNodesStart, allNodesGoal);

        if (processStep(openSetGoal, allNodesGoal, allNodesStart, gScoreGoal, unitType))
            return reconstructPath(allNodesStart, allNodesGoal);
    }

    return {};
}

// Expande nodos en la búsqueda
bool AStar::processStep(std::priority_queue<Node*, std::vector<Node*>, NodeComparator>& openSet,
                        std::unordered_map<int, Node*>& allNodes,
                        std::unordered_map<int, Node*>& otherNodes,
                        std::unordered_map<int, float>& gScore,
                        UnitType unitType) {
    if (openSet.empty()) return false;

    Node* current = openSet.top();
    openSet.pop();

    if (otherNodes.find(hash(current->pos)) != otherNodes.end()) {
        return true;  // Se encontraron ambas búsquedas
    }

    std::vector<glm::ivec2> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};

    for (const auto& dir : directions) {
        glm::ivec2 neighborPos = current->pos + dir;
        int neighborHash = hash(neighborPos);

        // Verifica si está fuera de los límites o es un obstáculo
        if (!tileMap->isWalkable(neighborPos, unitType)) {
            continue;
        }

        if (tileMap->isOccupied(neighborPos)) {
            continue;
        }

        float movementCost = tileMap->getMovementCost(neighborPos, unitType);
        if (movementCost < 0) {  //Porque es -1 en terreno intransitable
            continue;
        }
        float tentativeG = current->gCost + movementCost;

        if (gScore.find(neighborHash) == gScore.end() || tentativeG < gScore[neighborHash]) {
            gScore[neighborHash] = tentativeG;
            Node* neighborNode = new Node(neighborPos, tentativeG, heuristic(neighborPos, current->pos), current);
            openSet.push(neighborNode);
            allNodes[neighborHash] = neighborNode;
        }
    }

    return false;
}

// Reconstruye la ruta cuando ambas búsquedas se encuentran
std::queue<glm::vec2> AStar::reconstructPath(std::unordered_map<int, Node*>& startNodes,
                                             std::unordered_map<int, Node*>& goalNodes) {
    std::queue<glm::vec2> path;
    Node* meetingPoint = nullptr;

    for (auto& [key, node] : startNodes) {
        if (goalNodes.find(key) != goalNodes.end()) {
            meetingPoint = node;
            break;
        }
    }

    if (!meetingPoint) return path;

    // Reconstruir camino desde el punto de encuentro al inicio
    Node* current = meetingPoint;
    while (current) {
        path.push(glm::vec2(current->pos));
        current = current->parent;
    }

    // Reconstruir camino desde el punto de encuentro al final
    std::vector<glm::vec2> reversePath;
    current = goalNodes[hash(meetingPoint->pos)];
    while (current) {
        reversePath.push_back(glm::vec2(current->pos));
        current = current->parent;
    }

    // Insertar en orden correcto
    for (auto it = reversePath.rbegin(); it != reversePath.rend(); ++it) {
        path.push(*it);
    }

    return path;
}
