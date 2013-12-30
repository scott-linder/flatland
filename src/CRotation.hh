#ifndef AS_ANGLE_HH
#define AS_ANGLE_HH

#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace fl {

/// Rotation (angle) of entity.
/** Must be in degrees from X-axis in CCW direction.
 */
struct CRotation : public entityx::Component<CRotation> {
    /// Ctor.
    CRotation(float degrees = 0);

    float degrees; ///< Rotation of entity.
};

} /* namespace fl */

#endif /* AS_ANGLE_HH */

