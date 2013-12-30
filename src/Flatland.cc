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

/**
 * \param position Where the entity should enter the world, expressed in 
 * meters relative to the origin.
 * \param dynamic Whether the entity should respond to physical stimulus.
 */
auto Flatland::createEntity(Vector2 position, bool dynamic) -> void {
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

auto Flatland::initialize() -> void {
    createEntity({0.0f, 0.0f}, true);
    createEntity({0.0f, -3.0f}, false);
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

