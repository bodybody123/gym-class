#ifndef ATTENDEE_HPP
#define ATTENDEE_HPP

#include <string>

using namespace std;

// ? Child
struct Attendee {
    string id;
    string name;
    string schedule;
    Attendee* next;
};

#endif