#ifndef BOOK_H
#define BOOK_H

#include <string>

class Patron;

class Book {
private:
    std::string title;
    Patron* checkedOutBy;

public:
    Book(const std::string& title);
    virtual ~Book();

    std::string getTitle() const;
    void setTitle(const std::string& title);
    Patron* getCurrentPatron();
    void checkOut(Patron* aPatron);
    void returnBook();
    bool isCheckedOut() const;

    virtual std::string toString() const;
    virtual std::string getBookSizeRepresentation() const = 0;
};

#endif // BOOK_H
