#ifndef EBOOK_H
#define EBOOK_H

#include "Book.h"

class EBook : public Book {
private:
    int sizeCharacters;
    int charsPerPage;

public:
    EBook(const std::string& title, int totalCharacters, int charactersPerPage);
    ~EBook();

    int getTotalCharacters() const;
    int getCharsPerPage() const;
    virtual std::string getBookSizeRepresentation() const override;
    virtual std::string toString() const override;
};

#endif // EBOOK_H
