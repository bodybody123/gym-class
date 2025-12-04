#include <iostream>
#include "../models/Attendee.hpp"

using namespace std;

// Print all Attendee (child) data from the linked list
void showAllChildData(Attendee* head) {
    if (head == nullptr) {
        cout << "No attendees available." << endl;
        return;
    }

    Attendee* cur = head;
    while (cur != nullptr) {
        cout << "Attendee: " << cur->data.name << " (ID: " << cur->data.id << ")" << endl;
        cur = cur->next;
    }
}
