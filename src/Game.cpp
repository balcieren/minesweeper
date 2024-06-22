#include "Game.h"
#include "../include/Menu.h"
#include "MenuView.h"
#include <string>
#include <iostream>
#include <Board.h>
#include <BoardView.h>
#include "Color.h"
#include "Logo.h"

void clearScreen()
{
    if (system("CLS"))
        system("clear");
}

void Game::initialize()
{
    std::string options[3] = {"HARD", "NORMAL", "EASY"};
    Menu menu(options);
    MenuView gameModeMenu(menu);

    Board board;
    BoardView boardView(board);

    while (true)
    {
        while (board.getGameState() == GameState::MAIN_MENU)
        {
            clearScreen();
            int width, height;
            displayLogo();
        reTryBoardSize:
            std::cout << YELLOW << "Enter board size (width height): " << RESET;
            std::cin >> width >> height;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << RED << "Invalid input!" << RESET << std::endl;
                goto reTryBoardSize;
            }

            if (width < 1 || height < 1 || width > 100 || height > 100)
            {
                std::cout << RED << "Invalid board size!" << RESET << std::endl;
                goto reTryBoardSize;
            }

            std::cout << YELLOW << "Select game mode: " << RESET << std::endl;
            gameModeMenu.display();
            switch (menu.getSelectedOption())
            {
            case 0:
                board = Board(width, height, GameMode::HARD);
                break;
            case 1:
                board = Board(width, height, GameMode::NORMAL);
                break;
            case 2:
                board = Board(width, height, GameMode::EASY);
                break;
            default:
                break;
            }
        }
        while (board.getGameState() == GameState::RUNNING || board.getGameState() == GameState::WON || board.getGameState() == GameState::LOST)
        {
            clearScreen();
            boardView.display();
        }
    }
}