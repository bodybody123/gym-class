#ifndef ATTENNDEELIST_HPP
#define ATTENNDEELIST_HPP

#include "../models/Attendee.hpp"

void insertAttendee(Attendee* head, Attendee *attendee);
void deleteAttendee(Attendee* head, const string& id);
void printAttendeeDetails(Attendee *attendee);
void getAllAttendees(Attendee* head);
Attendee* getAttendeeById(Attendee* head, string id);
void updateAttendee(Attendee* head, Attendee* attendee);

#endif