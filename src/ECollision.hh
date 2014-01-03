#ifndef FL_ECOLLISION_HH
#define FL_ECOLLISION_HH

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

#endif /* FL_ECOLLISION_HH */

