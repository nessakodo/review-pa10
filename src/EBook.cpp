// EBook.cpp
#include "EBook.h"

EBook::EBook(const std::string& title, int sizeCharacters, int charsPerPage)
    : Book(title), sizeCharacters(sizeCharacters), charsPerPage(charsPerPage) {}

EBook::~EBook() {}

int EBook::getSizeCharacters() const {
    return sizeCharacters;
}

int EBook::getCharsPerPage() const {
    return charsPerPage;
}

std::string EBook::getBookSizeRepresentation() const {
    return "has " + std::to_string(sizeCharacters / charsPerPage) + " digital pages.";
}
