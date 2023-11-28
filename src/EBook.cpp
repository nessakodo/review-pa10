#include "EBook.h"
#include <cmath>

EBook::EBook(const std::string& title, int totalCharacters, int charactersPerPage)
    : Book(title), sizeCharacters(totalCharacters), charsPerPage(charactersPerPage) {}

EBook::~EBook() {}

int EBook::getTotalCharacters() const {
    return sizeCharacters;
}

int EBook::getCharsPerPage() const {
    return charsPerPage;
}

std::string EBook::getBookSizeRepresentation() const {
    int numPages = static_cast<int>(ceil(static_cast<double>(sizeCharacters) / charsPerPage));
    return "has " + std::to_string(numPages) + " digital pages.";
}

std::string EBook::toString() const {
    return "EBook: '" + title + "'";
}
