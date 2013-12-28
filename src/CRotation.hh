#ifndef AS_ANGLE_HH
#define AS_ANGLE_HH

#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace as {

struct CRotation : public entityx::Component<CRotation> {
    CRotation(float degrees = 0);

    float degrees;
};

} /* namespace as */

#endif /* AS_ANGLE_HH */

