#include <iostream>
#include <string>
#include "../utils/GenerateId.hpp"
#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include "../Lists/ClassSessionList.hpp"
#include "../Lists/RegistrationList.hpp"
#include "../Lists/AttendeeList.hpp"
#include "../service/ClassSessionService.hpp"
#include "../service/RegistrationService.hpp"
#include "../service/AttendeeService.hpp"

void CManageRegistrationPage(ClassSession *classSessionHead, Registration *&registrationHead, Attendee *attendeeHead)
{
    int input;

    while (true)
    {
        cout << "Kelola User" << endl;
        cout << "1. Lihat semua registrasi" << endl;
        cout << "2. Registrasi user ke kelas" << endl;
        cout << "3. Deregistrasi user dari kelas" << endl;
        cout << "4. Lihat semua kelas yang tersedia untuk pengguna" << endl;
        cout << "5. Kembali" << endl;
        cout << "Pilih: ";
        cin >> input;

        if (input == 5)
            break;

        string userId, classId;

        Attendee *attendee;
        ClassSession *classSession;

        switch (input)
        {
        case 1:
            getAllRegistration(registrationHead);
            break;
        case 2:
            cout << "User ID: ";
            cin >> userId;
            cout << "Class ID: ";
            cin >> classId;
            attendee = getAttendeeById(attendeeHead, userId);
            classSession = getClassSessionById(classSessionHead, classId);

            if (attendee == nullptr && classSession == nullptr)
            {
                cout << "ID Salah." << endl;
                continue;
            }
            
            attendingClassSession(classSession, registrationHead, attendee);

            break;
        case 3:
            cout << "User ID: ";
            cin >> userId;
            cout << "Class ID: ";
            cin >> classId;
            attendee = getAttendeeById(attendeeHead, userId);
            classSession = getClassSessionById(classSessionHead, classId);

            if (attendee == nullptr && classSession == nullptr)
            {
                cout << "ID Salah." << endl;
                continue;
            }

            deregisterAttendee(registrationHead, attendee, classSession);

            break;
        case 4:
            cout << "User ID: ";
            cin >> userId;
            attendee = getAttendeeById(attendeeHead, userId);

            if (attendee == nullptr)
            {
                cout << "ID Salah." << endl;
                continue;
            }

            cout << "Kelas tersedia untuk " << attendee->data.name << ":" << endl;
            getAllAvailableToAttendClass(classSessionHead, registrationHead, attendee);

            break;
        default:
            break;
        }
    }
}