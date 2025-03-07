#!/usr/bin/env bash

# Lista de carpetas a escanear
SOURCE_DIRS=(
    "src/core"
    "src/ecs/components"
    "src/ecs/systems"
    "src/pathfinding"
    "src/rendering"
)

# Archivo de salida
OUTPUT_FILE="sources.cmake"

echo "Generando $OUTPUT_FILE..."

# Encabezado de sources.cmake
echo "set(SOURCES" > "$OUTPUT_FILE"

# Buscamos archivos .cpp en cada carpeta y agregarlos
for dir in "${SOURCE_DIRS[@]}"; do
    if [ -d "$dir" ]; then
        find "$dir" -type f -name "*.cpp" | sort | while read -r file; do
            # Convertir \ a / por compatibilidad (no siempre necesario en Linux)
            file="${file//\\/\/}"
            echo "    $file" >> "$OUTPUT_FILE"
        done
    else
        echo "Directorio no encontrado: $dir"
    fi
done

# Cerramos el set
echo ")" >> "$OUTPUT_FILE"

echo "$OUTPUT_FILE generado correctamente."

