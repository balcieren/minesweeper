#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include "Board.h"

class BoardView
{
private:
    Board &board;
    void displayInput();
    void displayWon();
    void displayLost();

public:
    BoardView(Board &board);
    void display();
};

#endif // BOARDVIEW_H