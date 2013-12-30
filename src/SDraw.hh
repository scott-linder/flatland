#ifndef AS_SDRAW_HH
#define AS_SDRAW_HH

#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

namespace fl {

/// SFML rendering system.
/** Displays entities with CDrawable components.
 */
class SDraw : public entityx::System<SDraw> {
public:
    /// Ctor.
    /**
     * \param target to render entities to.
     */
    explicit SDraw(std::shared_ptr<sf::RenderTarget> target);
    /// Render entities.
    auto update(entityx::ptr<entityx::EntityManager> entities,
                entityx::ptr<entityx::EventManager> events,
                double dt) -> void final;
private:
    /// Target to render entities to.
    std::shared_ptr<sf::RenderTarget> target_;
};

} /* namespace fl */

#endif /* AS_SDRAW_HH */

