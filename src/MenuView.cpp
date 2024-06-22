#include "MenuView.h"
#include <iostream>
#include <Color.h>

MenuView::MenuView(Menu &menu) : menu(menu)
{
}

void MenuView::displayInput()
{
    int selectedOption;
reTryOption:

    std::cout << "Enter option: ";
    std::cin >> selectedOption;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << RED << "Invalid input!" << RESET << std::endl;
        goto reTryOption;
    }

    if (selectedOption < 1 || selectedOption > menu.getOptions().size())
    {
        std::cout << RED << "Invalid option!" << RESET << std::endl;
        goto reTryOption;
    }
    menu.setSelectedOption(selectedOption - 1);
}

void MenuView::display()
{
    for (int i = 0; i < menu.getOptions().size() - 1; i++)
    {
        std::cout << " " << i + 1 << ". " << menu.getOptions()[i] << std::endl;
    }
    displayInput();
}