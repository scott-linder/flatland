#include <memory>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "asteroids.hh"
#include "physics.hh"
#include "physics_system.hh"
#include "debug_system.hh"
#include "draw_system.hh"

namespace as {

const b2Vec2 Asteroids::kGravity{0.0f, -10.0f};

Asteroids::Asteroids(std::shared_ptr<sf::RenderTarget> target,
        entityx::ptr<entityx::EventManager> events,
        entityx::ptr<entityx::EntityManager> entities,
        entityx::ptr<entityx::SystemManager> systems)
    : world_(std::make_shared<b2World>(kGravity))
    , target_(target)
    , events_(events)
    , entities_(entities)
    , systems_(systems)
{}

Asteroids::~Asteroids()
{}

auto Asteroids::configure() -> void {
    systems_->add<PhysicsSystem>(world_);
    systems_->add<DebugSystem>();
    systems_->add<DrawSystem>(target_);
    systems_->configure();
}

auto Asteroids::initialize() -> void {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.position.Set(0.0f, 0.0f);
    auto entity = entities_->create();
    auto body = std::shared_ptr<b2Body>(world_->CreateBody(&body_def),
            [this](b2Body *body) { world_->DestroyBody(body); });
    entity.assign<Physics>(body);
}

auto Asteroids::update(double dt) -> void {
    systems_->update<PhysicsSystem>(dt);
    systems_->update<DebugSystem>(dt);
    systems_->update<DrawSystem>(dt);
}

} /* namespace as */

