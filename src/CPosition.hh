#ifndef AS_POSITION_HH
#define AS_POSITION_HH

#include <entityx/entityx.h>
#include <Box2D/Box2D.h>

namespace as {

struct CPosition : public entityx::Component<CPosition> {
    CPosition(float x = 0, float y = 0);

    float x, y;
};

} /* namespace as */

#endif /* AS_POSITION_HH */

