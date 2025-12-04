// Show parent (ClassSession) data for a given child (Attendee) ID
#include <iostream>
#include <string>
#include "../Lists/FindParent.hpp"
#include "../models/Date.hpp"

using namespace std;

// Print parent (ClassSession) data for attendee with id `attendeeId`.
void showParentDataFromChild(Registration* registrationHead, const string& attendeeId) {
    if (registrationHead == nullptr) {
        cout << "No registrations available." << endl;
        return;
    }

    ClassSession* parent = findElementParent(registrationHead, attendeeId);
    if (parent == nullptr) {
        cout << "No class session found for attendee ID '" << attendeeId << "'." << endl;
        return;
    }

    cout << "Class Session for attendee '" << attendeeId << "':" << endl;
    cout << "  ID: " << parent->id << endl;
    cout << "  Name: " << parent->name << endl;
    cout << "  Schedule: " << getDate(parent->schedule) << endl;
    cout << "  Coach: " << parent->coach << endl;
    cout << "  Capacity: " << parent->capacity << endl;
    cout << "  Attendee count: " << parent->attendee_count << endl;
    cout << "  Fee: " << parent->fee << endl;
}
