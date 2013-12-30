#ifndef AS_SPHYSICS_HH
#define AS_SPHYSICS_HH

#include <memory>
#include <vector>
#include <utility>
#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace fl {

/// Box2D physics system.
/** Update physics and emit collision events.
 */
class SPhysics : public entityx::System<SPhysics> , public b2ContactListener {
public:
    /// Ctor.
    /**
     * \param world to update physics of.
     */
    explicit SPhysics(std::shared_ptr<b2World> world);
    /// Step physics simulation and emit collision events.
    auto update(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events,
                double dt) -> void final;
    /// Track collisions to be emitted upon update()
    virtual auto BeginContact(b2Contact *contact) -> void;
private:
    /// Fixed physics simulation timestep.
    static const float32 kTimeStep;
    static const int32 kVelocityIterations, ///< Fixed physics simulation 
                                            ///< velocity iterations.
                        kPositionIterations; ///< Fixed physics simulation
                                             ///< position iterations.
    /// World to update physics of.
    std::shared_ptr<b2World> world_;
    /// Time which has been rendered but not yet simulated in physics.
    float32 pending_time_;
    /// Collisions which are waiting to be  emitted.
    std::vector<std::pair<entityx::Entity, entityx::Entity>> pending_collision_;
};

} /* namespace fl */

#endif /* AS_SPHYSICS_HH */

