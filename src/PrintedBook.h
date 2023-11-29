// PrintedBook.h
#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "Book.h"

class PrintedBook : public Book {
private:
    int numPages;

public:
    PrintedBook(const std::string& title, int numPages);
    ~PrintedBook();

    int getNumPages() const;
    virtual std::string toString() const override;
    virtual std::string getBookSizeRepresentation() const override;
    
};

#endif // PRINTEDBOOK_H
