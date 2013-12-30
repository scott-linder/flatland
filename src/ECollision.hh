#ifndef AS_ECOLLISION_HH
#define AS_ECOLLISION_HH

#include <entityx/entityx.h>

namespace fl {

struct ECollision : entityx::Event<ECollision> {
    ECollision(entityx::Entity entity_a, entityx::Entity entity_b);

    entityx::Entity entity_a, entity_b;
};

} /* namespace fl */

#endif /* AS_ECOLLISION_HH */

