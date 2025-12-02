#ifndef CLASSSESSION_HPP
#define CLASSSESSION_HPP

#include <string>
#include "Date.hpp"

using namespace std;

// ? Parent
struct ClassSession {
    string id;
    string name;
    Date schedule;
    int capacity;
    int fee;
    int attendee_count;
    string coach;
    ClassSession* next;
};

struct ClassSessionAttendees {
    ClassSession* class_session;
    int attendee_count;
    ClassSessionAttendees* next;
    Attendee* attendees;
};

#endif