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
    if (classSession != nullptr) {
        cout << "Class ID: " << classSession->id << endl;
        cout << "Class Name: " << classSession->name << endl;
        cout << "Description: " << classSession->description << endl;
        cout << "Schedule: " << getDateTime(classSession->schedule) << endl;
        cout << "Capacity: " << classSession->capacity << endl;
        cout << "Fee: Rp." << classSession->fee << endl;
        cout << "Attendee Count: " << classSession->attendee_count << endl;
        cout << "Coach: " << classSession->coach << endl;
    } else {
        cout << "Class session not found." << endl;
    }
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

void updateClassSessionData(ClassSession *head, const string &id, ClassSession updatedData)
{
    ClassSession* classSession = getClassSessionById(head, id);
    if (classSession == nullptr) {
        return;
    }

    classSession->name = updatedData.name;
    classSession->description = updatedData.description;
    classSession->schedule = updatedData.schedule;
    classSession->capacity = updatedData.capacity;
    classSession->fee = updatedData.fee;
    classSession->attendee_count = updatedData.attendee_count;
    classSession->coach = updatedData.coach;
}

void showAllClassSessions(ClassSession* head) {
    ClassSession* current = head;
    while (current != nullptr) {
        std::cout << current->id << " - "
                  << current->name << "\n";
        current = current->next;
    }
}
