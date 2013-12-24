#ifndef AS_CONVERSIONS_HH
#define AS_CONVERSIONS_HH

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace as {

constexpr float kPi = 3.14159f;
constexpr float kRadiansPerDegree = (2.0f * kPi) / 360.0f;

constexpr auto toRadians(float degrees) -> float {
    return degrees * kRadiansPerDegree;
}

constexpr auto toDegrees(float radians) -> float {
    return radians / kRadiansPerDegree;
}

constexpr float kPixelsPerMeter = 100;

inline auto toPixels(const b2Vec2 &v) -> sf::Vector2f {
    return {v.x * kPixelsPerMeter, -v.y * kPixelsPerMeter};
}

} /* namespace as */

#endif /* AS_CONVERSIONS_HH */

