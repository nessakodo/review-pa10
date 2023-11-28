#ifndef MENU_H
#define MENU_H

#include "Library.h" // Assuming Library class is included in Library.h

class Menu {
private:
    Library& library; // Store a reference to the Library object

public:
    Menu(Library& lib);
    void displayMainMenu();
    void displayAddBookMenu();
};

#endif // MENU_H
