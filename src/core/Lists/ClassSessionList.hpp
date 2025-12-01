#ifndef CLASSSESSIONLIST_HPP
#define CLASSSESSIONLIST_HPP

#include "../models/ClassSession.hpp"

void insertClassSessionData(ClassSession* head, ClassSession *classSession);
void deleteClassData(ClassSession* head, const string& id);

#endif