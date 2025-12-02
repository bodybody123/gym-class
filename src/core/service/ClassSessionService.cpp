#include <iostream>
#include "../models/Registration.hpp"
#include "../Lists/RegistrationList.hpp"
#include "ClassSessionService.hpp"
 
void attendingClassSession(
    ClassSession *classSession, 
    Registration *registrationHead, 
    Attendee *attendee
) {
    Registration data = Registration();
    data.registration_date = Date();
    data.attendee = attendee;
    data.class_session = classSession;

    insertRegistration(registrationHead, &data);
}

void getAllClassAndAttendees(
    ClassSession *classSessionHead, 
    Registration *registrationHead
) {
    // ClassSessionAttendees classSessionAttendeesHead = ClassSessionAttendees();
    ClassSession *currentClassSession = classSessionHead;
    // ClassSessionAttendees *currentClassSessionAttendees = &classSessionAttendeesHead;

    while (currentClassSession != nullptr)
    {   
        // currentClassSessionAttendees->class_session = currentClassSession;
        // currentClassSessionAttendees->attendee_count = 0;

        Registration *currentRegistration = registrationHead;

        if (currentRegistration->class_session->id != currentClassSession->id) {   
            // currentClassSessionAttendees->attendees = currentRegistration->attendee;
        }

        while (currentRegistration != nullptr)
        {
            if (currentRegistration->class_session == currentClassSession)
            {
                // currentClassSessionAttendees->attendee_count += 1;
                
                // currentClassSessionAttendees->attendees = currentRegistration->attendee->next;
            }
            currentRegistration = currentRegistration->next;
        }

        // currentClassSessionAttendees = currentClassSessionAttendees->next;
        currentClassSession = currentClassSession->next;
    }
    
    // return classSessionAttendeesHead;
}
