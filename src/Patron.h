
#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include "Book.h"

class Patron {
public:
    Patron(const std::string& name, const std::string& address, const std::string& phoneNumber);
    ~Patron();

    void addCheckedBook(Book* book);
    void removeCheckedBook(Book* book);
    bool isBookCheckedOutByPatron(Book* book) const;

    std::string getName() const;
    std::string getAddress() const;
    std::string getPhoneNumber() const;

    void setName(const std::string& newName);
    void setAddress(const std::string& newAddress);
    void setPhoneNumber(const std::string& newPhoneNumber);

private:
    std::string name;
    std::string address;
    std::string phoneNumber;
    std::vector<Book*> checkedBooks;

};

#endif // PATRON_H
