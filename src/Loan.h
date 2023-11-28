#ifndef LOAN_H
#define LOAN_H

#include "Book.h"
#include "Patron.h"
#include "Date.h"

class Loan {
public:
    Loan(Book* aBook, Patron* patron, const Date& dueDate);
    ~Loan();

    Book* getBook() const;
    Patron* getPatron() const;
    Date getDueDate() const;

private:
    Book* book;
    Patron* patron;
    Date dueDate;
};

#endif // LOAN_H

