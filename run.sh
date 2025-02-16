#!/bin/bash
mkdir -p build && cd build
cmake ..
make -j$(nproc)
./bin/umbrella-RTS
