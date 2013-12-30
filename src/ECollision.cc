#include <entityx/entityx.h>
#include "ECollision.hh"

namespace fl {

ECollision::ECollision(entityx::Entity entity_a, entityx::Entity entity_b)
    : entity_a(entity_a), entity_b(entity_b)
{}

} /* namespace fl */

