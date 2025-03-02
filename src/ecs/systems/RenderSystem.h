#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include "../components/PositionComponent.h"
#include "../components/SelectableComponent.h"
#include "../Entity.h"
#include <vector>
#include <GL/gl.h>

class RenderSystem {
public:
    static void render(const std::vector<Entity>& entities) {
        glClear(GL_COLOR_BUFFER_BIT);

        for (const auto& entity : entities) {
            auto pos = entity.getComponent<PositionComponent>();
            auto selectable = entity.getComponent<SelectableComponent>();

            if (pos) {
                if (selectable && selectable->selected) {
                    glColor3f(1.0f, 1.0f, 0.0f);  // Amarillo si está seleccionada
                } else {
                    glColor3f(0.0f, 0.0f, 1.0f);  // Azul si no
                }

                glBegin(GL_TRIANGLE_FAN);
                glVertex2f(pos->position.x, pos->position.y);
                for (int i = 0; i <= 20; ++i) {
                    float angle = i * (2.0f * 3.14159f / 20);
                    glVertex2f(pos->position.x + cos(angle) * 0.5f,
                               pos->position.y + sin(angle) * 0.5f);
                }
                glEnd();
            }
        }
    }
};

#endif
