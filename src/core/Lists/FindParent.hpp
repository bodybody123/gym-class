#ifndef FINDPARENT_HPP
#define FINDPARENT_HPP

#include "../models/Registration.hpp"
#include "../models/ClassSession.hpp"
#include "../models/Attendee.hpp"
#include <string>
#include <vector>

using namespace std;

// ===== g. Find element Parent =====
/**
 * Find the parent (ClassSession) of a given child (Attendee)
 * @param registrationHead - pointer to registration linked list
 * @param attendeeId - ID of the attendee (child)
 * @return pointer to ClassSession (parent), or NULL if not found
 */
ClassSession* findElementParent(Registration* registrationHead, const string& attendeeId);

// ===== h. Find element Child =====
/**
 * Find all children (Attendees) of a given parent (ClassSession)
 * @param registrationHead - pointer to registration linked list
 * @param classSessionId - ID of the class session (parent)
 * @return vector of Attendee pointers registered in this class
 */
vector<Attendee*> findElementChild(Registration* registrationHead, const string& classSessionId);

// ===== i. Check Parent-Child Relationship =====
/**
 * Check if a specific parent (ClassSession) and child (Attendee) have a relationship
 * @param registrationHead - pointer to registration linked list
 * @param attendeeId - ID of the attendee (child)
 * @param classSessionId - ID of the class session (parent)
 * @return true if relationship exists, false otherwise
 */
bool hasParentChildRelation(Registration* registrationHead, const string& attendeeId, const string& classSessionId);

// Simple helper: return only the parent (ClassSession) id for an attendee
// Returns empty string if not found
string findParentId(Registration* registrationHead, const string& attendeeId);

#endif
