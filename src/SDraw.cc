#include <SFML/Graphics.hpp>
#include "conversions.hh"
#include "CPosition.hh"
#include "CRotation.hh"
#include "CDrawable.hh"
#include "SDraw.hh"

namespace as {

SDraw::SDraw(std::shared_ptr<sf::RenderTarget> target)
    : target_(target)
{}

auto SDraw::update(entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::EventManager> events,
            double dt) -> void {

    for (auto entity : entities->entities_with_components<CPosition, CRotation, CDrawable>()) {
        auto position = entity.component<CPosition>();
        auto rotation = entity.component<CRotation>();
        auto drawable = entity.component<CDrawable>()->drawable;

        sf::Transformable physics_transformable;
        physics_transformable.setPosition(toPixels({position->x, position->y}));
        physics_transformable.setScale(kPixelsPerMeter, kPixelsPerMeter);
        physics_transformable.setRotation(rotation->degrees);
        target_->draw(*drawable, physics_transformable.getTransform());
    }
}

} /* namespace as */

