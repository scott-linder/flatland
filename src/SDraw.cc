#include "SDraw.hh"

namespace as {

SDraw::SDraw(std::shared_ptr<sf::RenderTarget> target)
    : target_(target)
    , circle_(0.5)
{}

auto SDraw::update(entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::EventManager> events,
            double dt) -> void {

    for (auto entity : entities->entities_with_components<CPhysics>()) {
        auto physics = entity.component<CPhysics>();
        auto position = toPixels(physics->body->GetPosition());
        auto rotation = toDegrees(physics->body->GetAngle());

        sf::Transformable physics_transformable;
        physics_transformable.setPosition(position);
        physics_transformable.setScale(kPixelsPerMeter, kPixelsPerMeter);
        physics_transformable.setRotation(rotation);
        target_->draw(circle_, physics_transformable.getTransform());
    }
}

} /* namespace as */

