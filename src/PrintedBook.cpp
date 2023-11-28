// PrintedBook.cpp
#include "PrintedBook.h"

PrintedBook::PrintedBook(const std::string& title, int numPages)
    : Book(title), numPages(numPages) {}

PrintedBook::~PrintedBook() {}

int PrintedBook::getNumPages() const {
    return numPages;
}

std::string PrintedBook::getBookSizeRepresentation() const {
    return "has " + std::to_string(numPages) + " pages.";
}
