#ifndef ATTENNDEELIST_HPP
#define ATTENNDEELIST_HPP

#include "../models/Attendee.hpp"

void insertAttendee(Attendee* head, Attendee *attendee);
void deleteAttendee(Attendee* head, const string& id);

#endif