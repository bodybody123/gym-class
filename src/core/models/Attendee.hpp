#ifndef ATTENDEE_HPP
#define ATTENDEE_HPP

#include <string>

using namespace std;

// ? Child
struct AttendeeData {
    string id;
    string name;
};

struct Attendee {
    AttendeeData data;
    Attendee* next;
};

#endif