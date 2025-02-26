#include "TextureManager.h"
#include <stb_image.h>
#include <iostream>

std::unordered_map<std::string, GLuint> TextureManager::textureCache;

GLuint TextureManager::loadTexture(const std::string& filePath) {
    if (textureCache.find(filePath) != textureCache.end()) {
        return textureCache[filePath];  // Devuelve la textura si ya está cargada
    }

    GLuint textureID = createTexture(filePath);
    if (textureID) {
        textureCache[filePath] = textureID;
    }
    return textureID;
}

GLuint TextureManager::getTexture(const std::string& filePath) {
    if (textureCache.find(filePath) != textureCache.end()) {
        return textureCache[filePath];
    }
    return 0;  // Devuelve 0 si la textura no está cargada
}

GLuint TextureManager::createTexture(const std::string& filePath) {
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 4);

    if (!data) {
        std::cerr << "Error: No se pudo cargar la textura " << filePath << std::endl;
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    stbi_image_free(data);
    return textureID;
}

void TextureManager::cleanup() {
    for (auto& texture : textureCache) {
        glDeleteTextures(1, &texture.second);
    }
    textureCache.clear();
}
