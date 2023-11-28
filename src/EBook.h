#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook : public Book {
private:
    int sizeCharacters;
    int charsPerPage;

public:
    EBook(const std::string& title, int sizeCharacters, int charsPerPage);
    int getSizeCharacters() const;
    int getCharsPerPage() const;
    std::string getBookSizeRepresentation() const override;
};

#endif // EBOOK_H
