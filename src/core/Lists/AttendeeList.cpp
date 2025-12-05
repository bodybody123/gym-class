#include <iostream>
#include "AttendeeList.hpp"

using namespace std;

void insertAttendee(Attendee* head, Attendee *attendee) {
    attendee->data.id = "random_id";
    attendee->next = head;
    head = attendee;
}

void deleteAttendee(Attendee* head, const string& id) {
    Attendee* temp = head;
    Attendee* prev = nullptr;

    while (temp != nullptr && temp->data.id != id) {
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

void printAttendeeDetails(Attendee *attendee)
{
    if (attendee != nullptr) {
        cout << "Attendee ID: " << attendee->data.id << ", Name: " << attendee->data.name << endl;
    } else {
        cout << "Attendee not found." << endl;
    }
}

void getAllAttendees(Attendee *head)
{
    Attendee* current = head;
    while (current != nullptr) {
        printAttendeeDetails(current);
        current = current->next;
    }
}

Attendee *getAttendeeById(Attendee *head, string id)
{
    Attendee* current = head;
    while (current != nullptr) {
        if (current->data.id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
