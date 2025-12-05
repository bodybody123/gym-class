#include <iostream>
#include "../Lists/ClassSessionList.hpp"
#include "../models/Registration.hpp"
#include "../Lists/RegistrationList.hpp"
#include "ClassSessionService.hpp"
#include "../models/Date.hpp"
 
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

    if (classSessionHead == nullptr) {
        cout << "No class sessions available." << endl;
        return;
    }

    while (currentClassSession != nullptr)
    {   
        cout << "Class Session: " << currentClassSession->name << " (ID: " << currentClassSession->id << ")" << endl;
        // currentClassSessionAttendees->class_session = currentClassSession;
        // currentClassSessionAttendees->attendee_count = 0;

        Registration *currentRegistration = registrationHead;

        // if (currentRegistration->class_session->id != currentClassSession->id) {   
        //     currentClassSessionAttendees->attendees = currentRegistration->attendee;
        // }

        cout << "Attendees:" << endl;
        while (currentRegistration != nullptr)
        {
            if (currentRegistration->class_session == currentClassSession)
            {
                cout << "- " << currentRegistration->attendee->data.name << " (Registration date: " 
                << getDate(currentRegistration->registration_date) << ")" << endl;
                
                // currentClassSessionAttendees->attendee_count += 1;
                
            }
            // currentClassSessionAttendees->attendees = currentRegistration->attendee->next;
            currentRegistration = currentRegistration->next;
        }

        // currentClassSessionAttendees = currentClassSessionAttendees->next;
        currentClassSession = currentClassSession->next;
    }
    
    // return classSessionAttendeesHead;
}

void countClassSessionAttendees(
    ClassSession *classSessionHead, 
    Registration *registrationHead
) {
    ClassSession *currentClassSession = classSessionHead;

    if (classSessionHead == nullptr) {
        cout << "No class sessions available." << endl;
        return;
    }

    while (currentClassSession != nullptr)
    {   
        int count = 0;
        Registration *currentRegistration = registrationHead;

        while (currentRegistration != nullptr)
        {
            if (currentRegistration->class_session == currentClassSession)
            {
                count++;
            }
            currentRegistration = currentRegistration->next;
        }

        cout << "Class Session: " << currentClassSession->name 
             << " has " << count << " attendees registered." << endl;

        currentClassSession = currentClassSession->next;
    }
}

void getClassSessionDetailById(
    ClassSession *classSessionHead, 
    Registration *registrationHead, 
    const string& id
) {
    ClassSession *classSession = getClassSessionById(classSessionHead, id);

    if (classSession == nullptr)
    {
        return;
    }

    printClassSessionDetails(classSession);   

    Registration *currentRegistration = registrationHead;
    while (currentRegistration != nullptr)
    {
        if (currentRegistration->class_session == classSession)
        {
            cout << "- Attendee: " << currentRegistration->attendee->data.name 
                 << " (Registration date: " << getDate(currentRegistration->registration_date) << ")" << endl;
        }
        currentRegistration = currentRegistration->next;
    }
}