#include <iostream>
#include <string>
#include "Date.hpp"

std::string getDate(Date date)
{
    return std::to_string(date.day) + "-" + 
    std::to_string(date.month) + "-" + 
    std::to_string(date.year);
}

std::string getDateTime(Date date)
{
    return std::to_string(date.day) + "-" + 
    std::to_string(date.month) + "-" + 
    std::to_string(date.year) + " " + 
    std::to_string(date.hour) + ":" + 
    std::to_string(date.minute) + ":" + 
    std::to_string(date.second);
}

void setDate(Date &date, int day, int month, int year, int hour, int minute, int second)
{
    date.day = day;
    date.month = month;
    date.year = year;
    date.hour = hour;
    date.minute = minute;
    date.second = second;
}
