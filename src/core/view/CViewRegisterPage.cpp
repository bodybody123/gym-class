#include <iostream>
#include <string>
#include "CPage.hpp"
#include "../models/Attendee.hpp"
#include "../utils/GenerateId.hpp"
#include "../service/AttendeeService.hpp"

void CViewRegisterPage(Attendee* &head) {
    string username;
    
    cout << "Masukkan username: ";
    getline(cin >> ws, username);

    Attendee *newUser = new Attendee{{generateId("USER_"), username}, nullptr};

    registerAttendee(head, newUser);
}