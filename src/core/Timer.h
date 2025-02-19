#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    static void start();
    static float getDeltaTime();

private:
    static std::chrono::time_point<std::chrono::high_resolution_clock> lastFrameTime;
};

#endif // TIMER_H
