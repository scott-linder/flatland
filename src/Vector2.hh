#ifndef FL_VECTOR2_HH
#define FL_VECTOR2_HH

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace fl {

/** A 2D vector of floats.
 * Used to bridge the gap between various implementations found in other
 * libraries, including sf::Vector2f and b2Vec2; most common functionality is 
 * mimicked and implicit conversions to/from each are supplied to make
 * its use more-or-less seamless.
 */
class Vector2 {
public:
    float x, ///< X-axis component.
          y; ///< Y-axis component.
    /// Ctor.
    Vector2();
    /// Conversion from b2Vec2.
    Vector2(const b2Vec2 &v);
    /// Conversion from sf::Vector2f.
    Vector2(const sf::Vector2f &v);
    /// Ctor.
    Vector2(float x, float y);
    /// Dtor.
    ~Vector2();
    /// Conversion to b2Vec2.
    operator b2Vec2() const {
        return {x, y};
    }
    /// Conversion to sf::Vector2f.
    operator sf::Vector2f() const {
        return {x, y};
    }
    /// Add vectors components component-wise.
    auto operator+(const Vector2 &right) -> Vector2;
    /// Subtract vectors components component-wise.
    auto operator-(const Vector2 &right) -> Vector2;
    /// Add to this vector component-wise.
    auto operator+=(const Vector2 &right) -> void;
    /// Subtract from this vector component-wise.
    auto operator-=(const Vector2 &right) -> void;
    /// Scale each component in this vector.
    auto operator*=(float right) -> void;
private:
};

} /* namespace fl */

#endif /* FL_VECTOR2_HH */

