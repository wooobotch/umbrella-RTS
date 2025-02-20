#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>
#include <GL/glew.h>

class ShaderProgram {
public:
    ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath);
    void use();
    GLuint getID() const;

private:
    GLuint id;
    std::string loadShaderCode(const std::string& path);
    GLuint compileShader(const std::string& code, GLenum type);
};

#endif
