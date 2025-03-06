cmake_minimum_required(VERSION 3.10)
project(umbrella-RTS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Configurar el directorio de salida para binarios
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Incluir directorios
include_directories(src)
include_directories(src/core)
include_directories(src/ecs)
include_directories(src/ecs/components)
include_directories(src/ecs/systems)
include_directories(src/pathfinding)
include_directories(src/rendering)

# Archivos fuente
set(SOURCES
    src/main.cpp

    # Núcleo del juego
    src/core/Game.cpp
    src/core/InputManager.cpp
    src/core/UnitManager.cpp
    src/core/Utils.cpp

    # Entidades y componentes
    src/ecs/components/PositionComponent.h
    src/ecs/components/SelectableComponent.h
    src/ecs/components/MovementComponent.h
    src/ecs/systems/SelectionSystem.h
    src/ecs/systems/RenderSystem.h
    src/ecs/systems/MovementSystem.h
    src/ecs/Entity.h

    # Pathfinding
    src/pathfinding/Astar.cpp

    # Renderizado
    src/rendering/Renderer.cpp
    src/rendering/Sprite.cpp
    src/rendering/Tilemap.cpp
    src/renderin/Texture.cpp
    src/rendering/Shader.cpp
)

# Definir el ejecutable
add_executable(umbrella-RTS ${SOURCES})

# Enlazar bibliotecas necesarias
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(umbrella-RTS PRIVATE ${SDL2_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS})
target_link_libraries(umbrella-RTS ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
