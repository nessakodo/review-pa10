#ifndef MENU_H
#define MENU_H
#include "Library.h"
#include <iostream>
#include <limits>

class Menu {
public:
    Menu(Library& library);

    void displayMainMenu(); // Function to display the main menu
    void addPatron(); // Function to add a patron
    void addBook(); // Function to add a book
    void addPrintedBook(); // Function to add a printed book
    void addEBook(); // Function to add an ebook
    void addAudioBook(); // Function to add an audiobook
    void searchPatron(); // Function to search for a patron
    void searchBook(); // Function to search for a book
    void checkOutBook(); // Function to check out a book
    void returnBook(); // Function to return a book
    void bookMenu(); // Function to open book menu
    void exitMenu(); // Function to exit menu

private:
    Library library;
};
#endif // MENU_H
