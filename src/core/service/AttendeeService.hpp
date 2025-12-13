#ifndef ATTENDEESERVICE_HPP
#define ATTENDEESERVICE_HPP

#include "../models/Attendee.hpp"
#include "../models/Registration.hpp"

void registerAttendee(Attendee *attendeeHead, Attendee *newAttendee);
void getAllAttendeesAndClassSessions(Attendee *attendeeHead, Registration *registrationHead);
void countAttendeesClassSessions(Attendee *attendeeHead, Registration *registrationHead);
int countAttendeesWithNoClassSessions(Attendee *attendeeHead, Registration *registrationHead);

#endif