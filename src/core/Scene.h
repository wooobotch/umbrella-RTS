#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    virtual ~Scene() {}
    virtual void init() = 0;
    virtual void handleInput() = 0;
    virtual void update(float) = 0;
    virtual void render() = 0;
    virtual void cleanup() = 0;
    virtual void pause() {};
    virtual void resume() {};
};

#endif
