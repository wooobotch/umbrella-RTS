#!/bin/bash
echo "Instalando dependencias..."
sudo apt update && sudo apt install -y \
    build-essential cmake git \
    libglfw3-dev libglfw3 \
    libglew-dev libglm-dev \
    libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev \
    mesa-utils libsdl2-dev
echo "Entorno configurado correctamente."
