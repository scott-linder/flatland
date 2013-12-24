#ifndef AS_ASTEROIDS_HH
#define AS_ASTEROIDS_HH

#include <vector>
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include "entity.hh"

namespace as {

class Asteroids : public sf::Drawable {
public:
    Asteroids();
    ~Asteroids();
    auto update(float delta_t) -> void;
    auto draw(sf::RenderTarget &target, sf::RenderStates states) const -> void final;
    auto addEntity(std::unique_ptr<as::Entity> entity) -> void;
private:
    // XXX reconsider: _static_, non-POD member kGravity
    static const b2Vec2 kGravity;
    static const float32 kTimeStep;
    static const int32 kVelocityIterations, kPositionIterations;
    float pending_time_;
    b2World world_;
    std::vector<std::unique_ptr<as::Entity>> entities_;
};

} /* namespace as */

#endif /* AS_ASTEROIDS_HH */

