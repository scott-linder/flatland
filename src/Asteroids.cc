#include <memory>
#include <iostream>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "CPosition.hh"
#include "CRotation.hh"
#include "CPhysics.hh"
#include "SPhysics.hh"
#include "SDebug.hh"
#include "SDraw.hh"
#include "ECollision.hh"
#include "Asteroids.hh"

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
    events_->subscribe<as::ECollision>(*this);
}

auto Asteroids::initialize() -> void {
    b2CircleShape circle;
    circle.m_radius = 0.5f;
    b2BodyDef dynamic_body_def;
    dynamic_body_def.type = b2_dynamicBody;
    dynamic_body_def.position.Set(0.0f, 0.0f);
    auto dynamic_entity = entities_->create();
    auto dynamic_body = std::shared_ptr<b2Body>(world_->CreateBody(&dynamic_body_def),
            [this](b2Body *body) { world_->DestroyBody(body); });
    dynamic_body->CreateFixture(&circle, 0.0f);
    // TODO who owns this entity? how does it get deleted?
    dynamic_body->SetUserData(new entityx::Entity(dynamic_entity));
    dynamic_entity.assign<CPhysics>(dynamic_body);

    b2BodyDef static_body_def;
    static_body_def.type = b2_staticBody;
    static_body_def.position.Set(0.0f, -3.0f);
    auto static_entity = entities_->create();
    auto static_body = std::shared_ptr<b2Body>(world_->CreateBody(&static_body_def),
            [this](b2Body *body) { world_->DestroyBody(body); });
    static_body->CreateFixture(&circle, 0.0f);
    // TODO who owns this entity? how does it get deleted?
    static_body->SetUserData(new entityx::Entity(static_entity));
    static_entity.assign<CPhysics>(static_body);
}

auto Asteroids::update(double dt) -> void {
    systems_->update<SPhysics>(dt);
    systems_->update<SDebug>(dt);
    systems_->update<SDraw>(dt);
}

auto Asteroids::receive(const as::ECollision &event) -> void {
    std::cout << "Collision received: " << std::endl
        << "->A: " << event.entity_a << std::endl
        << "->B: " << event.entity_b << std::endl;
    entities_->get(event.entity_a.id()).destroy();
    entities_->get(event.entity_b.id()).destroy();
}

} /* namespace as */

