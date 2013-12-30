#ifndef AS_CONVERSIONS_HH
#define AS_CONVERSIONS_HH

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace fl {

/// Approximation of the mathematical constant Pi.
constexpr float kPi = 3.14159f;
/// Unit conversion factor from degrees to radians.
constexpr float kRadiansPerDegree = (2.0f * kPi) / 360.0f;

/// Convert an angle measure from degrees to radians.
constexpr auto toRadians(float degrees) -> float {
    return degrees * kRadiansPerDegree;
}

/// Convert an angle measure from radians to degrees.
constexpr auto toDegrees(float radians) -> float {
    return radians / kRadiansPerDegree;
}

/// Unit conversion factor from meters to pixels.
/** In game, units are meters (for reasons including the use of Box2D fo
 * physics simulation) but must be converted to pixels for rendering. Thus,
 * this constant should be isolated to use in graphics-handling code.
 */
constexpr float kPixelsPerMeter = 100;

/// Convert a Box2D vector in meters into an SFML one in pixels.
inline auto toPixels(const b2Vec2 &v) -> sf::Vector2f {
    return {v.x * kPixelsPerMeter, -v.y * kPixelsPerMeter};
}

} /* namespace fl */

#endif /* AS_CONVERSIONS_HH */

