#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include <GL/glew.h>
#include "ShaderProgram.h"

class SpriteRenderer {
public:
    SpriteRenderer(ShaderProgram& shader);
    void draw(GLuint texture, float x, float y, float width, float height);

private:
    ShaderProgram& shader;
    GLuint VAO, VBO;
    void initRenderData();
};

#endif
