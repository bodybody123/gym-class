#include "pages.hpp"
#include <SFML/Graphics.hpp>

void dashboardHandleEvent(const sf::Event&) {}

void dashboardRender(sf::RenderWindow& window)
{
    sf::Font font("assets/fonts/Inter/Regular.ttf");

    sf::Text text(font);

    text.setString("Hello, World Dashboard page");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    window.draw(text);
}
