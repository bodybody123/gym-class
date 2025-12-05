#include "RegistrationList.hpp"
#include <string>

void insertRegistration(Registration* head, Registration *registration)
{
    registration->next = head;
    head = registration;
}

void deleteRegistration(Registration* head, const string& id)
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
