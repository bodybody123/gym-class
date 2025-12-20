#ifndef DATEUTILS_HPP
#define DATEUTILS_HPP

#include "../models/Date.hpp"

bool isLeapYear(int year);
bool isValidDate(int d, int m, int y, int h, int min);
Date getValidDateInput();

#endif
