cmake_minimum_required(VERSION 3.31.5)
project(umbrella-RTS)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES "src/core/*.cpp" "src/game/*.cpp" "src/utils/*.cpp")

add_executable(umbrella-RTS main.cpp ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

target_include_directories(umbrella-RTS PRIVATE include third_party)
target_link_libraries(umbrella-RTS glfw OpenGL::GL GLEW)
