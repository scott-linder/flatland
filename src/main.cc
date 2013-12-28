#include <memory>
#include <entityx/entityx.h>
#include <entityx/deps/Dependencies.h>
#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "CPosition.hh"
#include "CRotation.hh"
#include "CPhysics.hh"
#include "Asteroids.hh"

auto main(int argc, char *argv[]) -> int {
    sf::VideoMode video_mode(800, 600);
    auto render_window = std::make_shared<sf::RenderWindow>(video_mode, "SFML - Asteroids");
    render_window->setVerticalSyncEnabled(true);
    sf::Clock clock;

    auto events = entityx::make_ptr<entityx::EventManager>();
    auto entities = entityx::make_ptr<entityx::EntityManager>(events);
    auto systems = entityx::make_ptr<entityx::SystemManager>(entities, events);

    systems->add<entityx::deps::Dependency<as::CPhysics, as::CPosition, as::CRotation>>();

    as::Asteroids asteroids(render_window, events, entities, systems);
    asteroids.start();

    while (render_window->isOpen()) {
        {
            sf::Event event;
            while (render_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    render_window->close();
                }
            }
        }

        render_window->clear(sf::Color::Black);

        asteroids.step(clock.restart().asSeconds());

        render_window->display();
    }

    return 0;
}
