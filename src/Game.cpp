#include "Game.h"
#include "../include/Menu.h"
#include "MenuView.h"
#include <string>
#include <iostream>
#include <Board.h>
#include <BoardView.h>
#include <SFML/Graphics.hpp>
#include <Logo.h>

void Game::initialize()
{
    int w = 32;
    Menu menu;
    Board board;
    board.setGameState(GameState::MAIN_MENU);
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper", sf::Style::Close | sf::Style::Titlebar);
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);

    MenuView menuView(menu, window);
    BoardView boardView(board, window);
    Logo logo(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if (board.getGameState() == GameState::MAIN_MENU)
        {
            window.setSize(sf::Vector2u(800, 600));
            sf::View view(sf::FloatRect(0, 0, 800, 600));
            view.setCenter(400, 300);
            window.setView(view);

            menuView.display();
            logo.display();

            switch (menu.getSelectedOption())
            {
            case 0:
                board = Board(menu.getBoardWidth(), menu.getBoardHeight(), GameMode::HARD);
                board.setGameState(GameState::MAIN_MENU);
                break;
            case 1:
                board = Board(menu.getBoardWidth(), menu.getBoardHeight(), GameMode::NORMAL);
                board.setGameState(GameState::MAIN_MENU);
                break;
            case 2:
                board = Board(menu.getBoardWidth(), menu.getBoardHeight(), GameMode::EASY);
                board.setGameState(GameState::MAIN_MENU);
                break;
            }

            if (menu.getPressedPlayButton() && menu.getSelectedOption() != -1)
            {
                board.setGameState(GameState::RUNNING);
                menu.setSelectedOption(-1);
                menu.setPressedPlayButton(false);
                sf::sleep(sf::milliseconds(500));
            }
            else
            {
                menu.setPressedPlayButton(false);
            }
        }

        if (board.getGameState() == GameState::RUNNING || board.getGameState() == GameState::WON || board.getGameState() == GameState::LOST)
        {

            window.setSize(sf::Vector2u(board.getWidth() * w, board.getHeight() * w));
            sf::View view(sf::FloatRect(0, 0, board.getWidth() * w, board.getHeight() * w));
            window.setView(view);
            boardView.display();
        }

        window.display();
    }
}