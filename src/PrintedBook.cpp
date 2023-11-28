#include "PrintedBook.h"

PrintedBook::PrintedBook(const std::string& title, int pages)
    : Book(title), numPages(pages) {}

PrintedBook::~PrintedBook() {}

int PrintedBook::getNumPages() const {
    return numPages;
}

std::string PrintedBook::getBookSizeRepresentation() const {
    return "has " + std::to_string(numPages) + " pages.";
}

std::string PrintedBook::toString() const {
    return "Printed Book: '" + getTitle() + "'";
}