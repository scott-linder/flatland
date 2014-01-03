#ifndef FL_PHYSICS_HH
#define FL_PHYSICS_HH

#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace fl {

/// Physical element (Box2D) of an entity.
struct CPhysics : public entityx::Component<CPhysics> {
    /// Ctor.
    /** body is not guaranteed to be valid.
     */
    CPhysics();
    /// Ctor.
    CPhysics(std::shared_ptr<b2Body> body);

    /// Physical element (Box2D) of an entity.
    std::shared_ptr<b2Body> body;
};

} /* namespace fl */

#endif /* FL_PHYSICS_HH */

