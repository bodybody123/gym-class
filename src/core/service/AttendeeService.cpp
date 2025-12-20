#include <iostream>
#include "../models/Attendee.hpp"
#include "../models/Registration.hpp"
#include "../Lists/AttendeeList.hpp"
#include "AttendeeService.hpp"

using namespace std;

void registerAttendee(
    Attendee *&attendeeHead, 
    Attendee *newAttendee
) {
    Attendee* attendee = getAttendeeByUsername(attendeeHead, newAttendee->data.name);

    if (attendee != nullptr) {
        cout << "Username sudah diambil" << endl;
        return; 
    }

    insertAttendee(attendeeHead, newAttendee);
}

void getAllAttendeesAndClassSessions(
    Attendee *attendeeHead, 
    Registration *registrationHead
) {
    Attendee *currentAttendee = attendeeHead;

    if (attendeeHead == nullptr) {
        cout << "No attendees available." << endl;
        return;
    }

    while (currentAttendee != nullptr)
    {   
        cout << "Attendee: " << currentAttendee->data.name << " (ID: " << currentAttendee->data.id << ")" << endl;

        Registration *currentRegistration = registrationHead;

        cout << "Registered Class Sessions:" << endl;
        while (currentRegistration != nullptr)
        {
            if (currentRegistration->attendee == currentAttendee)
            {
                cout << "- " << currentRegistration->class_session->name << endl 
                << "Schedule: " << getDate(currentRegistration->class_session->schedule) << endl
                << "Coach: " << currentRegistration->class_session->coach << endl
                << " (Registration date: "
                << getDate(currentRegistration->registration_date) << ")" << endl;
            }
            currentRegistration = currentRegistration->next;
        }

        currentAttendee = currentAttendee->next;
    }
}

void countAttendeesClassSessions(
    Attendee *attendeeHead, 
    Registration *registrationHead
) {
    Attendee *currentAttendee = attendeeHead;

    if (attendeeHead == nullptr) {
        cout << "No attendees available." << endl;
        return;
    }

    while (currentAttendee != nullptr)
    {   
        int count = 0;
        Registration *currentRegistration = registrationHead;

        while (currentRegistration != nullptr)
        {
            if (currentRegistration->attendee == currentAttendee)
            {
                count++;
            }
            currentRegistration = currentRegistration->next;
        }

        cout << "Attendee: " << currentAttendee->data.name << " is registered in " << count << " class session(s)." << endl;

        currentAttendee = currentAttendee->next;
    }
}
int countAttendeesWithNoClassSessions(Attendee *attendeeHead, Registration *registrationHead)
{
    Attendee* currentAttendee = attendeeHead;

    int noClassSessionCount = 0;

    while (currentAttendee != nullptr)
    {
        bool hasClassSessions = false;
        Registration* currentRegistration = registrationHead;

        while (currentRegistration != nullptr)
        {
            if (currentRegistration->attendee == currentAttendee)
            {
                hasClassSessions = true;
                break;
            }
            currentRegistration = currentRegistration->next;
        }

        if (!hasClassSessions)
        {
            noClassSessionCount++;
        }

        currentAttendee = currentAttendee->next;
    }

    return noClassSessionCount;
}