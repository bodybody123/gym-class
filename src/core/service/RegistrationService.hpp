#ifndef REGISTRATIONSERVICE_HPP
#define REGISTRATIONSERVICE_HPP

#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include "../models/ClassSession.hpp"

bool hasRelation(
    Registration* registrationHead, 
    const string& attendeeId, 
    const string& classSessionId
) {
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

#endif