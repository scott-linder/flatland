#ifndef AS_SDRAW_HH
#define AS_SDRAW_HH

#include <iostream>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include "CPhysics.hh"
#include "conversions.hh"

namespace as {

class SDraw : public entityx::System<SDraw> {
public:
    SDraw(std::shared_ptr<sf::RenderTarget> target);
    auto update(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events,
                double dt) -> void final;
private:
    std::shared_ptr<sf::RenderTarget> target_;
    sf::CircleShape circle_;
};

} /* namespace as */

#endif /* AS_SDRAW_HH */

