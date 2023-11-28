#include "AudioBook.h"

AudioBook::AudioBook(const std::string& title, int durationSeconds)
    : Book(title), durationSeconds(durationSeconds) {}

int AudioBook::getDurationSeconds() const {
    return durationSeconds;
}

std::string AudioBook::getBookSizeRepresentation() const {
    return "has a duration of " + std::to_string(durationSeconds / 60) + ":" +
           std::to_string(durationSeconds % 60) + ".";
}
