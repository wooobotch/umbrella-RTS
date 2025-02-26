#include "UnitManager.h"
#include <iostream>

std::vector<Unit> UnitManager::units;
Unit* UnitManager::selectedUnit = nullptr;

void UnitManager::initialize() {
    // Agregamos unidades de prueba
    addUnit(glm::vec2(-0.5f, 0.5f));
    addUnit(glm::vec2(0.3f, -0.2f));
}

void UnitManager::selectUnitAt(const glm::vec2& worldPos) {
    selectedUnit = nullptr; // Reset de selección
    for (auto& unit : units) {
        float dist = glm::length(worldPos - unit.position);
        if (dist <= unit.radius) {
            selectedUnit = &unit;
            unit.selected = true;
            std::cout << "Unidad seleccionada en (" << unit.position.x << ", " << unit.position.y << ")\n";
        } else {
            unit.selected = false;
        }
    }
}

Unit* UnitManager::getSelectedUnit() {
    return selectedUnit;
}

void UnitManager::addUnit(const glm::vec2& position) {
    units.emplace_back(position);
}

const std::vector<Unit>& UnitManager::getUnits() {
    return units;
}
