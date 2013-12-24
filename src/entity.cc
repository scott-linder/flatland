#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "conversions.hh"
#include "entity.hh"

namespace as {

Entity::~Entity()
{}

auto Entity::setBody(std::shared_ptr<b2Body> body) -> void {
    body_ = body;
}

auto Entity::getBody() const -> std::shared_ptr<b2Body> {
    return body_;
}

auto Entity::setDrawable(std::shared_ptr<sf::Drawable> drawable) -> void {
    drawable_ = drawable;
}

auto Entity::getDrawable() const -> std::shared_ptr<sf::Drawable> {
    return drawable_;
}

auto Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const -> void {
    // If we have a drawable, draw it
    if (drawable_) {
        // If we have a physics body, use its position and rotation
        if (body_) {
            sf::Transformable body_transformable;
            // TODO box2d to sfml units ?
            body_transformable.setPosition(as::toPixels(body_->GetPosition()));
            body_transformable.setScale(as::kPixelsPerMeter, as::kPixelsPerMeter);
            auto rotation = body_->GetAngle();
            body_transformable.setRotation(as::toDegrees(rotation));
            states.transform *= body_transformable.getTransform();
        }
        target.draw(*drawable_, states);
    }
}

} /* namespace as */
