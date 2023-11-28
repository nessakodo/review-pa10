#include "Loan.h"

Loan::Loan(Book* aBook, Patron* aPatron, const Date& dueDate)
    : book(aBook), patron(aPatron), dueDate(dueDate) {
    // Constructor implementation
}

Loan::~Loan() {
    // Destructor implementation
}

Book* Loan::getBook() const {
    return book;
}

Patron* Loan::getPatron() const {
    return patron;
}

Date Loan::getDueDate() const {
    return dueDate;
}
