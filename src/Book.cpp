#include "Book.h"
#include "Patron.h"

Book::Book(const std::string &title) : title(title), checkedOutBy(nullptr) {}

Book::~Book() {}

std::string Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string &title) {
    this->title = title;
}

Patron* Book::getCurrentPatron() {
    return checkedOutBy;
}

void Book::checkOut(Patron* aPatron) {
    checkedOutBy = aPatron;
}

void Book::returnBook() {
    checkedOutBy = nullptr;
}

bool Book::isCheckedOut() const {
    return checkedOutBy != nullptr;
}


std::string Book::toString() const {
    return "'" + getTitle() + "' has " + getBookSizeRepresentation();
}