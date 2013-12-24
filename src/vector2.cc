#include "vector2.hh"

namespace as {

Vector2::Vector2()
    : Vector2(0, 0)
{}

Vector2::Vector2(const b2Vec2 &v)
    : Vector2(v.x, v.y)
{}

Vector2::Vector2(const sf::Vector2f &v)
    : Vector2(v.x, v.y)
{}

Vector2::Vector2(float x, float y)
    : x(x), y(y)
{}

Vector2::~Vector2()
{}

auto operator-(const Vector2 &right) -> Vector2 {
    return {-right.x, -right.y};
}

auto Vector2::operator+(const Vector2 &right) -> Vector2 {
    return {x + right.x, y + right.y};
}

auto Vector2::operator-(const Vector2 &right) -> Vector2 {
    return {x - right.x, y - right.y};
}

auto Vector2::operator+=(const Vector2 &right) -> void {
    x += right.x;
    y += right.y;
}

auto Vector2::operator-=(const Vector2 &right) -> void {
    x -= right.x;
    y -= right.y;
}

auto Vector2::operator*=(float right) -> void {
    x *= right;
    y *= right;
}


auto worldToPixels(const b2Vec2 &v) -> sf::Vector2f {
    return {v.x, -v.y};
}

} /* namespace as */
