#include <memory>
#include <utility>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "player.hh"

namespace as {

Player::Player(b2World *world, float size)
{
    b2BodyDef body_def;
    body_def.type = b2_dynamicBody;
    auto body = std::shared_ptr<b2Body>(world->CreateBody(&body_def),
            [world](b2Body *body) { world->DestroyBody(body); }); 
    b2CircleShape shape;
    shape.m_radius = size;
    body->CreateFixture(&shape, 10.0f);
    setBody(body);

    auto drawable = std::make_shared<sf::CircleShape>(size);
    setDrawable(drawable);
}

Player::~Player()
{}

auto Player::update(float seconds) -> void {
}

} /* namespace as */

