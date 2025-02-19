#include "Timer.h"

std::chrono::time_point<std::chrono::high_resolution_clock> Timer::lastFrameTime = std::chrono::high_resolution_clock::now();

void Timer::start() {
    lastFrameTime = std::chrono::high_resolution_clock::now();
}

float Timer::getDeltaTime() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsedTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;
    return elapsedTime.count();
}
