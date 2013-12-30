#include <memory>
#include <entityx/entityx.h>
#include <entityx/deps/Dependencies.h>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "CPosition.hh"
#include "CRotation.hh"
#include "CPhysics.hh"
#include "CDrawable.hh"
#include "Flatland.hh"

/** \mainpage Flatland (WIP)
 *
 * Not much going on yet. Stay tuned.
 */

/** \namespace fl
 * %Flatland specific code.
 *
 * Naming conventions used:
 * * C is entityx::Component
 * * S is entityx::System
 * * E is entityx::Event
 */

auto main(int argc, char *argv[]) -> int {
    // We need to pass the render target (in this case a window) around, so
    // it will be a std::shared_ptr
    sf::VideoMode video_mode(800, 600);
    auto render_window = std::make_shared<sf::RenderWindow>(video_mode, "SFML - Flatland");
    render_window->setVerticalSyncEnabled(true);
    // Used for frametime
    sf::Clock clock;

    // EntityX managers for events, entities, and systems
    auto events = entityx::make_ptr<entityx::EventManager>();
    auto entities = entityx::make_ptr<entityx::EntityManager>(events);
    auto systems = entityx::make_ptr<entityx::SystemManager>(entities, events);

    // EntityX Component dependencies
    systems->add<entityx::deps::Dependency<fl::CPhysics, fl::CPosition, fl::CRotation>>();
    systems->add<entityx::deps::Dependency<fl::CDrawable, fl::CPosition, fl::CRotation>>();

    // Flatland is an EntityX manager and our main game class
    fl::Flatland flatland(render_window, events, entities, systems);
    flatland.start();

    while (render_window->isOpen()) {
        {
            sf::Event event;
            while (render_window->pollEvent(event)) {
                // For now, process only close events
                if (event.type == sf::Event::Closed) {
                    render_window->close();
                }
            }
        }

        // Blank screen, step game, display window

        render_window->clear(sf::Color::Black);

        flatland.step(clock.restart().asSeconds());

        render_window->display();
    }

    return 0;
}
