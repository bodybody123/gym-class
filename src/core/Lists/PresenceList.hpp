#ifndef PRESENCELIST_HPP
#define PRESENCELIST_HPP

#include "../models/Presence.hpp"

void insertPresence(Presence* head, Presence *presence);
void deletePresence(Presence* head, const string& id);

#endif