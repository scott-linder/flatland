#ifndef AS_ECOLLISION_HH
#define AS_ECOLLISION_HH

#include <entityx/entityx.h>

namespace fl {

/// Describes physical collision of two entities.
struct ECollision : entityx::Event<ECollision> {
    /// Ctor.
    ECollision(entityx::Entity entity_a, entityx::Entity entity_b);

    entityx::Entity entity_a, ///< First entity colliding.
                    entity_b; ///< Second entity colliding.
};

} /* namespace fl */

#endif /* AS_ECOLLISION_HH */

