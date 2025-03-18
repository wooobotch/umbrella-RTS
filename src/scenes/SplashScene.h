#ifndef SPLASH_SCENE_H
#define SPLASH_SCENE_H

#include "../core/Scene.h"
#include <memory>

class SplashScene : public Scene {
private:
    float elapsedTime;
    float displayDuration;

public:
    SplashScene();
    void init() override;
    void handleInput() override;
    void update(float deltaTime) override;
    void render() override;
    void cleanup() override;
};

#endif
