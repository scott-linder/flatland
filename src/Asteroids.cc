#include <memory>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Asteroids.hh"
#include "CPhysics.hh"
#include "SPhysics.hh"
#include "SDebug.hh"
#include "SDraw.hh"

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
    systems_->add<SPhysics>(world_);
    systems_->add<SDebug>();
    systems_->add<SDraw>(target_);
    systems_->configure();
}

auto Asteroids::initialize() -> void {
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    body_def.position.Set(0.0f, 0.0f);
    auto entity = entities_->create();
    auto body = std::shared_ptr<b2Body>(world_->CreateBody(&body_def),
            [this](b2Body *body) { world_->DestroyBody(body); });
    entity.assign<CPhysics>(body);
}

auto Asteroids::update(double dt) -> void {
    systems_->update<SPhysics>(dt);
    systems_->update<SDebug>(dt);
    systems_->update<SDraw>(dt);
}

} /* namespace as */

