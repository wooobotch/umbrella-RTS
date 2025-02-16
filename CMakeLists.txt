cmake_minimum_required(VERSION 3.10)
project(MataBurros)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE SOURCES "src/core/*.cpp" "src/game/*.cpp" "src/utils/*.cpp")

add_executable(MataBurros main.cpp ${SOURCES})

find_package(OpenGL REQUIRED)
find_package(GLFW REQUIRED)

target_include_directories(MataBurros PRIVATE include third_party)
target_link_libraries(MataBurros glfw OpenGL::GL)
