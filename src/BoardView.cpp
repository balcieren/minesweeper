#include "BoardView.h"
#include "Board.h"
#include <iostream>
#include <SFML/Graphics.hpp>

BoardView::BoardView(Board &board, sf::RenderWindow &window) : board(board), window(window) {}

void BoardView::displayWon()
{
    sf::Font font;
    font.loadFromFile("./assets/font.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("You won!");
    text.setCharacterSize(36);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
    text.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    window.draw(text);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        board.setGameState(GameState::MAIN_MENU);
    }

    sf::Text PressEnterText;
    PressEnterText.setFont(font);
    PressEnterText.setString("Press Enter to return to the main menu");
    PressEnterText.setCharacterSize(14);
    PressEnterText.setFillColor(sf::Color::Green);
    PressEnterText.setStyle(sf::Text::Bold);
    PressEnterText.setOrigin(PressEnterText.getLocalBounds().width / 2, PressEnterText.getLocalBounds().height / 2);
    PressEnterText.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 25);
    window.draw(PressEnterText);
}

void BoardView::displayLost()
{

    sf::Font font;
    font.loadFromFile("./assets/font.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("You lost!");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
    text.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    window.draw(text);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        board.setGameState(GameState::MAIN_MENU);
    }

    sf::Text PressEnterText;
    PressEnterText.setFont(font);
    PressEnterText.setString("Press Enter to return to the main menu");
    PressEnterText.setCharacterSize(14);
    PressEnterText.setFillColor(sf::Color::Red);
    PressEnterText.setStyle(sf::Text::Bold);
    PressEnterText.setOrigin(PressEnterText.getLocalBounds().width / 2, PressEnterText.getLocalBounds().height / 2);
    PressEnterText.setPosition(window.getSize().x / 2, window.getSize().y / 2 + 25);
    window.draw(PressEnterText);
}

void BoardView::displayBoard()
{
    int w = 32;

    sf::Texture t;
    t.loadFromFile("./assets/tiles.png");
    t.setSmooth(true);
    sf::Sprite s(t);

    for (int y = 0; y < board.getHeight(); y++)
    {
        for (int x = 0; x < board.getWidth(); x++)
        {
            char f = board.getFieldInfo(x, y);
            if (f == '*')
            {
                s.setTextureRect(sf::IntRect(9 * w, 0, w, w));
                s.setPosition(x * w, y * w);
            }
            else if (f == ' ')
            {
                s.setTextureRect(sf::IntRect(10 * w, 0, w, w));
                s.setPosition(x * w, y * w);
            }
            else if (f == 'F')
            {
                s.setTextureRect(sf::IntRect(11 * w, 0, w, w));
                s.setPosition(x * w, y * w);
            }
            else
            {
                s.setTextureRect(sf::IntRect(atoi(&f) * w, 0, w, w));
                s.setPosition(x * w, y * w);
            }
            window.draw(s);
        }
    }

    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int x = pos.x / w;
    int y = pos.y / w;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && board.getGameState() == GameState::RUNNING)
    {
        board.revealField(x, y);
        sf::sleep(sf::milliseconds(200));
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && board.getGameState() == GameState::RUNNING)
    {
        board.toggleFlag(x, y);
        sf::sleep(sf::milliseconds(200));
    }
}

void BoardView::display()
{
    displayBoard();

    if (board.getGameState() == GameState::WON)
    {
        displayWon();
    }
    else if (board.getGameState() == GameState::LOST)
    {
        displayLost();
    }
};
