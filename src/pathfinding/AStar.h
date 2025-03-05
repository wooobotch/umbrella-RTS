#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <glm/glm.hpp>

class AStar {
public:
    std::queue<glm::vec2> findPath(glm::vec2 start, glm::vec2 goal, const std::vector<std::vector<int>>& grid);
    void setOccupiedPositions(const std::vector<glm::ivec2>& occupied);

private:
    bool processStep(std::priority_queue<Node*, std::vector<Node*>, NodeComparator>& openSet,
                     std::unordered_map<int, Node*>& allNodes,
                     std::unordered_map<int, Node*>& otherNodes,
                     std::unordered_map<int, float>& gScore,
                     const std::vector<std::vector<int>>& grid);

    std::queue<glm::vec2> reconstructPath(std::unordered_map<int, Node*>& startNodes,
                                          std::unordered_map<int, Node*>& goalNodes);

    bool isOccupied(glm::ivec2 pos);

    std::set<int> occupiedPositions;
};

#endif
