#include "menu.h"
#include "Library.h"
#include <iostream>
#include <limits>

Menu::Menu(Library& library) : library(library) {}

void Menu::displayMainMenu() {
    int choice = 0;

    do {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "            Main Menu" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "1. Add Patron" << std::endl;
        std::cout << "2. Add Book" << std::endl;
        std::cout << "3. Search for Patron" << std::endl;
        std::cout << "4. Search for Book" << std::endl;
        std::cout << "5. Check Out Book" << std::endl;
        std::cout << "6. Return Book" << std::endl;
        std::cout << "99. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear(); // Clearing error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        switch (choice) {
            case 1:
                addPatron();
                break;

            case 2:
                addBook();
                break;

            case 3:
                searchPatron();
                break;

            case 4:
                searchBook();
                break;

            case 5:
                checkOutBook();
                break;

            case 6:
                returnBook();
                break;

            case 99:
                exitMenu();
                break;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 99);
}

void Menu::addPatron() {
    std::string name, address, phoneNumber;
    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter Patron's name: ";
    std::getline(std::cin, name);
    std::cout << "Enter Patron's address: ";
    std::getline(std::cin, address);
    std::cout << "Enter Patron's phone number: ";
    std::getline(std::cin, phoneNumber);
    library.addPatron(name, address, phoneNumber);
    std::cout << "Patron added successfully!" << std::endl;
}

void Menu::addBook() {
    int bookChoice = 0;

    do {
        std::cout << "---------------------------------" << std::endl;
        std::cout << "          Add Book Menu" << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "1. Add Printed Book" << std::endl;
        std::cout << "2. Add Ebook" << std::endl;
        std::cout << "3. Add Audiobook" << std::endl;
        std::cout << "4. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";

        if (!(std::cin >> bookChoice)) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (bookChoice) {
            case 1:
                addPrintedBook();
                break;

            case 2:
                addEBook();
                break;

            case 3:
                addAudioBook();
                break;

            case 4:
                std::cout << "Returning to Main Menu." << std::endl;
                return; // Return to main menu

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (bookChoice != 4);
}


void Menu::addPrintedBook() {
    std::string title, author;
    int numPages;
    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter Printed Book's title: ";
    std::getline(std::cin, title);
    std::cout << "Enter the number of pages: ";
    if (!(std::cin >> numPages)) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    library.addPrintedBook(title, numPages);
    std::cout << "Printed Book added successfully!" << std::endl;
}

void Menu::addEBook() {
    std::string title;
    int numPages, sizeMB;
    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter eBook's title: ";
    std::getline(std::cin, title);
    std::cout << "Enter the number of pages: ";
    if (!(std::cin >> numPages)) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cout << "Enter the size in MB: ";
    if (!(std::cin >> sizeMB)) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    library.addEBook(title, numPages, sizeMB); 
    std::cout << "EBook added successfully!" << std::endl;
}

void Menu::addAudioBook() {
    std::string title;
    int durationMinutes;
    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter Audiobook's title: ";
    std::getline(std::cin, title);
    std::cout << "Enter the duration in minutes: ";
    if (!(std::cin >> durationMinutes)) {
        std::cout << "Invalid input. Please enter a valid number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    library.addAudioBook(title, durationMinutes); 
    std::cout << "AudioBook added successfully!" << std::endl;
}

void Menu::searchPatron() {
    std::string name;
    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter Patron's name to search: ";
    std::getline(std::cin, name);
    Patron* foundPatron = library.searchPatron(name); 
    if (foundPatron != nullptr) {
        std::cout << "Patron Found:" << std::endl;
        std::cout << "Name: " << foundPatron->getName() << std::endl;
        std::cout << "Address: " << foundPatron->getAddress() << std::endl;
        std::cout << "Phone Number: " << foundPatron->getPhoneNumber() << std::endl;
    } else {
        std::cout << "Patron not found." << std::endl;
    }
}

void Menu::searchBook() {
    std::string title;
    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter book's title to search: ";
    std::getline(std::cin, title);
    Book* foundBook = library.searchBook(title); 
    if (foundBook != nullptr) {
        std::cout << "Book Found:" << std::endl;
        std::cout << "Title: " << foundBook->getTitle() << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }
}

void Menu::checkOutBook() {
    std::string bookTitle, patronName;
    int dueYear, dueMonth, dueDay;

    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter book's title to check out: ";
    std::getline(std::cin, bookTitle);
    std::cout << "Enter patron's name: ";
    std::getline(std::cin, patronName);
    std::cout << "Enter due date (year month day): ";

    if (!(std::cin >> dueYear >> dueMonth >> dueDay)) {
        std::cout << "Invalid input. Please enter valid numbers for the due date." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    // Get the Book and Patron objects from the Library based on their names
    Book* book = library.searchBook(bookTitle);
    Patron* patron = library.searchPatron(patronName);

    if (!book || !patron) {
        std::cout << "Book or patron not found." << std::endl;
        return;
    }

    // Pass the due date as separate integers
    library.checkOutBook(book, patron, dueYear, dueMonth, dueDay);
}

void Menu::returnBook() {
    std::string bookTitle, patronName;
    std::cin.ignore(); // Ignore previous input
    std::cout << "Enter book's title to return: ";
    std::getline(std::cin, bookTitle);
    std::cout << "Enter patron's name: ";
    std::getline(std::cin, patronName);

    Book* book = library.searchBook(bookTitle);
    Patron* patron = library.searchPatron(patronName);

    if (!book || !patron) {
        std::cout << "Book or patron not found." << std::endl;
        return;
    }

    library.returnBook(book, patron);
}


void Menu::exitMenu() {
    std::cout << "Are you sure you want to exit? (y/n): ";
    char exitChoice;
    std::cin >> exitChoice;
    if (exitChoice == 'y' || exitChoice == 'Y') {
        std::cout << "Goodbye!" << std::endl;
        exit(0);
    } else if (exitChoice == 'n' || exitChoice == 'N') {
        displayMainMenu();
        return;
    } else {
        std::cout << "Invalid choice. ";
        std::cout << "Returning to main menu." << std::endl;
        displayMainMenu();
        return;
    }
}
