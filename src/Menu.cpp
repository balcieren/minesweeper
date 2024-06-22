#include "../include/Menu.h"
#include "Menu.h"

Menu::Menu(std::string options[])
{
    selectedOption = -1;
    for (int i = 0; i < options->length(); i++)
    {
        this->options.push_back(options[i]);
    }
}

std::vector<std::string> Menu::getOptions() const
{
    return options;
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