cmake_minimum_required(VERSION 3.10)
project(umbrella-RTS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(OpenGL_GL_PREFERENCE "GLVND")

# Incluir directorios
include_directories(src)
include_directories(src/core)
include_directories(src/ecs)
include_directories(src/ecs/components)
include_directories(src/ecs/systems)
include_directories(src/pathfinding)
include_directories(src/rendering)

# Incluir el archivo generado dinámicamente
include(sources.cmake)

# Definir el ejecutable
add_executable(umbrella-RTS src/main.cpp ${SOURCES})

# Enlazar bibliotecas necesarias
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

target_include_directories(umbrella-RTS PRIVATE ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
target_link_libraries(umbrella-RTS ${SDL2_LIBRARIES} glfw ${OPENGL_LIBRARIES} GLEW)
