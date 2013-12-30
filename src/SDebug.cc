#include <iostream>
#include <iomanip>
#include <limits>
#include "CPosition.hh"
#include "CRotation.hh"
#include "SDebug.hh"

namespace fl {

SDebug::SDebug()
{}

auto SDebug::configure(entityx::ptr<entityx::EventManager> events) -> void {
    events->subscribe<entityx::EntityCreatedEvent>(*this);
    events->subscribe<entityx::EntityDestroyedEvent>(*this);
}

auto SDebug::update(entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::EventManager> events,
            double dt) -> void {

    for (auto entity : entities->entities_with_components<CPosition, CRotation>()) {
        auto position = entity.component<CPosition>();
        auto rotation = entity.component<CRotation>();

        std::cout << std::setprecision(std::numeric_limits<float>::digits10)
            << entity << std::endl
            << "->Position: " << position->x << ", " << position->y << std::endl
            << "->Rotation: " << rotation->degrees << std::endl;
    }
}

auto SDebug::receive(const entityx::EntityCreatedEvent &event) -> void {
    std::cout << event.entity << " Created" << std::endl;
}

auto SDebug::receive(const entityx::EntityDestroyedEvent &event) -> void {
    std::cout << event.entity << " Destroyed" << std::endl; 
}

} /* namespace fl */

