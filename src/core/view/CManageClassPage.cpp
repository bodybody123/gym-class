#include <iostream>
#include <string>
#include "../utils/GenerateId.hpp"
#include "../models/ClassSession.hpp"
#include "../models/Registration.hpp"
#include "../Lists/ClassSessionList.hpp"
#include "../service/ClassSessionService.hpp"
#include "../service/RegistrationService.hpp"

void CManageClassPage(ClassSession *&classSessionHead, Registration *&registrationHead) {
    int input;

    while (true) 
    {
        cout << "Kelola Kelas" << endl;
        cout << "1. Lihat semua kelas" << endl;
        cout << "2. Lihat detail kelas" << endl;
        cout << "3. Buat kelas baru" << endl;
        cout << "4. Ubah kelas detail" << endl;
        cout << "5. Hapus kelas" << endl;
        cout << "6. Kembali" << endl;
        cout << "Pilih: ";
        cin >> input;

        if (input == 6) break;

        string classId;
        ClassSession *classSession;
        switch (input)
        {
        case 1:
            getAllClassAndAttendees(classSessionHead, registrationHead);
            break;
        case 2:
            cout << "Masukkan ID kelas: ";
            cin >> classId;
            getClassSessionDetailById(classSessionHead, registrationHead, classId);
            break;
        case 3:
            createNewClassSession(classSessionHead);
            break;
        case 4:
            updateNewClassSession(classSessionHead);
            break;
        case 5:
            cout << "Enter Class ID to Delete: ";
            cin >> classId;
            deleteClassData(classSessionHead, classId);
            cout << "Class Deleted (if it existed).\n";
            break;
        default:
            cout << "Pilihan tidak ditemukan" << endl;
            break;
        }
    }
    
}