#ifndef AS_SPHYSICS_HH
#define AS_SPHYSICS_HH

#include <memory>
#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace as {

class SPhysics : public entityx::System<SPhysics> {
public:
    explicit SPhysics(std::shared_ptr<b2World> world);
    auto update(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events,
                double dt) -> void final;
private:
    static const float32 kTimeStep;
    static const int32 kVelocityIterations,
                        kPositionIterations;
    std::shared_ptr<b2World> world_;
    float32 pending_time_;
};

} /* namespace as */

#endif /* AS_SPHYSICS_HH */

