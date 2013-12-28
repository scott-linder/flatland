#include <iostream>
#include <iomanip>
#include <limits>
#include "CPosition.hh"
#include "CRotation.hh"
#include "SDebug.hh"

namespace as {

auto SDebug::update(entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::EventManager> events,
            double dt) -> void {

    auto i = 0;
    for (auto entity : entities->entities_with_components<CPosition, CRotation>()) {
        auto position = entity.component<CPosition>();
        auto rotation = entity.component<CRotation>();

        std::cout << std::setprecision(std::numeric_limits<float>::digits10)
            << "Entity " << i++ << ":" << std::endl
            << "->Position: " << position->x << ", " << position->y << std::endl
            << "->Rotation: " << rotation->degrees << std::endl;
    }
}

} /* namespace as */

