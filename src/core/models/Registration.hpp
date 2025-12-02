#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include <string>
#include "Date.hpp"
#include "Attendee.hpp"
#include "ClassSession.hpp"

using namespace std;

// ? Relation
struct Registration {
    Date registration_date;
    Registration* next;
    Attendee* attendee;
    ClassSession* class_session;
};

#endif