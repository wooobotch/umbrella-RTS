#ifndef NODE_H
#define NODE_H

#include <glm/vec2.hpp>

struct Node {
    glm::ivec2 pos;
    float gCost, hCost;
    Node* parent;

    Node(glm::ivec2 p, float g, float h, Node* par) : pos(p), gCost(g), hCost(h), parent(par) {}

    float fCost() const { return gCost + hCost; }
};

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        return a->fCost() > b->fCost();
    }
};

#endif
