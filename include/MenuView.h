#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <string>
#include "../include/Menu.h"

class MenuView
{
private:
    Menu &menu;
    void displayInput();

public:
    MenuView(Menu &menu);
    void display();
};

#endif // MENUVIEW_H