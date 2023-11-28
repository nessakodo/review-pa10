#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"

class AudioBook : public Book {
private:
    int durationSeconds;

public:
    AudioBook(const std::string& title, int duration);
    ~AudioBook();

    int getDurationSeconds() const;
    virtual std::string getBookSizeRepresentation() const override;
    virtual std::string toString() const override;
};

#endif // AUDIOBOOK_H
