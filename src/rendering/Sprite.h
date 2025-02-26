#ifndef SPRITE_H
#define SPRITE_H

#include <glm/glm.hpp>
#include <string>
#include "Renderer.h"
#include "TextureManager.h"

class Sprite {
public:
    Sprite(const std::string& texturePath, const glm::vec2& position, const glm::vec2& size);
    ~Sprite();

    void render() const;
    void setPosition(const glm::vec2& newPosition);
    void setSize(const glm::vec2& newSize);

    glm::vec2 getPosition() const;
    glm::vec2 getSize() const;

private:
    GLuint textureID;
    glm::vec2 position;
    glm::vec2 size;
};

#endif
