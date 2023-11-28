#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "Book.h"

class PrintedBook : public Book {
private:
    int numPages;

public:
    PrintedBook(const std::string& title, int pages);
    ~PrintedBook();

    int getNumPages() const;
    virtual std::string getBookSizeRepresentation() const override;
    virtual std::string toString() const override;
};

#endif // PRINTEDBOOK_H
