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

int countClassSessionsWithNoAttendees(ClassSession *classSessionHead, Registration *registrationHead)
{
    ClassSession* currentClassSession = classSessionHead;
    int noAttendeeCount = 0;

    while (currentClassSession != nullptr)
    {
        bool hasAttendees = false;
        Registration* currentRegistration = registrationHead;

        while (currentRegistration != nullptr)
        {
            if (currentRegistration->class_session == currentClassSession)
            {
                hasAttendees = true;
                break;
            }
            currentRegistration = currentRegistration->next;
        }

        if (!hasAttendees)
        {
            noAttendeeCount++;
        }

        currentClassSession = currentClassSession->next;
    }

    return noAttendeeCount;
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

void showAttendeesFromClass(
    Registration* registrationHead,
    const std::string& classSessionId
) {
    if (classSessionId.empty()) {
        std::cout << "Class session ID cannot be empty.\n";
        return;
    }

    if (registrationHead == nullptr) {
        std::cout << "No registration data available.\n";
        return;
    }

    std::cout << "\n=== Attendees of Class Session "
              << classSessionId << " ===\n";

    int count = 0;
    Registration* current = registrationHead;

    while (current != nullptr) {
        if (current->class_session != nullptr &&
            current->attendee != nullptr &&
            current->class_session->id == classSessionId) {

            std::cout << ++count << ". "
                      << current->attendee->data.name
                      << " (ID: "
                      << current->attendee->data.id
                      << ")\n";
        }

        current = current->next;
    }

    if (count == 0) {
        std::cout << "No attendees registered for this class.\n";
    } else {
        std::cout << "Total attendees: " << count << "\n";
    }

    std::cout << "====================================\n";
}