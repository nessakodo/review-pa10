#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
protected:
    std::string title;

public:
    Book(const std::string& title);
    virtual ~Book();

    virtual std::string getBookSizeRepresentation() const = 0;
    virtual std::string toString() const = 0;
};

#endif // BOOK_H
