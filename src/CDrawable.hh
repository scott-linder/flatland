#ifndef FL_CDRAWABLE_HH
#define FL_CDRAWABLE_HH

#include <memory>
#include <entityx/entityx.h>
#include <SFML/Graphics.hpp>

namespace fl {

/// Drawable element of an entity.
struct CDrawable : entityx::Component<CDrawable> {
    /// Ctor.
    /** drawable is guaranteed to be valid.
     */
    CDrawable();
    /// Ctor.
    CDrawable(std::unique_ptr<sf::Drawable> drawable);

    /// Drawable element of an entity.
    std::unique_ptr<sf::Drawable> drawable;
};

} /* namespace fl */

#endif /* FL_CDRAWABLE_HH */

