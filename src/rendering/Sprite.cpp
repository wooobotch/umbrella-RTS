#include "Sprite.h"

Sprite::Sprite(const std::string& texturePath, const glm::vec2& position, const glm::vec2& size)
    : position(position), size(size) {
    textureID = TextureManager::loadTexture(texturePath);
}

void Sprite::render() {
    Renderer::renderQuad(position, size, textureID);
}

void Sprite::setPosition(const glm::vec2& newPosition) {
    position = newPosition;
}

void Sprite::setSize(const glm::vec2& newSize) {
    size = newSize;
}

glm::vec2 Sprite::getPosition() const {
    return position;
}

glm::vec2 Sprite::getSize() const {
    return size;
}
