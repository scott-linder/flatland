#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include "util.hh"
#include "CDrawable.hh"

namespace fl {

CDrawable::CDrawable()
    : drawable(std::make_unique<sf::CircleShape>(0.1f))
{}

CDrawable::CDrawable(std::unique_ptr<sf::Drawable> drawable)
    : drawable(std::move(drawable))
{}

} /* namespace fl */

