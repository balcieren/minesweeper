#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <string>
#include "../include/Menu.h"
#include <SFML/Graphics.hpp>

class MenuView
{
private:
    Menu &menu;
    sf::RenderWindow &window;
    void displayBoardSizeInput();
    void displayPlayButton();

public:
    MenuView(Menu &menu, sf::RenderWindow &window);
    void display();
};

#endif // MENUVIEW_H