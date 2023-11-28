#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"

class AudioBook : public Book {
private:
    int durationSeconds;

public:
    AudioBook(const std::string& title, int durationSeconds);
    int getDurationSeconds() const;
    std::string getBookSizeRepresentation() const override;
};

#endif // AUDIOBOOK_H
