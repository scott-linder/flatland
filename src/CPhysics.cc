#include <memory>
#include <Box2D/Box2D.h>
#include "CPhysics.hh"

namespace fl {

CPhysics::CPhysics()
    : body(nullptr)
{}

CPhysics::CPhysics(std::shared_ptr<b2Body> body)
    : body(body)
{}

} /* namespace fl */

