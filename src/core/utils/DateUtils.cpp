#include <iostream>
#include <string>
#include <limits>
#include <ios>
#include "DateUtils.hpp"
#include "../models/Date.hpp"

using namespace std;

// Helper: Check for leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Helper: Validate Date Rules
bool isValidDate(int d, int m, int y, int h, int min) {
    // Basic range checks
    if (y < 2000 || y > 2100) return false; // Adjust year range as needed
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > 31) return false;
    if (h < 0 || h > 23) return false;
    if (min < 0 || min > 59) return false;

    // Days in month logic
    if (m == 2) {
        if (isLeapYear(y)) {
            if (d > 29) return false;
        } else {
            if (d > 28) return false;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        if (d > 30) return false;
    }

    return true;
}

// Helper: Loop until valid input received
Date getValidDateInput() {
    Date d;
    while (true) {
        cout << "Masukkan tanggal (DD MM YYYY HH MM): ";
        // Check if input format is integers
        if (cin >> d.day >> d.month >> d.year >> d.hour >> d.minute) {
            d.second = 0; // Default seconds
            
            if (isValidDate(d.day, d.month, d.year, d.hour, d.minute)) {
                return d; // Success!
            } else {
                cout << ">> Error: Tanggal atau waktu tidak benar. Coba lagi.\n";
            }
        } else {
            cout << ">> Error: Format salah masukkan. Masukkan angka.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }
    }
}