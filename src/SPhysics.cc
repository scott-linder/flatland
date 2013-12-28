#include <memory>
#include <Box2D/Box2D.h>
#include "CPhysics.hh"
#include "SPhysics.hh"

namespace as {

const float32 SPhysics::kTimeStep = 1.0f / 60.0f;
const int32 SPhysics::kVelocityIterations = 6,
            SPhysics::kPositionIterations = 2;

SPhysics::SPhysics(std::shared_ptr<b2World> world)
    : world_(world)
    , pending_time_(0.0f)
{}

auto SPhysics::update(entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::EventManager> events,
            double dt) -> void {
    pending_time_ += static_cast<float32>(dt);
    while (pending_time_ > kTimeStep) {
        world_->Step(kTimeStep, kVelocityIterations, kPositionIterations);
        pending_time_ -= kTimeStep;
    }
}

} /* namespace as */

