#ifndef UNIT_MANAGER_H
#define UNIT_MANAGER_H

#include <vector>
#include <glm/glm.hpp>

class Unit {
public:
    glm::vec2 position;
    float radius = 0.5f;
    bool selected = false;

    Unit(glm::vec2 pos) : position(pos) {}
};

class UnitManager {
public:
    static void initialize();
    static void selectUnitAt(const glm::vec2& worldPos);
    static Unit* getSelectedUnit();
    static void addUnit(const glm::vec2& position);
    static const std::vector<Unit>& getUnits();

private:
    static std::vector<Unit> units;
    static Unit* selectedUnit;
};

#endif


