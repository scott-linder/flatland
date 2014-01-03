#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <entityx/entityx.h>
#include "util.hh"
#include "Vector2.hh"
#include "CPhysics.hh"
#include "CDrawable.hh"
#include "Factory.hh"

namespace fl {


Factory::Factory(std::shared_ptr<b2World> world,
        entityx::ptr<entityx::EntityManager> entities)
    : world_(world)
    , entities_(entities)
{}

/**
 * \param position Where the entity should enter the world, expressed in 
 * meters relative to the origin.
 * \param dynamic Whether the entity should respond to physical stimulus.
 */
auto Factory::physicsEntity(Vector2 position, bool dynamic, sf::Color color)
        -> entityx::Entity {

    auto entity = entities_->create();

    auto draw_shape = std::make_unique<sf::CircleShape>(0.5f);
    draw_shape->setFillColor(color);

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
    entity.assign<CDrawable>(std::move(draw_shape));
    return entity;
}

} /* namespace fl */

