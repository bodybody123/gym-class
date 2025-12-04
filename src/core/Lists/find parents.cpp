#include "../models/Registration.hpp"
#include "../models/ClassSession.hpp"
#include "../models/Attendee.hpp"
#include <string>
#include <vector>

using namespace std;

// ===== Find element Parent (ClassSession) =====
/**
 * Find the parent (ClassSession) of a given child (Attendee)
 * Returns the ClassSession that an attendee is registered in
 * @param registrationHead - pointer to registration linked list
 * @param attendeeId - ID of the attendee (child)
 * @return pointer to ClassSession (parent), or NULL if not found
 */
ClassSession* findElementParent(Registration* registrationHead, const string& attendeeId) {
    Registration* current = registrationHead;
    
    // Traverse registration list to find matching attendee
    while (current != NULL) {
        if (current->attendee != NULL && current->attendee->data.id == attendeeId) {
            // Found matching attendee, return their parent (ClassSession)
            return current->class_session;
        }
        current = current->next;
    }
    
    return NULL; // Parent not found
}

// Simple helper: return only the ClassSession id for a given attendee id
// Does not modify other files (header left unchanged)
string findParentId(Registration* registrationHead, const string& attendeeId) {
    Registration* current = registrationHead;
    while (current != NULL) {
        if (current->attendee != NULL && current->attendee->data.id == attendeeId) {
            if (current->class_session != NULL) {
                return current->class_session->id;
            }
            return string();
        }
        current = current->next;
    }
    return string();
}