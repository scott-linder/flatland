#include "Vector2.hh"

namespace fl {

Vector2::Vector2()
    : Vector2(0, 0)
{}

/**
 * \param v vector to copy components of.
 */
Vector2::Vector2(const b2Vec2 &v)
    : Vector2(v.x, v.y)
{}

/**
 * \param v vector to copy components of.
 */
Vector2::Vector2(const sf::Vector2f &v)
    : Vector2(v.x, v.y)
{}

/** Initializes x and y components.
 * \param x X-axis component.
 * \param y Y-axis component.
 */
Vector2::Vector2(float x, float y)
    : x(x), y(y)
{}

Vector2::~Vector2()
{}

/// Flip signs of both components.
/**
 * \param right vector to flip signs of.
 */
auto operator-(const Vector2 &right) -> Vector2 {
    return {-right.x, -right.y};
}

/**
 * \param right other vector to add.
 */
auto Vector2::operator+(const Vector2 &right) -> Vector2 {
    return {x + right.x, y + right.y};
}

/**
 * \param right other vector to subtract.
 */
auto Vector2::operator-(const Vector2 &right) -> Vector2 {
    return {x - right.x, y - right.y};
}

/**
 * \param right other vector to add.
 */
auto Vector2::operator+=(const Vector2 &right) -> void {
    x += right.x;
    y += right.y;
}

/**
 * \param right other vector to subtract.
 */
auto Vector2::operator-=(const Vector2 &right) -> void {
    x -= right.x;
    y -= right.y;
}

/**
 * \param right factor to scale by.
 */
auto Vector2::operator*=(float right) -> void {
    x *= right;
    y *= right;
}

} /* namespace fl */
