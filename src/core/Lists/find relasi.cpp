#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include "../models/ClassSession.hpp"
#include <string>

using namespace std;

/**
 * Check whether a specific parent (class session id) and child (attendee id)
 * have a relation (i.e., the attendee is registered in that class).
 *
 * @param registrationHead - head of the Registration linked list
 * @param attendeeId - id of the attendee (child)
 * @param classSessionId - id of the class session (parent)
 * @return true if a registration exists linking them, false otherwise
 */
bool hasRelation(Registration* registrationHead, const string& attendeeId, const string& classSessionId) {
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
