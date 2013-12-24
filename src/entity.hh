#ifndef AS_ENTITY_HH
#define AS_ENTITY_HH

#include <memory>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>

namespace as {

class Entity : public sf::Drawable {
public:
    virtual ~Entity();
    virtual auto draw(sf::RenderTarget &target, sf::RenderStates states) const -> void final;
    virtual auto update(float seconds) -> void = 0;
    auto setBody(std::shared_ptr<b2Body> body) -> void;
    auto getBody() const -> std::shared_ptr<b2Body>;
    auto setDrawable(std::shared_ptr<sf::Drawable> drawable) -> void;
    auto getDrawable() const -> std::shared_ptr<sf::Drawable>;
private:
    std::shared_ptr<b2Body> body_;
    std::shared_ptr<sf::Drawable> drawable_;
};

}

#endif /* AS_ENTITY_HH */

