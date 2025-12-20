#include "RegistrationService.hpp"

bool hasRelation(Registration *registrationHead, const string &attendeeId, const string &classSessionId)
{
    Registration* cur = registrationHead;
    while (cur != NULL) {
        if (cur->attendee != NULL && cur->class_session != NULL) {
            if (cur->attendee->data.id == attendeeId && cur->class_session->id == classSessionId) {
                return true;
            }
        }
        cur = cur->next;
    }
    return false;
}

void deregisterAttendee(Registration *&registrationHead, Attendee *attendee, ClassSession *classSession)
{
    Registration* cur = registrationHead;
    Registration* prev = NULL;

    while (cur != NULL) {
        if (cur->attendee == attendee && cur->class_session == classSession) {
            if (prev == NULL) {
                registrationHead = cur->next;
            } else {
                prev->next = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void deleteRegistrationsByAttendee(
    Registration*& head,
    Attendee* attendee)
{
    Registration* curr = head;
    Registration* prev = nullptr;

    while (curr)
    {
        if (curr->attendee == attendee)
        {
            Registration* toDelete = curr;
            if (prev)
                prev->next = curr->next;
            else
                head = curr->next;

            curr = curr->next;
            delete toDelete;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}
