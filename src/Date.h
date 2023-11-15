//
// Created by Javier Pastorino on 11/5/22.
//

#ifndef DATE_H
#define DATE_H
#include <iostream>

#include <ctime>


class Date {
public:
    Date();
    Date(int year, int month, int day); // default constructor
    ~Date(); // destructor

    bool isAfter(Date anotherDate) const;
    bool isAfter(int aYear, int aMonth, int aDay) const;

    static int currentYear();
    static int currentMonth();
    static int currentDay();

private:
    int year;
    int month;
    int day;
};


#endif //DATE_H
