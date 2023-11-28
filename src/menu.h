#ifndef MENU_H
#define MENU_H

#include "Library.h"

class Menu {
private:
    Library& library;

public:
    Menu(Library& lib);

    void displayMainMenu();
    void displayAddBookMenu();
};

#endif // MENU_H
