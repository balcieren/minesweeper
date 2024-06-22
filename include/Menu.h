#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

enum SelectedBoardSizeType
{
    HEIGHT,
    WIDTH
};

class Menu
{
private:
    std::vector<std::string> options;
    int selectedOption;
    int boardWidth, boardHeight;
    SelectedBoardSizeType selectedBoardSizeType;
    bool pressedPlayButton = false;

public:
    Menu();
    Menu(std::string options[]);
    std::vector<std::string> getOptions() const;
    int getSelectedOption() const;
    void setSelectedOption(int option);
    int getBoardWidth() const;
    void setBoardWidth(int width);
    int getBoardHeight() const;
    void setBoardHeight(int height);
    SelectedBoardSizeType getSelectedBoardSizeType() const;
    void setSelectedBoardSizeType(SelectedBoardSizeType type);
    bool getPressedPlayButton();
    void setPressedPlayButton(bool pressedPlayButton);
};

#endif // MENU_H
