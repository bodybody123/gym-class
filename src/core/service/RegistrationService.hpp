#ifndef REGISTRATIONSERVICE_HPP
#define REGISTRATIONSERVICE_HPP

#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include "../models/ClassSession.hpp"

bool hasRelation(
    Registration* registrationHead, 
    const string& attendeeId, 
    const string& classSessionId
);

void deregisterAttendee(Registration *&registrationHead, Attendee *attendee, ClassSession *classSession);
void deleteRegistrationsByAttendee(Registration*& head, Attendee* attendee);\

#endif