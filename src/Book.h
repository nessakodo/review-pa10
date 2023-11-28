#pragma once

#include <string>

class Patron;

class Book {
protected:
    std::string title;
    Patron* checkedOutBy;

public:
    // Constructors
    Book(const std::string& title);
    virtual ~Book();

    // Member functions
    std::string getTitle() const;
    void setTitle(const std::string& title);
    Patron* getCurrentPatron();
    void checkOut(Patron* aPatron);
    void returnBook();
    bool isCheckedOut() const;

    // Abstract functions
    virtual std::string toString() const = 0;
    virtual std::string getBookSizeRepresentation() const = 0;
};
