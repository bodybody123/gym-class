#ifndef DATE_HPP
#define DATE_HPP

struct Date
{
    int day;
    int month;
    int year;

    int hour;
    int minute;
    int second;
};

void printDate(Date date);
void setDate(Date& date, int day, int month, int year);

#endif