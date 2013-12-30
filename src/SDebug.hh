#ifndef AS_SDEBUG_HH
#define AS_SDEBUG_HH

#include <iostream>
#include <entityx/entityx.h>
#include "CPhysics.hh"

namespace fl {

/// Text-based debug system.
/** Provides information about entities/components and system events.
 */
class SDebug : public entityx::System<SDebug>, public entityx::Receiver<SDebug> {
public:
    /// Ctor.
    SDebug();
    /// Subscribe to events.
    auto configure(entityx::ptr<entityx::EventManager> events) -> void;
    /// Collect and display debug information about game.
    auto update(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events,
                double dt) -> void final;
    /// Log entity creation.
    auto receive(const entityx::EntityCreatedEvent &event) -> void;
    /// Log entity destruction.
    auto receive(const entityx::EntityDestroyedEvent &event) -> void;
private:
};

} /* namespace fl */

#endif /* AS_SDEBUG_HH */

