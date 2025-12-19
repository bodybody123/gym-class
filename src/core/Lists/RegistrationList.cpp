#include "RegistrationList.hpp"
#include <string>
#include <iostream>
#include "ClassSessionList.hpp"
#include "AttendeeList.hpp"
#include "../models/Date.hpp"

void insertRegistration(Registration* &head, Registration *registration)
{
    registration->next = head;
    head = registration;
}

void deleteRegistration(Registration* &head, const string& id)
{
    Registration *temp = head;
    Registration *prev = nullptr;

    while (temp != nullptr && temp->attendee->data.id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
        return;

    if (prev == nullptr)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
}

void getAllRegistration(Registration *head)
{
    Registration *curr = head;

    while (curr != nullptr)
    {
        printClassSessionDetails(curr->class_session);
        cout << getDate(curr->registration_date) << endl;
        printAttendeeDetails(curr->attendee);

        curr = curr->next;
    }

    cout << endl;
}
