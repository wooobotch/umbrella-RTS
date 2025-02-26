#include "Renderer.h"
#include <glad/glad.h>
#include <iostream>

Renderer::Renderer() {}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Renderer::init() {
    shader.load("assets/shaders/batch.vert", "assets/shaders/batch.frag");
    setupBatchRendering();
}

void Renderer::setupBatchRendering() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 1000, nullptr, GL_DYNAMIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    indices.reserve(1500);  // Espacio para índices
    for (int i = 0; i < 250; ++i) {
        int offset = i * 4;
        indices.push_back(offset);
        indices.push_back(offset + 1);
        indices.push_back(offset + 2);
        indices.push_back(offset + 2);
        indices.push_back(offset + 3);
        indices.push_back(offset);
    }
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

    glBindVertexArray(0);
}

void Renderer::beginBatch() {
    vertices.clear();
    textureCount = 0;
}

void Renderer::submitQuad(const glm::vec2& position, const glm::vec2& size, GLuint textureID) {
    if (textureCount >= 32) {
        endBatch();
        beginBatch();
    }

    float texSlot = -1.0f;
    for (int i = 0; i < textureCount; ++i) {
        if (textureSlot[i] == textureID) {
            texSlot = (float)i;
            break;
        }
    }

    if (texSlot == -1.0f) {
        textureSlot[textureCount] = textureID;
        texSlot = (float)textureCount;
        textureCount++;
    }

    vertices.push_back({position, {0.0f, 0.0f}});
    vertices.push_back({{position.x + size.x, position.y}, {1.0f, 0.0f}});
    vertices.push_back({{position.x + size.x, position.y + size.y}, {1.0f, 1.0f}});
    vertices.push_back({{position.x, position.y + size.y}, {0.0f, 1.0f}});
}

void Renderer::endBatch() {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());
}

void Renderer::render() {
    shader.use();
    glBindVertexArray(VAO);

    for (int i = 0; i < textureCount; ++i) {
        glActiveTexture(GL_TEXTURE0 + i);
        glBindTexture(GL_TEXTURE_2D, textureSlot[i]);
    }

    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
