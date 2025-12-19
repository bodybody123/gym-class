#include <iostream>
#include "core/models/ClassSession.hpp"
#include "core/models/Registration.hpp"
#include "core/models/Attendee.hpp"
#include "core/Lists/ClassSessionList.hpp"
#include "core/Lists/RegistrationList.hpp"
#include "core/Lists/AttendeeList.hpp"
#include "core/view/CPage.hpp"
#include "core/utils/GenerateId.hpp"

void init(ClassSession *&classSessionHead,
          Registration *&registrationHead,
          Attendee *&attendeeHead)
{
    /* =========================
       CREATE ATTENDEES (3)
       ========================= */

    Attendee *a0 = new Attendee{{generateId("ADMIN_"), "Admin"}, nullptr};
    Attendee *a1 = new Attendee{{generateId("USER_"), "John Doe"}, nullptr};
    Attendee *a2 = new Attendee{{generateId("USER_"), "Jane Smith"}, nullptr};
    Attendee *a3 = new Attendee{{generateId("USER_"), "Michael Lee"}, nullptr};

    insertAttendee(attendeeHead, a0);
    insertAttendee(attendeeHead, a1);
    insertAttendee(attendeeHead, a2);
    insertAttendee(attendeeHead, a3);

    /* =========================
       CREATE CLASS SESSIONS (5)
       ========================= */

    ClassSession *c1 = new ClassSession{
        generateId("CLASSID_"),
        "Morning Yoga",
        "Relaxing yoga session",
        {1, 1, 2025, 7, 0, 0},
        20,
        50000,
        "Coach Anna",
        nullptr};

    ClassSession *c2 = new ClassSession{
        generateId("CLASSID_"),
        "HIIT Training",
        "High intensity interval training",
        {2, 1, 2025, 9, 0, 0},
        15,
        75000,
        "Coach Brian",
        nullptr};

    ClassSession *c3 = new ClassSession{
        generateId("CLASSID_"),
        "Zumba",
        "Dance fitness class",
        {3, 1, 2025, 16, 0, 0},
        25,
        60000,
        "Coach Clara",
        nullptr};

    ClassSession *c4 = new ClassSession{
        generateId("CLASSID_"),
        "Weight Training",
        "Strength training basics",
        {4, 1, 2025, 18, 0, 0},
        10,
        80000,
        "Coach David",
        nullptr};

    ClassSession *c5 = new ClassSession{
        generateId("CLASSID_"),
        "Pilates",
        "Core strengthening class",
        {5, 1, 2025, 8, 0, 0},
        12,
        65000,
        "Coach Emma",
        nullptr};

    insertClassSessionData(classSessionHead, c1);
    insertClassSessionData(classSessionHead, c2);
    insertClassSessionData(classSessionHead, c3);
    insertClassSessionData(classSessionHead, c4);
    insertClassSessionData(classSessionHead, c5);

    /* =========================
       CREATE REGISTRATIONS
       ========================= */

    // John -> Yoga, HIIT
    Registration *r1 = new Registration{
        {20, 12, 2024, 10, 0, 0},
        nullptr,
        a1,
        c1};

    Registration *r2 = new Registration{
        {21, 12, 2024, 11, 30, 0},
        nullptr,
        a1,
        c2};

    // Jane -> Yoga, Zumba
    Registration *r3 = new Registration{
        {22, 12, 2024, 9, 0, 0},
        nullptr,
        a2,
        c1};

    Registration *r4 = new Registration{
        {23, 12, 2024, 14, 0, 0},
        nullptr,
        a2,
        c3};

    // Michael -> Weight Training
    Registration *r5 = new Registration{
        {24, 12, 2024, 16, 0, 0},
        nullptr,
        a3,
        c4};

    insertRegistration(registrationHead, r1);
    insertRegistration(registrationHead, r2);
    insertRegistration(registrationHead, r3);
    insertRegistration(registrationHead, r4);
    insertRegistration(registrationHead, r5);
}

int main()
{
    ClassSession *classSessionHead = nullptr;
    Registration *registrationHead = nullptr;
    Attendee *attendeeHead = nullptr;
    Attendee *currentUser = nullptr;

    init(classSessionHead, registrationHead, attendeeHead);

    while (true)
    {
        int input;

        if (currentUser == nullptr)
        {
            cout << "==== Gym Class ====" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "99. Exit" << endl;
            cout << "Pilih: ";
            cin >> input;

            switch (input)
            {
            case 1:
                CViewLoginPage(attendeeHead, currentUser);
                cout << "Halo, " + currentUser->data.name << endl;
                break;
            case 2:
                break;
            case 99:
                return 0;
                break;
            default:
                cout << "Pilihan tidak ditemukan" << endl;
                break;
            }

            continue;
        }

        // if (currentUser->data.name == "Admin")
        // {
        //     cout << "DEBUG: ADMIN PANEL";
        //     cout << "1. Dashboard" << endl;
        //     cout << "2. Search" << endl;
        //     cout << "99. Exit" << endl;
        //     cout << "Pilih: ";
        //     cin >> input;
        //     switch (input)
        //     {
        //     case 1:
        //         /* code */
        //         break;

        //     default:
        //         break;
        //     }

        //     continue;
        // }

        cout << "1. Dashboard" << endl;
        cout << "2. Lihat semua kelas" << endl;
        cout << "3. Detail" << endl;
        cout << "4. Registrasi kelas baru" << endl;
        cout << "5. Batalkan pendaftaran dari kelas" << endl;
        cout << "98. Logout" << endl;
        cout << "99. Exit" << endl;
        cout << "Pilih: ";
        cin >> input;

        string classId;

        switch (input)
        {
        case 1:
            CDashboardPage(classSessionHead, registrationHead, attendeeHead, currentUser);
            break;
        case 2:
            CGetAllClassPage(classSessionHead);
            break;
        case 3:
            cout << "Pilih ID kelas: ";
            cin >> classId;
            CClassDetailPage(classSessionHead, registrationHead, classId);
            break;
        case 4:
            CRegisterClassSessionPage(classSessionHead, registrationHead, currentUser);
            break;
        case 5:
            CDeregisterClassSessionPage(classSessionHead, registrationHead, currentUser);
            break;
        case 98:
            currentUser = nullptr;
            break;
        case 99:
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}