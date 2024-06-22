#include "Logo.h"

Logo::Logo(sf::RenderWindow &window) : window(window)
{
}

void Logo::display()
{
    sf::Font font;
    font.loadFromFile("./assets/font.ttf");
    sf::Text t;

    t.setFont(font);
    t.setString("MINESWEEPER");
    t.setCharacterSize(96);
    t.setFillColor(sf::Color::Red);
    t.setStyle(sf::Text::Bold);
    t.setOrigin(t.getLocalBounds().width / 2, t.getLocalBounds().height / 2);
    t.setPosition(window.getSize().x / 2, window.getSize().y / 2 - 200);

    window.draw(t);
}