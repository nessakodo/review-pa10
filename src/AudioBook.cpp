// AudioBook.cpp
#include "AudioBook.h"

AudioBook::AudioBook(const std::string& title, int durationSeconds)
    : Book(title), durationSeconds(durationSeconds) {}

AudioBook::~AudioBook() {}

int AudioBook::getDurationSeconds() const {
    return durationSeconds;
}

std::string AudioBook::getBookSizeRepresentation() const {
    int hours = durationSeconds / 3600;
    int minutes = (durationSeconds % 3600) / 60;
    int seconds = durationSeconds % 60;

    return " has a duration of " + std::to_string(hours) + ":" +
           std::to_string(minutes) + ":" + std::to_string(seconds) + ".";
}

std::string AudioBook::toString() const {
    return "'" + getTitle() + "'" + getBookSizeRepresentation();
}