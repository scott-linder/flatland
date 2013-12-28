#ifndef AS_SDEBUG_HH
#define AS_SDEBUG_HH

#include <iostream>
#include <entityx/entityx.h>
#include "CPhysics.hh"

namespace as {

class SDebug : public entityx::System<SDebug> {
public:
    SDebug()
    {}
    auto update(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events,
                double dt) -> void final;
private:
};

} /* namespace as */

#endif /* AS_SDEBUG_HH */

