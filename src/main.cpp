#include "menu.h"
#include "Library.h" // Include the necessary library header

int main() {
    Library library; // Assuming Library class instance is created here

    Menu menu(library);

    menu.displayMainMenu();

    return 0;
}
