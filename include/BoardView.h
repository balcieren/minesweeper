#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "Board.h"
#include <SFML/Graphics.hpp>

class BoardView
{
private:
    Board &board;
    sf::RenderWindow &window;
    void displayWon();
    void displayLost();
    void displayBoard();

public:
    BoardView(Board &board, sf::RenderWindow &window);
    void display();
};

#endif // BOARDVIEW_H