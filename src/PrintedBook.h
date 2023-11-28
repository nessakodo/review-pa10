#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include "Book.h"

class PrintedBook : public Book {
private:
    int numPages;

public:
    PrintedBook(const std::string& title, int pages);
    int getNumPages() const;
    std::string getBookSizeRepresentation() const override;
};

#endif // PRINTEDBOOK_H
