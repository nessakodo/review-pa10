#include "Book.h"
#include "Patron.h"

Book::Book(const std::string& title) : title(title), currentPatron(nullptr), checkedOut(false) {}

Book::~Book() {}

std::string Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

Patron* Book::getCurrentPatron() const {
    return currentPatron;
}

void Book::checkOut(Patron* aPatron) {
    currentPatron = aPatron;
    checkedOut = true;
}

void Book::returnBook() {
    currentPatron = nullptr;
    checkedOut = false;
}

bool Book::isCheckedOut() const {
    return checkedOut;
}

std::string Book::toString() {
    return "Book: '" + title + "'";
}
