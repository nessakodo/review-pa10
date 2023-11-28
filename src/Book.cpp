#include "Book.h"

Book::Book(const std::string& title) : title(title), checkedOutBy(nullptr) {}


Book::~Book() {
    checkedOutBy = nullptr;
}

std::string Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

Patron* Book::getCurrentPatron() {
    return checkedOutBy;
}

void Book::checkOut(Patron* aPatron) {
    checkedOutBy = aPatron;
}

bool Book::isCheckedOut() const {
    return checkedOutBy != nullptr;
}

void Book::returnBook() {
    checkedOutBy = nullptr;
}
