#include <SFML/Graphics.hpp>
#include "core/view/pages.hpp"

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "Gym Class");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            viewHandleEvent(*event);
        }

        window.clear(sf::Color::White);
        viewRender(window);
        window.display();
    }
}