#include "Patron.h"

Patron::Patron(const std::string& name, const std::string& address, const std::string& phoneNumber)
    : name(name), address(address), phoneNumber(phoneNumber) {}

Patron::~Patron() {
}

std::string Patron::getName() const {
    return name;
}

std::string Patron::getAddress() const {
    return address;
}

std::string Patron::getPhoneNumber() const {
    return phoneNumber;
}

void Patron::setName(const std::string& newName) {
    name = newName;
}

void Patron::setAddress(const std::string& newAddress) {
    address = newAddress;
}

void Patron::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Patron::addCheckedBook(Book* aBook) {
    checkedBooks.push_back(aBook);
}

void Patron::removeCheckedBook(Book* aBook) {
    for (auto it = checkedBooks.begin(); it != checkedBooks.end(); ++it) {
        if (*it == aBook) {
            checkedBooks.erase(it);
            break;
        }
    }
}
bool Patron::isBookCheckedOutByPatron(Book* aBook) const {
    for (auto& book : checkedBooks) {
        if (book == aBook) {
            return true;
        }
    }
    return false;
}
