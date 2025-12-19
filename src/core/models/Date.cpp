#include <iostream>
#include <string>
#include "Date.hpp"
#include <chrono>
#include <ctime>

std::string twoDigit(int value)
{
    if (value < 10)
        return "0" + std::to_string(value);
    return std::to_string(value);
}

std::string getDate(Date date)
{
    return twoDigit(date.day) + "-" +
           twoDigit(date.month) + "-" +
           std::to_string(date.year);
}

std::string getDateTime(Date date)
{
    return twoDigit(date.day) + "-" +
           twoDigit(date.month) + "-" +
           std::to_string(date.year) + " " +
           twoDigit(date.hour) + ":" +
           twoDigit(date.minute) + ":" +
           twoDigit(date.second);
}

Date getCurrentDateTime()
{
    using namespace std::chrono;

    auto now = system_clock::now();
    std::time_t t = system_clock::to_time_t(now);

    std::tm localTime{};

#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&localTime, &t);   // Windows
#else
    localtime_r(&t, &localTime);   // Linux / macOS
#endif

    Date d;
    d.day    = localTime.tm_mday;
    d.month  = localTime.tm_mon + 1;
    d.year   = localTime.tm_year + 1900;
    d.hour   = localTime.tm_hour;
    d.minute = localTime.tm_min;
    d.second = localTime.tm_sec;

    return d;
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
