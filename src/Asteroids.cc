#include <memory>
#include <iostream>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Vector2.hh"
#include "CPosition.hh"
#include "CRotation.hh"
#include "CPhysics.hh"
#include "CDrawable.hh"
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

auto Asteroids::createEntity(Vector2 position, bool dynamic) -> void {
    auto entity = entities_->create();

    auto draw_shape = std::make_shared<sf::CircleShape>(0.5f);

    /*
    b2PolygonShape phys_shape;
    phys_shape.Set(shape, shape.count);
    */
    b2CircleShape phys_shape;
    phys_shape.m_radius = 0.5f;

    b2BodyDef phys_body_def;
    phys_body_def.type = dynamic ? b2_dynamicBody : b2_staticBody;
    phys_body_def.position = position;
    auto phys_body = std::shared_ptr<b2Body>(world_->CreateBody(&phys_body_def),
            [this](b2Body *body)
            { delete static_cast<entityx::Entity*>(body->GetUserData());
                world_->DestroyBody(body); });
    phys_body->CreateFixture(&phys_shape, 1.0f);
    phys_body->SetUserData(new entityx::Entity(entity));

    entity.assign<CPhysics>(phys_body);
    entity.assign<CDrawable>(draw_shape);
}

auto Asteroids::initialize() -> void {
    createEntity({0.0f, 0.0f}, true);
    createEntity({0.0f, -3.0f}, false);
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

