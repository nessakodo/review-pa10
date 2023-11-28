#include "Library.h"
#include "menu.h"

int main() {
    Library library("My Library");
    Menu menu(library);

    menu.displayMainMenu();

    return 0;
}
