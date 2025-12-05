#include <iostream>
#include "ClassSessionList.hpp"
#include "../models/Date.hpp"

void insertClassSessionData(ClassSession* head, ClassSession *classSession) {
    classSession->id = "random_id";
    classSession->next = head;
    head = classSession;
}

void deleteClassData(ClassSession* head, const string& id) {
    ClassSession* temp = head;
    ClassSession* prev = nullptr;

    while (temp != nullptr && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
}

void printClassSessionDetails(ClassSession *classSession)
{
    cout << "Class Session ID: " << classSession->id 
         << ", Name: " << classSession->name 
         << ", Schedule: " << getDate(classSession->schedule)
         << ", Coach: " << classSession->coach << endl;
}

void getAllClassSessions(ClassSession *head)
{
}

ClassSession *getClassSessionById(ClassSession *head, string id)
{
    ClassSession* current = head;
    while (current != nullptr) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}
