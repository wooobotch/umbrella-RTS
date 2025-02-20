#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
    virtual ~Component() = default;

    virtual void update() {}
    virtual void render() {}
};

#endif /
