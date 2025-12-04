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

// ===== Find element Child (Attendee) =====
/**
 * Find all children (Attendees) of a given parent (ClassSession)
 * Returns all attendees registered in a specific class
 * @param registrationHead - pointer to registration linked list
 * @param classSessionId - ID of the class session (parent)
 * @return vector of Attendee pointers registered in this class
 */
vector<Attendee*> findElementChild(Registration* registrationHead, const string& classSessionId) {
    vector<Attendee*> children;
    Registration* current = registrationHead;
    
    // Traverse registration list to find all attendees in this class
    while (current != NULL) {
        if (current->class_session != NULL && current->class_session->id == classSessionId) {
            // Found a registration in this class, add attendee to list
            if (current->attendee != NULL) {
                children.push_back(current->attendee);
            }
        }
        current = current->next;
    }
    
    return children;
}

// ===== Check if Parent and Child have relationship =====
/**
 * Check if a specific parent (ClassSession) and child (Attendee) have a relationship
 * Verifies if an attendee is registered in a specific class
 * @param registrationHead - pointer to registration linked list
 * @param attendeeId - ID of the attendee (child)
 * @param classSessionId - ID of the class session (parent)
 * @return true if relationship exists, false otherwise
 */
bool hasParentChildRelation(Registration* registrationHead, const string& attendeeId, const string& classSessionId) {
    Registration* current = registrationHead;
    
    // Traverse registration list to find matching parent-child relationship
    while (current != NULL) {
        if (current->attendee != NULL && current->class_session != NULL) {
            // Check if both IDs match
            if (current->attendee->data.id == attendeeId && current->class_session->id == classSessionId) {
                return true; // Relationship found
            }
        }
        current = current->next;
    }
    
    return false; // No relationship found
}