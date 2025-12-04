#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include "../models/ClassSession.hpp"
#include <vector>
#include <string>

using namespace std;

/**
 * Find all children (Attendee pointers) for a given ClassSession id.
 * @param registrationHead - head of the Registration linked list
 * @param classSessionId - id of the ClassSession (parent)
 * @return vector of Attendee* (may be empty if none found)
 */
vector<Attendee*> findElementChild(Registration* registrationHead, const string& classSessionId) {
    vector<Attendee*> result;
    Registration* current = registrationHead;

    while (current != NULL) {
        if (current->class_session != NULL && current->class_session->id == classSessionId) {
            if (current->attendee != NULL) {
                result.push_back(current->attendee);
            }
        }
        current = current->next;
    }

    return result;
}

/**
 * Convenience helper: return attendee IDs for a given ClassSession id.
 * @return vector of attendee id strings (may be empty)
 */
vector<string> findElementChildIds(Registration* registrationHead, const string& classSessionId) {
    vector<string> ids;
    Registration* current = registrationHead;

    while (current != NULL) {
        if (current->class_session != NULL && current->class_session->id == classSessionId) {
            if (current->attendee != NULL) {
                ids.push_back(current->attendee->data.id);
            }
        }
        current = current->next;
    }

    return ids;
}
