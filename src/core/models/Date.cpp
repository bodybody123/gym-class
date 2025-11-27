#include <iostream>
#include "Date.hpp"

void printDate(Date date)
{
    std::cout << "%02d-%02d-%04d", date.day, date.month, date.year;
}

void setDate(Date &date, int day, int month, int year)
{
    date.day = day;
    date.month = month;
    date.year = year;
}