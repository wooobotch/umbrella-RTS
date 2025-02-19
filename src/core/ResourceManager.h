#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <string>
#include <GL/glew.h>

class ResourceManager {
public:
    static GLuint loadTexture(const std::string& filePath);
    static void clear();

private:
    static std::map<std::string, GLuint> textures;
};

#endif // RESOURCE_MANAGER_H
