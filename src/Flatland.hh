#ifndef FL_ASTEROIDS_HH
#define FL_ASTEROIDS_HH

#include <memory>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "Vector2.hh"
#include "Factory.hh"
#include "ECollision.hh"

namespace fl {

/// Main game manager.
class Flatland : public entityx::Manager, public entityx::Receiver<Flatland> {
public:
    /// Ctor.
    /** Accepts a target to render on and entity managers to use.
     */
    Flatland(std::shared_ptr<sf::RenderTarget> target,
            entityx::ptr<entityx::EventManager> events,
            entityx::ptr<entityx::EntityManager> entities,
            entityx::ptr<entityx::SystemManager> systems);
    /// Dtor.
    ~Flatland();
    /// Respond to a collision between physical entities.
    auto receive(const fl::ECollision &event) -> void;
protected:
    /// Setup entity systems and event subscriptions.
    auto configure() -> void;
    /// Create entities and initialize gameplay.
    auto initialize() -> void;
    /// Step game simulation.
    /* \param dt Time since last render.
     */
    auto update(double dt) -> void;
private:
    /// Acceleration due to gravity.
    static const b2Vec2 kGravity;
    /// Physics world.
    std::shared_ptr<b2World> world_;
    /// Target to render game world to.
    std::shared_ptr<sf::RenderTarget> target_;
    /// Event manager.
    entityx::ptr<entityx::EventManager> events_;
    /// Entity manager.
    entityx::ptr<entityx::EntityManager> entities_;
    /// System manager.
    entityx::ptr<entityx::SystemManager> systems_;
    /// Entity factory
    std::shared_ptr<Factory> factory_;
};

} /* namespace fl */

#endif /* FL_ASTEROIDS_HH */

