#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <unordered_map>
#include <string>
#include "../../third_party/glad/glad.h"

class TextureManager {
public:
    static GLuint loadTexture(const std::string& filePath);
    static GLuint getTexture(const std::string& filePath);
    static void cleanup();

private:
    static std::unordered_map<std::string, GLuint> textureCache;
    static GLuint createTexture(const std::string& filePath);
};

#endif
