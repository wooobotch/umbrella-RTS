#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TextureManager.h"

struct Vertex {
    glm::vec2 position;
    glm::vec2 texCoords;
};

class Renderer {
public:
    Renderer();
    ~Renderer();

    void init();
    void beginBatch();
    void submitQuad(const glm::vec2& position, const glm::vec2& size, GLuint textureID);
    void endBatch();
    void render();

private:
    GLuint VAO, VBO, EBO;
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    GLuint textureSlot[32];  // OpenGL permite hasta 32 texturas activas
    int textureCount = 0;

    ShaderProgram shader;

    void setupBatchRendering();
};

#endif
