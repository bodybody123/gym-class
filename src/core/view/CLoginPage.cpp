#include <iostream>
#include <string>
#include "CPage.hpp"
#include "../Lists/AttendeeList.hpp"
#include "../models/Attendee.hpp"

void CViewLoginPage(Attendee *head, Attendee* &currentUser) {
    std::string username;

    std::cout << "==== Login ====" << std::endl;
    std::cout << "Username: ";
    std::getline(std::cin >> std::ws, username);

    currentUser = getAttendeeByUsername(head, username);

    if (currentUser == nullptr) {
        cout << "User not found" << endl;
        return;
    }
}
