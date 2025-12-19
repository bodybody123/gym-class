#ifndef CLASSSESSIONSERVICE_HPP
#define CLASSSESSIONSERVICE_HPP

#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"

void attendingClassSession(ClassSession *classSession, Registration* &registrationHead, Attendee *attendee);
void getAllClassAndAttendees(ClassSession *classSessionHead, Registration *registrationHead);
void getClassSessionDetailById(ClassSession *classSessionHead, Registration *registrationHead, const string& id);
void countClassSessionAttendees(ClassSession *classSessionHead, Registration *registrationHead);
int countClassSessionsWithNoAttendees(ClassSession *classSessionHead, Registration *registrationHead);
void getAllAttendingClass(Registration *registrationHead, Attendee *attendee);
void getAllAvailableToAttendClass(ClassSession *classSessionHead, Registration *registrationHead, Attendee *attendee);

#endif