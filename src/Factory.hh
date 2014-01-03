#ifndef FL_FACTORY_HH
#define FL_FACTORY_HH

#include <memory>
#include <entityx/entityx.h>
#include <Box2D/Box2D.h>
#include "Vector2.hh"

namespace fl {

class Factory {
public:
    /// Ctor.
    Factory(std::shared_ptr<b2World> world,
            entityx::ptr<entityx::EntityManager> entities);
    /// Create a new physical entity.
    auto physicsEntity(Vector2 position, bool dynamic, sf::Color color)
        -> entityx::Entity;
private:
    /// Physics world.
    std::shared_ptr<b2World> world_;
    /// Entity manager
    entityx::ptr<entityx::EntityManager> entities_;
};

} /* namespace fl */

#endif /* FL_FACTORY_HH */

