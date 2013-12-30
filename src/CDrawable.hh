#ifndef AS_CDRAWABLE_HH
#define AS_CDRAWABLE_HH

#include <memory>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

namespace as {

struct CDrawable : entityx::Component<CDrawable> {
    CDrawable();
    CDrawable(std::shared_ptr<sf::Drawable> drawable);

    std::shared_ptr<sf::Drawable> drawable;
};

} /* namespace as */

#endif /* AS_CDRAWABLE_HH */

