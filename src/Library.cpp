#include "Library.h"
#include "PrintedBook.h"
#include "EBook.h"
#include "AudioBook.h"
#include <iostream>

Library::Library(const std::string& name) : name(name) {}


Library::~Library() {
    for (auto loan : loans) {
        delete loan;
    }
    loans.clear();

    for (auto book : books) {
        delete book;
    }
    books.clear();

    for (auto patron : patrons) {
        delete patron;
    }
    patrons.clear();
}

std::string Library::getName() const {
    return name;
}


std::vector<Book*> Library::getBookList() const {
    return books;
}

std::vector<Patron*> Library::getPatronList() const {
    return patrons;
}

std::vector<Loan*> Library::getLoanList() const {
    return loans;
}

Book* Library::searchBook(const std::string& title) {
    for (auto book : books) {
        if (book->getTitle() == title) {
            return book;
        }
    }
    return nullptr;
}

Patron* Library::searchPatron(const std::string& name) {
    for (auto patron : patrons) {
        if (patron->getName() == name) {
            return patron;
        }
    }
    return nullptr;
}

void Library::addPrintedBook(const std::string& title, int numPages) {
    if (searchBook(title) != nullptr) {
        throw std::invalid_argument("A book with the same title already exists.");
    }
    printedbooks.push_back(new PrintedBook(title, numPages));
    books.push_back(static_cast<Book*>(printedbooks.back())); // Casting to Book pointer
}

void Library::addEBook(const std::string& title, int sizeCharacters, int charsPerPage) {
    if (searchBook(title) != nullptr) {
        throw std::invalid_argument("A book with the same title already exists.");
    }
    ebooks.push_back(new EBook(title, sizeCharacters, charsPerPage));
    books.push_back(static_cast<Book*>(ebooks.back())); // Casting to Book pointer
}

void Library::addAudioBook(const std::string& title, int durationSeconds) {
    if (searchBook(title) != nullptr) {
        throw std::invalid_argument("A book with the same title already exists.");
    }
    audiobooks.push_back(new AudioBook(title, durationSeconds));
    books.push_back(static_cast<Book*>(audiobooks.back())); // Casting to Book pointer
}

void Library::addPatron(const std::string& name, const std::string& address, const std::string& phoneNumber) {
    if (searchPatron(name) != nullptr) {
        throw std::invalid_argument("A patron with the same name already exists.");
    }
    patrons.push_back(new Patron(name, address, phoneNumber));
}

void Library::checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay) {
    if (aBook == nullptr || aPatron == nullptr) {
        throw std::invalid_argument("Book or patron pointer is null.");
    }

    if (!aBook->isCheckedOut()) {
        loans.push_back(new Loan(aBook, aPatron, Date(dueYear, dueMonth, dueDay)));
        aBook->checkOut(aPatron);
    } else {
        throw std::invalid_argument("The book is not available for check out.");
    }
}

void Library::returnBook(Book* aBook, Patron* aPatron) {
    if (aBook == nullptr || aPatron == nullptr) {
        throw std::invalid_argument("Book or patron pointer is null.");
    }

    bool foundLoan = false;
    for (auto it = loans.begin(); it != loans.end(); ++it) {
        Loan* loan = *it;
        if (loan->getBook() == aBook && loan->getPatron() == aPatron) {
            delete loan;
            loans.erase(it);
            foundLoan = true;
            break;
        }
    }

    if (!foundLoan) {
        throw std::invalid_argument("Loan could not be found.");
    }

    aBook->returnBook();
    aPatron->removeCheckedBook(aBook);
}
