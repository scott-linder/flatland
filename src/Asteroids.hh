#ifndef AS_ASTEROIDS_HH
#define AS_ASTEROIDS_HH

#include <memory>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "ECollision.hh"

namespace as {

class Asteroids : public entityx::Manager, public entityx::Receiver<Asteroids> {
public:
    Asteroids(std::shared_ptr<sf::RenderTarget> target,
            entityx::ptr<entityx::EventManager> events,
            entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::SystemManager> systems);
    ~Asteroids();
    auto receive(const as::ECollision &event) -> void;
protected:
    auto configure() -> void;
    auto initialize() -> void;
    auto update(double dt) -> void;
private:
    static const b2Vec2 kGravity;
    std::shared_ptr<b2World> world_;
    std::shared_ptr<sf::RenderTarget> target_;
    entityx::ptr<entityx::EventManager> events_;
    entityx::ptr<entityx::EntityManager> entities_;
    entityx::ptr<entityx::SystemManager> systems_;
};

} /* namespace as */

#endif /* AS_ASTEROIDS_HH */

