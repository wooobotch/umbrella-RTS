#include "ShaderProgram.h"
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgram::ShaderProgram(const std::string& vertexPath, const std::string& fragmentPath) {
    // Cargar código fuente de los shaders
    std::string vertexCode = loadShaderCode(vertexPath);
    std::string fragmentCode = loadShaderCode(fragmentPath);

    // Compilar shaders
    GLuint vertexShader = compileShader(vertexCode, GL_VERTEX_SHADER);
    GLuint fragmentShader = compileShader(fragmentCode, GL_FRAGMENT_SHADER);

    // Crear programa de shaders
    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);

    // Verificar errores en la vinculación
    int success;
    char infoLog[512];
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(id, 512, nullptr, infoLog);
        std::cerr << "Error al enlazar programa de shaders: " << infoLog << std::endl;
    }

    // Eliminar shaders después de enlazarlos
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void ShaderProgram::use() {
    glUseProgram(id);
}

GLuint ShaderProgram::getID() const {
    return id;
}

std::string ShaderProgram::loadShaderCode(const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;

    if (file) {
        buffer << file.rdbuf();
        file.close();
    } else {
        std::cerr << "Error al leer el archivo de shader: " << path << std::endl;
    }

    return buffer.str();
}

GLuint ShaderProgram::compileShader(const std::string& code, GLenum type) {
    GLuint shader = glCreateShader(type);
    const char* codeCStr = code.c_str();
    glShaderSource(shader, 1, &codeCStr, nullptr);
    glCompileShader(shader);

    // Verificar errores de compilación
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "Error al compilar shader: " << infoLog << std::endl;
    }

    return shader;
}
