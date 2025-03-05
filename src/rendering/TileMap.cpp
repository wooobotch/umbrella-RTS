#include "TileMap.h"

TileMap::TileMap(int width, int height) : width(width), height(height) {
    tiles.resize(width, std::vector<TileType>(height, TileType::EMPTY));
}

void TileMap::setTile(glm::ivec2 pos, TileType type) {
    if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height) {
        tiles[pos.x][pos.y] = type;
    }
}

TileType TileMap::getTile(glm::ivec2 pos) const {
    if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height) {
        return tiles[pos.x][pos.y];
    }
    return TileType::BLOCKED;
}

bool TileMap::isWalkable(glm::ivec2 pos) const {
    return getTile(pos) == TileType::EMPTY || getTile(pos) == TileType::ROAD;
}
