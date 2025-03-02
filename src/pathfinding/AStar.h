#ifndef A_STAR_H
#define A_STAR_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <glm/glm.hpp>

class AStar {
public:
    static std::queue<glm::vec2> findPath(glm::vec2 start, glm::vec2 goal);
};

#endif
