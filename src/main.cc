#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "asteroids.hh"

auto main(int argc, char *argv[]) -> int {
    sf::RenderWindow render_window{{800, 600}, "SFML - Asteroids"};
    render_window.setVerticalSyncEnabled(true);
    sf::Clock clock;

    as::Asteroids asteroids;

    while (render_window.isOpen()) {
        {
            sf::Event event;
            while (render_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    render_window.close();
                }
            }
        }

        render_window.clear(sf::Color::Black);

        asteroids.update(clock.restart().asSeconds());
        render_window.draw(asteroids);

        render_window.display();
    }

    return 0;
}
