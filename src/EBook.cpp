#include "EBook.h"

EBook::EBook(const std::string& title, int sizeCharacters, int charsPerPage)
    : Book(title), sizeCharacters(sizeCharacters), charsPerPage(charsPerPage) {}

int EBook::getSizeCharacters() const {
    return sizeCharacters;
}

int EBook::getCharsPerPage() const {
    return charsPerPage;
}

std::string EBook::getBookSizeRepresentation() const {
    return "has a size of " + std::to_string(sizeCharacters) + " characters.";
}
