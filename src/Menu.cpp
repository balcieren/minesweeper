#include "../include/Menu.h"
#include "Menu.h"

Menu::Menu()
{
    selectedOption = -1;
    options.push_back("HARD");
    options.push_back("NORMAL");
    options.push_back("EASY");

    boardWidth = 10;
    boardHeight = 10;
}

Menu::Menu(std::string options[])
{
    selectedOption = -1;
    for (int i = 0; i < options->length(); i++)
    {
        this->options.push_back(options[i]);
    }

    boardWidth = 10;
    boardHeight = 10;
}

std::vector<std::string> Menu::getOptions() const
{
    return options;
}

int Menu::getBoardWidth() const
{
    return boardWidth;
}

void Menu::setBoardWidth(int width)
{
    this->boardWidth = width;
}

int Menu::getBoardHeight() const
{
    return boardHeight;
}

void Menu::setBoardHeight(int height)
{
    this->boardHeight = height;
}

SelectedBoardSizeType Menu::getSelectedBoardSizeType() const
{
    return selectedBoardSizeType;
}

void Menu::setSelectedBoardSizeType(SelectedBoardSizeType type)
{
    this->selectedBoardSizeType = type;
}

int Menu::getSelectedOption() const
{
    return selectedOption;
}

void Menu::setSelectedOption(int option)
{
    if (option < 0 || option >= options.size())
    {
        return;
    }
    selectedOption = option;
}

bool Menu::getPressedPlayButton()
{
    return pressedPlayButton;
}

void Menu::setPressedPlayButton(bool pressedPlayButton)
{
    this->pressedPlayButton = pressedPlayButton;
}