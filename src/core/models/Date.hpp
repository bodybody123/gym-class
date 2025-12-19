#ifndef DATE_HPP
#define DATE_HPP

#include <string>

struct Date
{
    int day;
    int month;
    int year;

    int hour;
    int minute;
    int second;
};

std::string getDate(Date date);
std::string getDateTime(Date date);
std::string printDate(Date date);
void setDate(Date& date, int day, int month, int year);
Date getCurrentDateTime();

#endif