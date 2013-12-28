#include "SDebug.hh"

namespace as {

auto SDebug::update(entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::EventManager> events,
            double dt) -> void {

    for (auto entity : entities->entities_with_components<CPhysics>()) {
        auto physics = entity.component<CPhysics>();
        auto position = physics->body->GetPosition();

        std::cout << position.x << ", " << position.y << std::endl;
    }
}

} /* namespace as */

