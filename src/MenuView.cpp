#include "MenuView.h"
#include <iostream>
#include <SFML/Graphics.hpp>

MenuView::MenuView(Menu &menu, sf::RenderWindow &window) : menu(menu), window(window)
{
}

void MenuView::displayBoardSizeInput()
{
    sf::String widthInput;
    sf::String heightInput;

    sf::Text widthValue;
    sf::Text heightValue;
    sf::Text widthText;
    sf::Text heightText;

    sf::Font font;
    font.loadFromFile("./assets/font.ttf");

    widthText.setFont(font);
    widthText.setString("Width: ");
    widthText.setCharacterSize(24);
    widthText.setFillColor(sf::Color::White);
    widthText.setStyle(sf::Text::Bold);
    widthText.setOrigin(widthText.getLocalBounds().width / 2, widthText.getLocalBounds().height / 2);
    widthText.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 100);

    heightText.setFont(font);
    heightText.setString("Height: ");
    heightText.setCharacterSize(24);
    heightText.setFillColor(sf::Color::White);
    heightText.setStyle(sf::Text::Bold);
    heightText.setOrigin(heightText.getLocalBounds().width / 2, heightText.getLocalBounds().height / 2);
    heightText.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 50);

    widthValue.setFont(font);
    widthValue.setString(std::to_string(menu.getBoardWidth()));
    widthValue.setCharacterSize(24);
    widthValue.setFillColor(sf::Color::White);
    widthValue.setStyle(sf::Text::Bold);
    widthValue.setOrigin(widthValue.getLocalBounds().width / 2, widthValue.getLocalBounds().height / 2);
    widthValue.setPosition(window.getSize().x / 2 + 100, window.getSize().y / 2 - 100);

    heightValue.setFont(font);
    heightValue.setString(std::to_string(menu.getBoardHeight()));
    heightValue.setCharacterSize(24);
    heightValue.setFillColor(sf::Color::White);
    heightValue.setStyle(sf::Text::Bold);
    heightValue.setOrigin(heightValue.getLocalBounds().width / 2, heightValue.getLocalBounds().height / 2);
    heightValue.setPosition(window.getSize().x / 2 + 100, window.getSize().y / 2 - 50);

    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int x = pos.x;
    int y = pos.y;

    if (x > window.getSize().x / 2 + 100 - widthValue.getLocalBounds().width / 2 && x < window.getSize().x / 2 + 100 + widthValue.getLocalBounds().width / 2 && y > window.getSize().y / 2 - 100 - widthValue.getLocalBounds().height / 2 && y < window.getSize().y / 2 - 100 + widthValue.getLocalBounds().height / 2)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            menu.setSelectedBoardSizeType(SelectedBoardSizeType::WIDTH);
            widthValue.setFillColor(sf::Color::Red);
        }
    }

    if (x > window.getSize().x / 2 + 100 - heightValue.getLocalBounds().width / 2 && x < window.getSize().x / 2 + 100 + heightValue.getLocalBounds().width / 2 && y > window.getSize().y / 2 - 50 - heightValue.getLocalBounds().height / 2 && y < window.getSize().y / 2 - 50 + heightValue.getLocalBounds().height / 2)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            menu.setSelectedBoardSizeType(SelectedBoardSizeType::HEIGHT);
        }
    }

    switch (menu.getSelectedBoardSizeType())
    {
    case SelectedBoardSizeType::HEIGHT:
        heightValue.setFillColor(sf::Color::Red);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (menu.getBoardHeight() > 51)
            {
                break;
            }

            menu.setBoardHeight(menu.getBoardHeight() + 1);
            heightValue.setString(std::to_string(menu.getBoardHeight()));
            sf::sleep(sf::milliseconds(200));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (menu.getBoardHeight() < 11)
            {
                break;
            }

            menu.setBoardHeight(menu.getBoardHeight() - 1);
            heightValue.setString(std::to_string(menu.getBoardHeight()));
            sf::sleep(sf::milliseconds(200));
        }

        break;
    case SelectedBoardSizeType::WIDTH:
        widthValue.setFillColor(sf::Color::Red);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (menu.getBoardWidth() > 51)
            {
                break;
            }

            menu.setBoardWidth(menu.getBoardWidth() + 1);
            widthValue.setString(std::to_string(menu.getBoardWidth()));
            sf::sleep(sf::milliseconds(200));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if (menu.getBoardWidth() < 11)
            {
                break;
            }

            menu.setBoardWidth(menu.getBoardWidth() - 1);
            widthValue.setString(std::to_string(menu.getBoardWidth()));
            sf::sleep(sf::milliseconds(200));
        }
        break;
    }

    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128)
            {
                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;

                switch (menu.getSelectedBoardSizeType())
                {
                case SelectedBoardSizeType::HEIGHT:
                    heightInput += static_cast<char>(event.text.unicode);

                    menu.setBoardHeight(int(event.text.unicode));
                    heightValue.setString(heightInput);
                    break;
                case SelectedBoardSizeType::WIDTH:
                    widthInput += static_cast<char>(event.text.unicode);

                    menu.setBoardWidth(int(event.text.unicode));
                    widthValue.setString(widthInput);
                    break;
                }
            }
        }
    }

    window.draw(widthText);
    window.draw(heightText);
    window.draw(widthValue);
    window.draw(heightValue);
}

