#include "menu.h"
#include "Menu.h"
#include <iostream>
#include <stdexcept>
#include <string>

Menu::Menu(Library& lib) : library(lib) {}

int choice;
void Menu::displayMainMenu() {
    int choice;
    do {
        std::cout << "\n---------------------------------\n";
        std::cout << "            Main Menu\n";
        std::cout << "---------------------------------\n";
        std::cout << "1) Add Patron\n";
        std::cout << "2) Add Book\n";
        std::cout << "3) Search for Patron\n";
        std::cout << "4) Search for Book\n";
        std::cout << "5) Check Out Book\n";
        std::cout << "6) Return Book\n";
        std::cout << "99) EXIT\n";
        std::cout << "---------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;


        switch (choice) {
            case 1: {
                std::string name, address, phoneNumber;
                std::cout << "Enter Patron's name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter Patron's address: ";
                std::getline(std::cin, address);
                std::cout << "Enter Patron's phone number: ";
                std::getline(std::cin, phoneNumber);

                try {
                    library.addPatron(name, address, phoneNumber);
                    std::cout << "Patron added successfully!\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            }
            case 2: {
                Menu::displayAddBookMenu();
                break;
            }
            case 3: {
                std::string patronName;
                std::cout << "Enter Patron's name to search: ";
                std::cin.ignore();
                std::getline(std::cin, patronName);

                Patron* foundPatron = library.searchPatron(patronName);
                if (foundPatron != nullptr) {
                    std::cout << "Patron found!\n";
                    // Display Patron details or perform actions
                } else {
                    std::cout << "Patron not found!\n";
                }
                break;
            }
            case 4: {
                std::string bookTitle;
                std::cout << "Enter Book's title to search: ";
                std::cin.ignore();
                std::getline(std::cin, bookTitle);

                Book* foundBook = library.searchBook(bookTitle);
                if (foundBook != nullptr) {
                    std::cout << "Book found!\n";
                    // Display Book details or perform actions
                } else {
                    std::cout << "Book not found!\n";
                }
                break;
            }
            case 5: {
                std::string bookTitle, patronName;
                int dueYear, dueMonth, dueDay;

                std::cout << "Enter Book's title to check out: ";
                std::cin.ignore();
                std::getline(std::cin, bookTitle);
                Book* checkedOutBook = library.searchBook(bookTitle);

                std::cout << "Enter Patron's name for check-out: ";
                std::getline(std::cin, patronName);
                Patron* patron = library.searchPatron(patronName);

                if (checkedOutBook != nullptr && patron != nullptr) {
                    std::cout << "Enter due date (Year Month Day): ";
                    std::cin >> dueYear >> dueMonth >> dueDay;

                    try {
                        library.checkOutBook(checkedOutBook, patron, dueYear, dueMonth, dueDay);
                        std::cout << "Book checked out successfully!\n";
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                    }
                } else {
                    std::cout << "Book or Patron not found!\n";
                }
                break;
            }
            case 6: {
                std::string bookTitle, patronName;

                std::cout << "Enter Book's title to return: ";
                std::cin.ignore();
                std::getline(std::cin, bookTitle);
                Book* returnedBook = library.searchBook(bookTitle);

                std::cout << "Enter Patron's name for return: ";
                std::getline(std::cin, patronName);
                Patron* patron = library.searchPatron(patronName);

                if (returnedBook != nullptr && patron != nullptr) {
                    try {
                        library.returnBook(returnedBook, patron);
                        std::cout << "Book returned successfully!\n";
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << '\n';
                    }
                } else {
                    std::cout << "Book or Patron not found!\n";
                }
                break;
            }

            case 99: {
                std::cout << "Exiting...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
} while (choice != 99);
}


void Menu::displayAddBookMenu() {
    int choice;
    do {
        std::cout << "\n---------------------------------\n";
        std::cout << "          Add Book Menu\n";
        std::cout << "---------------------------------\n";
        std::cout << "1) Add Printed Book\n";
        std::cout << "2) Add Ebook\n";
        std::cout << "3) Add Audiobook\n";
        std::cout << "---------------------------------\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::string title;
        int numPages, sizeCharacters, charsPerPage, durationSeconds;

        switch (choice) {
            case 1: {
                std::cout << "Enter Printed Book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter number of pages: ";
                std::cin >> numPages;

                try {
                    library.addPrintedBook(title, numPages); // Use the library reference
                    std::cout << "Printed Book added successfully!\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            }
            case 2: {
                std::cout << "Enter Ebook title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter size in characters: ";
                std::cin >> sizeCharacters;
                std::cout << "Enter chars per page: ";
                std::cin >> charsPerPage;

                try {
                    library.addEBook(title, sizeCharacters, charsPerPage); // Using library reference
                    std::cout << "EBook added successfully!\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            }
            case 3: {
                std::cout << "Enter Audiobook title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter duration in seconds: ";
                std::cin >> durationSeconds;

                try {
                    library.addAudioBook(title, durationSeconds); // Using library reference
                    std::cout << "AudioBook added successfully!\n";
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Error: " << e.what() << '\n';
                }
                break;
            }

            default: {
                std::cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (choice != 1 && choice != 2 && choice != 3);
}