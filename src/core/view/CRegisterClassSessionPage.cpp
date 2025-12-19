#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include <iostream>
#include <string>

#include "../Lists/ClassSessionList.hpp"
#include "../service/ClassSessionService.hpp"

void CRegisterClassSessionPage(
    ClassSession *classSessionHead, 
    Registration* &registrationHead, 
    Attendee* currentUser) {
    
    cout << "Kelas yang tersedia untuk didaftar" << endl;
    getAllAvailableToAttendClass(classSessionHead, registrationHead, currentUser);


    cout << "Masukkan ID Class yang ingin didaftar: ";
    string classId;
    cin >> classId;

    ClassSession *classSession = getClassSessionById(classSessionHead, classId);

    if (classSession == nullptr) {
        cout << "Kelas tidak ditemukan" << endl;
        return;
    }

    attendingClassSession(classSession, registrationHead, currentUser);
}