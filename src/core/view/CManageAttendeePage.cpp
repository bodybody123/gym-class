#include <iostream>
#include <string>
#include "../utils/GenerateId.hpp"
#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include "../Lists/AttendeeList.hpp"
#include "../service/ClassSessionService.hpp"
#include "../service/RegistrationService.hpp"
#include "../service/AttendeeService.hpp"

void CManageAttendeePage(Attendee *&attendeeHead, Registration *&registrationHead, ClassSession *&classSessionHead)
{
    int input;
    Attendee* newUse = new Attendee();

    while (true)
    {
        cout << "Kelola User" << endl;
        cout << "1. Lihat semua user" << endl;
        cout << "2. Lihat detail User" << endl;
        cout << "3. Buat user baru" << endl;
        cout << "4. Ubah nama user" << endl;
        cout << "5. Hapus user" << endl;
        cout << "6. Lihat kelas yagn terdaftar pada user tertentu" << endl;
        cout << "7. Kembali" << endl;
        cout << "Pilih: ";
        cin >> input;

        if (input == 7) break;

        string strInput;
        Attendee* attendee = new Attendee();
        switch (input)
        {
        case 1:
            getAllAttendees(attendeeHead);
            break;
        case 2:
            cout << "Enter Username: ";
            cin.ignore(); getline(cin, strInput);
            {
                Attendee* found = getAttendeeById(attendeeHead, strInput);
                printAttendeeDetails(found);
            }
            break;
        case 3:
            attendee->data.id = generateId("USER_");
            cout << "Enter Name: "; cin.ignore(); getline(cin, attendee->data.name);
            registerAttendee(attendeeHead, attendee);
            cout << "User Registered: " << attendee->data.id << endl;
            break;
        case 4:
            cout << "Enter User ID: ";
            cin >> strInput;

            attendee->data.id = strInput;
            cout << "Enter New Name: "; cin.ignore(); getline(cin, attendee->data.name);
            
            updateAttendee(attendeeHead, attendee);
            cout << "User Updated.\n";
            delete attendee;
            break;
        case 5:
            cout << "Enter User ID to Delete: ";
            cin >> strInput;
            attendee = getAttendeeById(attendeeHead, strInput);
            deleteRegistrationsByAttendee(registrationHead, attendeeHead);
            deleteAttendee(attendeeHead, strInput);
            cout << "User Deleted.\n";
            break;
        case 6:
            cout << "Enter User ID: ";
            cin >> strInput;
            {
                Attendee* u = getAttendeeById(attendeeHead, strInput);
                if (u) getAllAttendingClass(registrationHead, u);
                else cout << "User not found.\n";
            }
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
            break;
        }
    }
}