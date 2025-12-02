#ifndef REGISTRATIONLIST_HPP
#define REGISTRATIONLIST_HPP

#include "../models/Registration.hpp"

void insertRegistration(Registration* head, Registration *registration);
void deleteRegistration(Registration* head, const string& id);

#endif