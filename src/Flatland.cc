#include <memory>
#include <iostream>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "util.hh"
#include "Vector2.hh"
#include "Factory.hh"
#include "CPosition.hh"
#include "CRotation.hh"
#include "CPhysics.hh"
#include "CDrawable.hh"
#include "SPhysics.hh"
#include "SDebug.hh"
#include "SDraw.hh"
#include "ECollision.hh"
#include "Flatland.hh"

namespace fl {

const b2Vec2 Flatland::kGravity{0.0f, -10.0f};

Flatland::Flatland(std::shared_ptr<sf::RenderTarget> target,
        entityx::ptr<entityx::EventManager> events,
        entityx::ptr<entityx::EntityManager> entities,
        entityx::ptr<entityx::SystemManager> systems)
    : world_(std::make_shared<b2World>(kGravity))
    , target_(target)
    , events_(events)
    , entities_(entities)
    , systems_(systems)
    , factory_(std::make_shared<Factory>(world_, entities_))
{}

Flatland::~Flatland()
{}

auto Flatland::configure() -> void {
    systems_->add<SPhysics>(world_);
    systems_->add<SDebug>();
    systems_->add<SDraw>(target_);
    systems_->configure();
    events_->subscribe<fl::ECollision>(*this);
}

auto Flatland::initialize() -> void {
    factory_->physicsEntity({0.0f, 0.0f}, true, sf::Color::Blue);
    factory_->physicsEntity({0.0f, -3.0f}, false, sf::Color::Red);
}

auto Flatland::update(double dt) -> void {
    systems_->update<SPhysics>(dt);
    systems_->update<SDebug>(dt);
    systems_->update<SDraw>(dt);
}

auto Flatland::receive(const fl::ECollision &event) -> void {
    std::cout << "Collision received: " << std::endl
        << "->A: " << event.entity_a << std::endl
        << "->B: " << event.entity_b << std::endl;
    entities_->get(event.entity_a.id()).destroy();
    entities_->get(event.entity_b.id()).destroy();
}

} /* namespace fl */

