#include "menu.h"
#include "Library.h" 

int main() {
    Library library;

    Menu menu(library);

    menu.displayMainMenu();

    return 0;
}
