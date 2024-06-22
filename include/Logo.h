#ifndef LOGO_H
#define LOGO_H

#include <SFML/Graphics.hpp>

class Logo
{
private:
    sf::RenderWindow &window;

public:
public:
    Logo(sf::RenderWindow &window);
    void display();
};

#endif // GAME_H