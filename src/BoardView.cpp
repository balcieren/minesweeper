#include "BoardView.h"
#include "Board.h"
#include <iostream>
#include <Color.h>

BoardView::BoardView(Board &board) : board(board) {}

void BoardView::displayInput()
{
    char cmd;
    int row, col;

reTry:
    std::cout << YELLOW << "Enter command ('r' to reveal or 'f' to flag) and coordinates (row col): " << RESET;
    ;
    std::cin >> cmd >> row >> col;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        goto reTry;
    }

    if (cmd == 'r' && row >= 0 && row < board.getHeight() && col >= 0 && col < board.getWidth())
    {
        board.revealField(col, row);
    }
    else if (cmd == 'f' && row >= 0 && row < board.getHeight() && col >= 0 && col < board.getWidth())
    {
        board.toggleFlag(col, row);
    }
    else
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << RED << "Invalid command!" << RESET << std::endl;
        goto reTry;
    }
}

void BoardView::displayWon()
{
    std::cout << GREEN << "You won!" << RESET << std::endl;
    std::cout << "Press enter to go to main menu" << std::endl;
    std::cin.ignore();
    std::cin.get();
    board.setGameState(GameState::MAIN_MENU);
}

void BoardView::displayLost()
{
    std::cout << RED << "You lost!" << RESET << std::endl;
    std::cout << "Press enter to go to main menu" << std::endl;
    std::cin.ignore();
    std::cin.get();
    board.setGameState(GameState::MAIN_MENU);
}

void BoardView::display()
{
    for (int x = 0; x < board.getWidth(); x++)
    {
        if (x == 0)
        {
            std::cout << "    ";
        }

        if (x >= 10)
        {
            std::cout << " " << x << " ";
        }
        else
        {
            std::cout << "  " << x << " ";
        }
    }
    std::cout << std::endl;
    for (int x = 0; x < board.getWidth(); x++)
    {
        if (x == 0)
        {
            std::cout << "     ";
        }
        std::cout << "" << "───" << " ";
    }
    std::cout << std::endl;

    for (int y = 0; y < board.getHeight(); y++)
    {
        if (y >= 10)
        {
            std::cout << y << " │ ";
        }
        else
        {
            std::cout << y << "  │ ";
        }

        for (int x = 0; x < board.getWidth(); x++)
        {
            std::cout << "[";
            if (board.getFieldInfo(x, y) == '*')
            {
                std::cout << RED << board.getFieldInfo(x, y) << RESET;
            }
            else if (board.getFieldInfo(x, y) == 'F')
            {
                std::cout << YELLOW << board.getFieldInfo(x, y) << RESET;
            }
            else if (board.getFieldInfo(x, y) == '1')
            {
                std::cout << GREEN << board.getFieldInfo(x, y) << RESET;
            }
            else if (board.getFieldInfo(x, y) == '2')
            {
                std::cout << BLUE << board.getFieldInfo(x, y) << RESET;
            }
            else if (board.getFieldInfo(x, y) >= '3')
            {
                std::cout << RED << board.getFieldInfo(x, y) << RESET;
            }
            else
            {
                std::cout << board.getFieldInfo(x, y);
            }
            std::cout << "]" << " ";
        }
        std::cout << std::endl;
        std::cout << " " << std::endl;
    }
    if (board.getGameState() == GameState::RUNNING)
    {
        displayInput();
    }
    else if (board.getGameState() == GameState::WON)
    {
        displayWon();
    }
    else if (board.getGameState() == GameState::LOST)
    {
        displayLost();
    }
    else
    {
    }
};
