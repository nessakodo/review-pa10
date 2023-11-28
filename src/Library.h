#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include "Date.h"
#include "Book.h"
#include "Patron.h"
#include "Loan.h"
#include "PrintedBook.h"
#include "EBook.h"
#include "AudioBook.h"

class Library {
public:
    Library(const std::string& name);
    ~Library();

    std::string getName() const;
    std::vector<Book*> getBookList() const;
    std::vector<Patron*> getPatronList() const;
    std::vector<Loan*> getLoanList() const;

    Book* searchBook(const std::string& title);
    Patron* searchPatron(const std::string& name);

    void addPrintedBook(const std::string& title, int numPages);
    void addEBook(const std::string& title, int sizeCharacters, int charsPerPage);
    void addAudioBook(const std::string& title, int durationSeconds);
    void addPatron(const std::string& name, const std::string& address, const std::string& phoneNumber);

    void checkOutBook(Book* aBook, Patron* aPatron, int dueYear, int dueMonth, int dueDay);
    void returnBook(Book* aBook, Patron* aPatron);

private:
    std::string name;
    std::vector<Book*> books;
    std::vector<Patron*> patrons;
    std::vector<Loan*> loans;
    std::vector<PrintedBook*> printedbooks;
    std::vector<EBook*> ebooks;
    std::vector<AudioBook*> audiobooks;
};

#endif // LIBRARY_H
