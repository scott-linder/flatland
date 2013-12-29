#include <entityx/entityx.h>
#include "ECollision.hh"

namespace as {

ECollision::ECollision(entityx::Entity entity_a, entityx::Entity entity_b)
    : entity_a(entity_a), entity_b(entity_b)
{}

} /* namespace as */

