#ifndef ASTAR_H
#define ASTAR_H

#include "Node.h"
#include "../rendering/TileMap.h"
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <glm/glm.hpp>

class AStar {
public:
    AStar(TileMap* tileMap);
    std::queue<glm::vec2> findPath(glm::vec2 start, glm::vec2 goal, UnitType unitType);
    void setOccupiedPositions(const std::vector<glm::ivec2>& occupied);

private:
    TileMap* tileMap;
    bool processStep(std::priority_queue<Node*, std::vector<Node*>, NodeComparator>& openSet,
                     std::unordered_map<int, Node*>& allNodes,
                     std::unordered_map<int, Node*>& otherNodes,
                     std::unordered_map<int, float>& gScore);

    bool isWalkable(glm::ivec2 pos, UnitType unitType);
    float getMovementCost(glm::ivec2 pos, UnitType unitType);

    std::queue<glm::vec2> reconstructPath(std::unordered_map<int, Node*>& startNodes,
                                          std::unordered_map<int, Node*>& goalNodes);

    bool isOccupied(glm::ivec2 pos);

    std::set<int> occupiedPositions;
};

#endif
