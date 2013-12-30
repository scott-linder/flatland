#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include "CDrawable.hh"

namespace fl {

CDrawable::CDrawable()
    : drawable(std::make_shared<sf::CircleShape>(0.1f))
{}

CDrawable::CDrawable(std::shared_ptr<sf::Drawable> drawable)
    : drawable(drawable)
{}

} /* namespace fl */

