#include "ClassSessionList.hpp"

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