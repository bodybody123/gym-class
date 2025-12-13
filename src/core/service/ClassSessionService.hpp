#ifndef CLASSSESSIONSERVICE_HPP
#define CLASSSESSIONSERVICE_HPP

#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"

void getAllClassAndAttendees(ClassSession *classSessionHead, Registration *registrationHead);
void getClassSessionDetailById(ClassSession *classSessionHead, Registration *registrationHead, const string& id);
void countClassSessionAttendees(ClassSession *classSessionHead, Registration *registrationHead);
int countClassSessionsWithNoAttendees(ClassSession *classSessionHead, Registration *registrationHead);

#endif