#ifndef AS_VECTOR2_HH
#define AS_VECTOR2_HH

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace as {

class Vector2 {
public:
    float x, y;
    Vector2();
    Vector2(const b2Vec2 &v);
    Vector2(const sf::Vector2f &v);
    Vector2(float x, float y);
    ~Vector2();
    operator b2Vec2() const {
        return {x, y};
    }
    operator sf::Vector2f() const {
        return {x, y};
    }
    auto operator+(const Vector2 &right) -> Vector2;
    auto operator-(const Vector2 &right) -> Vector2;
    auto operator+=(const Vector2 &right) -> void;
    auto operator-=(const Vector2 &right) -> void;
    auto operator*=(float right) -> void;
private:
};

} /* namespace as */

#endif /* AS_VECTOR2_HH */

