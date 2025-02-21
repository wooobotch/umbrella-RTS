#include "ResourceManager.h"
#include "./Logger.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

std::map<std::string, GLuint> ResourceManager::textures;

GLuint ResourceManager::loadTexture(const std::string& filePath) {
    if (textures.find(filePath) != textures.end()) {
        return textures[filePath]; // Con la textura yacargada
    }

    int width, height, nrChannels;
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);

    if (!data) {
        Logger::error("No se pudo cargar la textura: " + filePath);
        return 0;
    }

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    textures[filePath] = texture;
    return texture;
}

void ResourceManager::clear() {
    for (auto& pair : textures) {
        glDeleteTextures(1, &pair.second);
    }
    textures.clear();
}
