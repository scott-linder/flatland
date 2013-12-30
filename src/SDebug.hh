#ifndef AS_SDEBUG_HH
#define AS_SDEBUG_HH

#include <iostream>
#include <entityx/entityx.h>
#include "CPhysics.hh"

namespace fl {

class SDebug : public entityx::System<SDebug>, public entityx::Receiver<SDebug> {
public:
    SDebug();
    auto configure(entityx::ptr<entityx::EventManager> events) -> void;
    auto update(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events,
                double dt) -> void final;
    auto receive(const entityx::EntityCreatedEvent &event) -> void;
    auto receive(const entityx::EntityDestroyedEvent &event) -> void;
private:
};

} /* namespace fl */

#endif /* AS_SDEBUG_HH */

