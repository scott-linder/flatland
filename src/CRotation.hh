#ifndef AS_ANGLE_HH
#define AS_ANGLE_HH

#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace fl {

struct CRotation : public entityx::Component<CRotation> {
    CRotation(float degrees = 0);

    float degrees;
};

} /* namespace fl */

#endif /* AS_ANGLE_HH */

