// EBook.h
#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook : public Book {
private:
    int sizeCharacters;
    int charsPerPage;

public:
    EBook(const std::string& title, int sizeCharacters, int charsPerPage);
    ~EBook();

    int getSizeCharacters() const;
    int getCharsPerPage() const;
    virtual std::string getBookSizeRepresentation() const override;
};

#endif // EBOOK_H
