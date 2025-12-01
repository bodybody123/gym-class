#include "AttendeeList.hpp"

void insertAttendee(Attendee* head, Attendee *attendee) {
    attendee->id = "random_id";
    attendee->next = head;
    head = attendee;
}

void deleteAttendee(Attendee* head, const string& id) {
    Attendee* temp = head;
    Attendee* prev = nullptr;

    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}