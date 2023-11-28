#include "AudioBook.h"
#include <iomanip>
#include <sstream>

AudioBook::AudioBook(const std::string& title, int duration)
    : Book(title), durationSeconds(duration) {}

AudioBook::~AudioBook() {}

int AudioBook::getDurationSeconds() const {
    return durationSeconds;
}

std::string AudioBook::getBookSizeRepresentation() const {
    int minutes = durationSeconds / 60;
    int seconds = durationSeconds % 60;
    std::stringstream ss;
    ss << "has a duration of " << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << seconds;
    return ss.str();
}

std::string AudioBook::toString() const {
    return "AudioBook: '" + title + "'";
}
