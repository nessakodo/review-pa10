#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Patron; // Forward declaration

class Book {
private:
    std::string title;
    Patron* currentPatron;
    bool checkedOut;

public:
    Book(const std::string& title);
    virtual ~Book();

    std::string getTitle() const;
    void setTitle(const std::string& title);

    Patron* getCurrentPatron() const;
    void checkOut(Patron* aPatron);
    void returnBook();
    bool isCheckedOut() const;

    virtual std::string toString() final;
    virtual std::string getBookSizeRepresentation() const = 0;
};

#endif // BOOK_H
