#include <memory>
#include <utility>
#include <Box2D/Box2D.h>
#include "conversions.hh"
#include "CPosition.hh"
#include "CRotation.hh"
#include "CPhysics.hh"
#include "SPhysics.hh"
#include "ECollision.hh"

namespace as {

const float32 SPhysics::kTimeStep = 1.0f / 60.0f;
const int32 SPhysics::kVelocityIterations = 6,
            SPhysics::kPositionIterations = 2;

SPhysics::SPhysics(std::shared_ptr<b2World> world)
    : world_(world)
    , pending_time_(0.0f)
{
    world_->SetContactListener(this);
}

auto SPhysics::update(entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::EventManager> events,
            double dt) -> void {
    pending_time_ += static_cast<float32>(dt);
    while (pending_time_ > kTimeStep) {
        world_->Step(kTimeStep, kVelocityIterations, kPositionIterations);
        pending_time_ -= kTimeStep;
    }

    for (auto entities : pending_collision_) {
        events->emit<as::ECollision>(entities.first, entities.second);
    }
    pending_collision_.clear();

    for (auto entity
            : entities->entities_with_components<CPhysics, CPosition, CRotation>()) {
        auto position = entity.component<CPosition>();
        auto angle = entity.component<CRotation>();
        auto physics = entity.component<CPhysics>();

        position->x = physics->body->GetPosition().x;
        position->y = physics->body->GetPosition().y;

        angle->degrees = toDegrees(physics->body->GetAngle());
    }
}

auto SPhysics::BeginContact(b2Contact *contact) -> void {
    auto entity_a = *static_cast<entityx::Entity*>(
            contact->GetFixtureA()->GetBody()->GetUserData());
    auto entity_b = *static_cast<entityx::Entity*>(
            contact->GetFixtureB()->GetBody()->GetUserData());
    std::cout << "Collision emitted: " << std::endl
        << "->A: " << entity_a << std::endl
        << "->B: " << entity_b << std::endl;
    pending_collision_.push_back(std::make_pair(entity_a, entity_b));
}

} /* namespace as */

