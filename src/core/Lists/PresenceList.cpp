#include "PresenceList.hpp"

void insertPresence(Presence *head, Presence *presence)
{
    presence->next = head;
    head = presence;
}

void deletePresence(Presence *head, const string &id)
{
    Presence *temp = head;
    Presence *prev = nullptr;

    while (temp != nullptr && temp->attendee->id != id)
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
