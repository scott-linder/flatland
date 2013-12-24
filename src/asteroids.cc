#include <memory>
#include <utility>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "util.hh"
#include "entity.hh"
#include "player.hh"
#include "asteroids.hh"

namespace as {

const b2Vec2 Asteroids::kGravity{0.0f, -10.0f};
const float32 Asteroids::kTimeStep = 1.0f / 60.0f;
const int32 Asteroids::kVelocityIterations = 6,
            Asteroids::kPositionIterations = 2;

Asteroids::Asteroids()
    : pending_time_(0.0f)
    , world_(Asteroids::kGravity)
{
    addEntity(std::make_unique<as::Player>(&world_, 1));

    b2BodyDef ground_body_def;
    ground_body_def.position.Set(0.0f, -5.0f);
    b2Body* ground_body = world_.CreateBody(&ground_body_def);
    b2PolygonShape ground_box;
    ground_box.SetAsBox(50.0f, 1.0f);
    ground_body->CreateFixture(&ground_box, 0.0f);
}

Asteroids::~Asteroids()
{}

auto Asteroids::update(float delta_t) -> void {
    // We use a fixed physics-sim timestep
    pending_time_ += delta_t;
    while (pending_time_ >= kTimeStep) {
        world_.Step(kTimeStep, kVelocityIterations, kPositionIterations);
        pending_time_ -= kTimeStep;
    }
    for (auto &entity : entities_) {
        entity->update(delta_t);
    }
}

auto Asteroids::draw(sf::RenderTarget& target, sf::RenderStates states) const -> void {
    for (auto &entity : entities_) {
        entity->draw(target, states);
    }
}

auto Asteroids::addEntity(std::unique_ptr<as::Entity> entity) -> void {
    entities_.push_back(std::move(entity));
}

} /* namespace as */

