#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu
{
private:
    std::vector<std::string> options;
    int selectedOption;

public:
    Menu(std::string options[]);
    std::vector<std::string> getOptions() const;
    int getSelectedOption() const;
    void setSelectedOption(int option);
};

#endif // MENU_H
