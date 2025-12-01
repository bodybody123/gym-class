#ifndef PRESENCE_HPP
#define PRESENCE_HPP

#include <string>
#include "Date.hpp"
#include "Attendee.hpp"
#include "ClassSession.hpp"

using namespace std;

enum class PresenceStatus {
    Present,
    Absent,
    Excused
};

// ? Relation
struct Presence{
    Date registration_date;
    PresenceStatus status;
    Presence* next;
    Attendee* attendee;
    ClassSession* class_session;
};

#endif