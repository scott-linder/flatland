#ifndef AS_PHYSICS_HH
#define AS_PHYSICS_HH

#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace as {

struct CPhysics : public entityx::Component<CPhysics> {
    CPhysics();
    CPhysics(std::shared_ptr<b2Body> body);

    std::shared_ptr<b2Body> body;
};

} /* namespace as */

#endif /* AS_PHYSICS_HH */

