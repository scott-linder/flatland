#ifndef AS_POSITION_HH
#define AS_POSITION_HH

#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace fl {

/// Position of an entity.
/** Must be represented in meters.
 */
struct CPosition : public entityx::Component<CPosition> {
    /// Ctor.
    CPosition(float x = 0, float y = 0);

    float x, ///< X-axis component.
          y; ///< Y-axis component.
};

} /* namespace fl */

#endif /* AS_POSITION_HH */