void MenuView::displayPlayButton()
{
    sf::RectangleShape button(sf::Vector2f(300, 50));
    button.setPosition(window.getSize().x / 2 - button.getSize().x / 2, window.getSize().y / 2 + 150);
    button.setFillColor(sf::Color::Transparent);
    button.setOutlineThickness(2);

    sf::Font font;
    font.loadFromFile("./assets/font.ttf");

    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString("PLAY");
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = buttonText.getLocalBounds();
    buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
                         textRect.top + textRect.height / 2.0f);
    buttonText.setPosition(button.getPosition().x + button.getSize().x / 2.0f,
                           button.getPosition().y + button.getSize().y / 2.0f);

    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int x = pos.x;
    int y = pos.y;

    if (x > button.getPosition().x && x < button.getPosition().x + button.getSize().x && y > button.getPosition().y && y < button.getPosition().y + button.getSize().y)
    {
        button.setFillColor(sf::Color::Red);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            menu.setPressedPlayButton(true);
        }
    }

    window.draw(button);
    window.draw(buttonText);
}

void MenuView::display()
{
    window.clear();
    sf::Vector2i pos = sf::Mouse::getPosition(window);
    int x = pos.x;
    int y = pos.y;

    sf::Event event;
    sf::String playerInput;
    sf::Text playerText;

    sf::Font font;
    font.loadFromFile("./assets/font.ttf");

    displayBoardSizeInput();

    for (int i = 0; i < menu.getOptions().size(); i++)
    {
        sf::Font font;
        font.loadFromFile("./assets/font.ttf");

        sf::Text text;
        text.setFont(font);
        text.setString(menu.getOptions()[i]);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setStyle(sf::Text::Bold);
        text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
        text.setPosition(window.getSize().x / 2, window.getSize().y / 2 + i * 50);

        if (x > window.getSize().x / 2 - text.getLocalBounds().width / 2 && x < window.getSize().x / 2 + text.getLocalBounds().width / 2 && y > window.getSize().y / 2 + i * 50 - text.getLocalBounds().height / 2 && y < window.getSize().y / 2 + i * 50 + text.getLocalBounds().height / 2)
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                text.setFillColor(sf::Color::Red);
                menu.setSelectedOption(i);
            }
        }

        if (menu.getSelectedOption() == i)
        {
            text.setFillColor(sf::Color::Red);
        }

        window.draw(text);

        displayPlayButton();
    }
}
