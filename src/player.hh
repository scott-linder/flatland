#ifndef AS_PLAYER_HH
#define AS_PLAYER_HH

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "entity.hh"

namespace as {

class Player : public as::Entity {
public:
    Player(b2World *world, float size);
    virtual ~Player() override;
    virtual auto update(float seconds) -> void override;
private:
};

} /* namespace as */

#endif /* AS_PLAYER_HH */

