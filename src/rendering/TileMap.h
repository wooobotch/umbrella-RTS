#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include <glm/glm.hpp>
#include <unordered_set>

enum class TileType {
    EMPTY,       // Caminable, referencia o base
    BLOCKED,     // Edificios, recursos, accidentes
    ROAD,        // Camino (movimiento más rápido)
    WATER,        // Intransitable (excepto para barcos)
    FOREST,      // Movimiento general más lento
    HILL         // Sólo unidades terrestres
};

// Tipos de unidades
enum class UnitType {
    INFANTRY,
    CAVALRY,
    ARCHER,
    NAVAL,
    FLYING //NPC, hawk-creep
};

struct Tile {
    TileType type;
    float movementCost;
    std::unordered_set<UnitType> allowedUnits;

    Tile(TileType type, float cost, std::unordered_set<UnitType> units)
        : type(type), movementCost(cost), allowedUnits(units) {}
};

class TileMap {
public:
    TileMap(int width, int height);

    void setTile(glm::ivec2 pos, Tile tile);
    const Tile& getTile(glm::ivec2 pos) const;

    bool isWalkable(glm::ivec2 pos, UnitType unitType) const;
    bool isOccupied(glm::ivec2 pos) const;
    float getMovementCost(glm::ivec2 pos, UnitType unitType) const;

private:
    int width, height;
    std::set<glm::ivec2> occupiedPositions;
    std::vector<std::vector<Tile>> tiles;
};

#endif
