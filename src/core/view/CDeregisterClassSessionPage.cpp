#include <iostream>
#include <string>
#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"

#include "../Lists/ClassSessionList.hpp"

#include "../service/RegistrationService.hpp"

void CDeregisterClassSessionPage(ClassSession *classSessionHead, Registration *registrationHead, Attendee *currentUser) {
    string classId;

    cout << "Pilih ID kelas: ";
    cin >> classId;

    ClassSession *classSession = getClassSessionById(classSessionHead, classId);

    if (classSession == nullptr &&
    !hasRelation(registrationHead, currentUser->data.id, classId)) {
        cout << "Kelas tidak ditemukan";
        return;
    }
    

    deregisterAttendee(registrationHead, currentUser, classSession);
    cout << "Kelas berhasil dibatalkan";
}