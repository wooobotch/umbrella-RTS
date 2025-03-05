#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <glm/glm.hpp>

enum class TileType {
    EMPTY,       // Caminable
    BLOCKED,     // Edificios, recursos, accidentes
    ROAD,        // Camino (movimiento más rápido)
    WATER        // Intransitable (excepto para barcos)
};

class TileMap {
public:
    TileMap(int width, int height);

    void setTile(glm::ivec2 pos, TileType type);
    TileType getTile(glm::ivec2 pos) const;

    bool isWalkable(glm::ivec2 pos) const;

private:
    int width, height;
    std::vector<std::vector<TileType>> tiles;
};

#endif
