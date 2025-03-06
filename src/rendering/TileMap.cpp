#include "TileMap.h"

TileMap::TileMap(int width, int height) : width(width), height(height) {
    tiles.resize(width, std::vector<Tile>(height,
        Tile(TileType::EMPTY, 1.0f, {UnitType::INFANTRY, UnitType::CAVALRY, UnitType::ARCHER})
    ));
}

void TileMap::setTile(glm::ivec2 pos, Tile tile) {
    if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height) {
        tiles[pos.x][pos.y] = tile;
    }
}

const Tile& TileMap::getTile(glm::ivec2 pos) const {
    return tiles[pos.x][pos.y];
}

bool TileMap::isWalkable(glm::ivec2 pos, UnitType unitType) const {
    return tiles[pos.x][pos.y].allowedUnits.count(unitType) > 0;
}

float TileMap::getMovementCost(glm::ivec2 pos, UnitType unitType) const {
    if (isWalkable(pos, unitType)) {
        return tiles[pos.x][pos.y].movementCost;
    }
    return -1.0f; // Intransitable
}
