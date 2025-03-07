#!/usr/bin/env python3

import os

# Directorios raíz desde los cuales escanear
SOURCE_DIRS = [
    "src/core",
    "src/ecs/components",
    "src/ecs/systems",
    "src/pathfinding",
    "src/rendering"
]

# Ruta del archivo que vamos a generar
OUTPUT_FILE = "sources.cmake"

def collect_sources():
    sources = []
    for source_dir in SOURCE_DIRS:
        for root, _, files in os.walk(source_dir):
            for file in files:
                if file.endswith(".cpp"):
                    full_path = os.path.join(root, file).replace("\\", "/")
                    sources.append(full_path)
    return sources

def generate_cmake_file(sources):
    with open(OUTPUT_FILE, "w") as f:
        f.write("set(SOURCES\n")
        for source in sources:
            f.write(f"    {source}\n")
        f.write(")\n")

def main():
    sources = collect_sources()
    generate_cmake_file(sources)
    print(f"Archivo '{OUTPUT_FILE}' generado con {len(sources)} archivos fuente.")

if __name__ == "__main__":
    main()
