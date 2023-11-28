#include "Library.h"
#include "menu.h"

void mainMenu(Library& library); // Forward declaration

int main() {
    Library library("My Library");
    mainMenu(library);

    return 0;
}

void mainMenu(Library& library) {
    Menu menu(library);
    menu.displayMainMenu();
}
