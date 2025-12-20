#include <iostream>
#include "CPage.hpp"
#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"
#include "../models/Attendee.hpp"
#include "../Lists/AttendeeList.hpp"
#include "../service/ClassSessionService.hpp"
#include "../service/RegistrationService.hpp"
#include "../service/AttendeeService.hpp"

void CAdminReportsPage(ClassSession *classSessionHead, Registration *registrationHead, Attendee *attendeeHead)
{
    int input;

    while (true)
    {
        cout << "Reports dan Analytics" << endl;
        cout << "1. Master log semua user dan kelas" << endl;
        cout << "2. Daftar Peserta Kelas (Semua Kelas dan Pesertanya)" << endl;
        cout << "3. Statistik Keterlibatan Pengguna (Jumlah kelas per pengguna)" << endl;
        cout << "4. Jumlah Pengguna Tidak Aktif (0 Kelas)" << endl;
        cout << "5. Statistik Popularitas Kelas (Jumlah peserta per kelas)" << endl;
        cout << "6. Jumlah Kelas Kosong (0 Peserta)" << endl;
        cout << "7. Kembali" << endl;
        cout << "Pilih: ";
        cin >> input;

        if (input == 7) break;

        switch (input)
        {
        case 1:
            getAllAttendeesAndClassSessions(attendeeHead, registrationHead);
            break;
        case 2:
            getAllClassAndAttendees(classSessionHead, registrationHead);
            break;
        case 3:
            countAttendeesClassSessions(attendeeHead, registrationHead);
            break;
        case 4:
            cout << "User yang belum daftar: " <<
            countAttendeesWithNoClassSessions(attendeeHead, registrationHead);
            break;
        case 5:
            countClassSessionAttendees(classSessionHead, registrationHead);
            break;
        case 6:
            cout << "Kelas yang kosong: " 
                 << countClassSessionsWithNoAttendees(classSessionHead, registrationHead) << endl;
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
            break;
        }
    }
    
}
